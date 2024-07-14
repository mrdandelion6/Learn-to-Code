import scala.concurrent.Future
import scala.concurrent.ExecutionContext.Implicits.global

object notes {
    def main(args: Array[String]): Unit = {
        println("Hello, world!")
    }

    def contents() = {
        welcome()
        function_syntax()
        futures()
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

    def futures(): Unit = {
        // the Future type is used to represent a value that will be available at some point in the future and may not exist yet
        // since the value may not exist yet, the Future type is used for asynchronous programming.
        // these are 

        // the Future type provides to work with the result of an asynchronous operation without blocking the current thread.
        // must have: import scala.concurrent.Future
        // must have: import scala.concurrent.ExecutionContext.Implicits.global

        // here is a summary of how future works in scala:
        // 1. asynchronous execution:
            // when you create a Future, the computation it represents is executed on a separate thread, allowing the current thread to continue without waiting for the Future to complete

        // 2. error handling:
            // futures can also handle failures. if the asynchronous computation fails, the Future will contain the exception instead of a successful result. you can respond to both successful and failed futures using callbacks like onComplete, onSuccess, onFailure, and recover.

        // 3. awaiting results:
            // while its generally best to stay non blocking and compose Futures, scala also provides the Await object, which can block the current thread until the Future completes for when you absolutely need to wait for a result.

        // heres a simple example of a future
        val futureResult: Future[Int] = Future {
            Thread.sleep(1000)
            42
        }

        futureResult.onComplete {
            case Success(value) => println(s"The result is $value")
            case Failure(exception) => println(s"Failed with $exception")
        }

    }
}

def top_level(): Unit = {
    println("top level function")
}

