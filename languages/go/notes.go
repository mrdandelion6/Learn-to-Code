package main

import "fmt"

func main() {
	if false { // list of topics
		intro_to_go()
		the_main_function()
	}
	the_main_function()
}

func intro_to_go() {
	// go is a statically typed, compiled language
	// the syntax is similar to C but it does not have as much low level control
	// go is a garbage collected language, so you don't have to worry about memory management

	// something very unique to go is that it is a CONCURRENT language
	// go is a concurrent language, it has built in support for concurrency.
	// concurrency is the ability to run multiple tasks at the same time
	// we'll talk more about this later in the concurrency() function

	// COMPILING GO
	// go is a compiled language, which means that you have to compile your code before you can run it like with C
	// you use the go compiler to compile your code

	// there are two ways to compile go code
	// GO RUN
		// go run is a command that compiles and runs your code
		// unlike gcc, it doesnt compile an executable file which is saved to disk be able to run later
		// instead, it compiles the code on the disk temporarily and runs it, then deletes the executable
		// this all happens in the background, so you don't really see it
		// this is useful for testing code quickly

	// GO BUILD
		// go build is a command that compiles your code and saves the executable to disk
		// you can then run the executable whenever you want
		// this is useful for when you want to run the code multiple times
		// you can also use the -o flag to specify the name of the executable just like with gcc
		// you can run the executable by typing ./<executable name> in the terminal, just like with C
		// note that for windows, u must include a .exe extension to the executable name for it to be able to run
		// like this: go build -o myprogram.exe myprogram.go
}

func the_main_function() {
	fmt.Println("welcome.")
	// the main function is the entry point of a go program
	// the idea is same as C, but the syntax is different

	// we need to state the package name at the top of the file
	// the package name is the name of the package that the file belongs to
	// the package name is the same as the name of the directory that the file is in
	// the package name is used to group related code together
	// this idea is the same as in java

	// the main package is a special package in go
	// it is the package that contains the main function
	// the main package declaration indicates that the file is an executable program, not a library
	// the package is the entry point of the program, and must contain a main function
}

func concurrency() {
	// go routines
	// a go routine is a function that runs concurrently with other functions
	// go routines are lightweight, they are cheap to create and destroy
	// you can create a go routine by using the 'go' keyword followed by a function call
	// go routines are a way to run multiple tasks at the same time
}
