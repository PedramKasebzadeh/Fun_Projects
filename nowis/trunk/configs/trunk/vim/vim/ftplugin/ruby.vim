" Vim filetype plugin file
" Language:    Ruby
" Maintainer:  Damien Gombault <desintegr@gmail.com>
" Last Change: 2008 Jan 30

" Auto tags
inoreabbrev <buffer> req require<Space>''<Esc>i
inoreabbrev <buffer> def def<CR>end<Esc>kA
inoreabbrev <buffer> class class<CR>end<Esc>kA
inoreabbrev <buffer> begin begin<CR>end<Esc>kA
inoreabbrev <buffer> case case<CR>end<Esc>kA
inoreabbrev <buffer> init def<Space>initialize<CR>end<Esc>kA
inoreabbrev <buffer> do do<CR>end<Esc>kA

" Auto brackets
inoremap <buffer> #{ #{}<Esc>i
inoremap <buffer> \|\| \|\|<Esc>i

" Folding options
let ruby_fold=1
