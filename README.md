# procon

競技プログラミングの練習用リポジトリ。AtCoder の過去問を [atcoder-tools](https://github.com/kyuridenamida/atcoder-tools) で解く。言語は C++ (C++23)。

## セットアップ

前提: `uv`、`g++` (Apple clang で可)、`python3`

```sh
./tools/setup.sh
```

このスクリプトは何度実行しても問題ない。以下を行う。

- `atcoder-tools` をインストール (`uv tool install atcoder-tools`)
- [AC Library](https://github.com/atcoder/ac-library) を `lib/ac-library` に clone (gitignore 済み)

続けて `bin/` を PATH に追加する (`~/.zshrc` などに書いておく)。

```sh
export PATH="$HOME/projects/inada-s/procon/bin:$PATH"
```

ログインは不要。過去問の取得はログインなしで行い、提出はブラウザで行う (AtCoder の提出ページには CAPTCHA があるため)。

### Windows の場合 (WSL2)

スクリプトは bash 前提なので、Windows では WSL2 (Ubuntu) の中で動かす。WSL での動作はまだ確認していない。

1. PowerShell を管理者で開いて WSL を入れ、再起動する

   ```powershell
   wsl --install
   ```

2. Ubuntu 側で必要なものを入れる

   ```sh
   sudo apt update && sudo apt install -y build-essential git python3 wslu
   curl -LsSf https://astral.sh/uv/install.sh | sh
   ```

   `wslu` は `s` が Windows 側のブラウザで提出ページを開くのに使う (`wslview`)。

3. リポジトリを WSL 側のホームに clone してセットアップする。`/mnt/c/...` 配下に置くとファイルアクセスがかなり遅いので `~/` に置く

   ```sh
   git clone <このリポジトリ> ~/procon
   cd ~/procon && ./tools/setup.sh
   echo 'export PATH="$HOME/procon/bin:$PATH"' >> ~/.bashrc
   ```

4. エディタは VS Code に「WSL」拡張を入れ、WSL の中で `code .` を実行すると WSL 内のファイルをそのまま編集できる

これ以降の手順は macOS と同じ。Linux の g++ には `bits/stdc++.h` が最初からあり、`DEBUG=1 t` の sanitizer も使える。`s` のクリップボードへのコピーは `clip.exe` で行う。

Windows ネイティブ (WSL なし) は勧めない。`gen` / `t` / `s` を動かすには Git Bash などが必要になり、MinGW の g++ では AddressSanitizer が使えないため。

## 練習の流れ

```sh
gen abc300            # atcoder/abc300/{A,B,C,...}/ にテンプレートとサンプルを作る
cd atcoder/abc300/A
vim main.cpp
t                     # ビルドしてサンプルを実行
s                     # サンプルが全部通れば、コードをコピーしてブラウザで提出ページを開く
cd ../B
```

生成されるディレクトリ:

```
atcoder/abc300/
├── A/
│   ├── main.cpp          # テンプレート (atcoder/template.jinja2) から生成。入力部分も自動生成される
│   ├── metadata.json     # 問題 ID、実行時間制限、判定方法 (誤差許容など)
│   ├── in_1.txt  out_1.txt
│   └── in_2.txt  out_2.txt ...
└── B/ ...
```

## コマンド

### `gen` — コンテストの問題を取得

```sh
gen abc300
```

`atcoder/<contest>/<問題>/` にテンプレートとサンプルを作る。ログインせずに取得するので、終了済みのコンテストだけが対象。

- 問題文から入力形式を推定し、`main.cpp` に入力を読む部分と `solve(...)` の引数を生成する。推定できなかった問題は `// Failed to predict input format` になるので、入力部分を自分で書く
- 複数テストケース形式 (先頭に `T` があるもの) はケースのループも生成する
- すでにディレクトリがある問題はスキップするので、書きかけの `main.cpp` が上書きされることはない。作り直したいときは問題のディレクトリを消してから `gen` する
- AtCoder は続けてアクセスすると 429 (レート制限) を返すので、リクエストの間隔を 0.5 秒空けている。`ATCODER_REQUEST_INTERVAL=1 gen abc300` のように変えられる。それでも取得に失敗した問題があれば、`gen` が少し待って自動で再実行する
- `gen` は `tools/atcoder_tools.py` 経由で atcoder-tools を呼ぶ。このラッパーはリクエストの間隔を空けるほか、atcoder-tools のバグ (小数の判定方法を推定できない問題で落ち、`main.cpp` が作られない) を回避している

### `t` — ビルドしてサンプルを実行

カレントディレクトリの `main.cpp` を `g++ -std=c++23 -O2 -DLOCAL` でビルドし、`atcoder-tools test` でサンプルを実行する。

```sh
t                     # 通常
t -n 2                # 追加の引数は atcoder-tools test に渡る (この例は 2 番目のサンプルだけ実行)
t -k                  # 最初に失敗したケースで止める
t -j absolute -v 1e-6 # 浮動小数点の誤差を許容して判定する (問題文から自動で判定されることも多い)
DEBUG=1 t             # -g -O0 と AddressSanitizer / UBSan を付けてビルド (範囲外アクセスなどを検出)
```

- 実行時間制限は問題の制限 x 1.2 (`tools/atcodertools.toml` の `timeout_adjustment`)
- `-DLOCAL` が付くので、テンプレートの `dump(x)` はローカルでだけ stderr に出力される
- `#include <bits/stdc++.h>` は `include/bits/stdc++.h` (代替ヘッダ) で解決し、`#include <atcoder/all>` は `lib/ac-library` で解決する
- 自分でテストケースを追加するときは、続きの番号で `in_4.txt` と `out_4.txt` を置く
- 手で入力して試すときは `./a.out < in_1.txt` のように実行する

### `s` — 提出

`t` を実行して全サンプルが AC なら、`main.cpp` をクリップボードにコピーし、ブラウザでその問題の提出ページを開く。ブラウザでは言語 (C++23 (GCC)) を確認し、コードを貼り付けて「提出」を押す。

```sh
s                     # 通常
FORCE=1 s             # サンプルが落ちても開く
```

## 補足

- 設定は `tools/atcodertools.toml` にあり、`gen` / `t` が `--config` で渡す。`~/.atcodertools.toml` は使わない
- テンプレートを変更するときは `atcoder/template.jinja2` を編集する ([テンプレートで使える変数](https://github.com/kyuridenamida/atcoder-tools#テンプレートの例))。変更は次に `gen` で作る問題から反映される
- 新しくビルドしたバイナリは、初回の実行だけ macOS の検査で 0.5〜1 秒ほど遅くなる。2 回目以降は通常の速度になる
- `atcoder/` 配下の古いディレクトリも同じ形式 (以前から atcoder-tools を使っていた) なので、そのまま `t` で試せる
- Vim の設定 (構文ハイライト、インデント、vim から `t` / `s` を呼ぶ) は [VIM.md](VIM.md) にまとめてある
