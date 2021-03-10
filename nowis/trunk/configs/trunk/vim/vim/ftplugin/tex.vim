" Vim filetype plugin file
" Language:    TeX
" Maintainer:  Damien Gombault <desintegr@gmail.com>
" Last Change: 2008 Oct 26

" Line break
setlocal linebreak
setlocal nolist
setlocal breakat+=\ 
setlocal tw=76

" Compilation
setlocal makeprg=pdflatex\ %

" correction orthographique
setlocal spell spelllang=fr
