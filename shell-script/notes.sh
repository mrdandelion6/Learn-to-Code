# Shell Scripting Notes


# === RUNNING SHELL SCRIPTS ===
# we can make shell script files which automatically run when executed!

# step 1: create the shell script .sh file, let's call it myscript.sh
# step 2: in a terminal, navigate to the directory where the script is
# step 3: run the command: chmod +x myscript.sh 
# this makes the script executable by giving it permission
    # lets break down chmod +x myscript.sh,
    # "chmod": changemode, for modifying the file's permissions
    # "+x": adds execute permission to file, allows myscript.sh to be run as a program or script
    # other permissions: +r (read permission), +w (write permission)
# step 4: now execute myscript.sh in terminal as you would any executable by entering: ./myscript.sh
# done!!

# we prefix exetucables by ./myscript.sh to tell shell to find the myscript.sh in the current directory
# for executables added to the system's PATH environment, we do not need ./ as those executables/programs are "global"
# an example is how we type in gcc without ./
# =============================


# SSH
# to ssh into a remote location use the following command:
# ssh <username>@<remote_host>
# for example, <utorid>@dhXXXXpcXX.utm.utoronto.ca
# type exit to exit the ssh


# === ASIDE ===
# other useful command line / terminal / bash / powershell things that may be specific to windows.
# skip this part unless u wanna know some useful tricks for windows

# FIND ANY PROCESSES RUNNING FROM SPECIFIC DIRECTORY (windows):
# run powershell as admin, and enter: Get-Process | Where-Object { $_.Path -like "C:\path\to\dir*" }
# replace C with the proper drive, D, E, F, etc.
# power shell will print all processes running from the specificed directory, eg;
# Handles  NPM(K)    PM(K)      WS(K)     CPU(s)     Id  SI ProcessName
# -------  ------    -----      -----     ------     --  -- -----------
#     151       8     1680       5232       0.05  21128   0 XSpltVidSvc

# JUNCTION LINKS (windows):
# open cmd as admin and navigate to the directory where you want to create the links
# enter: mklink /J "link-name" "path\to\actual\stuff"
# this will create a symbolic junction link "link-name" in the present working directory which points to "path\to\actual\stuff".
# note that you can only point to directories, not other files.
# junction links are very useful for keeping synced folders, allowing access to the same content in two different places
# whereas shortcuts are merely a link that jumps you to the source.
# =============


# ===== COMMANDS =====
# cd <path>: change directory to path, can use .. in place of <path> to jump into current directory's parent directory
# ls: list present files in current directory
# ls -lah: list directories with l) long format, providing detailed information. a) all entries, shows hidden files as well. h) human-readable bit sizes such as KB, MB, GB not just the raw bytes 
# gcc -o <name> <cfile>.c:  compile an executable file named <name> for <cfile>.c which can be ran using ./<name>
    gcc -o main main.c
    ./main
# > <file> output redirection, redirects to write and override into <file>
    ls > mytext.txt # writes the output of ls to mytext.txt instead of console
    ls >> mytext.txt # same as above but doesnt override the existing content of mytext.txt, instead it appends it
# | pipe: command line operator that takes output (stdout) for the command on its right
# grep: command line utility for searching text using regular expressions
    ls | grep "txt" # filters directories to only display those whose name has .txt in it
# <var>=`<stuff>`: back ticks known as command substitution, capture the output of <stuff> and assign it to <var>.
# wc: word count
    wc mytext.txt
# < <file>: input rediction 
    wc < mytext.txt: # goes from essay.txt --> wc, ie) wc <-- essay.txt, ie) wc < essay.text.
    # this form uses input redirection (<) to send the contents of the file (essay.txt) to the wc command through standard input. 
    # so wc reads from its standard input as if the contents of the file were typed directly into the terminal. 
    # it doesn't directly know that it's reading from a file; it just sees the input stream.
# <command> <<< <string>: here-string
    # used to direct a string into a command. example:
    cat <<< "hello"
# <() process substituion
    wc <(ls) # process sub. creates a temp file to transfer the output from one or more processes to the stdin of another process
    # here we take the output of ls and pass it into the stdin of wc, as if we are entering the output of ls into wc
    # spaces are important
# mkdir <filename>
    mkdir filename # make a new directory named <filename>
# mv <location>/<file> <destination>/<new_name>
    # move <file> from <location> to <destination>. omit <new_name> to move with same name.
    # we can use this to rename files by moving the file to the same location with a new name
    # mv <location>/<file> <location>/<new_name>
# cp <location>/<file> <destination>/<new_name>
    # copy <file> from <location> to <destination> and give it the name <new_name>. omit <new_name> to copy same name.
