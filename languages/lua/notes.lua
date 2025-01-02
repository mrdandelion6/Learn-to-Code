function Main()
	-- call the function you would like to run here to see any outputs.
	-- RUN
	Modules()
end

function Contents()
	What_is_lua()
	Variables()
	Printing()
	Data_types()
	Lua_tables()
	Loops_and_conditionals()
	Modules()

	Lua_for_neovim()
	Vim_global_object()
	Neovim_configuration_patterns()
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

	-- IF CONDITIONALS
	-- if statements are similiar to python, they just have then-end for scoping
	local x = 5
	if x < 10 then
		print("case 1")
	elseif 10 < x and x < 15 then -- use and, not &&
		print("case 2")
	elseif (20 < x and x < 25) or (60 < x and x < 65) then -- use or, not ||
		print("case 3")
	elseif x ~= 69 then -- use ~= instead of !=
		print("case 4")
	else
		print("case 5")
	end

	local flag = true
	if not flag then -- use not, not !
		print("hello!")
	end
end

function Modules()
	-- modules in lua are fundamentally just lua files that return a value (usually a table).
	-- we will now investigate how they work. open the file mymodule.lua
	--
	-- in mymodule.lua, we see that we have a variable
	local M = {} -- it is common convention to use M for a 'module table'
	-- this table will be returned at the end of mymodule.lua.
	-- we add keys to M like functions and more.
	-- when we add functions to tables, we refer to them as 'methods', just like how classes have methods.
	M.method = function()
		return "I'm a method"
	end
	-- now we can call it like so
	print(M.method())
	--
	-- another way to create a method for a table is as follows
	function M.method2()
		return "I'm also a method, entirely equivalent"
	end
	print(M.method2())
	-- note that mehod2() is entirely the same as method(), it is just syntactic sugar.
	-- you could also do
	local N = {
		function_name = function()
			return "I'm a method defined directly inside N"
		end,
	}
	print(N.function_name())
	-- however, this is not preferred because it nests everything inside and makes it harder to read.
	--
	-- REQUIRING FILES
	-- now to actually "import" or "inlcude" modules, we simply use the built in `require()` function.
	-- this function is used very often in things like neovim configuration, as you need to import a lot of modules often.
	local mymod = require("mymodule")
	-- when we call requrie() to load the module, lua does the following:
	-- 1. checks package.loaded["mymodule"] for cached module
	-- 2. if not found, searches package.path for the file
	-- 3. loads and executes the file
	-- 4. caches the reteurn value in package.loaded
	-- 5. returns the cached value
	--
	-- note that the `package` in lua is a global table that contains variables and functions related to module loading.
	-- here are some of its key components::
	-- 1. package.path
	--	a string that tells lua where to look for modules
	print("package.path is " .. package.path)
	--	from the above we get something like this
	--
	--	package.path is /usr/local/share/lua/5.4/?.lua;/usr/local/share/lua/5.4/?/
	--	init.lua;/usr/local/lib/lua/5.4/?.lua;/u sr/local/lib/lua/5.4/?/init.lua;
	--	/usr/share/lua/5.4/?.lua;/usr/share/lua/5.4/?/init.lua;./?.lua;./?/init.lua
	--
	--	notice that we have "./?.lua" as one of the paths.
	--	this is same as ./*.lua, which just means also search the PWD.
	--	an important thing to note is that ./ refers to the directory where the lua program was launched from!
	--	./ does not refer to the location of the source code where require() is being called.
	--
	-- 2. package.loaded
	--	a table that acts as a cache for loaded modules.
	--	when you require a module lua first checks if it's in package.loaded
	--
	-- let's use our imported module now.
	print("mymod.example_method() returns " .. mymod.example_method())
	--
	-- REQUIRING DIRECTORIES
	-- we can also require entire directories
	local dir_mod = require("examples") -- imports the examples directory
	-- this will look for a file called `init.lua` inside the examples/ directory.
	-- once it's found it will run the file and return whatever it returns, just like if we required init.lua directly.
	print(dir_mod.greet())

	-- CLOSURES & PRIVATE STATES
	-- when a module is loaded, all its code runs but the local variables it creates continue to exist in memory as long as there are functions (closures) that reference them.
	-- for example, take a look at examples/init.lua.
	-- we have the local variable counter that is not inside M.
	-- even though it's not inside M, it is referenced by M.increment, hence it's value gets preserved in memory.
	dir_mod.increment() -- will print updated counter
	dir_mod.increment() -- keeps state

	-- what's more is that each time we call require() on the module, we take the cached M.
	-- don't forget that M (from dir_mod) is cached in package.loaded.
	-- this means that each new require() of the module will preserve the counter as well!
	--
	-- we say that the counter has a private state because it is not directly accessible.
	-- we can only modify it through the API we provide which is essentially the functions of the table M.
	--
	-- USING SETUP()
	-- we often use a setup method returned by module tables in neovim plugins and other lua projects.
	-- this function is useful because it:
	--	allows users to configure the module before it's used
	--	maintains private state using local variables (as we just saw)
	--	validates configuration
	--	merges user config with defaults
	--	prevents multiple initializations
	--	ensures setup is called before using other functionality
	--
	-- take a look at examples/typical_module.lua to see exactly how setup() is used.
end

function Lua_for_neovim()
	-- lua is the language used for configuring neovim
	-- in order to best customize your neovim, you should understand the basics of lua, which is everything we just went over.
	-- in the next sections we will now go over the following topics for lua:
	--	vim global object
	--	essential configuration patterns
	--	autocommands and events
	--	plugin development basics
	--	advanced concepts
	--	asynchronous operations
	--	performance optimization
	--
	-- note that attempting to run any of the neovim related functions will fail because the standard lua binary does not include things like the vim global and other required modules.
	--
	-- KEY DIFFERENCES FROM STANDARD LUA
	--	1. path handling uses neovim's runtime path
	--	2. built-in package.path is modified to include neovim directories
	--	3. additional global objects like vim, assert, etc.
	--	4. concurrent execution model differences
end

function Vim_global_object()
	-- the vim object is your primary interface with neovim. it provides access to:
	--	API functions, via vim.api
	--	neovim-specific functions, via vim.fn
	--	variables and options via:
	--		vim.g (global)
	--		vim.b (buffer)
	--		vim.w (window)
	--		vim.o (options
	--	utility functions like vim.inspect() for debugging
	--
	-- here is an example of a basic interaction,
	vim.g.mapleader = " " -- set the leader key as space
	vim.opt.number = true -- setting display line numbers to be true

	-- now here is an example of using api functions
	vim.api.nvim_set_keymap("n", "<leaderw", ":write<CR>", { noremap = true, silent = true })
	-- most of learning how to effectively script your neovim config with lua involves learning how to use the different properties from the vim global.
end

function Neovim_configuration_patterns()
	-- for neovim, we keep our configuration files typically in ~/.config/nvim/
	-- here is an example of how the nvim/ tree looks like (it is important to understand this for configuring properly)
	--
	-- ~/.config/nvim/
	-- ├── init.lua			      # main configuration entry point
	-- ├── lua/                           # custom lua modules
	-- │   └── user/		      # your configuration modules
	-- │       ├── init.lua			# main module initialization
	-- │       ├── options.lua		# editor options
	-- │       ├── keymaps.lua		# key mappings
	-- │       ├── plugins.lua		# plugin management
	-- │       ├── autocmds.lua		# autocommands
	-- │       └── utils.lua		# utility functions
	-- ├── after/			      # loads after plugins
	-- │   └── plugin/                    # configuration that runs after plugins load
	-- │       └── telescope.lua		# example plugin-specific config
	-- ├── plugin/			      # automatically loaded scripts
	-- │   └── filetypes.lua		# example filetype-specific settings
	-- ├── ftplugin/	              # filetype-specific settings
	-- │   ├── lua.lua			# settings for lua files
	-- │   └── python.lua			# settings for python files
	-- └── snippets/		      # custom snippets
	--     └── lua.json			# snippets for lua
	--
	-- best practice is to organize our configuration into modules like shown above in lua/user/
	-- as shown, the main directories are:
	--	lua/
	--	after/
	--	plugin/
	--	ftplugin/
	--	snippets/
	--
	-- lua/
	--	contains modules with custom configurations.
	--	configurations can be for keymaps, editor options, auto commands (more on this later), managing plugins, etc.
	--	plugins are loaded here, specifically in `lua/plugins.lua`
	--
	-- after/
	--	files here load AFTER all plugins have been loaded
	--	this is crucial when your configuration DEPENDS on plugins having first been fully initialized
	--	perfect for plugin-specific settings that need the plugin to be loaded first
	--
	-- plugin/
	--	files here load at startup, BEFORE plugins are loaded
	--	used for configurations that don't depend on plugins
	--	good for vim's built-in settings, autocommands, or commands that need to be available immediately
	--
	-- ftplugin/
	--	this directory holds filetype-specific settings that are loaded only when you open a file of that type
	--	the files inside must much the filetype name exactly. eg) lua.lua, python.lua, java.lua.
	--	here is an example, suppose it is inside ftplugin/python.lua
	vim.opt_local.expandtab = true
	vim.opt_local.shiftwidth = 4
	vim.opt_local.softtabstop = 4
	vim.opt_local.textwidth = 88
	--	this will set these settings specifically for python files.
	--	note you should use vim.opt_local instead of vim.opt to set buffer-specific options.
	--	you can also add custom keymaps like this
	vim.keymap.set("n", "<leader>lr", ":luafile %<CR>", { buffer = true }) -- use buffer = true for buffer-local maps

	-- snippets/
	--	files here are for custom snippets for language specific files.
	--	snippets are quick ways of typing in code, for example 'for' + <tab> for a for loop.
	--	example files: lua.lua, python.lua, all.lua
	--	we can have a file for global snippet settings as well (all.lua)
	--	the filles in snippets/ may not always be .lua ones, it depends on your snippet engine.
	--	for example, the .lua snippets are from the LuaSnip snippet engine.
	--	we also have .json snippets like lua.json, python.json, global.json, which is used by many snippet engines. you may recognize these from VS code.
	--	then there's also the SnipMate snippet engine that jas lua.snippets, python.snippets, and _all.snippets.
	--	your snippet engine is a plugin that you would load (recall we can load plugins in `lua/user/plugins.lua`
	--
	-- ORDER OF EXECUTION
	-- we will now go over the order of execution of files in nvim/ in depth.
	-- first we must understand that some folders are enforced to execute at a certain stage by nvim and some are just conventional.
	-- here is the core execution order enforced by neovim:
	--	1. init.lua			# first thing that is loaded
	--	2. plugin/*.lua:		# loaded before plugins are loaded
	--					# plugins get loaded, this typically includes snippets
	--	3.after/plugin/*.lua:		# loaded after plugins
	--	4. ftplugin/*.lua:		# gets loaded when opening matching filetypes
	--
	--	note that lua/user/ does not get automatically loaded by neovim!
	--	evertyhing  in lua/user is not enforced by neovim and requires use to call `require()` from init.lua
	--	example, suppose the following is in nvim/init.lua:
	require("user.options") -- this runs lua/user/options.lua. note that we don't need to do 'lua.user.options'
end

Main()
