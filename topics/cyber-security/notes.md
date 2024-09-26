# cybersecurity notes

## welcome

welcome to my notes on cybersecurity. in these notes, we will learn about the basics of cybersecurity, including common vulnerabilities, exploits, and impacts. we will also learn how to write secure code and how to protect against common attacks.

disclaimer: these notes are for educational purposes only. do not use this information to attack systems that you do not own or have permission to attack. hacking is illegal and unethical. always get permission before testing the security of a system.

my notes will involve both hands on code examples and just general notes on cybersecurity. do not try to replicate the code examples on systems that you do not own or have permission to attack. also don't do it on any machine that you care about. i will be using a virtual machine for our code examples.

# general topics

here are some of the general topics that we will be covering in these notes:

### software security
- what is bad code
- writing good cade
- buffer overruns
- sql injections
- xss: cross site scripting

### system security
- how to protect your system
- permissions
- scripts
- hardware
- passwords
- instrusion detection
- fingerprinting

### network security
- firewalls
- networking
- processes
- scanning networks
- footprinting
- routing

### cryptography
- how to keep secrets
- share them with only specified party
- know you are communicating with the right party

### social engineering
- fishing
- people
- and trust

might not get to social engineering.. not sure at the moment.

## stuff to protect
- personal security
- operations security
- communications security
- network security
- information security

## relevant tools

you will need the following languages:
-  C,
- python
- bash
- ruby
- php
- perl

you will want the following debugging tools:
- gdb
- valgrind
- strace

don't worry if you don't know these, we will cover the basics along the way. but what you really need to know (that i won't be covering) is the following:
- python
- C
- bash

if you don't know these, you're cooked. go read my notes on them first.

# resources
- virus total
	- virus total is a website that allows you to scan files for viruses. you can upload a file to the website, and it will scan the file with multiple antivirus engines. this can help you determine if a file is safe to open.
- kali linux
	- kali linux is a linux distribution that is designed for penetration testing and security auditing. it comes with a number of tools that can be used to test the security of a system.
- US cert
	- the united states computer emergency readiness team is a division of the department of homeland security that is responsible for analyzing and reducing cyber threats and vulnerabilities.
- haveibeenpwned
	- have i been pwned is a website that allows you to check if your email address has been involved in a data breach. you can enter your email address on the website, and it will tell you if your email address has been compromised.
- https://openwrt.org/
	- openwrt is an open-source firmware for routers that can be used to improve the security of your network. it comes with a number of features that can help you secure your network, such as a firewall, intrusion detection system, and vpn support.
- sectools
	- sectools is a website that lists a number of security tools that can be used to test the security of a system. the website is organized by category, such as:
- vulnerability scanners
	- general scanner tools
- forensic tools


# terminology

we will introduce some terminology that we will be using throughout these notes:

- **vulnerability**: a weakness in a system that can be exploited by an attacker.
- **exploit**: to use a vulnerability
- **impact**: the effect of an exploit

## CIA triad

the CIA triad is a model that is used to describe the core principles of information security. it stands for:

#### C: confidentiality
- ensuring that data is only accessible to those who are authorized to access it.
#### I: integrity
- ensuring that data is not altered by unauthorized users. information remains unchanged in transit and rest.
#### A: availability
- ensuring that data is available when needed to authorized users.

we also further break down the CIA triad into the following:

### vulerable system CIA
- a system becomes vulernable when it is compromised..

### subsequent system CIA
- but what are the subsequent effects of a system being compromised?

### more fine grained CIA

#### A: authentication
- ensuring that a user, data, or software is genuine
#### A: accountability
- maintaining identity and activity logs

## more terminology

- **exploit a vulnerability**: to take advantage of a vulnerability to gain unauthorized access to a system.
- **prevention**: to stop an exploit from occurring. eg) prevent smashing the stack by randomizing the stack.
- **detection**: to identify an exploit after it has occurred. eg) detect a buffer overrun by monitoring the stack. another example, *Tripwire* is a tool that can be used to detect changes to files on a system.
- **recovery**: to recover from an exploit after it has occurred. eg) recover from a buffer overrun by restoring the stack to a previous state.
- **scanning**: probe systems on the internet to find vulnerabilities. eg) use *nmap* to scan a network for open ports.
- **vulernability scanner**: a tool that can be used to scan for known weaknesses
- **sniffer**: software that captures network trafffic while in transit. eg) *wireshark* is a popular sniffer.

