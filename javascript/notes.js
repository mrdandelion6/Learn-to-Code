// SEPARATION OF CONCERNS:
// we separate our javascript code from our html code
// html: content, js: behaviour

// JS in Node
// To use JS in node, open terminal and simply cd to the directory where the JS file is (for example say our JS file is index,js).
// now type "node index.js" and it will run the index.js file using Node.

// VARIABLES
// in js, we use let keyword to declare variables.
let x = 1;
x = 4;

// CONSTANTS
// kind of like static variables in java, do not change
const y = 0.5; // always use const on vars u dont need to reassign

// below are some primitive/value types:
// string, number, booleans, undefined, null
// note, we don't have floats or integers, just number for both

let name = 'Faisal'; // typically use single quotes for strings in javascript
let age = 19;
let isCool = true;

let firstName; // value is undefined automatically
// so the above is same as
let lastName = undefined;

// null is different from undefined.
// use null when we want to clear variable's value
if (lastName = undefined) {
    lastName = null;
}

// 2 kinds of languages:
// static language: variable types cannot change once set
// dynamic language: variable types can change
// JS is a dynamic language.

// null is a type of object as well as a value
// undefined is also a type of object as well as a value

// OBJECTS
// objects are reference type.
// arrays and functions are also reference types.
// note: why do functions have a type??
// haha clever guy, skipping ahead? functions are treated as "first-class citizens" in JavaScript.
// in other words, they are also treated as values! you can see more at line 756.

let person = {}; //object literal
person = {
    name: 'fsl', // object properties
    age: 20 // note no semicols
};
// the properties (keys), can also be strings!!
// ie) we can use objects as dictionaries as well.

person = {
	"yo": "whaaat"
};
console.log(person.yo); // prints "whaaat"

// property access 2 ways:

// dot notation
person.name = 'six';

// bracket notation
person['name'] = 'sixpop';

// we normally use dot notation, and only really use bracket notation if the property name could vary at runtime.
// eg; if the users choose the property name, then we can have a variable for the property name:

let selection = 'name'; // x may vary at runtime
person[selection] = 'six';

// even though objects are very similiar to maps (we will learn about map object later on line 880),
// there are key differences: 
// - maps allow for any type of keys (including numbers and booleans)
// - maps preserve the order of key-value pair insertion
// - maps are convenient to iterate over 

// ARRAYS
let selectedColors =['red', 'blue']; // arrays syntax literally (almost) same as python
x = selectedColors[0]; // same indexing as python
// however, we do not get any indexing errors. empty indices are just undefined
// moreover, we can have gaps in the list. eg) [ 'red', 'blue', 'green', <2 empty items>, 'orange' ]

selectedColors[2] = 'green';
selectedColors[5] = 'orange'; // skipped 3 and four, 2 empty items

// note that typeof array is object. it has properties such as length, etc.
// note that empty items as gaps in the list are counted in the length, ie) the length of the array goes up to the last index where an item exists
// for example ['red', 'blue', 'green', <2 empty items>, 'orange'] has a length of 6.

// FUNCTIONS
function greet(name) {
    console.log('Hello ' + name);
} // no need for semicol at end of creating function (like java)

greet('six');

// parameter vs argument
// parameters are what we define for functions to take in
// arguments are what we actually provide when we call the function
// "arguments are the value we supply for parameters"

// passing in less arguments than expected doesnt crash code, it just considers missing arguments as undefined and proceeds

// TYPES OF FUNCTIONS

function square(number) {
    return number * number; // a function with an actual return value
}

let twoSquared = square(2);

// == BROCODE ==

// VARIABLES
// Two steps
// 1. Declaration (var, let, const)
// 2. Assignment (= assignment operator)

let x1; // declaration
x1 = 21; // assignment
let x2 = 21; // both together

// we can access and set the content of html files like so:
firstName = "six";
age = 19;
let student = true;

document.getElementById("p1").innerHTML = "hello " + firstName;
document.getElementById("p2").innerHTML = "you are " + age + " years old";
document.getElementById("p3").innerHTML = "enrolled " + student;


// ACCEPT USER INPUT

// simple way
let username = window.prompt("whats ur name"); // browser displays popup box, not practical

// html advanced way
let username2;
document.getElementById("submitButton").onclick = function () { // do onlclick for setting a function to be called on click!
    username2 = document.getElementById("nameText").value; // grab value within textbook
    console.log(username2) 
    document.getElementById("myLabel").innerHTML = username; // set the new innerHTML (text) for the label to be the provided username!
}


// TYPE CONVERSION
age = window.prompt("How old are you?"); // we retrieve this as a string, want to turn it into a number
age = Number(age); // convert the string to a number
age += 1;
console.log("happy bday, you are " + age);

// more examples of converting type
let z;
x = Number("3.14"); // simple
y = String(3.14);
z = Boolean("pizza");
console.log(x, typeof x);
console.log(y, typeof y);
console.log(z, typeof z);

// converting something that is not a number into a number, eg:
x = Number("bars");
// will result in the value of x being NaN (not a number)


// MATH
// Math is an object that provides math functionality and constants (pi)
x = 3.14;
x = Math.round(x);
x = Math.ceil(x);
x = Math.floor(x);
x = Math.pow(x, 2); // x^2
x = Math.pow(x, x); // x^x
x = Math.sqrt(x);
x = Math.abs(x);
// max and min
x = Math.max(3, 4, 6);
x = Math.min(-3, 100, 2, -90);

//constant pi
x = Math.PI;

// USEFUL STRING METHODS
usename = "bro";
username.length // length
username.charAt(2); // charAt
username.indexOf("r"); // index of first occurance of a character
username.lastIndexOf("r"); // index of last occurance of a character
username = " whats up ";
username = username.trim(); // gets rid of leading and trailing empty spaces
document.getElementById("p1").innerHTML = username; // no need to trim, html auto trims stuff (for <p> at least)

let phoneNumber = "123-456-7890";
phoneNumber.replaceAll("-", ""); 

// slice() extracts a section of a string and returns it as a new string,
// doesnt modify original string
username = "six pop";
firstName = username.slice(0, 3); // slicing doesnt include last index
lastName = username.slice(4); // no ending index implies go to end

let space = username.indexOf(" ");
firstname = username.slice(0, space)
lastName = username.slice(space + 1);

// METHOD CHAINING
// call one method after another in a continuous line of code (simple)
username = "six";
let letter = username.charAt(0);
letter = letter.toUpperCase();

// we can write the above code more elegantly using method chaining 
letter = username.charAt(0).toUpperCase();

// IF STATEMENTS
// same as java
age = 21;
if (age >= 18) {
    console.log("You are an adult");
} else {
    console.log("You are a child");
}

// CHECKED PROPERTY
// lets us know if a checkbox or a radio button is selected
// .checked is a boolean property for radiobuttons and checkboxes

// checkboxes:
document.getElementById("hiButton").onclick = function() {
    if (document.getElementById("BoxYa").checked) { // use checked attribute
        document.getElementById("hiButton").innerHTML = "thanks!";
    } else {
        document.getElementById("hiButton").innerHTML = "SELECT IT >:("
    }
}

// factor out a constant
const submitButton = document.getElementById("hiButton");

submitButton.onclick = function() {
    if (document.getElementById("BoxYa").checked) {
        submitButton.innerHTML = "thanks!";
    } else {
        submitButton.innerHTML = "SELECT IT >:("
    }
}

