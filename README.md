# Learn C and Shell Script!

Welcome to my C and Shell Script learning repository! This repository is a collection of my notes and code snippets as I embark on the journey of learning C and shell scripting. 🚀

I will be using Ubuntu through WSL.  

## Contents
- `c`: This directory contains everything pertaining to C.
    - `notes.c`: Dive into my detailed notes on various C concepts.


- `shell-script`: This directory contains everything pertaining to Shell Script.
    - `notes.sh`: Dive into my detailed notes on various shell scripting concepts.

- `other`: All other files whether in `c` or `shell-script` will not contain any notes. These files are related to chapters in the notes and help with demonstration. For example, `Makefile` is related to the chapter on Makefiles in `notes.c`.

## Usage
### notes.c
`notes.c` not only contains detailed notes but actual C code examples implemented within the notes. Each different topic is sectioned off into its own function. Similiar to a table of contents, you can view the list of topics in `main()` and ctrl-click them to jump to a topic. 

If you would like to run code inside a particular topic, simply make that topic be the only function called in `main()`, then compile `notes.c`. You will need a C compiler, for example I use `gcc`. So in shell I will `cd` to the directory containing `notes.c` and run the following command:

```
gcc -o notes notes.c
./notes
```

### notes.sh
`notes.sh` is not intended to be ran as a script. Rather, users may read through `notes.sh` and test commands in a bash terminal or create their own script in `myscript.sh`. To execute `myscript.sh` from shell, cd to the directory containing my script.sh and run the following command:
```
chmod a+x myscript.sh
./myscript.sh
```

## Feedback
Feel free to clone the repository and experiment with the code. If you have any suggestions or find areas for improvement, don't hesitate to open an issue or pull request.

Happy coding.
