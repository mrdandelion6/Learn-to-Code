# Shell Scripting Notes

# we can make shell script files which automatically run when executed!

# step 1: create the shell script .sh file, let's call it myscript.sh
# step 2: in a terminal, navigate to the directory where the script is
# step 3: run the command: chmod +x myscript.sh, this makes the script executable by giving it permission
    # lets break down chmod +x myscript.sh,
    # "chmod": changemode, for modifying the file's permissions
    # "+x": adds execute permission to file, allows myscript.sh to be run as a program or script
    # other permissions: -r (read permission), -w (write permission)
# step 4: now execute myscript.sh in terminal as you would any executable by entering: ./myscript.sh
# done!!

# we prefix exetucables by ./myscript.sh to tell shell to find the myscript.sh in the current directory
# for executables added to the system's PATH environment, we do not need ./ as those executables/programs are "global"
# an example is how we type in gcc without ./

# SSH
# to ssh into a remote location use the following command:
# ssh <username>@<remote_host>
# for example, <utorid>@dhXXXXpcXX.utm.utoronto.ca
# type exit to exit the ssh

# DECLARING VARIABLES
x="Hello World!"
# no space around =

# ARITHMETIC
x=1
y=1
z=$((x + y)) # must encapsulate math with $(( ))
echo $z # prints 2