// radiobuttons
const submitButton = document.getElementById("hiButton");
const visaButton = document.getElementById("visaBtn");
const masterButton = document.getElementById("masterBtn");
const paypalButton = document.getElementById("ppBtn");

submitButton.onclick = function() {
    if (document.getElementById("BoxYa").checked) { //again, just used .checked
        submitButton.innerHTML = "thanks!";
    } else {
        submitButton.innerHTML = "SELECT IT >:("
    }

    if (visaButton.checked) {
        alert("You are paying with Visa!");
    } else if (masterButton.checked) {
        alert("You are paying with Mastercard!");
    } else if (paypalButton.checked) {
        alert("You are paying with PayPal!");
    }
}

// SWITCHES
// used in place of several else if statements
// examins a value for a match against many case clauses

let grade = "A";

// this is inefficient
if (grade == "A") {
    console.log("You did great!");
}
if (grade == "B") {
    console.log("You did good!");
}
if (grade == "C") {
    console.log("You did okay!");
}
if (grade == "D") {
    console.log("You passed!");
}
if (grade == "F") {
    console.log("You failed!");
}
else {
    console.log("Not a grade!");
}

// use a switch, more efficient:
switch (grade) {
    case "A": 
        console.log("You did great");
        break; // add a break after the code for a case is done
    case "B":
        console.log("You did good!");
        break;
    case "C":
        console.log("You did okay!");
        break;
    case "D":
        console.log("You passed!");
        break;
    case "F":
        console.log("You failed!");
        break;
    default: // default for no other matching clause
        console.log("Not a letter grade");
}

// can also check conditions
grade = 95;

switch (true) { // compare true against a bunch of conditions
    case grade >= 90: // compares this against true
        console.log("You did great");
        break; 
    case grade >= 80:
        console.log("You did good!");
        break;
    case grade >= 70:
        console.log("You did okay!");
        break;
    case grade >= 50:
        console.log("You passed!");
        break;
    case grade < 50:
        console.log("You failed!");
    default: // default for no other matching clause
        console.log("Not a letter grade");
}

// && (and), || (or) logical operators
let temp = 15;
if (30 > temp && temp > 0) {
    console.log("good temp");
} else {
    console.log("bad temp");
}

if (temp > 30 || 0 > temp) {
    console.log("bad temp");
}

// ! (not) operator

if (!(temp > 0)) {
    console.log("it's freezing");
}

// WHILE LOOP
username = "";
while (username == "" || username == null) { // repeatedly prompt users until they provide a username
    username = window.prompt("choose a username");
}

console.log("hello", username);

// DO WHILE LOOP
// do the loop body first, then check condition and repeat if met
// differs from regular while in that we do something BEFORE checking
username;

do {
    username = window.prompt("choose a username");
} while (username == "" || username == null)

console.log("hello", username);

// FOR LOOPS
// same as java 
for (let x = 1; x <= 10; x++) {
    console.log(x);
}
console.log(x); // can't access since we used let

// doing var instead of let makes the variable accessible outside of loop
for (var i = 1; i <= 10; i++) {
    console.log(i);
}

console.log(i); // we can access i since we used var

// BREAK AND CONTINUE
// break: break out of a loop entirely
// continue: skip a loop iteration

for (let i = 1; i <= 20; i++) {
    if (i == 13) {
        break; // exits loop
    }
    console.log(i);
}

for (let i = 1; i <= 20; i++) {
    if (i == 13) {
        continue; // skips iteration of when i == 13
    }
    console.log(i);
}

// FUNCTIONS

function happyBday(name) { // simple syntax, just say function before the name
    console.log("Happy Birthday", name);
}

happyBday("bro");

// RETURN STATEMENTS

function areaRect(width, height) {
    return width * height;
}
console.log(areaRect(10, 20));

// TERNARY OPERATOR
// shortcut for if-else stmt
// takes 3 operands
// 1. condition ?
// 2. expression if true
// 3. expression if false

// condition ? exprIfTrue : exprIfFalse

//if-else version:
let adult = checkAgeIfElse(21);
function checkAgeIfElse(age) {
    if (age >= 18) {
        return true;
    } else {
        return false;
    }
}

// ternary operator version (much cleaner)
adult = checkAgeTernaryOp(21); 
function checkAgeTernaryOp(age) {
    return age >= 18 ? true : false // condition is age >= 18
}

checkWinner(false);

// don't necessarily need return
function checkWinner(won) {
    won ? console.log("YOU WON!") : console.log("YOU LOST!");
}

// TEMPLATE LITERALS
// basically .f format string in python
// denoted by `
// allow for embedded variables and expressions

// consider this code
let userName = "Bro";
let items = 3;
let total = 75;

console.log("Hello", userName);
console.log("You have", items, "items in your cart");
console.log("Your total is $", total);

// template literal version
console.log(`Hello ${userName}`);
console.log(`You have ${items} in your cart`);
console.log(`Your total is $${total}`);

// can also stretch a template literal to multiple lines unlike strings
// each line break in the template literal is counded as a line break when logged
let text =
`Hello ${userName}
You have ${items} items in your cart
Your total is $${total}`
console.log(text);
// really useful for updating html element with several lines, eg:
text =
`Hello ${userName}<br>
You have ${items} items in your cart<br>
Your total is $${total}<br>`;
console.log(text); // we end up seeing <br> in the console log
// needed <br> for the HTML below

document.getElementById("p1").innerHTML = text; // change innerHTML of paragraph

// FORMATTING NUMBERS AS CURRENCY
// toLocaleString()
// number.toLocaleString(locale, {options});

// 'locale' = specify the language (passing in undefined uses the default language set by your browser)
// 'options' = object with formatting options

let myNum = 123456.789
myNum = myNum.toLocaleString("en-US"); // US english
console.log(myNum); // formats to 123,456.789

myNum = 123456.789
myNum = myNum.toLocaleString("hi-IN");  // hindi
console.log(myNum); // formats to 1,23,456.789

myNum = 123456.789
myNum = myNum.toLocaleString("de-DE");  // german
console.log(myNum);

//currencies

//USD
myNum = 123456.789
myNum = myNum.toLocaleString("en-US", {style: "currency", currency: "USD"});
console.log(myNum);
// rupees
myNum = 123456.789
myNum = myNum.toLocaleString("hi-IN", {style: "currency", currency: "INR"});
console.log(myNum);
// euros
myNum = 123456.789
myNum = myNum.toLocaleString("de-DE", {style: "currency", currency: "EUR"});
console.log(myNum);

// percentages
myNum = 0.5;
myNum = myNum.toLocaleString(undefined, {style: "percent"});
console.log(myNum); // formats it to 50%, 1 is 100%

// units
myNum = 100;
myNum = myNum.toLocaleString(undefined, {style: "unit", unit: "celsius"});

// ARRAYS
let arr = ["apple", "orange", "banana"];

arr.push("lemon"); // add element to end of array
arr.pop(); // remove element from end of array

// unshift and shift
arr.unshift("mango"); // add element to start of array
arr.shift(); // remove element from start of array

// LOOP THROUGH ARRAYS
arr = [5, 10, 15, 20];
// for loop
for (let i=0; i < arr.length; i++) {
    console.log(arr[i]);
}

// for-of loop, like a java for each loop, for (int i : arr) {}
for (let i of arr) {
    console.log(i);
}

// SORTING ARRAYS
let fruits = ["apple", "orange", "banana", "mango"];
fruits = fruits.sort(); // sort alphabetically (same as python)
for (let fruit of fruits) {
    console.log(fruit);
}

