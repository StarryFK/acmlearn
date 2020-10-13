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
function Close(char)
    if getline('.')[col('.') - 1] == a:char
        return "\<Right>"
    else
        return a:char
    endif
endfunction

map <C-A> ggVG"+y
map <F5> :call Run()<CR>
func! Run()
    exec "w"
    exec "!g++ -O2 -std=c++11 -Wall % -o %<"
    exec "!./%<"
endfunc
