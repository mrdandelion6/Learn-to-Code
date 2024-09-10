# Learn to Code

Welcome to my code learning repository. This repository is a collection of my notes and code snippets as I embark on the journey of learning many different programming languages. 🚀


## Notes I've Made
My notes are split into 2 categories: languages and topics.

### Languages
Here are some languages I have made a good amount of notes on so far. Some may not be complete yet, but have ample notes to get you started.

- `C` : systems programming, pipes, processes, and sockets. an introduction to low level programming.
- `Bash` 
- `JavaScript` : DOM
- `Python & Jupyter` : advanced notes on python and some jupyter notebooks
- `R`
- `Data Structures`
- `HTTP`

The other folders may also contain some decent notes, but are not going to be as in depth as the above list. I am making them as I go along.

## Usage

Here's how to use my notes interactively for different sections.

### Learn C
Located in the `c` directory. These notes are made for someone who has never seen C before but they also delve into more advanced systems programming topics such as pipes, processes, and sockets. Most of the material in these notes is pertaining to the course **CSC209 at UofT**, but anyone who wants to learn C and low level systems programming will find this useful.

`notes.c` contains all the notes I have made along with C code examples. Each different topic is sectioned off into its own function. Similiar to a table of contents, you can view the list of topics in `main()` and ctrl-click them to jump to a topic. These notes are made to be compiled and read on Linux as I made them through Ubuntu on WSL. You can do otherwise but you may get intellisense and compilation errors. Windows users should compile using Ubuntu.

If you would like to run code inside a particular topic, simply make that topic be the only function called in `main()`, then compile `notes.c`. You will need a C compiler, for example I use `gcc`. So in shell I will `cd` to the directory containing `notes.c` and run the following command:

```
gcc -o notes notes.c
./notes
```

---
### Learn Shell Script
Located in the `shell-script` directory. Made for someone who has never seen Shell Script before. This material is very brief and most of it is pertaining to the course **CSC209 at UofT**, but anyone who wants to learn a little Shell Script may find this useful.

`notes.sh` only contains notes and is not intended to be ran as a script. Rather, users may read through `notes.sh` and test commands in a bash terminal or create their own script in `myscript.sh`. To execute `myscript.sh` from shell, cd to the directory containing my script.sh and run the following command:
```
chmod a+x myscript.sh
./myscript.sh
```

---
### Learn JavaScript
Located in the `javascript` directory. Made for someone who has never seen JavaScript before but has some familiarity with HTML and CSS.

`notes.js` contains detailed notes on JavaScript with side by side code examples. `compare.java` compares Java's syntax against JavaScript's for those of you who are familiar with Java. See [javascript/README](javascript/README.md) for more info.

---
### Learn Python & Jupyter Notebooks
Located in the `python` directory. Made for someone who is already familiar with Python and interested in learning how to code ML and perform data analysis. 

`data_analysis.ipynb` contains detailed notes on using Jupyter and various libraries such as NumPy, Pandas, and Matplotlib. There aren't any notes for learning Python from the ground up in this section unlike the others. 

You can find comprehensive notes for coding ML in `python/ML`. Some topics include:
- Supervised learning (see `Supervised_Learning.ipynb`)
- Unsupervised learning (see `Unsupervised_Learning.ipynb`)
- NLPs (see `NLP.ipynb`).
There are also many slides for understanding how ML works in `python/ML/slides`. Credit to [Nakul Upadhya](https://github.com/upadhyan).

#### Setup:
You will need to have Jupyter and a Python interpreter of version **3.12.1** or later installed along with all the required libraries. To install the required libraries you should create a virtual environment in the `python` directory, activate it, then install everything in `requirements.txt`. You can do so as follows (on Windows):
```
python -m venv env
env\Scripts\activate
pip install -r requirements.txt
```
For a more advanced setup using `virtualenv`, to install and manage multiple different Python interpreters using `pyenv`, [check out my article](https://medium.com/towardsdev/managing-virtual-environments-with-different-python-interpreters-b997b7bb7254) on Medium.

Make sure your IDE is using the Python interpreter from the virtual environment you created, you may need to specify the path to the Python executable: `path-to-repo\repo-root\python\env\Scripts\python.exe`. You will also need to configure the notebook to use this same interpreter as its kernel.

---
### Learn R
Learn data analysis and a little ML using R. Made for someone who has never seen R before. Located in the `r` directory.

`notes.Rmd` will contain detailed notes on using R. See [r/README](r/README.md) for setting up R in VS Code or also [read my article](https://towardsdev.com/setting-up-r-for-vs-code-c03a6fda311d) on Medium

---

#### Happy coding.