// for reverse sorting do:
fruits = fruits.sort().reverse();

// SPREAD OPERATOR
// expands out elements of iterables such as array or string
let numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9];
console.log(...numbers); // logs: 1 2 3 4 5 6 7 8 9

username = "six pop"
console.log(...username); // logs: s i x   p o p

// useful for calling max/min or arrays
console.log(Math.max(numbers)); // results in NaN because we cant use max([Array])
console.log(Math.max(...numbers)); // this works!

// can also use for merging arrays
let class1 = ["Spongebob", "Patrick", "Sandy"];
let class2 = ["Squidward", "Mr. Krabs", "Plankton"];
class1.push(class2); // this just creates a nested array! doesn't work
class1.pop();

class1.push(...class2); // same as class1.extend(class2) from python

// REST PARAMETERS
// represents an indefinite number of parameters
// packs arguments into an array

let a = 1;
let b = 2;
let c = 3;
let d = 4;
let e = 5;

console.log(sum(a, b));

function sum(a, b) { // not suitable for more than 2 arguments!
    return a + b
}

// solution: use rest parameters

function sumRest(...nums) { // we dont pass in one single nums array!
    let total = 0;
    for (let num of nums) {
        total += num;
    }
    return total;
}
// the arguments will automatically be packed into a nums array

// we can pass in any number of args since we did ...nums!
console.log(sumRest(a, b));
console.log(sumRest(a));
console.log(sumRest(a, b, c, d, e));

// we can also do something like:
function sumMix(x, y, ...nums) { // ie) minimum args is 2
    let total = x + y;
    for (let num of nums) {
        total += num;
    }
    return total;
}
// when doing this make sure that the rest parameter is always the last parameter

// CALLBACK
// a function passed as an argument to another function
// benefit: we can decide at runtime which function to call in a simple way

// useful example
let tot = newSum(2, 3);
displayConsole(tot);
displayDOM(tot);

function newSum(x, y) {
    let result = x + y;
    return result;
}

function displayConsole(output) {
    console.log(output);   
}

function displayDOM(output) {
    document.getElementById("p2").innerHTML = output;
}

// can write the above with a callback instead:
callbackSum(2, 3, displayConsole); // could easily swap for displayDOM

function callbackSum(x, y, f) {
    f(x + y);
}

function displayConsole(output) {
    console.log(output);   
}

function displayDOM(output) {
    document.getElementById("p2").innerHTML = output;
}

// FOR EACH: arr.forEach()
// we pass in a callback as an argument into forEach
let students = ["spongebob", "patrick", "squidward"];

// forEach() method automatically provides the three arguments below!
function capitalize(element,  index, array) {
    array[index] = element.charAt(0).toUpperCase() + element.slice(1); // capitalize each element in the array
} // could also use element.substring(1) here, as it behaves same as slice for positive indices.

// call the method on the array and pass in the callback function
console.log(students);
students.forEach(capitalize);
console.log(students);
// might seem strange but the forEach method automatically passes in the 3 args above into the given callback function.


// ARRAY.MAP() METHOD
// array.map() executes a provided callback function once for each array element
// and creates a NEW array

numbers = [1, 2, 3, 4, 5];
let squares = numbers.map(square);
console.log(squares);

function square(elem) { // note that map() also auto passes 3 same args (elem, index, arr)
    // we choose to only make use of elem here but we could also have used the other args
    return Math.pow(elem, 2);
}

// unlike array.forEach(), array.map() creates a new array and fills it with the return value of the callback function
// forEach(): mutates
// map(): creates new

// FILTER() METHOD
// array.filter() creates a new array with elements that pass a condition provided by a callback function

arr = [1, 2, 3, 4, 5, 6, 7, 8];
evens = arr.filter(isEven);

function isEven(elem) {
    return !Boolean(elem % 2);
}

console.log(evens);

// REDUCE() METHOD
// array.reduce(f) reduces an array to a single value. f is a callback.
// a good example of reduce() method is to sum up all the values of an array
let prices = [5, 10, 15, 20, 25];
let totalPrice = prices.reduce(checkOut);
console.log(totalPrice);

// reduce() automatically passes an accumalated value, and the current element
function checkOut(total, element) {
    return total + element;
}
// it is important to understasnd that the accumulated value reduce() passes in
// is just simply an accumulating sum of each callback return. it is nothing fancy.

// CUSTOM SORTING ARRAYS
// use array.sort(f) and pass in f as a callback function
let grades = [100, 50, 20, 90, 60, 80];
let descendingGrades = grades.sort(descendingSort);
console.log(descendingGrades);
let ascendingGrades = grades.sort(ascendingSort);
console.log(ascendingGrades);
// side remark: bc of aliasing, grades, descendingGrades, and ascendingGrades
// are all the same object! to get around this and have descGrades and ascGrades
// unchanging, just use slicing!

// sort() auto passes 2 args into the callback
// two values at a time. 
function ascendingSort(x, y) { // compares two values at a time
    return x - y; 
} // the smaller this return value is, 
// the smaller x is with respect to the other elements
// smaller return value means x should be come before y

function descendingSort(x, y) { 
    return y - x; // swapping x and y "tricks" the sort into seeing
}                 // the opposite comparison
// a smaller return value here means x should come after y
// makes sense

// FUNCTION EXPRESSION !!!! NEW IDEA
// a function expression is a function without a name
// known as an anonymous function.
// benefit: prevents us from polluting the global scope
// with a bunch of random function names
// ie; we can write the function then forget about it later
// assign a variable to some anon function

const greeting = function () {
    console.log("hello!");
} // this function can be forgot about if we reassign greeting

// in JavaScript, functions are "first-class citizens"
// this means they can be treated as reference type values like objects,
// for example, a function can be returned from another function!
// having function expressions allows us to capture some anonymous function in a variable.
// this enhances dynamic behaviour of code.
// we can conditionally define/build functions at runtime!

// CLOSURES !!! NEW IDEA
// a closure is created when a function is defined inside of another function,
// this allows the inner function to access outer function's variables
// even after the outer function has finished executing.
// eg:

function outer() {
    let outerVariable = "I am from outer";

    function inner() {
        console.log(outerVariable); // Accessing outerVariable from the closure
    }

    return inner;
}

let closureFunction = outer();
closureFunction(); // Outputs: "I am from outer"

// we see above that the inner function, assigned to closureFunction() has access to a variable
// in the scope of the outer() function, even though outer() has already finished executing.

// this "functions' retainment of access to the variables in their declared scope" creates a sort of encapsulation for data.
// this is useful for creating private variables (and maintaining state) across multiple function calls.

// Function expressions continued:

// old way of inc/dec button before using function expressions:
let count = 0;
document.getElementById("decreaseBtn").onclick = decreaseCount;
document.getElementById("increaseBtn").onclick = increaseCount;
// note, assign functions without (), or else we end up calling  them!

// we make two top level functions solely for the buttons
function increaseCount() {
    count += 1;
    document.getElementById("counterLabel").innerHTML = count;
}

function decreaseCount() {
    count -= 1;
    document.getElementById("counterLabel").innerHTML = count;
}


// new way with function exprs:
count = 0;
document.getElementById("decreaseBtn").onclick = function () {
    count -= 1;
    document.getElementById("counterLabel").innerHTML = count;
}
document.getElementById("increaseBtn").onclick = function () {
    count += 1;
    document.getElementById("counterLabel").innerHTML = count;
} // no need to create 2 new function names! we are preventing clutter in our code by not making top level functions that other things do not use!


