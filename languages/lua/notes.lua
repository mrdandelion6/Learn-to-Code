function Main()
	-- call the function you would like to run here to see any outputs.
	-- RUN
	Loops_and_conditionals()
end

function Contents()
	What_is_lua()
	Variables()
	Printing()
	Data_types()
	Lua_tables()
	Loops_and_conditionals()
	Lua_for_vim()
end

function What_is_lua()
	-- lua is is an interpreted, lightweight, high-level programming language.
	-- it was created two main principles in mind:
	-- 1. simplicity
	-- 2. embeddability

	-- lua is primarily used for the following things:
	-- 1. game dev
	--	lua is extremely popular for game dev. it is used for scripting in WoW, roblox, and gmod. game devs often embed lua to allow modding and to handle game logic without recompiling the main engine.
	-- 2. embedded systems
	--	due to its small and efficient design, lua is frequently used in embedded systems and IoT devices where resources are limited
	-- 3. configuration
	--	many applications use lua as a configuration language because of its clear syntax and ability to handle complex configurations in an elegant way. for example, neovim.
	-- 4. application scripting
	--	software like adobe lightroom and neovim use lua for extensibility and plugin development.

	-- in these notes we are using lua 5.4
end

function Lua_Compilation()
	-- lua is an interpreted language but it still does get compiled.
	-- similar to java, lua gets compiled into bytecode and then interpreted on a virtual machine
	-- lua's bytecode is read by the lua virtual machine (LVM)
	--
	-- however, lua is much different than java! it is still considered an interpreted language because it's compilation is not discrete
	-- lua's bytecode only stays in memory and does not actually get saved to disk like an java or c executable.
	-- lua is also dynamically typed.
	-- the LVM is also very small, only about 100KB.
	--
	-- to run lua, you need to install the lua interpreter binary. to begin with, install lua5.4 on your system.
	-- for example, on ubutu you do `sudo apt install lua5.4`.
	--
	-- run this code by setting Lua_Compilation() as the function being called at the top under "-- RUN".
	-- you must do: `lua notes.lua` to compile and run the code.
	print("you ran lua code!")

	-- note that the lua binary contains both the lua compiler and lua interpreter.
	-- so here is the full process for running lua code:
	--	1. call `lua source_code.lua`
	--	2. the source code is loaded
	--	3. source code gets compiled to bytecode in memory
	--	4. LVM immediately executes that bytecode from memory
	--	5. bytecoded is typically discarded after execution
	--		- if you want to keep the bytecode, you can save it with a tool like `luac`
end

function Printing()
	-- printing is very simple in lua. you can use the built-in print() function to print to stdout.
	print("hello word!") -- just like python!
	-- automatically adds newline at the end.
	-- to make print() output to somewhere other than stdout, you can modify the `_G.print` global variable and use the `io` library:
	local old_print = print -- can save functions as variables, they are first class values (more on this later)
	_G.print = function(...)
		-- could write to a file, buffer, or somewhere else
		local file = io.open("examples/output.txt", "w") -- "w" for write mode
		-- io.open won't create directories but it will create files with "w" mode
		if file ~= nil then
			file:write(...)
			file:close()
		end
	end
	-- _G is a special global table in lua that contains all global variables and functions.
	-- it's essentially the global environment of your lua program. from there you can modify global functions like print.

	-- you can also use the built-in io library to write things with more control like so
	io.write("Hello ")
	io.write("World")
	io.write("\n")
	-- can be useful for creating custom-formatted output, but we won't go further into this.

	-- you can use .. to concat strings in lua instead of +
	local s = "concated " .. "this!"
	print(s) -- since we had modified _G.print, you will find the output in `examples/output.txt`

	print = old_print -- restore the old print
	print(s)

	-- we can use .. concat to print variables in our text
	local name = "faisal"
	print("hi, " .. name .. " is the coolest person ever.")

	-- now, we will show how to print tables.
	-- you will properly learn about tables later, but they are essentially a datastructure that combines both arrays and dictionaries.

	-- we will first go over printing a simple array like table:
	local arr = { "apple", "banana", "mango", "pineapple" }
	print("contents of arr are " .. table.concat(arr, ", "))
	-- to print key-value tables, you will need to iterate over them and print the key-value pairs one by one.
	-- we will see an example of this in Loops_and_conditionals()

	-- to print booleans in concat, we must use the tostring() built in method
	local bool_x = true
	print(bool_x) -- this works fine because we are just printing it by itself.
	print("bool_x is " .. tostring(bool_x)) -- for this, since we are concat the string with .., need tostring() around bools
