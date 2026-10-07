"""atcoder-tools をいくつか補正して実行するラッパー。インストール済みのパッケージは書き換えない。

- AtCoder へのリクエストの間隔を ATCODER_REQUEST_INTERVAL 秒 (既定 0.5) 以上空ける。
  間隔を空けずにアクセスすると 429 (レート制限) が返り、その問題の取得に失敗するため。
- 判定方法 (小数の誤差判定) の推定に失敗しても落ちないようにする。
  upstream は NoDecimalCandidatesError などを捕まえておらず、サンプルだけ作って main.cpp を作らずに終わるため。

使い方: <atcoder-tools の python> tools/atcoder_tools.py gen abc300 ...
"""
import os
import sys
import time

from atcodertools.atcoder_tools import main
from atcodertools.client.atcoder import AtCoderClient
from atcodertools.common.judgetype import NormalJudge
from atcodertools.common.logging import logger
import atcodertools.constprediction.constants_prediction as constants_prediction

INTERVAL = float(os.environ.get("ATCODER_REQUEST_INTERVAL", "0.5"))

_original_request = AtCoderClient._request
_last_request = 0.0


def _throttled_request(self, *args, **kwargs):
    global _last_request
    wait = _last_request + INTERVAL - time.monotonic()
    if wait > 0:
        time.sleep(wait)
    try:
        return _original_request(self, *args, **kwargs)
    finally:
        _last_request = time.monotonic()


_original_predict_judge_method = constants_prediction.predict_judge_method


def _safe_predict_judge_method(html):
    try:
        return _original_predict_judge_method(html)
    except (constants_prediction.NoDecimalCandidatesError,
            constants_prediction.MultipleDecimalCandidatesError) as e:
        logger.warning("decimal prediction failed ({}) -- normal judge is used".format(type(e).__name__))
        return NormalJudge()


AtCoderClient._request = _throttled_request
constants_prediction.predict_judge_method = _safe_predict_judge_method

if __name__ == "__main__":
    sys.argv[0] = "atcoder-tools"
    sys.exit(main())