// ARROW FUNCTION EXPRESSIONS !!! NEW IDEA
// =>
// compact alternative to regular functions (just a syntax thing)
// const myFunc = (args) => returnVal;
// eg)

const greeting2 = function (userName) {
    console.log(`hello ${userName}`);
}

greeting2("six");

// compact alternative to above function expression is:
const greeting3 = (userName) => console.log(`hello ${userName}`);
greeting3("six"); // note, no return value, just do a console log!

// another eg:
const percent = function(x, y) {
    return x / y * 100;
}

console.log(`${percent(75, 100)}%`);

// arrow function version:
const percent2 = (x, y) =>  x / y * 100;
// remove return statement

// important rmk: arrow functions are inherently anonymous.
// using a const variable makes their functionality basically identical to named functions
// but they're still just anonymous functions captured in variables.

// another eg)
// recall the sorting stuff from before
grades =  [100, 50 , 90, 80, 70];

// traditional function
grades.sort(descending);
function descending(x, y) {
    return y- x;
}
console.log(grades);

// now with function exprs
grades.sort(function(x, y) {
    return y-x;
});

// arrow functions
grades.sort((x,y) => y-x);

// MAPS
// key value pairs object
// need to use new for calling map constructor unlike arrays.
const store = new Map([
    ["t-shirt", 20], // subarrays within an array passed as an arg into Map()
    ["shorts", 15], // each subarray is a key value pair
    ["jeans", 30],
    ["socks", 5],
    ["underwear", 150],
]);

// Map.forEach(f) auto passes value, key args into the callback
store.forEach((value, key) => console.log(`${key} costs $${value}`));

// note that arrays could also be made using an Array() constrcutor

// both of these are same:
// let arr = [1, 2, 3];
// let arr = new Array(1, 2, 3);

// this is also same (Array constructor doesnt need new)
// let arr = Array(1, 2, 3); 
// note that map constructor needs new, ie; cannot do let mapo = Map([["yo", 1], ["bro", 32]]);

// get() method: Map.get(key)
console.log(store.get("underwear")); // logs 150

// set() method: Map.set(key, value);
store.set("hat", 1);
console.log(store);

// delete() method: Map.delete(key);
store.delete("underwear"); // NOOO
console.log(store);

// has() method: Map.has(key)
console.log(store.has("underwear")); // false now :(

// Map.size property
console.log(store.size);

// OBJECT ORIENT PROGRAMMING IN JS
// object is a group of properties and methods
// properties are values an object has
// methods are "object-specific functions", ie; stuff u can do with object
// use . to access properties and methods!

// how to make an object (NOT A CLASS):
const car = {
    // properties:
    model: "Mustang", // separate with commas!
    color: "black",
    year: "1995",

    // methods:
    drive : function () {
        console.log("vroom");
    }, // note we have to put commas after method braces as well!

    brake : function () {
        console.log("skiddd");
    }
}
// this created an object and stored it in car variable!
// object has no class. it just a single object referenced in car variable

console.log(car);
// logging it shows:
// {model: 'Mustang', color: 'black', year: '1995', drive:f, brake:f}

// access properties
console.log(car.year);

//call methods
car.drive();
car.brake();

// "THIS" KEYWORD
// used to  refer to a particular object; depends on the immediate context


// two objects!
const car1 = {
    model: "Mustang",
    color: "black",
    year: "1995",

    drive : function () {
        console.log(`you drive ${this.model}`);
    }, 

    brake : function () {
        console.log("skiddd");
    },

    thisTest : function () {
        console.log(this);
    }
}

const car2 = {
    model: "mini cooper",
    color: "lime",
    year: "2001",

    drive : function () {
        console.log(`you drive ${this.model}`); // refer to property with this.property!
    }, 

    brake : function () {
        console.log("skdd");
    }
}

car1.drive();
car2.drive();

// this depends on the context
// within an object, the context is the object itself
car1.thisTest();
// logs the object, same as if we did console.log(car1);

// outside of any objects, our context is a Window object!
console.log(this);
// {window: Window, self: Window, document: document, name: '', location: Location, …}
// we can use this to edit window properties! eg)
// this.name = "cool";

// CLASSES
// class is a blueprint for creating objects!
// typically have constructors (we will get to this later)
// similiar concepts to java

class Player {
    // properties
    score = 0;

    // methods
    pause() {
        console.log("you paused");
    }
    exit() {
        console.log("you exited");
    }
}

// must use new keyword to create a new object instance of a class
const player1 = new Player();
const player2 = new Player();

// CONSTRUCTORS
// special method to accept arguments and assign properties
// constructor()
class Student {
    constructor(name, age, gpa) {
        this.name = name;
        this.age = age;
        this.gpa = gpa;
    }
    
    study() {
        console.log(`${this.name} is studying!`);
    }
}

const stud1 = new Student("spongebob", 19, 4.0);
console.log(stud1.gpa);

// STATIC KEYWORD
// static method and properties belong to entire class and not any specific objects 

class Car {
    // use static keyword
    static numOfCars = 0;

    constructor(model) {
        this.model = model;
        Car.numOfCars ++; // refer to it using Class.property, not this.property,
        // that is, Car.numOfCars and not this.numOfCars
    }

    // static method, same idea
    static startRace() {
        console.log("3.. 2.. 1.. GO!");
    }
}

car1 = new Car("honda");
car2 = new Car("ferrari");
let car3 = new Car("toyota");
let car4 = new Car("nissan");

// access the static variable directly from class
// cannot invoke it from a specific instance
console.log(Car.numOfCars);

// call static method directly from class
// cannot invoke it from a specific instance
Car.startRace();

// INHERITANCE
// child classes and parent classes

class Rabbit {
    alive = true;
    name = "rabbit";

    eat() {
        console.log(`${this.name} is eating`);
    }
    sleep() {
        console.log(`${this.name} is sleeping`);
    }
    run() {
        console.log(`${this.name} is running`);
    }
}
class Fish {
    alive = true;
    name = "rabbit";

    eat() {
        console.log(`${this.name} is eating`);
    }
    sleep() {
        console.log(`${this.name} is sleeping`);
    }
    swim() {
        console.log(`${this.name} is swimming`);
    }
}
class Hawk {
    alive = true;
    name = "rabbit";

    eat() {
        console.log(`${this.name} is eating`);
    }
    sleep() {
        console.log(`${this.name} is sleeping`);
    }
    fly() {
        console.log(`${this.name} is flying`);
    }
}

// factor out all these classes from a parent class Animal

class Animal {
    alive = true;

    eat() {
        console.log(`${this.name} is eating`);
    }
    sleep() {
        console.log(`${this.name} is sleeping`);
    }
}

class goodRabbit extends Animal {
    name = "rabbit";

    run() {
        console.log`${this.name} is running`;
    }
}
class goodFish extends Animal {
    name = "fish";

    swim() {
        console.log`${this.name} is swimming`;
    }
}
class goodHawk extends Animal {
    name = "hawk";

    fly() {
        console.log`${this.name} is flying`;
    }
}

const rabbit = new goodRabbit();
const fish = new goodFish();
const hawk = new goodHawk();

console.log(rabbit.alive);
console.log(rabbit.eat());
console.log(fish.sleep());
// same as python, java, etc.

// SUPER() CONSTRUCTOR
// refers to parent class when using inheritance
// commonly used to invoke parent class' constructor

