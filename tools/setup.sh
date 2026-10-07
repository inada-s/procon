#!/usr/bin/env bash
# acc / oj / aclogin のインストールと acc の設定、AC Library の取得を行う。何度実行してもよい。
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# oj: Python 3.12+ では distutils が無いので setuptools を同梱する
if ! oj --version >/dev/null 2>&1; then
  uv tool install --force --with setuptools online-judge-tools
fi
# aclogin: ブラウザの REVEL_SESSION クッキーを acc / oj に保存する (AtCoder のログインは CAPTCHA 付きのため)
command -v aclogin >/dev/null || uv tool install aclogin
command -v acc >/dev/null || npm install -g atcoder-cli

# acc の設定
acc config default-task-choice all
acc config default-test-dirname-format tests
acc config default-template cpp
acc config oj-path "$(command -v oj)"

# テンプレートはリポジトリで管理し、acc の設定ディレクトリへシンボリックリンクを張る
CONFIG_DIR="$(acc config-dir)"
ln -sfn "$ROOT/tools/acc-template/cpp" "$CONFIG_DIR/cpp"

# AC Library
if [[ ! -d "$ROOT/lib/ac-library" ]]; then
  git clone --depth 1 https://github.com/atcoder/ac-library.git "$ROOT/lib/ac-library"
fi

echo
echo "セットアップ完了。まだなら以下を行ってください:"
echo "  1. PATH に追加: export PATH=\"$ROOT/bin:\$PATH\""
echo "  2. ログイン:    aclogin   (README の「ログイン」参照)"
