-- welcome to my SQL notes
-- in these notes we will start from the basics of SQL and work our way up
-- below is a list of topics we will cover stored in procedures (learn about these in the notes)
-- to jump to a topic, simply word search it with your text editor.

-- --------------------------------------------------------------------------------------------------------------------
/*
TOPICS:

INTRO and SETUP:
    - what_is_sql()
    - setup_mysql()
    - how_to_use_these_notes()
        > functions & procedures intro
    - delimiter()
    - functions_procedures_syntax()

USING SQL:
    - how_is_sql_used()
    - database_servers()

SQL BASICS:
    - tables_and_relations()
        > primary and foreign keys
    - operations_intro()
    - data_types()
    - constraints()
    - indexes()

CREATING & MANAGING DATABASES & TABLES:
    creating_and_dropping_db()
        > create database
        > drop database
        > use database
    creating_and_dropping_tables()
        > create table
        > drop table
        > use table
    
CORE SQL OPERATIONS:
    - select_statements()
        > basic queries
        > column selection
        > aliasing
    - where_filter()
    - order_by()
    - distinct_keyword()
    - basic_operators()

DATA MANIPULATION:
    - insert_statements()
    - update_records()
    - delete_operations()
    - truncate_vs_delete()
    - transactions_and_acid()

JOINS AND RELATIONSHIPS:
    - inner_join()
    - left_right_join()
    - full_outer_join()
    - cross_join()
    - self_joins()
    - multiple_table_joins()

AGGREGATE FUNCTIONS:
    - count_sum_avg()
    - min_max()
    - group_by()
    - having_clause()
    - window_functions()

ADVANCED QUERIES:
    - subqueries()
    - prepared_statements()
    - common_table_expressions()
    - union_and_union_all()
    - views()
    - temporary_tables()

FUNCTIONS AND PROCEDURES:
    - built_in_functions()
        > string functions
        > date/time functions
        > numeric functions
    - user_defined_functions()
    - stored_procedures()
    - triggers()
    - events()

SECURITY AND BEST PRACTICES:
    - sql_injections()
    - prepared_statements_vs_direct_queries()
    - user_management()
    - permissions_and_privileges()
        > GRANT
        > REVOKE
    - connection_security()

DATABASE DESIGN
    - normalization()
    - entity_relationship_diagrams()
    - schema_design_principles()
    - performance_considerations()
*/
-- --------------------------------------------------------------------------------------------------------------------

CREATE DATABASE IF NOT EXISTS sql_notes;
USE sql_notes;
SOURCE ./helpers.sql
SOURCE ./initialize_mock_data.sql

DROP PROCEDURE IF EXISTS what_is_sql;
DELIMITER //
CREATE PROCEDURE what_is_sql()
BEGIN
    /*
    SQL stands for structured query language. it is a language used to communicate with databases. 
    query means to ask a question. so SQL is used to ask questions to a database.
    SQL is used to perform tasks such as updating data on a database, or retrieving data from a database.
    SQL is an interpreted language like python or bash. it is interpreted by the database in use.
    */

    /*
    DATABASES
    databases, also known as database management systems (DBMS), are software systems designed to store, manage, and organize data. 
    some popular databases are MySQL, PostgreSQL, SQLite, Oracle, and MongoDB.
    the way data is stored can vary depending on the database. some databases store data in tables, while others store data in json documents.
    you can think databases as sophisticated digital filing systems. 
    in order to query with these databases, we need some sort of 'query language support', like SQL.
    */
END //
DELIMITER ;

