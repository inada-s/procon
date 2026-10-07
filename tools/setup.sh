#!/usr/bin/env bash
# atcoder-tools のインストールと AC Library の取得を行う。何度実行してもよい。
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

command -v atcoder-tools >/dev/null || uv tool install atcoder-tools

# AC Library
if [[ ! -d "$ROOT/lib/ac-library" ]]; then
  git clone --depth 1 https://github.com/atcoder/ac-library.git "$ROOT/lib/ac-library"
fi

echo
echo "セットアップ完了。まだなら PATH を通してください:"
echo "  export PATH=\"$ROOT/bin:\$PATH\""
