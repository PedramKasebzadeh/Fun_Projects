" Vim filetype plugin file
" Language:    Perl
" Maintainer:  Damien Gombault <desintegr@gmail.com>
" Last Change: 2008 Oct 25

" Keyboard shortcuts
noremap <buffer> <C-S-f> :%!perltidy -q<CR>
vnoremap <buffer> <C-S-f> :!perltidy -q<CR>

" Syntax check
setlocal makeprg=perl\ -c\ %
setlocal errorformat=
   \%-G%.%#had\ compilation\ errors.,
   \%-G%.%#syntax\ OK,
   \%m\ at\ %f\ line\ %l.,
   \%+A%.%#\ at\ %f\ line\ %l\\,%.%#,
   \%+C%.%#