DROP PROCEDURE IF EXISTS setup_mysql;
DELIMITER //
CREATE PROCEDURE setup_mysql()
BEGIN
    /* 
    SETUP
    in these notes, we will be using the MySQL database.
    these notes will assume you are working on a linux environment like ubuntu.
    if you are on windows, then it may be harder to follow along, just use GPT or claude to figure out windows configuration.

    DOWNLOAD MYSQL
    run the following commands to install mysql on your machine (you will need sudo):
    sudo apt update
    sudo apt install mysql-server
    sudo mysql_secure_installation

    after running mysql_secure_installation, select the following options:

    ... Would you like to setup VALIDATE PASSWORD component?
    $ y

    ... Please enter 0 = LOW, 1 = MEDIUM and 2 = STRONG: 1
    $ 1

    ... Remove anonymous users?
    $ y

    ... Disallow root login remotely?
    $ y

    ... Remove test database and access to it?
    $ y

    and to confirm installation, run:
    sudo systemctl status mysql

    you should see something like:
    ● mysql.service - MySQL Community Server
        Loaded: loaded (/lib/systemd/system/mysql.service; enabled; vendor preset: enabled)
        Active: active (running) since Tue 2024-12-10 22:00:05 EST; 2min 31s ago
        Process: 241786 ExecStartPre=/usr/share/mysql/mysql-systemd-start pre (code=exited, status=0/SUCCESS)
    Main PID: 241794 (mysqld)
        Status: "Server is operational"
        Tasks: 39 (limit: 16702)
        Memory: 360.5M
        CGroup: /system.slice/mysql.service
                └─241794 /usr/sbin/mysqld

    Dec 10 22:00:04 Acer-DK systemd[1]: Starting MySQL Community Server...
    Dec 10 22:00:05 Acer-DK systemd[1]: Started MySQL Community Server.
     */

    /* 
    UNIX SOCKET AUTHENTICATION
    you need to now setup local authentication that uses your system user credentials.
    this is so we don't have to use sudo each time we want to run mysql.

    first run the command: sudo mysql

    now, create a new user matching your ubuntu username and configure it to use auth_socket plugin.
    to do this, run the following commands while in mysql (after u ran sudo mysql):
        CREATE USER 'your_ubuntu_username'@'localhost' IDENTIFIED WITH auth_socket;
        GRANT ALL PRIVILEGES ON *.* TO 'your_ubuntu_username'@'localhost';
        FLUSH PRIVILEGES;

    now exit mysql by running \q
    open a new terminal (same user) and run mysql without sudo: mysql
    this should now work.
    */
END //
DELIMITER ;

DROP PROCEDURE IF EXISTS how_to_use_these_notes;
DELIMITER //
CREATE PROCEDURE how_to_use_these_notes()
BEGIN
    /* 
    RUNNING CODE FROM NOTES
    before proceeding with understanding SQL itself, we must first see how we can use these notes.
    specifically, how we can run the demonstrations and examples i wrote inside them.

    as you can see, each individual section of these notes is sectioned off into it's own "procedure".
    SQL has both 'functions' and 'stored procedures'.
    just like functions, procedures are a set of same instructions which can be called again, foo(1, 2)
    however, SQL functions and SQL procedures have some differences!
    */
    
    /*  
    STORED PROCEDURES vs FUNCTIONS:
    stored procedures are pre-written sets of SQL statements that can be saved and reused later, like a recipe you can follow multiple times.
    
    STORED PROCEDURES:
        - can perform multiple operations like INSERT, UPDATE, DELETE, and SELECT
        - can modify the data in the database
        - don't need to return a value (though they can)
        - can have input and output parameters
        - are typically used for business logic and complex operations

    FUNCTIONS:
        - must return a value
        - can't modify data in the database, they are read only
        - can only contain SELECT statements
        - are typically used for calculations or data retrieval
    */

    /* 
    RUNNING NOTES
    this file, notes.sql, "creates" many procedures. if we run this source file in mysql, all the created procedures will persist.
    i.e, they will be stored in our MySQL server until we explicitly "drop" them. 
    you will learn more these create, drop operations soon in the notes.
    the key takeaway is that we only need to run the source code once, and all of our procedures get stored as metadata.

    to run the source code, we can simply do: mysql < notes.sql
    this creates a new database "sql_notes" where all of our data will be stored
    now we start mysql for this database by doing: mysql sql_notes
    or you could do:
        my sql
        USE sql_notes
    and then we can see all procedures defined in our notes by running: SHOW PROCEDURE STATUS WHERE Db = 'sql_notes';
    as the procedures are all stored in the system's metadata tables, they will persist until you drop them.
    you can drop a procedure by doing: DROP PROCEDURE procedure_name;

    to run a specific procedure we created, we do: CALL procedure_name();
    for example, run the source code (mysql < notes.sql) and do call this procedure:
        CALL how_to_use_these_notes();
    */
    SELECT 'hello world!' AS output;
    /* 
    because of the command above, calling this procedure will print the following:

        mysql> CALL how_to_use_these_notes();
        +--------------+
        | output       |
        +--------------+
        | hello world! |
        +--------------+
        1 row in set (0.00 sec)

        Query OK, 0 rows affected (0.00 sec)
    */

    /*  
    DUPLICATE PROCEDURES
    whenever we modify or add some procedures, we will need to drop them and readd them (because they persist).
    we cannot create a procedure with name X if one with name X already exists.
    that is why we have the command: DROP PROCEDURE IF EXISTS procedure_name; above every procedure creation. 
    */

    /* 
    well now you know how to get started with these notes. here is a quick summary of all the steps again:

        1. run: mysql < notes.sql
        2. run: mysql sql_notes
        3. run: CALL procedure_name;
    */
END //
DELIMITER ;

DROP PROCEDURE IF EXISTS delimiter;
DELIMITER //
CREATE PROCEDURE delimiter()
BEGIN
    /*  
    in SQL, a delimiter is the character that marks the end or separation of an SQL statement.
    it is like a period at the ned of a sentence.
    the standard delimiter in SQL is the semicolon ;

    delimiters are important because:
        1. when you run multiple SQL statements together, the delimiter tells the database system where each statement ends.
    */
