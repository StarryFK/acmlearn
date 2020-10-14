filetype plugin indent on
set nu
set hlsearch 
set syntax=on
set tabstop=4
set shiftwidth=4
set smarttab
set smartindent
set showmatch
set matchtime=0
set report=0
set nomagic

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
map <F5> :call Comp()<CR>
map <F6> :!time ./%< <in.txt

func! Comp()
    exec "w"
    exec "!g++ -O2 -std=c++11 -Wall % -o %<"
endfunc
