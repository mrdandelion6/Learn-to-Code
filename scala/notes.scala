object notes {
    def main(args: Array[String]): Unit = {
        println("Hello, world!")
    }

    def welcome(): Unit = {
        // scala is a object oriented language + functional programming language
        // scala is a statically typed and compiled language
        // scala uses a JVM (Java Virtual Machine) to run the code, so it is platform independent!
        // there are a lot of similarities between Java and Scala

        // FUNCTIONAL PROGRAMMING
        // functional programming is a programming paradigm that treats computation as the evaluation of mathematical functions and avoids changing-state and mutable data

        // here are some key concepts of functional programming:
        // 1. immutability: once a value is assigned to a variable, it cannot be changed
        // 2. first-class functions: functions are treated as first class citizens and can be assigned to variables, passed as arguments, and returned from other functions
        // 3. pure functions: a pure function is a function that has no side effects and returns the same output for the same input. think of a mathematical function f(x) that doesnt look at any external variables
        // 4. recursion: functional programming favors recursion over loops

    }

    def function_syntax(): Unit = {
        // function syntax
        def add(x: Int, y: Int): Int = {
            return x + y
        }

        // the return keyword is optional
        def subtract(x: Int, y: Int): Int = {
            x - y
        }

        // if the function is a one-liner, you can omit the curly braces
        def multiply(x: Int, y: Int): Int = x * y

        // if the function does not return a value, you can use the Unit type
        def divide(x: Int, y: Int): Unit = {
            println(x / y)
        }
        // Unit is similar to void in Java

        // you can also omit the return type
        def modulo(x: Int, y: Int) = x % y

        // you can also use the => operator to make anonymous functions as variables
        val power = (x: Int, y: Int) => Math.pow(x, y)
        // anonymous functions are also called lambda functions, they are functions without a name

        // you can also define a function with default parameters
        def greet(name: String = "world"): Unit = {
            println(s"Hello, $name!")
        }

        // you can also define a function with a variable number of arguments
        def sum(args: Int*): Int = {
            var total = 0
            for (arg <- args) {
                total += arg
            }
            total
        }
        // here, args is a sequence of integers

        // you can also define a function with a return type of Any
        def addOrMultiply(x: Int, y: Int, add: Boolean): Any = {
            if (add) {
                x + y
            } else {
                x * y
            }
        }
    }
}

def top_level(): Unit = {
    println("top level function")
}