class Animal {
    constructor(name, age) {
        this.name = name;
        this.age = age;
    }
}



class Rabbit extends Animal {
    constructor(name, age, runSpeed) {
        super(name, age); // must call super() constructor! same as java
        this.runSpeed = runSpeed;
    }
}
class Fish extends Animal {
    constructor(name, age, swimSpeed) {
        super(name, age);
        this.swimSpeed = swimSpeed;
    }
}
class Hawk extends Animal {
    constructor(name, age, flySpeed) {
        super(name, age);
        this.flySpeed = flySpeed;
    }
}
// if we dont call the super method to invoke the parent's constructor we end up getting an error!
// must call super constructor in child class before accessing 'this'

// GETTERS & SETTERS
// get binds an object property to a function when that property is accessed

// format is 
// get property() {return stuff}
// where property is NOT the EXACT name of the property to get!!
// common convention is to have the actual property name preceded with an underscore, denoting that it is private
// eg;

class Car {
    constructor(power) {
        this._power = power; // underscored property _power !
        this._gas = 25;
    }

    get power() { // method name is not _power() but rather power() !
        return `${this._power} hp`;
    }
    get gas() { // method name is not _power() but rather power() !
        return `${this._gas} L`;
    }
} // suppose our property's name was also power (no underscore), then we would run into an error
// this is because as i said before, the getter method must have a different name from the property we are getting!

let car10 = new Car(400);
// getters help us with getting a property in a desired format or representation, like how we added hp

console.log(car10.power); // note we just type object.power as if it is a property! we do not do object.power() unlike java.
// note that power does not have a setter hence it is not writeable
// eg:
car10.power = 500; // this does nothing 
// we could do this however,
car10._power = 500; // but clients swear a pledge to not do this, (pls don't!!!)

// setters
// binds an object property to a method

class Car {
    constructor(power) {
        this._power = power; 
        this._gas = 25;
    }

    get power() { 
        return `${this._power}hp`;
    }
    get gas() { 
        return `${this._gas}L (${this._gas / 50 * 100}%)`;
    }

    // note setters must have EXACTLY one parameter
    set gas(value) {
        if (value > 50) {
            value = 50;
        } else if (value < 0) {
            value = 0;
        }
        this._gas = value;
    }
}

let car11 = new Car(500);
console.log(car11.gas);

car11.gas = 40;
console.log(car11.gas);

car11.gas = 100;
console.log(car11.gas);

car11.gas = -30;
console.log(car11.gas);

// might seem a bit odd since we are essentially considering property manipulation as direct setting and getting
// as opposed to java or python where we would explicitly use object.setProperty().
// just get used to it!

// ANONYMOUS OBJECTS
// simple
// objects that dont have a name and are not directly referenced.
// pros: less syntax, no need for unique names
// cons: do not have direct access

class Card {
    constructor(value, suit) {
        this.value = value;
        this.suit = suit;
    }
}

// normal way
let card1 = new Card("A", "Hearts");
let card2 = new Card("A", "Spades");
let card3 = new Card("A", "Diamonds");
let card4 = new Card("A", "Clubs");
let card5 = new Card("2", "Hearts");
let card6 = new Card("2", "Spades");
let card7 = new Card("2", "Diamonds");
let card8 = new Card("2", "Clubs");

let cards = [card1, card2, card3, card4, card5, card6, card7, card8];

console.log(cards[0].value, cards[0].suit);

// no need to create 8 unique names!! hint: we are storing them in an array 

// anonymous version:
let cards2 = [
new Card("A", "Hearts"),
new Card("A", "Spades"),
new Card("A", "Diamonds"),
new Card("A", "Clubs"),
new Card("2", "Hearts"),
new Card("2", "Spades"),
new Card("2", "Diamonds"),
new Card("2", "Clubs")]

// simple
console.log(cards[0].value, cards[0].suit);

// ERROR HANDLING
// errors themselves are objects as well!
// they are objects awith a description of something that went wrong

// eg:
// cant open a file
// lost connection
// user types incorrect input
// TypeError

// same as java

// use try and catch block!

try {
    console.lag();
} catch(error) {
    console.log(error);
}

// sometimes stuff goes wrong but generates no error

try {
    let x = window.prompt("enter a number");
    x = Number(x); // wont catch this if we put in something like "Pizza"

    if (isNaN(x)) throw "That wasn't a number!";
    if (x == "") throw "That was empty!";


    console.log(`${x} is a number!`);
} 

catch(error) {
    console.log(error);
}

finally { // this block always executes at the end of try-catch stuff
    console.log("this always executes");
}
// useful for stuff like closing files at the end

// SETTIMEOUT() FUNCTION
// setTimeout(f, t) invokes a callback f and t milliseconds
// doesn't pause the execution of the code! it is asynchronous

let timer1 = setTimeout(firstMsg, 4000); // returns an ID
let timer2 = setTimeout(secondMsg, 2000);
let timer3 = setTimeout(thirdMsg, 6000);

function firstMsg() {
    alert(`BUY A CHOCOLATE BAR FOR $10,000`);
}
function secondMsg() {
    alert(`pls NO scam`);
}
function thirdMsg() {
    alert(`WHY DID U REDEEM IT`);
}

// to cancel our clear setTimeout() we can use clearTimeout()
// linking to a button in html doc
document.getElementById("BUYcourse").onclick = function () {
    clearTimeout(timer1);
    clearTimeout(timer2);
    clearTimeout(timer3);
    alert("thx for buying <33")
}

// you can pass args into the callback through setTimeout(f, t, ...args) by listing those args after the t.
item = "chocolat";
price = 10000;

timer1 = setTimeout(firstMsg, 4000, item, price); // returns an ID
timer2 = setTimeout(secondMsg, 2000);
timer3 = setTimeout(thirdMsg, 6000);

function firstMsg(item, price) {
    alert(`BUY A ${item} BAR FOR $${price}`);
}
function secondMsg() {
    alert(`pls NO scam`);
}
function thirdMsg() {
    alert(`WHY DID U REDEEM IT`);
}

document.getElementById("BUYcourse").onclick = function () {
    clearTimeout(timer1);
    clearTimeout(timer2);
    clearTimeout(timer3);
    alert("thx for buying <33")
}

// SETINTERVAL() FUNCTION
// setInterval() invokes a function repeatedly after a given amount of time
// asychornous; doesn't pause execution of code

c = 0;
let max = window.prompt("count up to.. ?");
max = Number(max);

const mytimer = setInterval(countUp, 1000);

function countUp() {
    c ++;
    console.log(c);

    if (c  >= max) {
        clearInterval(mytimer);
    }
}


// DATE OBJECTS

let date = new Date();
date = date.toLocaleString(); // makes it more readible and compact

document.getElementById("dateLab").innerHTML = date;

// passing in an argument into the Date() constructor gives the date
// from epoch time + milliseconds as the argument.

date = new Date(0);
date = date.toLocaleString();
document.getElementById("dateLab").innerHTML = date;
// gives epoch time: 12/31/1969, 7:00:00 PM

date = new Date(1000); // 1 second past epoch time
date = date.toLocaleString();
document.getElementById("dateLab").innerHTML = date;

// can also pass other args (there are several constructors)
date = new Date(2023, 0, 1, 2, 3, 4, 5); 
// (year, month - 1, day, hour, minute, second, ms)
date = date.toLocaleString();
document.getElementById("dateLab").innerHTML = date;

