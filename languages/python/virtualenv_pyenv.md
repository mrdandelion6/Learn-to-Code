# Install Multiple Python Versions using Pyenv on Windows

This is a detailed guide demonstrating how to install and manage using different versions of Python interpreters for your virtual environments using `pyenv`.

`pyenv` is a python package which allows you to download different versions of Python directly from the command line. We can use this to manage multiple versions of Python and easily get different versions as we need.

The setup will only take a few minutes and once you're done, it will be a lot easier to leverage different installations of Python for your virtual environments.

## Install pip
Make sure you have pip installed and in your system's PATH. To check you can type `pip --version` in Powershell. Installing pip is a very easy! It automatically gets installed any time you download Python from the web. If you have never downloaded Python before you can choose a version to download from here https://www.python.org/downloads/

Once you have downloaded it, add it to your path. Save the location you downloaded it, for me it was in `C:\Python312\`. Then you can add it to your path by following the steps in the section below.

## How to Add Stuff to your System's PATH
Specficially, I will demonstrate how to add an installation of Python to your system's PATH. The procedure for adding anything to your PATH is always the same, just replace the file destination with the thing you want to add to your PATH.

- Press windows key and search *Edit the System Environment Variables* then go on the option in Control Panel.
- A window called *System Properties* will pop up. If you are not in it already, go in the *Advanced* tab.
- Click *Environment Variables*.
- In *System Variables* below, click *Path* and press the *Edit* button.
- Click the *New* button at the top right and paste in the path to your interpreter, for me it was `C:\Python312\`
- Additionally, click *New* again and paste in the path the to Scripts folder inside the path to your interpreter, for me it was `C:\Python312\Scripts`.
- Click OK, OK, Apply, OK

And that's how you can add anything to your system's PATH. You will need to add some more things to your system's PATH later so don't forget.


## Installing pyenv
We want to install `pyenv` globally, not just in some virtual environment! And we want to install it specifically in your home directory. To find your home directory, you can enter `$HOME` in Powershell. Simply enter the following line in Powershell to quickly install `pyenv` in your home directory:

```
pip install pyenv-win --target $HOME\.pyenv
```

## Confgiuring Pyenv in System Variables
Now we will want to add `pyenv` to your system's PATH as before. First note down where you installed `pyenv`. This should be in `$HOME\.pyenv`, where `$HOME` is your home directory. You will want to specfically add two files to your system's PATH:
- $HOME\.pyenv\pyenv-win\bin
- $HOME\.pyenv\pyenv-win\shims

Make sure to replace `$HOME` with your home directory. To make sure that `pyenv` was properly added to your system's PATH, type `pyenv --version` in a random terminal and it should display the version.

Notice that you might have gotten some warnings when you called `pyenv --version`, telling you that the following variables are not configured:
- PYENV
- PYENV_HOME
- PYENV_ROOT

If you didn't get any warnings you can skip the rest of this step, but if you got the warning for any of the above variables, you must do the following:
- Open up the Environmental Variables again.
- Instead of clicking *Path* and *Edit*, click *New* directly in *System Variables*.
- In *Variable Name*, put the variable that's giving you the warning (PYENV, PYENV_HOME, or PYENV_ROOT).
- In *Variable Value* enter the path to your `pyenv` folder. This should be `$HOME\.pyenv\pyenv-win`.
- Click OK, OK, Apply, OK
  
Repeat the above steps for all variables which give you the warning. Every time you will add the same path to *Variable Value*.

Now type `pyenv --version` again and you should not get any warnings. Congradulations, you're all done with the setup. We will now demonstrate installing a specific Python interpreter using `pyenv` and adding it for your virtual environment.

## Installing a Python Interpreter 
This is going to be why `pyenv` is so nice. All you need to download the version of Python you want is the following:

```
pyenv install X.X.X
```

Repleace X.X.X with your desired version. For example, 3.9.0 is a common version you might want to have. That's it lol.

## Basics of Virtual Environments
Before we show how to set up a virtual environment with a specific Python interpter, let's just go over the very basics. If you are using VS Code, also make sure you install the *Python* VS Code extension by Microsoft.

Using `pip`, install the `virtualenv` package globally. Ensure that you are not in any active virtual environment. You can do this by opening up a random instance of command prompt or Powershell and entering the following:
```
pip install virtualenv
```
Ensure you have installed virtualenv globally by entering `virtualenv --version` in some random terminal. It should display the version.

Now cd to your Python project folder (the place you want to set up your virtual environment). Altneratively, if you are working in VS Code, open your project folder in VS Code and start an integrated terminal session *(ctrl + `)*. Run the following in Powershell:
```
virtualenv env
env\Scripts\activate.bat
env\Scripts\activate
```
This will create a virtual environment folder with the name `env` (you can name it whatever but using env is a common practice). The latter two lines activate your virtual environment. Note that by default, your virtual environment will use your default global Python interpeter. A later section below will show how to specify the interpreter. 

Now you must configure VS Code to use your virtual environment's interpreter:
- Open command palette by pressing *ctrl + shift + p*
- Search *Python: Select Interpreter* 
- Click *Enter interpreter path...*
- Clik *Find...*
- Navigate to your `env` folder and select `path\to\env\Scripts\python.exe`
- Congrats you're done!
  
Now close the integrated terminal and reopen it. You should get a popup saying: 

*Python virtual environment was successfully activated, even though "(env)" indicator may not be present in the terminal prompt.*

You can now use `pip install` to install any Python packages locally within your virtualenv, and they will not add to your system globally. Just start an integrated terminal session in VS Code with your project opened, and run the commands from there. You can also use `pip list` to view your installed packages. 

## Creating a Virtual Environment
Now finally, we will see how we can set up a virtualenv with a specific Python interpreted we downloaded from `pyenv`.

Use the following command in Powershell:
```
virtualenv -p path\to\pyenv-win\versions\X.X.X\python.exe env
```
Make sure to replace path\to\pyenv-win with your path to pyenv-win, and X.X.X with your version of Python. That's it! Don't figure to activate your virtualenv and configure VS Code as shown in the section above.

## Exporting and Importing Virtual Environments
The `env` folder you create isn't portable itself. What that means is, if you copy paste your entire project folder from one computer to another, it will almost always not work! To get around this, users create a `requirements.txt` file to install and keep track of dependencies. You should not copy the `env` folder over with the rest of the project when you are moving things between different systems! Additionally, if you are using anything like a version control system, you should add `env` to your `.gitignore` file. 

You must cd into your Python project folder and enter the following command in Powershell:
```
pip freeze > requirements.txt
```
This creates a file called `requirements.txt` and adds in all the Package dependencies of your project. Note that this **does not specify the Python version of the project!** You must keep track of that separately.

To install all package dependencies from a `requirements.txt` folder, you can simply run the following command while being in an activate virtual environment:
```
pip install -r requirements.txt
```


