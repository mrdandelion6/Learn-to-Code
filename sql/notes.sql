-- welcome to my SQL notes

-- what is SQL ?
-- SQL stands for structured query language. it is a language used to communicate with databases. 
-- query means to ask a question. so SQL is used to ask questions to a database.
-- SQL is used to perform tasks such as updating data on a database, or retrieving data from a database.

-- DATABASES
-- databases are used to store data. some popular databases are MySQL, PostgreSQL, SQLite, Oracle, and MongoDB.
-- the way data is stored can vary depending on the database. some databases store data in tables, while others store data in json documents.

-- TABLES
-- tables are used to store data in a database for services like MySQL, PostgreSQL, and SQLite.
-- tables are made up of rows and columns. each row represents a record, and each column represents a field.
-- pretty simple, just like a spreadsheet or a pandas dataframe

-- COLUMNS
-- columns store a category of data. for example "name" might store the name of users

-- ROWS
-- rows store an instance of data. each row corresponds to a single "datapoint", for example a single user
-- if you want to store difference types of data, you would add that in different table. for example, if your current table stores user data, and you want to store product data, you would create a new table for products.
-- just some simple ideas to understand

-- SQL COMMANDS
-- SQL commands are used to communicate with a database. some common commands are SELECT, INSERT, UPDATE, DELETE, CREATE, and DROP.

-- SELECT
-- SELECT is used to retrieve data from a database. it is the most commonly used SQL command. the data is returned in a table format, and referred to as a result set. here's an example:
SELECT * FROM users WHERE age > 18; -- this will return all users who are older than 18

-- INSERT
-- INSERT is used to add new data to a database. here's an example:
INSERT INTO users (name, age) VALUES ('john', 25); -- this will add a new user with the name "john" and age "25"

-- note that SQL commands are case-insensitive, so you can write them in uppercase or lowercase.
insert into users (name, age) values ('bob', 19); -- this is the same as the previous command. also note the use of semicolons at the end of each command. this is used to separate commands.

-- UPDATE
-- UPDATE is used to modify existing data in a database. here's an example:
UPDATE users SET age = 30 WHERE name = 'john'; -- this will update the age of the user with the name "john" to 30