// also string argument
date = new Date("January 1, 2023, 00:00:00"); 

// some get methods
console.log(date.getFullYear()); // returns the year
console.log(date.getDate()); // returns the day
console.log(date.getMonth()); // returns month - 1
// also corresponding set methods

date = date.toLocaleString();
document.getElementById("dateLab").innerHTML = date;

// formatting date and time
// useful
function formatDate(date) {
    let year = date.getFullYear();
    let month = date.getMonth() + 1; // remember .getMonth() returns month - 1
    let day = date.getDate();

    return `${month}/${day}/${year}`
}

date = new Date();
document.getElementById("dateLab").innerHTML = formatDate(date);

// ASYNCHRONOUS VS SYNCHRONOUS CODE

// synch: in  ordered sequence
// step by step linear instructions
// most code

// asynch: out of sequence
// start now, finish sometime later
// eg) accessing database

// synch example:
console.log("START");
console.log("synchronous step");
console.log("END");

// asynch example:
console.log("START");
setTimeout( () => console.log("asynchronous step"), 5000);
console.log("END");

// console.time() method
// start a timer you can use to track how each long an operation takes

//start
console.time("response time");

alert("CLICK OK");
setTimeout(() => console.log("hello"), 10000);

// end
console.timeEnd("response time"); // prints time elapsed

// of course, we don't wait for asynch code (it's asynchronous! we skip ahead)

// PROMISES !!! NEW IDEA
// promises are objects that encapsulate the result of an asynchrnous operation
// this enables asynchronous methods to return values like synchronous methods
// "i promise to return something in the future"

// within promise constructor, we put a callback, arrow function, or function expression
// loading a file is an asynchronous process

// promises have a STATE.
// the state is first 'pending', then it can either be 'fulfilled' or 'rejected'.
// the return value is known as the RESULT

// reject and resolve are functions associated with Promise object.
// resolve() is used to fulfill a promise with a resolved  value

// promises have 2 parts: producing and consuming:

// producing part:
const promise = new Promise((resolve, reject) => {
    // asynch code goes here
    let fileLoaded = true; // assume we invoked a file load asynchronously here
    
    if(fileLoaded) {
        resolve("file loaded"); // consuming code handles this!
    } else {
        reject("file not loaded");
    }
});


// the resolved value can be accessed through the .then() method when the promise is resolved
// Promise.then(f), "if our promise is resolved, then we do this"
promise.then(value => console.log(value))
       .catch(error => console.log(error));

// we must catch any reject() calls using promise.catch();
// we can just trail it like this, promise.then().catch();

// we don't even need a reject(), we can make promises without them
// we can make a promise without a reject!
const promise2 = new Promise(resolve => {
    // asynch code goes here
    setTimeout(resolve, 5000);
});

promise2.then(() => console.log("thanks for waiting!"));

// we can also create a function to return promises based on given args
const wait = time => new Promise(resolve => { // wait is now a FUNCTION that RETURNS a promise object
    // asynch code goes here
    setTimeout(resolve, time);
});

wait(4000).then(() => console.log("thanks for waiting!"));

// p = new Promise(f)
// f(resolve, reject) {good: resolve(), bad: reject()}
// p.then(g).catch(h)
// g(args) {code if resolved}
// h(args) {code if rejeceted}

// ASYNC KEYWORD
// async makes a function return a promise

const promis = new Promise((resolve, reject) => {
    let fileLoaded = true;

    if (fileLoaded) {
        resolve("file was loaded"); // returns this value as resolved
    } else {
        reject("file was not loaded"); // throws this value as reason for an error
    }
});

promis.then(val => console.log(val))
      .catch(err => console.log(err));


// easier way of writing the arrow function argument f in new Promise(f), is to write an async function!
async function loadFile() {
    let fileLoaded = true;

    if (fileLoaded) {
        return "file was loaded"; // returns this value as resolved
    } else {
        throw "file was not loaded"; // throws this value as reason for an error
    }
}


// then we simply don't need to make a promise object
// since we put the async keyword on loadFile(), it returns a promise
// a return value would be considered the resolved value.
// and a thrown error would be considered the reject error.

loadFile().then(val => console.log(val))
     .catch(err => console.log(err));
    

// AWAIT KEYWORD
// await makes an async function wait for a Promise

async function loadFile() {
    let fileLoaded = true;

    if (fileLoaded) {
        return "file was loaded";
    } else {
        throw "file was not loaded"; 
    }
}

// alternative to writing these two lines of code is using await
loadFile().then(val => console.log(val))
     .catch(err => console.log(err));
    
// using await:
let msg = await loadFile();
console.log(msg);
// this gives an error because we need to place it within another async function
// so we can do this:
async function startProcess() {
    let msg = await loadFile();
    console.log(msg);    
}

startProcess();

// we should have a try-catch block within startProcess for handling the thrown error
// at this point it seems cumbersome to do it with await but perhaps preferable over doing it with .then() and .catch() somehow.
// ANSWER: the point of doing it like this is useful if we are waiting for more than one asynchronous function
// we can have several async function results factored out into one single async function
async function loadFile() {
    let fileLoaded = false;

    if (fileLoaded) {
        return "file was loaded";
    } else {
        throw "file was not loaded"; 
    }
}
    
async function startProcess() {
    try {
        let msg = await loadFile();
        console.log(msg);    
    } catch (error) {
        console.log(error);
    }
}

startProcess();

// ES6 MODULES
// a module is a file of reusable code we can import.
// great for general utility values and functions.
// helps to make our code more reusable and maintainable.
// modules are like separate chapters of a book.

// in your HTML make sure to put type="module" for your script

// for everything u want to be exportable in some file, preceed it with export
// see modules/math_util.js for example!

// you can import stuff like this:
import {PI, getCircumference, getArea} from "./modules/math_util.js"
// do import{methods/vars/classes} from "path"

console.log(PI);

// instead of doing individual imports, we can import * as Nickname:

// nickname should be descriptive, we can choose anything
import * as MathUtil from "./modules/math_util.js"
// do import{methods/vars/classes} from "path"

console.log(MathUtil.PI);
// must preceed all stuff with nickname.

// DOM!!!
// Document Object Model (API)
// an interface used to change content of page

// our DOM is a hierarchical representation of an HTML document:
// =============================================================
    // document
        // html (root element)
            // head (element)
                // title (element)
                    // (text) "my title"
            // body (element)
                // h1 (element)
                    // (text) "a heading"
                // a (element) -> attribute: href
                    // (text) "link text"
// =============================================================

// document is the entry point of our DOM
console.dir(document); // dir(document) displays all the properties of the dom
document.body.style.backgroundColor = "skyblue";
// change background color!

// ways to select elements in a webpage!! 

// by ID
let elem = document.getElementById("menuTitle");
elem.style.backgroundColor = "lightgreen";

// by NAME (several elements)
cards = document.getElementsByName("card");
// creates a node list of all the buttons, like an array

setInterval(checkSelected, 2000);

function checkSelected() {
    // go through cards list (list of radio buttons)
    // and print the id of a checked radio button
    cards.forEach(card => {
        if (card.checked) {
            console.log(card.id);
        }
    })
}


// by TAGNAME
let veggies = document.getElementsByTagName("li");
// returns an HTML collection which behaves similarly to an array

veggies[1].style.backgroundColor = "lightgreen";

// by CLASSNAME
let deserts = document.getElementsByClassName("deserts");
// returns an array-like object

