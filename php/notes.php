<?php

function contents() {
    // list of topics
    intro_to_php();
    how_php_works();
}

function intro_to_php() {
    // php is a server side scripting language that is used to develop web applications
    // php stands for hypertext preprocessor
    // unlike C and java, php is an interpreted language, meaning that it is not compiled before execution
    // this is similiar to python, bash, and javascript

    // SERVER SIDE SCRIPTING LANGUAGE
    // this means that php scripts run on a web server, not on the client's browser like js
    // the webserver processes the php code with a php interpreter and then sends the output to the client's browser
    // this allows for dynamic content to be generated on the server before being sent to the client
        // for example, interacting with a database to retrieve data

    // PHP IS EMEDDABLE IN HTML
    // this can be done using the <?php ?\> tags(no \ after the ?)

    // for example:
        // <!DOCTYPE html>
        // <html>
        // <head>
        //     <title>PHP in HTML Example</title>
        // </head>
        // <body>
        
        // <h1>Welcome to My Website</h1>
        // <p>Today's date is: <?php echo date('F j, Y'); ?\></p>
        
        // </body>
        // </html>   

    // CROSS PLATFORM
    // as php is an interpreted language, it can run on any platform that has a php interpreter installed

    // DATABASE INTEGRATION
    // php has extensive support for interacting with a wide range of databases, the most common being MySQL

    // RICH LIBRARY SUPPORT
    // php comes with a rich set of built-in functions and libraries that make it easy to perform common tasks
    // these tasks vary from pdf generation to parsing xml
}

function how_php_works() {
    // php's workflow can be broken down as follows:
    // 1. REQUEST
        // a user requests a page via a web browser
    // 2. SERVER PROCESSING
        // the php preprocessor executes the php code, this may involve interacting with a database, processing user input, or performing other operations
}