## more more terminology
- **exploit**: a ready to run program that takes advantage of a vulnerability
- **side-channel attack**: eavesdropping, acoustic keyboard eavesdropping
- **root kit**: software designed to hide the fact that a system has been compromised. for example, replace `ls` on a unix system to hide the fact that rogue processes are running.
- **leet speak**: a form of writing that replaces letters with numbers or symbols. for example, "hacker" might be written as "h4ck3r". this is often used by hackers to obfuscate their code.
- **honeypot**: a server that acts as a decoy to lure attackers. for example, a server that is intentionally left unpatched to attract attackers.
- **threat modelling**: a formal approach to security
- **penetration testing**: a simulated attack on a system to identify vulnerabilities. for example, using *nmap* to scan a network for open ports.
- **red team**: a group of security experts who simulate attacks on a system. for example, a group of hackers who try to break into a company's network.
- **blue team**: a group of security experts who defend a system against attacks. for example, a group of security analysts who monitor a company's network for suspicious activity.
- **purple team**: a group of security experts that communicate between the red and blue teams. for example, a group of security analysts who coordinate the response to a security incident.

you don't need to memorize these terms, but you should be familiar with them and understand their meaning.

## defender vs attacker principles
1. the defender must defend all points; the attacker can choose the weakest point
2. the defender can defend only against known attacks; the attacker can probe for unknown vulnerabilities
3. the defender must be constantly viligant; the attacker can strike at will
4. the defender must play by the rules; the attacker play dirty

### defender principles

#### compartmentalization
- separate systems so that a compromise in one system does not affect the others. for example, use a firewall to separate a web server from a database server.
- if one thing gets taken over, should not be able to take over other parts

#### multiple layers of security
- use multiple layers of security to protect against different types of attacks. for example, use a firewall, intrusion detection system, and antivirus software.
- get other people to check your work

#### don't volunteer information
- attacks commonmly work in the dark and perform reconnaissance to uncover information about a target. don't make it easy for them. 
- dont show context, dont show your hand

#### fail safely
- if a system is compromised, it should fail in a safe manner. for example, if logins aren't working because of an internal issue, the rest of the web page should be working while only logins are halted.

#### practice simplicity
- the simpler a system is, the easier it is to secure. for example, use a simple password policy that is easy to enforce.

## the ten immutable laws of security
1. if a bad actor can persuade you to run his program on yoru computer, it's not your computer anymore
2. if a bad actor can alter the os on yoru computer, its not your computer anymore
3. if a bad actor has unrestricted physicsal access to your computer, its not your computer anymore
4. if you allow a bad actor to upload programs to your website, it's not your website anymore
5. weak passwords trump strong security
6. a computer is only as secure as the administrator is trustworthy
7. encrypted data is only as secure as the decryption key
8. an out of date virus scanner is only marginally better than no virus scanner at all
9. absolute anonymity isn't practical, in real life or on the web
10. technology is not a panacea (solution or remedy for all difficulties or diseases)

## common vulnerabilities

we list the most common vulernabilities in order of how common they are, to motivate us to learn about them:
1. out-of-bounds writes
2. improper neutralization of input during web page generation
3. improper neutralization of input used in SQL commands
4. out-of-bounds reads

and here are some more (unordered):
- null pointer dereference
- use after free (when a program tries to access memory that has already been freed)
- hard coding credentials
- integer overflow


## writing secure code

here's some terminology to consider to when writing secure code:

#### assessment
- analysis of the environment and the system security requirements. what piece of software does this program run in (iOS, android, etc)?
- during this phase you create and document a security policy and plans for implementing that policy.

#### protection
- implementing a secuirity plan. this includes implementing security controls, such as firewalls, intrusion detection systems, and antivirus software.

#### detection
- identifying security incidents. this includes monitoring the network for unusual activity, such as unauthorized access attempts.