# scp <local_location>/<file-or-dir> username@hostname:<host_location>
    # copy <file-or-dir> from <local_location> to a remote <host_location>.
    # important remark; if any sort of message is printed when logging into the remote (through .bash_profile or .bashrc), then this will not work. i wasted hours over lol
# scp username@hostname:<host_location>/<file-or-dir> <local_location>
    # copy from remote to local
    # for copying directories and their contents use -r after scp
# touch [options] <filename>
    # used to update the access and modification timestamps of a file. 
    # or can omit [options] to create a new file <filename> only if it doesnt exist
# cat <file>
    # concatenate and print contents of files
# tr [options] <set1> <set2>
    # replace the characters of <set1> by the characters of <set2>
# tail -n <N> <file>
    # display the last <N> lines of a file
# IFS=<char> 
    # internal field separator. not a command but a value that other commands use.
    # the value of IFS is what shell uses for word splitting. set it to something else to manipulate how shell will separate words.
# read [options] <var>
    # reads some input and assigns it to var
    # some [options] are:
        # -r, treats backslashes as literal characters instead of special characters
        # -a, outputs the input into an array
# ====================


# DECLARING VARIABLES
x="Hello World!"
# no space around =

# SCOPE OF VARIABLES
# having a variable declaration by itself on a line has a global scope
IFS='A';
# having a variable on the same line of some command has a limited scope only for the stuff on that line
IFS='B' read -ra grArray <<< "yoskiesBahhh" 

# ARITHMETIC
x=1
y=1
z=$((x + y)) # must encapsulate math with $(( ))
echo $z # prints 2

# CREATING ALIASES AND PERSISTENT SHELL CONFIGURATION
# to set an alias for ls, do the following
alias ls='ls -lah'
# this sets ls to same behaviour as ls -lah
# reopening terminal discards this alias. want to make it persistent

# to make this persistent, we want to have a .bash_profile in our home directory
# we can create one by doing vim .bash_profile. make sure ur in home directory first
# so cd to ~ if you arent there already
cd ~
vim .bash_profile
# this will create a file called .bash_profile 
# enter the following in the .bash_profile through vim
if [ -f ~/.bashrc ]; then
	source ~/.bashrc
fi
# this code means if there exists a file called .bashrc in ~ (home directory), then source it
# sourcing it means we run any code that exists there.

# then press esc to be in normal mode in vim, and type :wq to write your changes and quit. this should create a .bash_profile file in your pwd (which should be ~)
# my pwd is in this git repo so it would have created a bash_profile for me right here, but you could have made this wherever you wanted. for example your home ~

# note, this means we now have to go to the .bashrc file in our home
# to see .bashrc, we need to do ls -lah because it is hidden and wont show with ls
# now once again, do vim .bashrc to open and edit .bashrc
# at the bottom add whatever code you want to run as soon as you open terminal
# for example, i put this to just test it first:
echo "testing"
# now recall we originally wanted to make our alias persistent so just type the following into the .bashrc
alias ls='ls -lah' 
# now ls always behave as ls -lah


