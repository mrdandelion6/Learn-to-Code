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
