# procon

競技プログラミングの練習用リポジトリ。AtCoder の過去問を [atcoder-cli (acc)](https://github.com/Tatamo/atcoder-cli) と [online-judge-tools (oj)](https://github.com/online-judge-tools/oj) で解く。言語は C++ (C++20)。

## セットアップ

前提: `uv`、`npm`、`g++` (Apple clang で可)

```sh
./tools/setup.sh
```

このスクリプトは何度実行しても問題ない。以下を行う。

- `oj` (`uv tool install --with setuptools online-judge-tools`) / `acc` (`npm i -g atcoder-cli`) / `aclogin` をインストール
- acc の設定: 全問題を取得、テストは `tests/`、テンプレートは `cpp`
- `tools/acc-template/cpp` を acc の設定ディレクトリへシンボリックリンク (テンプレートはこのリポジトリで管理)
- [AC Library](https://github.com/atcoder/ac-library) を `lib/ac-library` に clone (gitignore 済み)

続けて `bin/` を PATH に追加する (`~/.zshrc` などに書いておく)。

```sh
export PATH="$HOME/projects/inada-s/procon/bin:$PATH"
```

### Windows の場合 (WSL2)

スクリプトは bash 前提なので、Windows では WSL2 (Ubuntu) の中で動かす。WSL での動作はまだ確認していない。

1. PowerShell を管理者で開いて WSL を入れ、再起動する

   ```powershell
   wsl --install
   ```

2. Ubuntu 側で必要なものを入れる。Node.js は nvm で入れる (apt の npm だと `npm i -g` に sudo が必要になるため)

   ```sh
   sudo apt update && sudo apt install -y build-essential git
   curl -LsSf https://astral.sh/uv/install.sh | sh
   curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/master/install.sh | bash
   # シェルを開き直してから
   nvm install --lts
   ```

3. リポジトリを WSL 側のホームに clone してセットアップする。`/mnt/c/...` 配下に置くとファイルアクセスがかなり遅いので `~/` に置く

   ```sh
   git clone <このリポジトリ> ~/procon
   cd ~/procon && ./tools/setup.sh
   echo 'export PATH="$HOME/procon/bin:$PATH"' >> ~/.bashrc
   ```

4. 次の「ログイン」と同じ手順でログインする。`REVEL_SESSION` は Windows 側のブラウザからコピーし、WSL で `aclogin` に貼り付ける
5. エディタは VS Code に「WSL」拡張を入れ、WSL の中で `code .` を実行すると WSL 内のファイルをそのまま編集できる

これ以降の手順は macOS と同じ。Linux の g++ には `bits/stdc++.h` が最初からあり、`DEBUG=1 t` の sanitizer も使える。

Windows ネイティブ (WSL なし) は勧めない。`t` / `s` / `setup.sh` を動かすには Git Bash などが必要になり、MinGW の g++ では AddressSanitizer が使えず、`setup.sh` が張るシンボリックリンクには開発者モードか管理者権限が必要になるため。

### ログイン

`acc new` は過去問の取得でもログインが必要。AtCoder のログイン画面には CAPTCHA があるため `acc login` / `oj login` は失敗するので、ブラウザのクッキーを `aclogin` でコピーする。

1. ブラウザで AtCoder にログインする
2. 開発者ツール → Application (Firefox は Storage) → Cookies → `https://atcoder.jp` を開き、`REVEL_SESSION` の値をコピーする
3. `aclogin` を実行し、値を貼り付ける (acc と oj の両方に保存される)

`acc session` で `OK` と表示されればログインできている。セッションが切れたら同じ手順をもう一度行う。

## 練習の流れ

```sh
cd atcoder
acc new abc300        # abc300/{a,b,c,...}/ にテンプレートとサンプルを展開
cd abc300/a
vim main.cpp
t                     # ビルドしてサンプルを実行
s                     # サンプルが全部通れば提出 (確認プロンプトあり)
cd ../b
```

生成されるディレクトリ:

```
atcoder/abc300/
├── contest.json      # acc のメタデータ (acc s が参照する)
├── a/
│   ├── main.cpp
│   └── tests/        # sample-1.in, sample-1.out, ...
└── b/ ...
```

## コマンド

### `t` — ビルドしてサンプルを実行

カレントディレクトリの `main.cpp` を `g++ -std=c++20 -O2 -DLOCAL` でビルドし、`oj t -c ./a.out -d tests` を実行する。

```sh
t                     # 通常
t -e 1e-6             # 追加の引数は oj t に渡る (この例は浮動小数点の誤差を許容)
DEBUG=1 t             # -g -O0 と AddressSanitizer / UBSan を付けてビルド (範囲外アクセスなどを検出)
```

- `-DLOCAL` が付くので、テンプレートの `dump(x)` はローカルでだけ stderr に出力される
- `#include <bits/stdc++.h>` は `include/bits/stdc++.h` (代替ヘッダ) で解決し、`#include <atcoder/all>` は `lib/ac-library` で解決する
- 自分でテストケースを追加するときは `tests/custom-1.in` と `tests/custom-1.out` を置く
- 手で入力して試すときは `./a.out < tests/sample-1.in` のように実行する

### `s` — 提出

`t` を実行して全サンプルが AC なら `acc s` で `main.cpp` を提出する。

```sh
s                     # 通常
FORCE=1 s             # サンプルが落ちても提出する
s -- -l <言語ID>      # "--" 以降は oj s に渡る。言語の自動判定がうまくいかないときに使う
```

### acc / oj を直接使う

```sh
acc new abc300 --choice inquire   # 取得する問題を選ぶ
acc add                            # contest ディレクトリ内で、未取得の問題を追加
acc tasks abc300                   # 問題一覧
oj d https://atcoder.jp/contests/abc300/tasks/abc300_a -d tests   # 1問だけサンプルを取得 (過去問ならログイン不要)
```

## 補足

- 新しくビルドしたバイナリは、初回の実行だけ macOS の検査で 0.5〜1 秒ほど遅くなる。2回目以降は通常の速度になる
- 古い `atcoder/` 配下のディレクトリ (`A/main.cpp`、`in_*.txt`、`metadata.json`) は以前使っていた atcoder-tools の形式。`atcoder/template.jinja2` はそのときのテンプレート
- テンプレートを変更するときは `tools/acc-template/cpp/main.cpp` を編集する (シンボリックリンク経由で acc に反映される)
