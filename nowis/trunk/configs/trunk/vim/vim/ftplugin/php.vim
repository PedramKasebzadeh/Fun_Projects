" Vim filetype plugin file
" Language:    PHP
" Maintainer:  Damien Gombault <desintegr@gmail.com>
" Last Change: 2007 Apr 19

" Auto tags
inoremap <buffer> <?p <?php<CR>?><Esc>O
inoremap <buffer> <? <?<Space><Space>?><Esc>2hi
inoremap <buffer> <?? <?<Space>
inoremap <buffer> <?<Space> <?<Space>
inoremap <buffer> <?= <?=<Space><Space>?><Esc>2hi
inoremap <buffer> <= <?=<Space><Space>?><Esc>2hi

" Syntax options
let php_sql_query=1
let php_baselib=1
let php_htmlInStrings=1
let php_parent_error_close=1
let php_parent_error_open=1
let php_folding=1
