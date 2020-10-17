filet indent on
se nocp hi=1000 rnu fdm=indent fen wmnu ic scs ls=2 sc nomagic report=0 mat=0 sm nu si ts=4 hls sw=4 sts=4 sta
sy on

:inoremap ( ()<ESC>i
:inoremap [ []<ESC>i
:inoremap { {}<ESC>i
:inoremap {<CR> {<CR>}<ESC>O

:inoremap ) <c-r>=Close(')')<CR>
:inoremap ] <c-r>=Close(']')<CR>
:inoremap } <c-r>=Close('}')<CR>

func! Close(char)
    if getline('.')[col('.') - 1] == a:char
        return "\<Right>"
    else
        return a:char
    endif
endfunc

map <C-A> ggVG"+y
map <C-S> ggVGc
map <F5> :w<CR>:!g++ -O2 -std=c++11 -Wall -Wextra -Wshadow % -o %<<CR>
map <F6> :!time ./%< <in.txt

