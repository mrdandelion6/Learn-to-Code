
# hello welcome to my notes on python
# there won't be much notes on anything here aside from a few harder things.

def contents():
    lambda_in_python()

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

if __name__ == "__main__":
    lambda_in_python()