END //
DELIMITER ;

DROP PROCEDURE IF EXISTS databases_and_relations;
DELIMITER //
CREATE PROCEDURE databases_and_relations()
BEGIN
    /*
    relational databases are databases that store data in tables. each table is made up of rows and columns.
    each row represents a record, and each column represents a field. a record is a single instance of data, and a field is a category of data.
    if you want to store different types of data, you would add that in different table. for example, if your current table stores user data, and you want to store product data, you would create a new table for products.
    */

    /*
    COLUMNS
    columns store a category of data. for example "name" might store the name of users
    */

    /*
    ROWS
    rows store an instance of data. each row corresponds to a single "datapoint", for example a single user
    just some simple ideas to understand
    */

    /*
    PRIMARY KEYS & FOREIGN KEYS
    each row of a table has its own unique identifier, called a PRIMARY KEY. this is used to identify the row within the table.
    the tables can be related to each other, hence the name "relational database".
    for example, the primary keys of one table can be used as some values in another table. this is called a FOREIGN KEY. see example:
    */

   -- TEAMS TABLE
    CREATE TABLE teams (
        id INT PRIMARY KEY,
        name VARCHAR(50)
    );

    -- USERS TABLE
    CREATE TABLE users (
        id INT PRIMARY KEY,
        name VARCHAR(50),
        age INT,
        team_id INT
    );
    /*
    note that CREATE TABLE is a SQL command used to create a new table. the table name is "users", and it has 4 columns: id, name, age, and team_id.
    */

    /*
    we see that the "users" table has a column called "team_id". this column is a foreign key that references the "id" column of the "teams" table.
    this means that the users table is related to the teams table. 
    this might seem very simple, but there is a good reason for why we choose the relational database model. 
    below we motivate some reasons for why we might want to use a relational database.
    */

    /*
    WHY USE A RELATIONAL DATABASE ?
    1. DATA INTEGRITY: relational databases enforce data integrity. this means that the data stored in the database is accurate and consistent.
        they do this by using primary keys to uniquely identify rows, and foreign keys to relate rows in different tables.
    2. DATA CONSISTENCY: relational databases ensure that data is consistent across tables. for example, if you delete a row from one table, you can also delete related rows from other tables.
    3. SCALABILITY: you essentially "normalize" your data by storing it in multiple tables. this makes it easier to scale your database as your data grows.
        NORMALIZATION just refers to splitting your data into multiple tables.
        an example is, suppose for the above users table, we had a column called "team_name" instead of "team_id". this would be redundant, because the team name is already stored in the teams table.
        and you might say, "well, why not just store the team name in the users table and get rid of the teams table?" 
        in our case we could do that but suppose we had a column called "team_location" as well, or just a lot of columns related to the team. it is better design to encapsulate all the team data in a separate table and reference it with a foreign key.
    */
END //
DELIMITER ;

DROP PROCEDURE IF EXISTS commands_and_statements;
DELIMITER //
CREATE PROCEDURE commands_and_statements()
BEGIN
    -- so SQL is not ony used to create, read, update, and delete data (CRUD), but it also gives data a structure.

    -- SQL COMMANDS & STATEMENTS
    -- now we go over some basic SQL syntax
    -- SQL commands are used to communicate with a database. some common commands are SELECT, INSERT, UPDATE, DELETE, CREATE, and DROP.
    -- recall we used CREATE to create tables above. here are some other commands:

    -- SELECT
    -- SELECT is used to retrieve data from a database. it is the most commonly used SQL command. the data is returned in a table format, and referred to as a result set. here's an example:
    SELECT * FROM users WHERE age > 18; -- this will return all the rows from the "users" table where the age is greater than 18
    -- we say the entire line above is a "statement"
    -- the column is sage, and the table name is users, these are known as 'identifiers' in the statement
    -- in this case, we are selecting all rows by using the asterisk (*), with the filter that the age is greater than 18

    -- INSERT
    -- INSERT is used to add new data to a database. here's an example:
    INSERT INTO users (name, age) VALUES ('john', 25); -- this will add a new user with the name "john" and age "25"

    -- note that SQL commands are not case-sensitive, so you can write them in uppercase or lowercase.
    insert into users (name, age) values ('bob', 19); -- this is the same as the previous command. also note the use of semicolons at the end of each command. this is used to separate commands.

    -- UPDATE
    -- UPDATE is used to modify existing data in a database. here's an example:
    UPDATE users SET age = 30 WHERE name = 'john'; -- this will update the age of the user with the name "john" to 30
    -- the python equivalent of this would be something like: users.loc[users['name'] == 'john', 'age'] = 30
END //
DELIMITER ;