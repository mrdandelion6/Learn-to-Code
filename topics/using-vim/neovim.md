# neovim notes

hello welcome to my neovim notes. these notes will be a full guide on using the **neovim** program for text editing. we will first begin with some simple motivation for vim.

## why use vim

firstly, let's distinguish between the 2 kinds of vim:
1. **the vim program** : a text editor program used directly inside the terminal. you use the `vim` or `vi` command to start it.
2. **vim motions** : key strokes and shortcuts configured to edit text quickly. can enable in other text editors like vscode using extensions.

while you may or may not want to use the vim program, **everyone** should use vim motions. it simply speeds up your text editing skills.

## neovim vs vim

now that we have some motivation to use vim, at least vim motions, let us compare its differences between neovim. 

### what is neovim ?

neovim is a fork and extension of the vim text editor that aims to modernize vim while maintaining compatibility with most vim features. by neovim, or nvim for short, we always mean the neovim program. there is no "neovim motions", that is just vim motions.

### differences

#### 1. codebase: 
neovim was created by refactoring vim's codebase, making it more maintainable and easier to contribute to. vim is written in c, while neovim is written in c and includes **lua** integration. this means you can write your entire **configuration** in lua instead of **vimscript**. more on these later.

#### 2. built in features
- neovim includes a built-in terminal emulator
    - i.e, you can run a terminal inside a terminal
    - you can split your nvim (neovim) editor and have code on one side and a terminal on the other side without leaving neovim 
- nvim has built-in LSP (language server protocol) for IDE-like features
    - gd: go to definition, can jump to a function/variables definition
    - gr: find references 
    - gi: go to implementation
    - error highlighting as you type
    - inline error messages
    - code completion
    - documentation over hover
    - find all references to a symbol
    - rename symbols across files
    - all you need to do is install the LSP for your language whereas for vim, you need to install lots of extension and plugins
- nvim has native lua support for configuration and plugins
- nvim supports asynchronous i/o by default
    - syntax highlighting and other nice features don't block text editing 
    - modern vim mostly supports this but not as much as nvim (i think ?)

#### 3. default settings
- nvim comes with modern defaults like colour support
- nvim has better key mappings out of the box
- mouse enabled by default

# setting up neovim

## basic installation
we will be setting up neovim from scratch on ubuntu. first update ubuntu then install neovim:
```bash
sudo apt update
sudo apt upgrade

# once done updating
sudo apt install neovim 
```
verify installation:
```bash
nvim --version
```

you can run neovim by doing `nvim` in terminal like this:
```bash
touch test.txt
nvim test.txt
```
we'll go over how you can use the text editor later on but for now press `esc` to enter **normal mode** then press `:` and type `q!` to exit without saving any changes or `wq` to save your changes and exit.

## configuration

we need to "configure" neovim further to use it properly. we need configuration for:
- LSP
    - gd
    - error detection
    - auto completion
    - find references
    - intelligent code refactoring
- modern features
    - tree-sitter
    - fuzzy finding
    - project-wide search
    - file tree
- quality of life improvements
    - custom keybinds
    - line numbers, indent guides
    - multiple cursor support

we will be **installing kickstart.nvim** to learn vim and help with configuration. before that, we need some prerequisites to setup.

### prerequisites
to begin, we will install kickstart. visit https://github.com/nvim-lua/kickstart.nvim and read the README. you will need the following prerequisites as listed on the README:
1. basic utils: git, make, unzip, C Compiler (gcc)
2. clipboard tool (xclip/xsel/win32yank or other depending on platform)
3. a [nerd font](https://www.nerdfonts.com/font-downloads)
4. language setup: npm for typescript, go for golang, etc.

assuming you already have the basic utils set up on your linux machine (whether it's wsl2 ubuntu or actual os), here is how to set up the rest of the prerequisites.

#### 2. clipboard tool
```bash
sudo apt install xclip
```



#### 3. nerd font

choose a nerd font from https://www.nerdfonts.com/font-downloads and right click the download button to get the url. i will be using *3270 Nerd Font*.

<details>
<summary>in ubuntu wsl2</summary>

```bash
# in wsl2 ubuntu or any other windows terminal
cd /mnt/c/Users/YourWindowsUser/Downloads
wget https://github.com/ryanoasis/nerd-fonts/releases/download/v3.3.0/3270.zip
unzip 3270.zip
```
it's important that for wsl2 setup that you download the font in windows. open the `C:/Users/YourWindowsUser/Downloads/3270/` folder in windows fire explorer and right click `3270NerdFontMono-Regular.ttf` (or anything else you prefer) and select `Install`. you can even install all of the fonts if you want to be able to pick and choose later.

to apply the font do the following:
- now close all instances of ubuntu and open it again
- right click the top bar in your ubuntu terminal
- select "properties"
- in "Font", scroll up to 3270 Nerd Font Mono and select it
- adjust your font size as needed
</details>

<details>
<summary>in other linux</summary>

```bash
mkdir ~/.local/share/fonts/
cd ~/.local/share/fonts/
wget https://github.com/ryanoasis/nerd-fonts/releases/download/v3.3.0/3270.zip
unzip 3270.zip
rm 3270.zip
fc-cache -fv
```
then edit your terminal to use the downloaded font. this process varies on your terminal and linux distro.
</details>


#### 4. language setup

<details>
<summary>for golang:</summary>

only get this if you want to write go.

```bash
# in ubuntu 
wget https://go.dev/dl/go1.22.1.linux-amd64.tar.gz
sudo rm -rf /usr/local/go
sudo tar -C /usr/local -xzf go1.22.1.linux-amd64.tar.gz
```

now add the following lines in `~/.bashrc` to have `go` in your path:
```bash
export PATH=$PATH:/usr/local/go/bin
export PATH=$PATH:$(go env GOPATH)/bin
```
</details>

<details>
<summary>for npm:</summary>

only do this if you want to write typescript.

```bash
sudo apt update
curl -fsSL https://deb.nodesource.com/setup_lts.x | sudo -E bash -
sudo apt install nodejs
```

verify
```bash
node --version
npm --version
```
</details>

### install kickstart.nvim

continuing the README for https://github.com/nvim-lua/kickstart.nvim, you will now fork the repository. and do the following:

``` bash
# if neovim config not yet made
mkdir -p ~/.config/nvim 

# if already existing, we wipe it (backup if u need it)
rm ~/.config/nvim

# clone fresh copy
git clone https://github.com/nvim-lua/kickstart.nvim.git ~/.config/nvim

# now run the command
nvim
```
the last command will be our first launch of nvim with kickstart which should trigger plugin installation via lazy vim. now just press `q` to close the  window.

## init.lua
`init.lua` is the main configuration file for neovim when using lua instead of the traditional `vimrc` for vim. it's where you define your core settings, keymaps, and plugin configurations.

for **kickstart.nvim** specifically, their `init.lua` serves as both a working configuration and a well-documented example of how to configure neovim. 

for the rest of these notes, we will be going through `init.lua`. to start with, first make a copy the original `init.lua` then open the original with neovim:
```bash
cp ~/.config/nvim/init.lua ~/.config/nvim/init.lua.backup
nvim ~/.config/nvim/init.lua 
```

# vim motions

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
- $: move to start of line
- 0: move to end of line
- move to first non-blank character of line

### gg, G (file)
- gg: move to start of file
- G: move to end of file

### {, } (paragraph)
- {: move up one paragraph
- }: move down one paragraph

### ctrl + d, ctrl + u (screen jumps)
- ctrl + d: move down half screen
- ctrl + u: move up half screen

### % (matching parenthesis)
- jump to matching bracket or parenthesis