#### response
- responding to security incidents. this includes investigating the incident, containing the incident, and recovering from the incident.

## ssh'ing into an ip address

how can we ssh into an old machine where we have the ip address?

```bash
ssh username@ip_address
```

we will typically get an error message like this:

```bash
Unable to negotiate with `ip_address` port 22: no matching key exchange method found. Their offer: diffie-hellman-group1-sha1
```

this is because the server is using an outdated key exchange method. we can listen to the server's offer, but we just end up running into a different error message.

the reason we are looking into this is because we will be working work old machine images that may have security vulerabilities. it will be easier to exploit these vulnerabilities while we are ssh'd into the machine.

### red hat 7.2

for my notes, i will be using a very old red hat 7.2 machine. specifically, we are using: rh72 2.4.7-10. we will be using this machine to learn about cybersecurity. you can find a zip for the vm in `cyber-security/VMs/RH72BufferOverruns

for the VM we are using, the command to `ssh` into it can be found in `jots.md`, but i add it here as well:
```
ssh -oKexAlgorithms=+diffie-hellman-group1-sha1 -c 3des-cbc hacker@10.10.10.12
```
where `10.10.10.12` is the ip address of the machine we are trying to ssh into.

## components of a computer system

### CPU
- executes instructions
- has registers to store data

### memory
- has stack and heap
- has program data
- has OS data

### instructions
- are executed by the CPU
- are loaded into memory from source code


now we ask the question. when we compile a program, it turns into an executable which can be run on a computer. this executable contains instructions. we ask the question, "how can we know what the instructions even mean? how are sure that a line of binary is an instruction to add somethong or just some data?"

well it depends on the CPU's architecture. the CPU looks at the instruction and determines what to do with it based on where the byutes are located and what values they are. we often represent these instructions in hex, because hex is a compact form.

## hexidecimal

hexidecimal is a base 16 number system. it uses the digits 0-9 and the letters A-F. it is used to represent binary data in a more compact form.

### converting between hex and binary

| Binary | Hexadecimal |
|--------|-------------|
| 0000   | 0           |
| 0001   | 1           |
| 0010   | 2           |
| 0011   | 3           |
| 0100   | 4           |
| 0101   | 5           |
| 0110   | 6           |
| 0111   | 7           |
| 1000   | 8           |
| 1001   | 9           |
| 1010   | A           |
| 1011   | B           |
| 1100   | C           |
| 1101   | D           |
| 1110   | E           |
| 1111   | F           |

hexidecimal usually starts with `0x` to indicate that it is a hex number. for example, `0x1A` is the hexidecimal representation of the binary number `00011010`.


### using gdb on a C program

we will learn how to effectively use gdb to debug a C program. this will help us understand how a program works at a low level.

consider the following C program:

```c
main(int argc, char **argv) {
    int x = 5;
    int y = 6;
    int z = x + y;
    printf("z is %d\n", z);
}
```

we can compile this program with the following command:

```bash
gcc -g -o add add.c
```

this allows us to be able to use gdb on the program. we can run the program with the following command:

```bash
gdb ./add
```

now let's add a break point at the start of main and run gdb:

```bash
(gdb) break main
(gdb) run
```

if do run, we see we are at the start of the main function since we added our breakpoint.

instead of typing `break`, we can also just type `b`. we could also break at a specific line number if we would like. for example:
```bash
(gdb) b 64
```

and to run, we could have used `r` instead. similarly, we can also step through code using the `step` command or `s` for short:
```bash
(gdb) step
``` 

moving on, we can also disassemble the main function with the following command:

```bash
(gdb) disassemble main
```

this will show us the assembly code for the main function. 

we can also see all the information about the registers with the following command:

```bash
(gdb) info registers
```

for this to work, we need to have executed some code (for example, we we set a breakpoint before).

note that we see many different register names like "ebp, esp, eip" or "rbp, rsp, rip". the "e" stands for "extended" and the "r" stands for "register". you might see "r" on a 64-bit system and "e" on a 32-bit system. we will list what these are for in the next section.

we can also use the command `x / 32` to see the next 32 bytes of memory. x stands for "examine" and 32 is the number of bytes we want to see. for example:

```bash
(gdb) x / 32 $esp
```
the above command will show us the next 32 bytes of memory starting from the stack pointer.

depending on the architecture, gdb might show us the memory in different ways. for example, on a 32-bit system, gdb might show us the memory in 4-byte chunks, while on a 64-bit system, gdb might show us the memory in 8-byte chunks.

## x86-64 registers

we will mostly only be inspecting the stack pointer, frame pointer, and instruction pointer but here's a list of all the registers and what they are used for:

rax: accumulator
- used for arithmetic operations

rbx: base
- used as a base pointer. this is a general purpose register.

rcx: counter
- used for loops and string operations

rdx: data
- used for I/O operations

rsi: source index
- used for string operations

rdi: destination index
- used for string operations

rbp: **base pointer** aka frame pointer
- points to the base of the stack frame.

rsp: **stack pointer**
- points to the top of the stack

rip: **instruction pointer**
- points to the next instruction to be executed


and for **the** 32-bit system it is the same, but with an "e" instead of an "r". for example, eax instead of rax.


## WYSINWYX

what you see is not what you execute. this is one of the most fundamental ideas in computer security. the idea is that your source code may seem fine, but what happens in the background at a low level may include hidden vulnerabilities.

for example, consider the following code:
```c
set(password, '\0', len);
free(password);
```
where `password` is some pointer to a string that contains sensitive data and len is the length of the string. a compiler might attempt to "optimize" this code never actually compiling code to call `set` because it sees that the memory is never used later on. this would leave the password in memory, even after it has been freed.

the idea is that we can't trust the source code for program security. a better security check would be to examine the compiled code and test for vulnerabilities there. you never know what the compiler might do to your code.

another such example is cases where libraries not part of the standard library are used. for example, in C, if you want to make a multithreaded program, you would typically use `pthread.h`, but this is an external library not part of the standard C framework. hence the compiler might create security risks for multithreaded programs that it would otherwise not have for single-threaded programs. 

### unexpected function pointer behavior

below is an example of how we can implicitly call a function pointer by manipulating memory:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f2() {
    printf("hello from f2\n");
}

void f1() {
    printf("jaja from f1\n");
}

int main() {
    int (*f) (void);
    // this is a function **pointer**
    // recall the syntax: int (*f) (void) means that f is a pointer to a function that returns and integer and takes no arguments (void)
    

    int diff = (char*)&f2 - (char*)&f1; 
    // gives offset between f1 and f2

    f = &f1;
    f = (int (*)())((char*)f + diff); 
    // f now points to f2
    
    (*f)(); 
    // indirect call to f2
}
```
not that we simplify took the difference between the memory addresses of the two functions and added that to the memory address of the first function. this allowed us to call the second function using the function pointer.