end

function Variables()
	-- LOCAL vs GLOBAL
	-- variables in lua can be either local or global
	-- and just like in python, lua's variables are dynamically typed
	-- typically, you would expect variables to be implicitly local and you would need to use a global keyword to make them globally scoped.
	-- or you would define them at the file level to make them global.
	-- in lua it's reversed. variables are implicitly global! you need to use a local keyword to make them local
	--
	-- so doing something like this,
	X = 10 -- note: global variables are capitalized by convention
	-- makes X a global variable of value 10
	-- if we want to make a local variable, we use the local keyword
	local y = 15

	-- to create a scope we can use a do-end. this is just like using { } to create a scope in C
	-- do-end isn't used for anything beyond creating a scope.
	do
		local y = 21
		print("inside do-end y is " .. y) -- prints 21
	end
	print("outside do-end y is " .. y) -- prints 15
	-- we see that redefining the variable inside the do-end does not persist outside of the scope.
	-- this is like if we define a variable inside a loop and cannot access it outside, the declaration is inside the scope of the loop only.

	-- however, if we declare without local keyword, the variable becomes global
	do
		A = 378
	end
	print("outside do-end A is " .. A) -- prints 378

	-- DYNAMICALLY TYPED
	-- variables in lua are dynamically typed like python
	local z = 10
	z = "yes" -- if you're using nvim then this line will give you a warning, but it still works!
	print("z is now " .. z)
end

