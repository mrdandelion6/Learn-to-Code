function Main()
	-- call the function you would like to run here to see any outputs.
	-- RUN
	Printing()
end

function Contents()
	What_is_lua()
	Variables()
	Printing()
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

function Lua_tables()
	-- tables are one of the most fundamental and powerful features of lua.
	-- they are the main--and only--data structure in the language.
	-- tables are incredibly VERSATILE and can be used as arrays, dictionaries, objects, or even a combination of these
	--
	-- here's some examples

	-- creating an empty table
	local myTable = {}

	-- tables as arrays (numeric indices starting at 1)
	local fruits = { "apple", "banana", "orange" }
	print("fruits[1] is " .. fruits[1]) -- prints "apple" because lua arrays start at 1, not 0
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
end

function Lua_for_vim() end

Main()