deserts[0].style.backgroundColor = "lightgreen";

// QUERY SELECTORS
// a popular way to select elements
// we can select element by an ID, classname, tag, or an attribute

let element = document.querySelector("#menuTitle"); // ID example
element.style.backgroundColor = "lightgreen";

element = document.querySelector(".deserts"); // class example
element.style.backgroundColor = "lightgreen";
// only selects the first element if there are several with same class

element = document.querySelector("li"); // tag example
element.style.backgroundColor = "lightgreen";
// only selects the first element if there are several with same tag

element = document.querySelector("[for]"); // attribute example
element.style.backgroundColor = "lightgreen";
// only selects the first element if there are several with same attribute

// to select all elements, we can use querySelectorAll

let elems = document.querySelectorAll("li");
// returns an array like object

elems.forEach(elem => {
    elem.style.backgroundColor = "lightblue";
})

// DOM TRAVERSAL TECHNIQUES
let element = document.body;
// we can traverse elements in body like so:
let firstChild = element.firstElementChild; // gets first child
firstChild.style.backgroundColor = "lightgreen";


let lastChild = element.lastElementChild; // gets last child
lastChild.style.backgroundColor = "lightgreen";
console.log(lastChild);
// ended up selecting script since its the last child of the body {}


let element = document.querySelector("#veg");

// parent
parent = element.parentElement;
console.log(parent); // selects body

// sibling
let sibling = element.nextElementSibling; // can also do previousElementSibling from last one
sibling.style.backgroundColor = "lightgreen";

let element = document.querySelector("#veg");

let parent = element.parentElement;
console.log(parent); // selects body

let sibling = element.nextElementSibling;
sibling.style.backgroundColor = "lightgreen";


// we can also access children of an element using .children which is an array like property

let child = element.children[1];
child.style.backgroundColor = "lightgreen";

// to select all children we do this:
let childrenn = Array.from(element.children); // we convert the array-like object into an array so we can use forEach on it.

childrenn.forEach(child => {
    child.style.backgroundColor = "lightgreen";
})


// ADDING/CHANGING HTML ELEMENTS
// creating a new element tag
const nameTag = document.createElement("h2");

// two ways to change html element
// 1) .innerHTML (vulnerable to XSS attacks)
// 2) .textContent (more secure)

nameTag.textContent = "YOSKIES";
document.body.append(nameTag);

// issue with using innerHTML: by altering innerHTML, it is possible to run a script!
// in other words, if users can alter innerHTML then they can run scripts on your website.
// this is done by also assigning tags along with some text.

// textContent cannot do this and only display everything as text
// anything given as textContent is only parsed as text.


// let us try adding something to an HTML list

const myList = document.getElementById("fruit");
const listItem = document.createElement("li");
listItem.textContent = "mango";

// myList.append(listItem);
// myList.prepend(listItem); // to put at start of list

// to put at a specific spot we must do this:
myList.insertBefore(listItem, myList.getElementsByTagName("li")[2]);
// the index [2] is the index in the list where we want it

// ADDING/CHANGING CSS PROPERTIES
const title = document.getElementById("helloworld");

title.style.backgroundColor = "lightgreen";
// we say element.style.property = value;


// EVENTS !!!
// events are user interactions etc.
// for instance, onclick event

// we can have the HTML code reference the functions here
function doSomething() {
    alert("you did something !")
}

// or we can directly set events here as well
document.getElementById("myButt").onclick = function () {
    alert("you clicked the BUTTON!")
}
// another event is onload; does the function when website loads in

// another is onchange; does when the element has been changed
document.getElementById("nameText").onchange = function () {
    alert("YO!");
}

let myDiv = document.getElementById("div1");

myDiv.onmouseover = function () {
    myDiv.style.backgroundColor = "lightgreen";
}

myDiv.onmouseleave = function () {
    myDiv.style.backgroundColor = "lightblue";
}

// ADDEVENTLISTENER
// .addEventListener(event, function, useCapture)
// one element can have several event listeners
// element.addEventListener(event, function, useCapture)

// benefit of using addEventListener is that we can wait for multiple events

innerDiv.addEventListener("click", function () {
    changeBlue(innerDiv);
});

outerDiv.addEventListener("click", function () {
    changeBlue(outerDiv);
}, true);

function changeBlue(element) {
    alert(`you selected ${element.id}`)
    element.style.backgroundColor = "lightblue";
}
// since innerDiv is nested within outerDiv, the clicks will overlap when clicking innerDiv
// the question is, which one do we want to be triggered first? both together, or only one? 
// using alerts we see that by default the inner happens first

// passing in true for the third argument into addEventListener, useCapture, will make this event happen first
// so we can pass in true for outerDiv's event listener!

outerDiv.addEventListener("click", function () {
    changeBlue(outerDiv);
}, true); // we pass in true as the third arg!
// now outerDiv's event happens first (can see this with the alerts)

// so we can use useCapture argument if two elements are taking the same space and listening for the same event (eg; a click), we can specify which one  has preference.


// SHOWING AND HIDING HTML ELEMENTS
const butoon = document.querySelector("#myButt");
const carPic = document.querySelector("#carPicture");

butoon.addEventListener("click", function () {
    carPic.classList.toggle("hidden");
});

// we do element.classList.toggle("hidden")
// where .hidden is a class made in style.css which has display: none;

// setting display: none; shifts all the elements below upwards.
// if we don't want this, we can just set visibility hidden.

// display: block vs none (shifts elements up)
// visibility: visible vs hidden (doesnt shift elements up)


// DETECT KEY PRESSES
// to do this we can add an event listener to our window
window.addEventListener("keydown", event => {console.log(event.key)});

// div1 position is set to relative
const div1 = document.querySelector("#div1");
window.addEventListener("keydown", move);

x = 0; 
y = 0;

function move(event) {

    switch(event.key) {
        case "s":
            y += 15;
            div1.style.top = y + "px"; // style.top for vertical position
            break;
        case "w":
            y -= 15;
            div1.style.top = y + "px";
            break;
        case "d":
            x += 15;
            div1.style.left = x + "px"; // style.left for horizontal position
            break;
        case "a":
            x -= 15;
            div1.style.left = x + "px";
            break;
        default:
            break;
    }
}

// now if we want an even better way to move the div around, such that we can do diagonal movement as well
// then we should keep track of all keys being pressed and have parallel cases for each!
x = 0;
y = 0;

// keep track of all keys being pressed
const keys = { // object!! we can use objects like dictionaries
    "w": false,
    "a": false,
    "s": false,
    "d": false,
};

window.addEventListener("keydown", event => {
    keys[event.key] = true;
    move();
});

window.addEventListener("keyup", event => {
    keys[event.key] = false;
    move();
});



function move() {
    
    function updatePos() {
        div1.style.top = y + "px";
        div1.style.left = x + "px";
    }

    if (keys["w"]) {
        y -= 15;
    }

    if (keys["a"]) {
        x -= 15;
    }

    if (keys["s"]) {
        y += 15;
    }

    if (keys["d"]) {
        x += 15;
    }

    updatePos(); 
}


// ANIMATIONS !!!

// element sliding animation:
// we want to begin an animation when we click the button
const myButt = document.querySelector("#beginButt");
const myAnimation = document.querySelector("#div1");

myButt.addEventListener("click", begin);