# === CUSTOMIZING SHELL ===
# STARTUP MESSAGE
# we can change the message of the day and have our own custom code run whenever we start shell
# for ubuntu do
cd /etc/update-motd.d
# now do ls -lah to view everything
# now we want to disable all that stuff we see, so we can simply just remove the execution permissions
chmod -x /etc/update-motd.d/*

# now we will install a few things:
# apt-get install lolcat figlet
# apt-get install update-motd
# there's also these three, but i never used them
# apt-get install inxi screenfetch ansiweather 

# type showfigfonts to show all the fonts from figlet. we can get more
# now to get even more fonts we can clone a git repo
git clone https://github.com/xero/figlet-fonts

# now we want to move all of these files over to the figlet folder for fonts
mv figlet-fonts/* /usr/share/figlet/ # note: mv <source> <destination>
# <destination> might be different for you
# type showfigfonts to see the new fonts
# we can now use figlet fonts by doing:
# figlet -f <font-name> "Whatever Text". example below
figlet -f red_phoenix "Hello"

# add color to it by piping output to lolcat, remember piping is like this:
# <output> | <input>
# takes the output of left side and passes it as input to right side, which does something with that input (example, generate a new output)
figlet -f red_phoenix "Welcome" | lolcat
# we can add custom rainbow spectrum. for example i like how -S 13 rainbow looks
figlet -f red_phoenix "Whats up" | lolcat -S 13
# now simply add this code to the bottom of your .bashrc, or whatever else code you want.
# it will now make output this everytime u open a new terminal/ubuntu shell

# SHELL COLORS
# go into .bashrc again (from ~)
cd ~
vim .bashrc
# uncomment force_color_promt=yes
# in the following if statement:
if [ "$color_prompt" = yes ]; then
                                                 # user and host     # colon      # directory      # the $             
    PS1='${debian_chroot:+($debian_chroot)}\[\033[00;31m\]\u@\h\[\033[00m\]:\[\033[01;30m\]\w\[\033[00m\]\$ ' # PS1 is the prompt string
else
    ...
fi
# we want to change the values as commented above. for example i set the user@host to be red, the colon to be white, the directory to be dark gray, and all text after to be white
# if u wanted to make user@host to blue for example, you would do [00;34m] instead of [00;31m]
# here are the color codes
# Black       0;30     Dark Gray     1;30
# Blue        0;34     Light Blue    1;34
# Green       0;32     Light Green   1;32
# Cyan        0;36     Light Cyan    1;36
# Red         0;31     Light Red     1;31
# Purple      0;35     Light Purple  1;35
# Brown       0;33     Yellow        1;33
# Light Gray  0;37     White         1;37
# =========================


# ====== BASH ARRAYS ======
fruitsArray=("apple" "mango" "pineapple" "guava" "lichi")
echo ${fruitsArray[0]} # prints apple
echo ${fruitsArray[4]} # prints lichi 
echo ${fruitsArray[5]} # prints nothing (echo prints \n by default)

#display whole array
echo ${fruitsArray[@]}

# add elements to array
fruitsArray+=("banana" "orange")
echo ${fruitsArray[5]} # prints banana

# change elements
fruitsArray[2]="grape"
echo ${fruitsArray[@]} # now third element is grapes
# =========================


# ======= VARIABLE DECLARTIONS =======
declare -i x=0 # i for integer
x=$x+1
echo $x
# ====================================


# ========= FUNCTIONS =========
# functions have a very simple syntax in shell script

functionA() {
    local name="$1"
    echo "Hello" $name
}


# for passing arguments just type them next to the function like this
functionA "bob" # will return Hello bob

# but handling return values gets complicated
# for returns, just use echo and grab values with $() or ``.
# capture return value instead of printing in terminal:
val1=$(functionA "bob")

# this is easy enough for one echo, but supposed a function has several echo that it prints and returns
# then you will need to use sed, it gets very annoying

multiple_return_values() {
    echo "orange1"
    echo "apple2"
    echo "carrot3"
    echo "mango4"
    echo "banana5"
    echo "peach6"
}

# for efficieny, let us first collect all of the echos in one variable
result=$(multiple_return_values)
# now we can access each individal return like so
val1=$(echo "$result" | sed -n '1p')
val2=$(echo "$result" | sed -n '2p')
val3=$(echo "$result" | sed -n '3p')
val4=$(echo "$result" | sed -n '4p')

echo $val1 # print values to check
echo $val2
echo $val3
echo $val4
# =============================


# ======== FOR LOOPS ========
# for loops over folders in pwd

# dir1 and dir2 are just presented as string values, not actual directories
# so cd $d is just same as typing cd dir1 into terminal, hence we could do this with files that dont exist
# if we did that with files that dont exist we would get a terminal message error
for d in dir1 dir2; do # do states that the following is what to do in loop
    echo $d # print d value
    cd $d # go into the d value
    ls # list everything there
    cd .. # go back for next loop
    echo # print a space
done # done states the loop is done
# ===========================


# ===== IF STATEMENTS =====
# if statement syntax is very simple in bash as well
# its just a matter of learning what conditionals there are

# there are two types of ways we can have conditions
# single square brackets []
# double square brackets [[]]

# [] brackets
    # traditional
    # performs only basic string and numeric comparisons
    # requires quoting of variables to avoid word split issues
    # uses -a and -o for logical AND, OR respectively which has unexpected behaviour sometimes

# single bracket examples
if [ conditional ]; then
    echo "condition met"
elif [ conditional2 ]; then 
    echo "condition 2 met"
else
    echo "no condition met"
fi # fi signifies the end of an if statement

# some useful [] conditionals!!
# check if dir exists
if [ -d "$directory" ]; then
    echo $directory
fi
#check if file exists
if [ -f "$file" ]; then
    echo $file
fi
# these are assuming you are in the pwd for file/directory. if not then preceed path based on pwd

# [[ ]] brackets
    # provides extended test features
    # supports additional string and numeric comparisons
    # variables inside dont need to be quoted
    # uses && and || for logical AND , OR respectively

# double bracket examples
a="ya"
if [[ $a == "ya" ]]; do # the spacing is important, should be [[ a == b ]] exactly, or else syntax error.
    echo variable a is ya
fi
# =========================