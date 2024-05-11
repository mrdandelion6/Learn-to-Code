# Learn R

Welcome to my notes on learning R. These notes focus on data analysis with R and assume you have never seen this language before.

All of my notes will be contained in `notes.Rmd`. The rest of this README will just be a setup guide for using R in VS Code. You can just use R Studio if you don't wanna do all this.

## Setup R for VS Code Windows

Here is a very comprehensive guide to setting up R for VS Code on Windows to the point you will not lose out on much for ditching R Studio. Took me a few hours to figure this all out.

### Overview of Steps
1. Have VS Code installed
2. Install R and language server
3. Install Python then Radian.
4. Install *Markdown All in One* and the *R* extension on VS code
5. Configure R.exe path, keyboard shortcuts, and .Rmd file identification for VS Code.

Figuring out the last step was very annoying but if you follow these notes you will not have to go through the same pain as I did.

## Step by Step Guide


### Install R

Download R for windows from https://cran.r-project.org/bin/windows/base/ and note down where you install it. For me, I installed it in the default location: `C:\Program Files\R\R-4.4.0`. Note my version is 4.4.0, for you it might be newer. 

---

### Add R's bin to System PATH
You will need to add the bin folder of your R installation: `path\to\R\R-4.4.0\bin` to your system's PATH. If you don't know how to, read this. 

Begin by pressing Windows start button and searching *"edit the system environment variables"*. Click the control panel option that shows up then do the following:
- A popup called *System Properties* should open. Go to the *Advanced* tab if you're not already in it.
- Click *Environment Variables*.
- In *System Variables* click *Path* then the *Edit...* button.
- Click the *New* button then enter `path\to\R\R-4.4.0\bin` and press enter.
- Click OK, OK, Apply, OK. 
- Good job you're done.

Check if R has been added to the system's path by typing `R --version` in cmd outside of the R installation folder. If R is successfully installed and in your system's PATH, you should get a message showing the version of R you have.

At this point you can type R in a terminal to run R. Note that in PowerShell you will need to run type `R.exe` because R already stands for a different existing command.

---

### Install languageserver

In `path\to\R\R-4.4.0\bin\x64`, run `Rgui.exe`. Type the following in the R console:
```r
install.packages("languageserversetup")
```
You may be prompted to select a CRAN mirror. Select `0-Cloud`. Now type this in the R console:
```r
languageserversetup::languageserver_install()
```
You will get a prompt saying *"This will attempt to use source(https...)..."* etc. Select yes. Another pop up will appear saying *"Do you want to install from sources the package..."*, doesn't matter if you select yes or no.

Now lastly, type in the following into R console:
```r
languageserversetup::languageserver_add_to_rprofile()
install.packages("rlang")
install.packages("jsonlite")
```
If you are asked to create a personal library, select yes.

---

### Edit .Rprofile
You may or may not need to do this step depending on whether starting R is giving you any errors. In cmd, run R and see what happens. You will need to edit your .Rprofile you get any errors like the following:
```r
Error: '\U' used without hex digits in character string (<input>:4:36)
```
This means the profile is using backslashes instead of forward slashes. You will need to locate where the `.Rprofile` file is stored and change the slashes. It is commonly in the `C:Users\User\Documents` directory, where `C:Users\User` is your USER PROFILE. To verify you user profile, in cmd you can type `cd %USERPROFILE%`.

If you cannot find a file called `.Rprofile` in Documents, launch `Rgui.exe` again, click *File* at the top right then *Display file(s)*, it may be there.

If you still cannot find it yet you are getting the above error, then do a full file search in file explorer, it should be somewhere in your computer after running `languageserversetup::languageserver_add_to_rprofile()`.

Once you have found the `.Rprofile` file, change all the backslashes into forward slashes. For example, mine looks like this after I have fixed it:

```r
# LanguageServer Setup Start (do not change this chunk)
# to remove this, run languageserversetup::remove_from_rprofile
if (requireNamespace('languageserversetup', quietly = TRUE)) {
  options(langserver_library = 'C:/Users/Admin/Documents/languageserver-library')
  languageserversetup::languageserver_startup()
  unloadNamespace('languageserversetup')
}
# LanguageServer Setup End
```

Now launch R and you should no longer get any errors.

---

### Install Radian
You could skip this step but I highly recommend you install Radian to use as a shell for R instead of anything else. You will need Python installed. If you don't have Python installed then look up a tutorial online. Ensure your installation of Python is added to the system's PATH.

Once you have Python installed, open PowerShell or cmd as an administrator and run the following command:

```
pip3 install -U radian
```

Now you can run Radian,
```
radian
```
Note that Radian is useful for not only R, but also Python and Julia. You will set this to be the default terminal for R in VS Code later.

---

### Install R and Markdown All in One Extensions in VS Code
Before installing the two extensions you will need to get the path to your R executable. Open a terminal and run R, then type R.home("bin") like so:
```r
> R.home("bin")
[1] "C:/PROGRA~1/R/R-44~1.0/bin/x64"
```
For me, R returns `C:/PROGRA~1/R/R-44~1.0/bin/x64`, which is the path to my R executable. Note this down.

Install the *R* and *Markdown All in One* VS Code extensions. Now go in the extension settings for the R extension and search *Rpath: Windows*. Set this to the R path you noted down.

At this point you're all set to use VS Code for .r files. However, further configuration is needed for .Rmd files.

---

### Set .Rmd File Association to rmarkdown
VS Code might have the file association for .Rmd files set to just plain markdown. If this is the case, you wont be get the benefit of R intellisense, nor will you be able to run lines of your .Rmd file.

Open `settings.json` from the command palette (CTRL + SHIFT + P) and ensure the following is present:

```json
    "files.associations": {
        "*.rmd": "rmarkdown"
    },
```
Make sure that it's **rmarkdown**, not just markdown.

---

### Add Keyboard Shortcut for .Rmd Files
Note that you can run lines of code in .R files by having your cursor on them and pressing CTRL + ENTER. This may not work if you try to run code inside code chunks in .Rmd files. 

Open command palette and search *Keyboard Shortcuts (JSON)*. Add the following code to the JSON file:
```json
    {
        "key": "ctrl+enter",
        "command": "r.runSelection",
        "when": "editorTextFocus && !editorReadonly && (editorLangId == 'r' || editorLangId == 'rmd' || editorLangId == 'r markdown)"
    }
```
This adds R's run selection command for .Rmd files. Be careful because this will run anything your cursor is on, including text outside of code chunks. I'm not sure if there's a better way to do this. Definitely reach out to me if you know of one.

---

### Set Radian to be Terminal for R
The last thing we want to do is set Radian to be the default terminal VS Code runs R on when we press CTRL + ENTER. Open the extension settings for the R extension and search *Rterm: Windows*. Set this value to path to your Radian executable.

To find where your Radian executable is just type `where radian` in any terminal and paste this value into *Rterm: Windows*.

---

## End

Good job, you're done. Enjoy coding R with all the benefits of Visual Studio Code. Feel free to give me any feedback for my R notes and/or installation guide.