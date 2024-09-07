
# hello welcome to my notes on python
# these notes are designed for someone who is already proficient in python.
# these notes provide knowledge on some of the more advanced and unusual things in python

def contents():
    lambda_in_python()
    with_as_in_python()

    return

def lambda_in_python():
    # lambda is a small anonymous function
    # anonymous means that the function does not have a name, and is not declared with def
    # you can think of these as function expressions

    # lambda arguments: expression
    # lambda functions can have any number of arguments but only one expression
    # the expression is executed and the result is returned

    # here is a simple example 
    cube = lambda x: x ** 3
    # the expression value is evaluated and returned

    # very similiar to function expressions in javascript
    # you can call the lambda function like this
    print(cube(3))

    # we can also have multiple arguments
    add = lambda x, y: x + y

    # lambda functions are used when you need a small function for a short period of time
    # they can be replaced by normal functions but lambda functions are more readable and simpler

    # here is an example of a lambda function being used in a function
    def some_power(n):
        return lambda a: a ** n
    
    # this function returns a lambda function that raises a number to the power of n
    squared = some_power(2)
    # this is what the function returns:
        # squared = lambda a: a ** 2 

    cubed = some_power(3)
    quadded = some_power(4)

    print(squared(3))
    print(cubed(3))
    print(quadded(3))

    return 

def with_as_in_python():
    # syntax: 
        # with (expression) as (variable):

    # with statement is used to wrap the execution of a block of code
    # it defines a context manager to be used
    # the context manager is responsible for a setup and cleanup actions
    # the with statement simplifies exception handling by encapsulating common preparation and cleanup tasks

    with open("requirements.txt") as file:
        data = file.read()
        print(data)

    # the file is automatically closed after the block of code is executed
    # this is what makes the with statement so useful

    # moreover, if an exception occurs during the execution of the block of code, 
    # using with ensures that the file is properly closed after error is handled

    # things with statements provides:
        # 1.) automatic cleanup
        # 2.) exception handling
        # 3.) better readability

    # closing files is important to free up system resources like memory and prevent memory leaks
    # it also ensures that the data is written to the file
    # moreover other programs can access the file after it is closed

    return


if __name__ == "__main__":
    with_as_in_python()