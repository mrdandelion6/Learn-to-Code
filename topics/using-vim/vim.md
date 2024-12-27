# vim notes

in these notes we will go over both the vim program and vim motions. we will first motivate why vim is worth learning and then differentiate between the vim program and vim motions.

after that we will go over the primary vim motions and some tips regarding them. later on we will see how to use and configure the vim program. 

## what is vim ?
there are 2 separate things we mean when we say "vim":
1. the vim program
2. vim motions

firstly, let's distinguish between the 2 kinds of vim:
1. **the vim program** : a text editor program used directly inside the terminal. you use the `vim` or `vi` command to start it.
2. **vim motions** : key strokes and shortcuts configured to edit text quickly. can enable in other text editors like vscode using extensions.

## why use vim ?

while you may or may not want to use the vim program, **everyone** should use vim motions. it simply speeds up your text editing skills.

## should i use neovim ?

short answer: probably

long answer: yeah probably

if you are unfamiliar with vim, i urge you to first read up to the "differences" section in my [neovim notes](neovim.md). neovim is just vim but better, easier configuration, more robust editing, and yet you can keep it as lightweight as you want.

anyhow, that doesn't mean you shouldn't read these notes. you must absolutely read the vim motions section!! you do not need to read about using and configuring the vim program if you do not want to.

# vim motions

vim motions are the primary reason you should learn vim. they are key strokes and shortcuts that allow you to edit text quickly. you can enable them in other text editors like vscode using extensions.

## modes
vim has 4 modes:
1. normal mode
2. insert mode
3. command mode
4. visual mode

### normal mode
press `esc` to enter normal mode. while in normal mode you cannot type into the editor. in normal mode is when you will be using vim motions. for example, **h, j, k, l** will act as arrow keys (left, down, up, right respectively) in this mode. 

### insert mode
press `i` to enter insert mode. while in insert mode, you can type and change text in files.

### commands mode
to enter command mode, press `:` while being in normal mode. you will see a bar at the bottom where you can type. here you run commands. for example,
```
:e /path/to/file
# opens the file in the current buffer
```

## text editing
- i: enter insert mode
- a: enter insert mode to the right of cursor
- v: enter visual mode
- u: undo last change
- ctrl + r: redo
- y: yank text
    - before yanking, have cursor at either the beginning or end of the text you want to yank
    - press y to begin yank
    - press a movement key to yank text up till there
    - eg) yank a paragraph below cursor: y + }
    - doesn't have to be y + } at same time, can be y, }
- p: paste yanked text
- O: insert blank link above cursor
- o: insert blank link below cursor and enter insert mode
- dd: delete line
- d: delete text
    - same as yank 

## movement

### h, j, k, l (single character)
- h: left
- l: right
- j: down
- k: up

keep your index finger on j, middle finger on k, and ring finger on l.

### w, b, e (words)
- w: move forward to the start of the next word
- b: move to the start of the current word
- e: move to the end of the word

### 0, $, ^ (line)
- 0: move to start of line
- $: move to end of line
- ^: move to first non-blank character of line
- A: move to end of line and enter insert mode

### gg, G (file)
- gg: move to start of file
- G: move to end of file

## advanced movement
### {, } (paragraph)
- {: move up one paragraph
- }: move down one paragraph

### ctrl + d, ctrl + u (screen jumps)
- ctrl + d: move down half screen
- ctrl + u: move up half screen

### % (matching parenthesis)
- jump to matching bracket or parenthesis

## running multiple editors
### creating and navigating panes
- ctrl+w+w: cycle through splits
- ctrl+w+h: go to next left split
- ctrl+w+l: go to next right split
- ctrl+w+j: go to next down split
- ctrl+w+k: go to next right split
- ctrl+w+x: swap split with next

## buffer navigation
- <leader> + /: current buffer fuzzy (word search in correct buffer)
- <leader> + <leader>: find existing buffers    
- 

# vim commands

## buffer navigation
- vsp: create a vertical split with same editor
- e /path/to/file: opens the file in the current buffer
- ls: shows all open buffers
    - you can see the buffer numbers in the leftmost column
- term: start a terminal in working directory (will be ~ by default) 

# vim set up
todo
