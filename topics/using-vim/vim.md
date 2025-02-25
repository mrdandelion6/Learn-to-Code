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

## vim pwd
it's important to note that vim will have it's **pwd** set to the location from where you invoke the vim command. for example suppose you call the following:
```bash
vim path/to/file.txt
```
then vim's working directory won't be `path/to/`, instead it will be the directory from which you invoked the command. this is important to understand because a lot vim's search functionality like fuzzy file finding is limited to the scope of the `pwd`. for example, if you're in `~` and you invoke the vim command from there, any fuzzy searching will search the entire system from `~`. 

a good tip i personally follow is to cd into the directory for the project i'm working on and run `nvim .` so my fuzzy searching scope is limited to the project folder only.

# vim motions

vim motions are the primary reason you should learn vim. they are key strokes and shortcuts that allow you to edit text quickly. you can enable them in other text editors like vscode using extensions.

the following keybinds mostly should work with plain vim, but some might need neovim with kickstart.nvim set up. the ones that are from nvim will be marked with (nvim). you can follow the setup guide in (neovim.md)[neovim.md].

keep your index finger on j, middle finger on k, and ring finger on l.

## modes
vim has 4 modes:
1. normal mode
2. insert mode
3. command mode
4. visual mode

### normal mode
press `esc` to enter normal mode. while in normal mode you cannot type into the editor. in normal mode is when you will be using vim motions. for example, **h, j, k, l** will act as arrow keys (left, down, up, right respectively) in this mode. 

### insert mode
press `i` to enter insert mode. while in insert mode, you can type and change text in files. there's also `r` for **replace mode** which is very similiar to insert mode. instead of your keystrokes adding text, they replace text.

### commands mode
to enter command mode, press `:` while being in normal mode. you will see a bar at the bottom where you can type. here you run commands. for example,
```
:e /path/to/file
# opens the file in the current buffer
```
we will now go over some default keybinds. to begin with, you can fuzzily search all keybinds with `<leader> + s + k`. you need neovim set up with kickstart.nvim for this bind. if you are using vanilla vim, you can use the `:map` command in command mode.

# default keybinds and motions

## movement
### h, j, k, l (single character)
- h: left
- l: right
- j: down
- k: up

### w, b, e (words)
- w: move forward to the start of the next word
- b: move backward to the start of the current word
- e: move forward to the end of the word

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

## basic text editing
- i: enter insert mode
- a: enter insert mode to the right of cursor
- v: enter visual mode
- r: enter replace mode
- ctrl+v: enter visual block mode (select columns)
- u: undo last change
- ctrl + r: redo
- x: delete character
- s: delete character and enter insert mode
- gd: go to definition (implementation)
- gD: go to declaration (prototype)
- p: paste yanked text below cursor
- P: paste yank text at cursor
- O: insert blank link at cursor and enter insert mode
- o: insert blank link below cursor, move cursor down, and enter insert mode

## operators
operators like `d`, `y`, `c`, `gc`, and so on follow vims composable command structure. we will go over composable commands in more depth later on, but for now understand of these keybinds as needing more subsequent strokes to choose the body of text. for example, `dd` deletes the entire line.

- d: delete text and yanks
    - diw: delete word under cursor and yank
    - dip: delete inner paragraph. note that di} doesn't work for this
    - dd: delete line and yanks
    - D: delete from cursor to end of line
    - "_d: delete line without yank
- c: delete and enter insert mode
    - ciw: delete word under cursor and enter insert mode
    - cip: change inner paragraph
    - cc: delete line and enter insert mode at proper indent level
    - C: delete from cursor to end of line and enter insert mode

for the following operators, we will omit repetitive things like the `ip` suffix etc.

- y: yank text
    - Y: yank from cursor to end of line
- gc: (needs Comment.nvim plug) comment text
    - gcc: comment line
- >: indent line right
    - >>: indent line out
- <: indent line left
    - <<: indent line in
- =: auto indent
    - ==: auto indent line

## insert mode
here are some keymaps while in vim's insert or replace mode. note that there aren't many.

- ctrl + n: next autocomplete suggestion
- ctrl + p: previous autocomplete suggestion
- ctrl + y: accept current autocomplete suggestion

## running multiple editors
### creating and navigating panes
- ctrl+w+w: cycle through splits
- ctrl+w+h: go to next left split
- ctrl+w+l: go to next right split
- ctrl+w+j: go to next down split
- ctrl+w+k: go to next right split
- ctrl+w+x: swap split with next

## buffer navigation
- <leader> + /: (nvim) current buffer fuzzy (word search in correct buffer)
- <leader> + <leader>: (nvim) find existing buffers
- <leader> + s + f: (nvim) fuzzy search file within scope of `pwd`
- <leader> + s + n: (nvim) fuzzy search neovim configuration files
- ctrl + o: jump to previous cursor positions
- ctrl + i: jump to newer cursor positions

## composable commands
vim's composable commands have the following pattern:
```
[operator][number][motion]
```
an example is `d3w` which deletes 3 words (forwards).

actually the order doesn't matter, as long as the motion isn't first. so `3dw` and `3wd` would also work but `w3d` wouldn't.

**operators**
what you want to do. eg)
- d: delete
- y: yank
- c: change

**number**
how many times to do it (optional). any number like 2, 3, 4, etc. can also use `i` instead of a number which will grab the "inner" of the item. for example, 

**motions**
where to do it, the "body" of text to work with. eg)
- w: words
- j: lines down
- }: paragraphs down

## registers
registers are a core part of vim's automation and text processing capabilities. they're used as clipboards for the most part but also offer extensive usage like macros, expression evaluations, and operations on files.

to view whats in the registers, enter the command `:reg`. to see what's in a specific register, etner `:reg [reg-name]`, eg) `:reg a`.

### pasting and copying
in normal mode, simply enter `[register][p or y]`. for example, to paste from `"0` register, we would enter `"0p`. and to yank into `"0`, we would do `"0y`.

### unnamed register ""
the unnamed registerd `""` is the default register when no register is specified
- y, d, p, without a register specified use this
- like a default clipboard

### numbered registers "0 to "9
these registers act like a cache of recent recent deletions. they are prefixed with ". 
- `"0` holds most recent yank
- "1" to "9" hold last 9 deletions
- each new deletion shifts content down

### small delete register "-
- `"-` holds deletions less than one line
- gets automatically used for deletes or changes that are smaller than one line
- for example, `dw`, `cw`, and `x` fill the `"-` register
- register `"0` still also gets filled

### named registers "a to "z
- for explicitly saving text or macros
- lowercase overwrites the register, eg) `"ay` yanks and overrides to `a`
- uppercase appends to register, eg `"Ay` yanks and appends to `a`

### special registers
- `"+`: system clipboard
- `"*`: system selection (for unix/linux)
- `"_`: black hole register (deletes without saving)
- `".`: last inserted text. type `[number].` to insert last inserted text number amount of times. eg) `3.`.
- `"%`: current file name
- `":`: last executed command
- `"/`: last search pattern

# vim commands
in this section we will cover commands we can run in vim using `:`.

## general
- lua <some lua code>: execute some lua code to change neovim configurations. useful for testing stuff out without having to reload neovim. eg) lua print("hello world!")

## buffer navigation
- e <path/to/file>: opens the file in the current buffer
- vsp: create a vertical split with same editor
- ls: shows all open buffers
    - you can see the buffer numbers in the leftmost column
- term: start a terminal in working directory (will be ~ by default) 
- bp: go to previous buffer
- bn: go to next buffer

# vim set up
todo
