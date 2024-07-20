<?php

// RUN:
how_php_works();

function contents() {
    // list of topics
    intro_to_php();
    how_php_works();
    php_tags();
    running_php();
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

    // YOU CAN HAVE HTML IN PHP FILES
    // anything outside the php tags is treated as html
    // see php_tags() for an more

    // PHP IS EMEDDABLE IN HTML
    // this is not inside HTML files, but rather inside HTML tags within PHP files
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
        // the web server receives the request and finds the php script
    // 3. PHP EXECUTION
        // the php preprocessor executes the php code. this may invovlve retrieving information from a database, processing uer input, etc.
    // 4. RESPONSE
        // the php script sends html outout back to the browser after processing
    // 5. DISPLAY
        // the user's browser displays the resulting html
    
    // example script:
    echo "Hello, World!\n\r";
}

function php_tags() {
    // php code is enclosed in <?php ?\> tags
    // you can see one at the beginning of this file
    // these tags tell the php interpreter where the php code begins and ends
    
    // you can have multiple php tags in a php file.
    // anything outside of the php tags is treated as html
    // for example, lets end our php code and write some html
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>PHP Tags Example</title>
</head>
<body>
    <h1><?php echo "Hello, World!"; ?></h1>
    <p>Today's date is <?php echo date('F j, Y'); ?>.</p>
</body>
</html>

<?php

function running_php() {
    // there are several ways to run php code:
    // 1. web server
        // the most common way to run php code is on a web server
        // the web server processes the php code and sends the output to the client's browser
    // 2. command line
        // you can run php code from the command line using the php interpreter
        // this is useful for testing and debugging php code
    
    // lets first look at running php in the command line.
    // simply create a php file and run it with the php command:
    // php myscript.php
    // of course, you need to have php interpreter on your system to do this
    
    // recall that PHP outputs html, so you can run php code in the command line and see any output html in the terminal

}