function Data_types()
	-- lua has 8 basic data types
	-- 1. nil
	--	a special value that represences absence of value, like null
	local value = nil

	-- 2. boolean
	--	true or false
	value = true

	-- 3. number
	--	represents real (double precision floating point) numbers
	--	no distinction between integers and floats
	--	can also use scientification notation
	value = 3.14
	value = 4
	value = 1.23e-5

	-- 4. string
	--	immutable sequences of characters
	--	can define with single quotes, double quotes, or long brackets [[ ]]
	--	the below would print:
	--	hello
	--	world
	value = "hello"
	value = "world"
	value = [[hello
world
]]
	print(value)

	-- 5. functrion
	--	first class values that can be stored in variables
	--	can be passed as arguments and returned from other functions
	--	support closures and proper tial calls
	--	this of course means we can have functions nested inside functions (they're first-class after all)
	local function add(a, b)
		return a + b
	end
	local funky = add
	print("funky(2, 3) is " .. funky(2, 3))
	-- can also get it anonymously like in javascript
	local multiply = function(a, b)
		return a * b
	end
	print("multiply(6, 9) is " .. multiply(6, 9))

	-- 6. userdata
	--	represents arbitrary C data
	--	typically used for representing different new types created by application program or lirbraries
	--	cannot be created or modified in lua, only through C API
	local file = io.open("examples/test.txt") -- this is userdata type
	print(type(file)) -- prints userdata

	-- 7. thread
	--	represents independent threads of execution
	--	used to implement coroutines
	--	not related to operating system threads, i.e, cant achieve true parallelism
	--	these are useful for game dev, event driven programming, and so on but we won't get into them for now

	-- 8. table
	--	the only data structuring mechanism in lua
	--	there is no OOP, there is only tables
	--	implements associativearrays
	--	can represent ordinary arrays, sequences, symbol tables, sets, records, graphs, trees, maps, etc.
	--	we will go over these in more depth in the next section Lua_tables()
	local tab = { 1, 2, 3 }
	tab = { age = 21, name = "faisal" }
	print(table.concat(tab, ", "))
end

function Lua_tables()
	-- tables are one of the most fundamental and powerful features of lua.
	-- they are the main--and only--data structure in the language.
	-- tables are incredibly VERSATILE and can be used as arrays, dictionaries, objects, or even a combination of these
	--
	-- here's some examples

	-- creating an empty table
	local myTable = {}

	-- tables as arrays (numeric indices starting at 1).
	-- these are also called "sequential tables"
	local fruits = { "apple", "banana", "orange" }
	print("fruits[1] is " .. fruits[1]) -- prints "apple" because lua arrays start at 1, not 0

	-- tables as dictionaries. note that any table with a key-value pair is NOT sequential.
	local person = {
		name = "faisal",
		age = 30,
		["favorite colorr"] = "blue",
	}
	-- square brackets [] are needed if we want to use a key that contains:
	--	- spaces
	--	- special characters
	--	- starts with a number

	print(person.name) -- access value with .key
	print(person["name"]) -- can also use [key] for dynamic access
	local dynamic_key = "age"
	print("person's age is " .. person[dynamic_key])

	-- tables can contain both single values and key-value pairs at once, acting as both arrays and dictionaries.
	-- tables can also nest other tables.
	local mixed = {
		1,
		"hello",
		size = 10,
		{
			"apple",
		},
		user = {
			id = 123,
			active = true,
		},
		[69] = 6969, -- need to wrap number keys with []
	}
	print("mixed[2] is " .. mixed[2])
	print("mixed.size is " .. mixed.size)
	print("mixed[3] is " .. table.concat(mixed[3], ", "))
	-- notice that the key-value pairs are not counted towards the indices.
	-- that is, mixed[3] skips over `size = 10` and instead grabs the next non-pair item, which is `{ "apple" }`

	-- LENGTH OPERATOR
	-- we can also get the length of a table with the length operator #
	-- this only works reliably for sequential tables.
	local vegetables = { "mango", "monkey", "alligator", "apple" }
	print("length of fruits is " .. #vegetables) -- prints 4

	-- TABLES ARE REFERENCE TYPES
	-- when you assign a table to a new variable, both variables refer to the same table
	local t1 = { 2025, 2024, 2023 }
	local t2 = t1
	t2[1] = 69
	print("t1[1] is now " .. t1[1])

	-- TABLES CAN GROW DYNAMICALLY
	-- just like python lists, tables grow dynamically.
	-- however, one difference is that you won't get an index out of bounds for assignments in lua.
	t1[1000] = "6969" -- this is perfectly valid even though it would fail in python!
	print("t1[1000] is " .. t1[1000])
	-- this actually creates a "sparse"

	-- BOOLEANS AS KEYS
	-- lua lets you have booleans as keys as well!
	local boolean_table = {}
	boolean_table[true] = "hi"
	print("boolean_table[true] is " .. boolean_table[true]) -- works fine, prints "hi"
	boolean_table[false] = "byebye"
	print("boolean_table[false] is " .. boolean_table[false]) -- works fine, prints "byebye"
	print("boolean_table[true] is " .. boolean_table[true]) -- also prints "byebye" !

	local boolean_table2 = {
		[false] = true, -- need to wrap boolean keys with []
		[true] = false,
	}
	print("boolean_table2[true] is " .. tostring(boolean_table2[true]))
	print("boolean_table2[true] is " .. tostring(boolean_table2[false]))
end

function Loops_and_conditionals()
	-- FOR LOOP
	-- here is a basic for loop
	for i = 5, 10 do -- starts at 5, prints up to 10 inclusive
		print(i)
	end
	-- note that do-end act like braces {}
	-- in lua, we include 10 as well. in python when we do `for i in range(5, 10)` we don't get 10, but in lua we do.

	-- with steps
	for i = 5, 20, 2 do -- start 5, end 20, step 2
		print(i)
	end

	-- generic for loop over a sequential table
	local fruits = { "apple", "banana", "orange", "pear" }
	for index, value in ipairs(fruits) do
		print(index, value)
	end
	-- using the built in ipairs(), i for index
	-- if you want to ignore inde use _ like for _, v

	-- generic for loop over a key-value table
	local person = { name = "henry", age = 69, snack = "cheesecake" }
	for key, value in pairs(person) do
		print(key, value)
	end
	-- using the built in pairs()
	-- if you want to ignore key use _ like for _, v
end

function Lua_for_vim() end

Main()
