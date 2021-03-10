" Vim filetype plugin file
" Language:    Prod
" Maintainer:  Damien Gombault <desintegr@gmail.com>
" Last Change: 2008 Feb 01

" Auto tags
inoreabbrev <buffer> tr #trans<CR>in<Space><Space>{<Space><Space>}<CR>out<Space>{<Space><Space>}<CR>#endtr<Esc>3kA

" Auto brackets
inoremap <buffer> << <..><Esc>hi
inoremap <buffer> {} {}<Esc>i