this may seem obvious or trivial, but we extend this idea to buffer overruns and other security vulnerabilities. what if we could manipulate memory to call a function that we shouldn't be able to call? this is the basis of many security vulnerabilities.


## buffer overruns

buffer overruns are a common security vulnerability in C programs. they occur when a program writes more data to a buffer than it can hold. this can cause the program to crash, or worse, allow an attacker to execute arbitrary code on the system.

see the c program in `code_examples/bufferoverruns/stack.c`

```c
#include<stdio.h>

// global variables, available to the whole program
char c;
short s;
int i;
long l;
float f;
double d;

int sumNums(int n, int m){
	int i;
	int sum=0;
	char c[16];
	i=n;
	while(i<m){
		sum=sum+i;
		i=i+1;
	}
	
	/*
	 *  modify this so 
	 * that the return address is overwritten with the address of hacked
	c[0]=0xb0;
	c[1]=0x25;
	c[2]=0x33;
	c[3]=0x55;
	*/

	return sum;
}
void f1(int a, int b, int c, int d){

}
void hacked(){
	printf("I've been hacked\n");
}
int main(int argc, char ** argv){
	sumNums(3,7);
	f1(1,2,3,4);
	f1(1,2,3,4);
}

```

we will compile this with the `-g` flag:
```bash
gcc -g stack.
```

