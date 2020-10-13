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
map <C-S> ggvG$c
map <F5> :call Comp()<CR>
map <F6> :call Run()<CR>
map <F7> :call Runw()<CR>
func! Comp()
    exec "w"
    exec "!g++ -O2 -std=c++11 -Wall % -o %<"
endfunc
func! Run()
	exec "!time ./%<"
endfunc
func! Runw()
	exec "!time ./%< <in.txt"
endfunc
