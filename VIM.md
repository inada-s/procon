# Vim の設定

このリポジトリで C++ を書くための `~/.vimrc` の設定。macOS 標準の `/usr/bin/vim` (Vim 9.1, `+terminal`) で動作を確認している。

vimrc がないと、macOS の vim では構文ハイライトもファイル種別ごとのインデントも有効にならない。

## できること

- C++ の構文ハイライトと、テンプレート (`atcoder/template.jinja2`) に合わせたスペース 4 つのインデント
- vim から `t` / `s` を呼び出し、結果を画面下のウィンドウに表示する

| キー | コマンド | 実行される処理 |
|---|---|---|
| `Space t` | `:T` | `t` (ビルドしてサンプルを実行) |
| `Space d` | `:TD` | `DEBUG=1 t` (sanitizer 付きでビルド) |
| `Space s` | `:S` | `s` (サンプルが全部通れば、コードをコピーしてブラウザで提出ページを開く) |
| — | `:FS` | `FORCE=1 s` (サンプルが落ちても開く) |
| `Space q` | — | 結果ウィンドウを閉じる |

- `:T` / `:TD` の後ろに書いた引数は `t` に渡る (例: `:T -n 2`、`:T -k`)
- 実行前に未保存の変更があれば保存する
- 実行するたびに前回の結果ウィンドウを閉じて開き直す
- 実行後はカーソルが編集中のウィンドウに戻る。結果ウィンドウをスクロールしたいときは `Ctrl-w p` で移動する
- `bin/t` / `bin/s` は開いているファイルのディレクトリから上へたどって探すので、`bin/` を PATH に入れていなくても動く。コマンドは開いているファイルのディレクトリで実行される

## 設定方法

以下を `~/.vimrc` に書く (既存の vimrc があれば追記する)。

```vim
" 基本
set nocompatible
set encoding=utf-8
set fileencodings=utf-8,sjis,euc-jp
set backspace=indent,eol,start
set hidden
set nobackup noswapfile

" 表示
syntax enable
filetype plugin indent on
set number
set ruler
set showcmd
set showmatch
set laststatus=2
set wildmenu
set background=dark

" 検索
set hlsearch
set incsearch
set ignorecase
set smartcase

" インデント (スペース 4 つ)
set expandtab
set tabstop=4
set shiftwidth=4
set softtabstop=4
set autoindent
set smartindent

" C/C++: namespace やアクセス指定子のインデント調整
autocmd FileType c,cpp setlocal cindent cinoptions=g0,N-s,:0,(0

" ---- procon: bin/t, bin/s を vim から呼ぶ ----
" ファイルの位置から上へたどって bin/<name> を探し、そのディレクトリで
" 下側のターミナルに実行する。前回の結果ウィンドウは閉じて使い回す。
let mapleader = "\<Space>"

function! s:ProconRun(name, env, args) abort
  let l:dir = expand('%:p:h')
  let l:bin = findfile('bin/' . a:name, l:dir . ';')
  if l:bin ==# ''
    echohl ErrorMsg | echo 'bin/' . a:name . ' が見つかりません' | echohl None
    return
  endif
  if &modified | write | endif
  for l:b in term_list()
    if getbufvar(l:b, 'procon_term', 0)
      execute 'bwipeout!' l:b
    endif
  endfor
  let l:cmd = a:env . shellescape(fnamemodify(l:bin, ':p')) . (a:args ==# '' ? '' : ' ' . a:args)
  let l:buf = term_start(['/bin/sh', '-c', l:cmd], {
        \ 'cwd': l:dir, 'term_rows': 15, 'term_name': a:name . ' ' . a:args})
  call setbufvar(l:buf, 'procon_term', 1)
  wincmd p
endfunction

" :T [atcoder-tools test の引数] / :TD (DEBUG=1) / :S (コピーして提出ページを開く) / :FS (FORCE=1 s)
command! -nargs=* T  call s:ProconRun('t', '', <q-args>)
command! -nargs=* TD call s:ProconRun('t', 'DEBUG=1 ', <q-args>)
command! -nargs=0 S  call s:ProconRun('s', '', '')
command! -nargs=0 FS call s:ProconRun('s', 'FORCE=1 ', '')

nnoremap <silent> <Leader>t :T<CR>
nnoremap <silent> <Leader>d :TD<CR>
nnoremap <silent> <Leader>s :S<CR>
" 結果ウィンドウを閉じる
nnoremap <silent> <Leader>q :for b in term_list() \| if getbufvar(b, 'procon_term', 0) \| execute 'bwipeout!' b \| endif \| endfor<CR>
```

`t` / `s` の中で呼ぶ `atcoder-tools` は vim から起動したシェルの PATH で探されるので、`atcoder-tools` に PATH が通っている必要がある (`./tools/setup.sh` でインストールした場合は `~/.local/bin` に入るので、通常そのままでよい)。

## 確認

```sh
vim --version | grep -o '[+-]terminal'   # +terminal なら t / s の呼び出しが使える
```

問題ディレクトリで `vim main.cpp` を開き、`:set ft? sw? et?` が `filetype=cpp shiftwidth=4 expandtab` になっていれば設定が読み込まれている。`Space t` で下にウィンドウが開き、`atcoder-tools test` の結果が出れば `t` の呼び出しも動いている。

## 補足

- `atcoder/arc001/` や `codeforces/` などの古いファイルはスペース 2 つでインデントしている。編集するときは `:setlocal sw=2 sts=2` で合わせる
- 背景が明るいターミナルでは `set background=dark` を `light` にする。配色を変えたいときは `colorscheme desert` などを追加する
- Neovim では `term_start` / `term_list` がないので、`t` / `s` の呼び出し部分はそのままでは動かない