and run it with gdb:
```bash
gdb ./stack
```

we can then use `list` to list the sumNums and main function, then use `b` to set some breakpoints:
```bash
listSumnums 
b 93 # nefore the "modify this" comment
list main
b 112 # on the call to sumNums
```

we can then examine the memory at the stack pointer with the following command:
```bash
x/32w $esp
```

this will show us the next 32 words of memory starting from the stack pointer. 

if we tried doing just `x/32`, we might get a message like "Cannot access memory at address 0x0" since we are trying to access memory that we don't have permission to access. we include the `$esp` to tell gdb to start at the stack pointer.


## SQL injections

before we get into SQL injections, here's some brief background on SQL:

### SQL intro

SQL stands for Structured Query Language. it is a language used to interact with databases. it is used to create, read, update, and delete data in a database. let's see some syntax

```SQL
CREATE TABLE users (
	id INT PRIMARY KEY,
	name VARCHAR(100),
	age INT
);


INSERT INTO users (id, name, age) VALUES (1, 'Alice', 25);

SELECT * FROM users;

UPDATE users SET age=26 WHERE name='Alice';

DELETE FROM users WHERE name='Alice';

DROP TABLE users;
```

each of these commands is a **SQL query**. a SQL query is a string that is sent to a database to perform some operation.


### PHP intro

PHP is a server-side scripting language. it is used to create dynamic web pages. PHP code is executed on the server, and the result is sent to the client as HTML. PHP code is embedded in HTML code using special tags. let's see some syntax:

```php

<?php
	$name = $_GET['name'];
	$age = $_GET['age'];
	
	echo "Hello, $name. You are $age years old.";
?>
```

### injections

we will now show some examples of how PHP code can be vulnerable to SQL injections.


the above code is vulnerable to **PHP injections**. this is when an attacker sends malicious input to a PHP script. this input is then executed as code on the server. this can allow an attacker to read, write, or delete data from the database.

for example, consider the following code:

```php
<?php
	$name = $_GET['name'];
	$age = $_GET['age'];
	
	$query = "SELECT * FROM users WHERE name='$name' AND age='$age'";
	$result = mysqli_query($conn, $query);
?>
```

if an attacker sends the following input to the script:

```
name=alice' OR '1'='1' -- &age=25
```

the query will be:

```sql
SELECT * FROM users WHERE name='alice' OR '1'='1' --' AND age='25'
```

this query will return all the rows in the users table, since `'1'='1'` is always true. the `--` is a comment in SQL, so the rest of the query is ignored. this allows the attacker to read all the data in the database.

essentially, using ' affter the name allows the attacker to inject their own SQL code into the query. this is a SQL injection. we can use **prepared statements**.

### prepared statements

prepared statements are a way to prevent SQL injections. they allow us to separate the query from the data. this way, the data is never executed as code. here's an example of how to use prepared statements in PHP:

```php
<?php
	$name = $_GET['name'];
	$age = $_GET['age'];
	
	$query = "SELECT * FROM users WHERE name=? AND age=?";
	$stmt = mysqli_prepare($conn, $query);
	mysqli_stmt_bind_param($stmt, "si", $name, $age);
	mysqli_stmt_execute($stmt);
?>
```

or in python:

```python
import sqlite3

connection = sqlite3.connect('example.db')
cursor = connection.cursor()

cursor.execute('SELECT * FROM users WHERE name=? AND age=?', (username, password))

user = cursor.fetchone()

connection.close()
```

in this example, the `?` are placeholders for the data. the data is then bound to the placeholders using `mysqli_stmt_bind_param`. this way, the data is never executed as code, so SQL injections are prevented. this may seem trivial, but a lot of security vulnerabilities come down to simple mistakes like this. in fact, a third of all security vulnerabilities are due to SQL injections.

let's just take a second to understand the code as well, in case you are unfamiliar with SQL. the sqlite3 is a library that allows us to interact with an sqlite database. we first connect to the database, then create a **cursor** object. a cursor is used to execute SQL queries. it's just like a cursor in a text editor, it points to a specific location in the database.  

