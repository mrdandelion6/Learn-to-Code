# databases notes

welcome to my database notes.

# introduction

## topics

- relational model
- ER model
- SQL
- aggregation and joins
- contraints and trriggers
- database security
- relational algebra
- views and indexes
- database design
- transactions
- concurrency
- intro to NoSQL and MongoDB
- hadoop vs. GFS vs. cassandra

## database management system (DBMS)
a DBMS is an abstraction or software designed to store, retrieve, define, and manage data in a database.

## big 5 V's
all pertaining to data
- value
- veracity
- velocity
- volume
- variety

## data as a service (DaaS)
data as a service is a cloud computing model where data is provided on demand to users over a network. the key idea is that companies can access and use data without having to build and maintain their own data structures.

### is WWW a database management system (DBMS) ?
no, but debatable
- data is unstructred
- no standardized way of declaring a website
- it's search only

### search vs query

a query is:
- a request of information from a database
- in DBMS a specialized query language is used, for example structured query language (SQL)
- more precise and structured than a search

a search is:
- based on keyword matching
- think of something like fuzzy finding, or searching on the internet

### is a file a DBMS ?
no, a file
- has no built in way to manage concurrency, this depends on the OS
- is just a simple container of data
- no built in query abilities

## why use a database?
- data independence and efficient access
- reduced application development time
- data integrity and security
- concurrenct access, recover from crashes

## data models
a data model is a collection of concepts for describing data.
- relation data model
- unstructured data model

### relational data model
- basically a table with rows and columns
- every relation has a **schema**, a which describes the columns (also referred to as fields)

### scheme
a scheme is a description of a particular collection of data, using a given data model.

## data independence
applications insulated from how data is structured and stored.
### logical data independence
- make the database independent from the rest of the application
### physics data independence
- hardware level considerations
- protection from changes in physical structure of data
- abstract the database from the hardware

## concurrency control
concurrent execution of user programs is key idea to good DBMS performance
- keep CPU working on several programs concurrently
- interleave actions of different programs



