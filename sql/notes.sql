-- welcome to my SQL notes

-- what is SQL ?
-- SQL stands for structured query language. it is a language used to communicate with databases. 
-- query means to ask a question. so SQL is used to ask questions to a database.
-- SQL is used to perform tasks such as updating data on a database, or retrieving data from a database.

-- DATABASES
-- databases are used to store data. some popular databases are MySQL, PostgreSQL, SQLite, Oracle, and MongoDB.
-- the way data is stored can vary depending on the database. some databases store data in tables, while others store data in json documents.

-- RELATIONAL DATABASES i.e, TABLES
-- sql is most commonly used with relational databases. relational databases store data in tables like with pandas dataframes or excel spreadsheets.
-- relational databases are databases that store data in tables. each table is made up of rows and columns.
-- each row represents a record, and each column represents a field. a record is a single instance of data, and a field is a category of data.
-- if you want to store differenT types of data, you would add that in different table. for example, if your current table stores user data, and you want to store product data, you would create a new table for products.

-- COLUMNS
-- columns store a category of data. for example "name" might store the name of users

-- ROWS
-- rows store an instance of data. each row corresponds to a single "datapoint", for example a single user
-- just some simple ideas to understand

-- PRIMARY KEYS & FOREIGN KEYS
-- each row of a table has its own unique identifier, called a PRIMARY KEY. this is used to identify the row within the table.
-- the tables can be related to each other, hence the name "relational database".
-- for example, the primary keys of one table can be used as some values in another table. this is called a FOREIGN KEY. see example:

-- USERS TABLE
CREATE TABLE users (
    id INT PRIMARY KEY,
    name VARCHAR(50),
    age INT,
    team_id INT,
);
-- note that CREATE TABLE is a SQL command used to create a new table. the table name is "users", and it has 4 columns: id, name, age, and team_id.

-- TEAMS TABLE
CREATE TABLE teams (
    id INT PRIMARY KEY,
    name VARCHAR(50),
);

-- we see that the "users" table has a column called "team_id". this column is a foreign key that references the "id" column of the "teams" table.
-- this means that the users table is related to the teams table. 
-- this might seem very simple, but there is a good reason for why we choose the relational database model. 
-- below we motivate some reasons for why we might want to use a relational database.

-- WHY USE A RELATIONAL DATABASE ?
-- 1. DATA INTEGRITY: relational databases enforce data integrity. this means that the data stored in the database is accurate and consistent.
    -- they do this by using primary keys to uniquely identify rows, and foreign keys to relate rows in different tables.
-- 2. DATA CONSISTENCY: relational databases ensure that data is consistent across tables. for example, if you delete a row from one table, you can also delete related rows from other tables.
-- 3. SCALABILITY: you essentially "normalize" your data by storing it in multiple tables. this makes it easier to scale your database as your data grows.
    -- NORMALIZATION just refers to splitting your data into multiple tables
    -- an example is, suppose for the above users table, we had a column called "team_name" instead of "team_id". this would be redundant, because the team name is already stored in the teams table.
    -- and you might say, "well, why not just store the team name in the users table and get rid of the teams table?" 
    -- in our case we could do that but suppose we had a column called "team_location" as well, or just a lot of columns related to the team. it is better design to encapsulate all the team data in a separate table and reference it with a foreign key.

-- SQL COMMANDS
-- now we go over some basic SQL syntax
-- SQL commands are used to communicate with a database. some common commands are SELECT, INSERT, UPDATE, DELETE, CREATE, and DROP.
-- recall we used CREATE to create tables above. here are some other commands:

-- SELECT
-- SELECT is used to retrieve data from a database. it is the most commonly used SQL command. the data is returned in a table format, and referred to as a result set. here's an example:
SELECT * FROM users WHERE age > 18; -- this will return all the rows from the "users" table where the age is greater than 18

-- INSERT
-- INSERT is used to add new data to a database. here's an example:
INSERT INTO users (name, age) VALUES ('john', 25); -- this will add a new user with the name "john" and age "25"

-- note that SQL commands are not case-sensitive, so you can write them in uppercase or lowercase.
insert into users (name, age) values ('bob', 19); -- this is the same as the previous command. also note the use of semicolons at the end of each command. this is used to separate commands.

-- UPDATE
-- UPDATE is used to modify existing data in a database. here's an example:
UPDATE users SET age = 30 WHERE name = 'john'; -- this will update the age of the user with the name "john" to 30
-- the python equivalent of this would be something like: users.loc[users['name'] == 'john', 'age'] = 30