function begin() {
    let timerID = null;
    let x = 0;
    let y = 0;

    timerID = setInterval(frame, 5);
    // repeatedly invoke frame() every 5 ms

    function frame() {
        if (x >= 200) {
            clearInterval(timerID);
            // stop animation when x reaches a position of 200px
        } else {
            x += 1;
            myAnimation.style.left = x + "px";
        }
    }
}

// rotation animation:

function begin() {
    let timerID = null;
    let degrees = 0;

    timerID = setInterval(frame, 5);
    // repeatedly invoke frame() every 5 ms

    function frame() {
        if (degrees >= 360) {
            clearInterval(timerID);
        } else {
            degrees ++;
            myAnimation.style.transform = "rotateZ("+degrees+"deg)";
            // can change this to X or Y to rotate on those axis (Z is out of page)
        }
    }
}

// rotate and move diagonally:
function begin() {
    let timerID = null;
    let degrees = 0;
    let x = 0;
    let y = 0;

    timerID = setInterval(frame, 5);
    // repeatedly invoke frame() every 5 ms

    function frame() {
        if (degrees >= 360 && x >= 200) { // goes until both conditions are met!
            clearInterval(timerID);
        } else {
            degrees += 2;
            x += 2;
            y += 2;
            myAnimation.style.top = y + "px";
            myAnimation.style.left = x + "px";
            myAnimation.style.transform = "rotateZ("+degrees+"deg)";        }
    }
}

// scaling image
function begin() {
    let timerID = null;
    let scaleX = 1;
    let scaleY = 1;
    
    timerID = setInterval(frame, 5);
    // repeatedly invoke frame() every 5 ms

    function frame() {
        if (scaleX >= 2) {
            clearInterval(timerID);
        } else {
            scaleX += 0.01;
            scaleY += 0.01;
            myAnimation.style.transform = "scale("+scaleX+","+scaleY+")";
            // the transform strings are weird, dont need to memorize all of them!
        }
    }
}


// Canvas API = a means for drawing graphics
// used for animations, games, and data visualization

// make a canvas element in our HTML document
let canvas = document.querySelector("#myCanvas");
let context = canvas.getContext("2d");
// context is the "painting" inside the canvas

// to draw on the canvas, we need to draw on the context, not the canvas itself

// drawing lines on canvas
context.strokeStyle = "red";
context.lineWidth = 2;
context.beginPath();
context.moveTo(0, 0);  // we place our "brush" on the canvas at our starting position
context.lineTo(250, 250); // one line to the center from our moveTo position
context.lineTo(250, 500); // one line from our last position to the bottom

context.moveTo(500, 0); // change our starting position
context.lineTo(250, 250); // change our starting position
context.stroke(); // finish it by doing stroke

// drawing traingle
context.strokeStyle = "green";
context.lineWidth = 2;
context.fillStyle = "red";
context.beginPath();
context.moveTo(250, 0);
context.lineTo(0, 250);
context.lineTo(500, 250);
context.lineTo(250, 0);
// instead of doing context.stroke(), we can do context.fill() to fill the triangle
context.fill();
context.stroke(); // add this for an outline as well

// drawing rectangle
context.strokeStyle = "black";
context.lineWidth = 3;
context.fillStyle = "red";
// .strokeRect(x, y, w, h)
context.strokeRect(0, 0, 250, 250) // very fast!
context.fillRect(0, 0, 250, 250) // very fast!

// drawing circle
// context.arc(x, y, r, sAngle, eAngle, ccw)
// starting angle and ending angle are in radians
// for full circle we go from 0 to 2PI
context.beginPath();
context.arc(250, 250, 150, 0, 2 * Math.PI);
context.stroke();

// drawing text
context.font = "50px MV Boli";
context.fillStyle = "red";
context.textAlign = "center";
context.fillText("YOU WIN!", canvas.width / 2, canvas.height / 2);


// WINDOW OBJECT
// window is an interface used to talk to the web browser
// the DOM is a property of the window

console.dir(window);
// document is a property of window
console.log(window.innerHeight);
console.log(window.innerWidth);

// there is also scroll values
console.log(window.scrollX);
console.log(window.scrollY);

// we can also change href value of website which is found within location

console.log(window.location);

// window.location.href = "https://www.youtube.com";
// our site will take us to youtube with the above uncommented

myButt = document.querySelector("#beginButt");

// useful methods:
// window.open("link") opens a new tab of link
// window.close() closes the site's tab 
myButt.addEventListener("click", () => window.open("https://www.youtube.com"));

// window.print() pops up print page menu
myButt.addEventListener("click", () => window.print());

// window.alert() displays a popup messasge
window.alert("hello!");

// window.confirm() displays a popup confirmation
window.confirm("press ok to continue");

// window.prompt() takes in some user input
let aage = window.prompt("enter your age");


// COOKIES
// a cookie is a small text file which is stored on your computer
// it is used to rememebr information about the user
// it's saved in name=value pairs

// to see if we have coookies enabled, you can type the following:

console.log(navigator.cookieEnabled);
// returns true or false

// adding cookies
document.cookie = "firstName=Sponge; expires=Sun, 1 January 2030 120:00:00 UTC; path=/";
// we can store some firstName value, as well as an expiry date and a path.
// the path specifies the URL path for which the cookie is valid

document.cookie = "lastName=SquarePants; expires=Sun, 1 January 2030 120:00:00 UTC; path=/";
// this does not override previous firstName value.
// it is kind of weird, but cookie is an objection that stores all these values
// and setting cookie = something doesnt change its value, it just adds new value property


// logging document.cookie will show all the values in the cookie object
// so it will show both firstName and lastName
console.log(document.cookie);

// to override an existing cookie, just pass in the same value, eg:
document.cookie = "lastName=SquareShorts; expires=Sun, 1 January 2030 120:00:00 UTC; path=/";
console.log(document.cookie);
// lastName value got changed

// setting a cookie's expiration date to a day that has already passed will delete the cookie

// function to make cookies

function setCookie(name, value, daysTillExpire) {
    const date = new Date();
    date.setTime(date.getTime() + daysTillExpire * 24 * 60 * 60 * 1000);
    // convert days to expire into ms (24)(60)(60)(1000)

    let expires = "expires=" + date.toUTCString();

    document.cookie = `${name}=${value}; ${expires}; path=/`;
}

setCookie("email", "bro@gmail.com", 5);
console.log(document.cookie);

// function for deleting cookies

function deleteCookie(name) {
    setCookie(name, null, null);
}

deleteCookie("lastName");

function getCookie(name) {
    const cDecoded = decodeURIComponent(document.cookie);
    // returns all of the cookies as a string

    // split each cookie into an array
    const cArray = cDecoded.split("; ");
    console.log(cArray);

    cArray.forEach(elem => {
        // for every element in the array, split it into two parts, name and value
        nv = elem.split("=");

        if (nv[0] == name){ // first index of nv contains the name
            console.log(nv[1]); // second index contains value
        }
    });
}

getCookie("email");

// another version of the getCookie method, returns instead of logging
function getCookie(name) {
    const cDecoded = decodeURIComponent(document.cookie);

    const cArray = cDecoded.split("; ");


    // recall forEach loop vs for-of loop!
    // forEach loop cannot break out of loop and return a value,
    // hence we use a for-of loop. for-of loops are lie for (elem : array) loops in java or for x in array loops in python.
    for (elem of cArray) {
        nv = elem.split("=");

        if (nv[0] == name){ 
            return nv[1]; 
        }
    }
    return "no such cookie";
}

console.log(getCookie("email"));
console.log(getCookie("bars"));
