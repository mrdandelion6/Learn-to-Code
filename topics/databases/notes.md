# databases notes
welcome to my database notes.

# introduction
## topics
- relational model
- ER model
- SQL
- aggregation and joins
- contraints and triggers
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
- every relation (table) has a **schema**, which describes the columns (also referred to as fields)

### schema
a schema is a description of a particular collection of data, using a given data model.
- relation schema describes the schema of a table/relation
- database schema is a set of all relation schemas in the database

## data independence
applications insulated from how data is structured and stored.
### logical data independence
- make the database independent from the rest of the application
### physical data independence
- hardware level considerations
- protection from changes in physical structure of data
- abstract the database from the hardware

## concurrency control
concurrent execution of user programs is key idea to good DBMS performance
- keep CPU working on several programs concurrently
- interleave actions of different programs

### relational database
a relational database is a set of relations. a relation is made of two parts:
1. instance: a table w rows and columns
2. schema: specifies name of a relation, and, name of each columns
- a blueprint that defines the the structure of a relation, aka table
- below is an example of a schema
```
Books (
    book_id: INTEGER,
    title: VARCHAR(100),
    author: VARCHAR(50),
    publication_year: INTEGER,
    isbn: VARCHAR(13),
    available_copies: INTEGER
)
```
to make it easier, think of a relation as a **set** of **rows** and **tuples**. each row should be a distinct "entity".

### tuples vs rows
tuples and rows are terms used interchangeably sometimes but theres a strict theoretical difference between them.

tuples are immutable and the order matters. whereas rows are mutable and the order typically doesnt matter, you access values with column names

# relational model terminology
1. **relation**: a table
2. **attribute**: a column
3. **tuple**: usually we mean a row.. but see above (tuples vs rows)
4. **arity/degree**: number of attributes in a relation
5. **cardinality**: number of tuples/rows in a relation

### tuple index notation
say we have the following relation schema
```
CREATE TABLE Student (
    id INT,
    name VARCHAR(50),
    age INT
);
```
and we have a table
```
id | name      | age
--------------------
1  | zack      | 30
2  | jack      | 69
3  | mack      | 40
4  | back      | 69
```
we can "index" with composite keys. consider the composite key K1 = {id, name}. now let t1 be the tuple (1, zack, 30).

=> t1[K1] = (1, zack)

similarly if we say K2 = {id, name, age}

=> t1[K2] = (1, zack, 30)

which just gives us all of t1

## a relation is a table
a relation is just another word for a table. the order of tuples in relations doesn't matter, i.e, they are unordered.

## levels of abstraction
- many views
    - think of them like APIs
    - how user interacts with database
- single conceptual scehma
    - the logical structure of the database, not necessarily directly available
    - high level overview of the entire database
- single physical scehma
    - the low level implementation of the database
    - describes actual storage structure
    - eg) using balance trees etc
```
view-1         view-2           view-3
  |              |                |
  ---------------|-----------------
                 |
          conceptual schema # defines logical structure
                 |
           physical schema # defines how files and indexes are used
```

here is an example of abstractions with a **university database**:

#### physical schema
- relations stored as unordered files
- index on the first column of students
#### conceptual schema
- Students(sid: string, cname: string, age: int, gpa: float)
- Courses(cid: string, cname: string, credits: int)
- Enrolled(sid: string, cid: string, grade: int)
#### external schema (aka views)
- course_info(cid: string, enrollment: int)

## keys
a key is a set of attributes that uniquely identifies tuples in a relation

### precise defintion
**super key**:
- a set of precise attributes K is a superkey for a relation R if R cannot contain two distinct tuples t1, t2 such that t1[K] == t2[K]

**candidate key**
- a candidate key K for R is a minimum superkey, i.e, if we remove any attribute from K, it is no longer a super key.
    - in other words, there exists no K' proper subset of K s.t K' is a superkey
- we sometimes refer to candidate keys as just keys

## relational query languages
a major strength of the relational model is that we can easily query into data.

