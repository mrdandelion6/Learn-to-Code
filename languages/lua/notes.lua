-- RUN
Variables()

function Contents()
	What_is_lua()
	Variables()
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
end

function Variables()
	-- variables in lua can be either local or global
	-- and just like in python, lua's variables are dynamically typed
	-- so doing something like this,
	x = 10
	-- makes x a global variable of value 10
	-- if we want to make a local variable, we use the local keyword
	local y = 15

	-- to create a scope we can use a do-end, more on this later but for now we use it to demonstrate access
	do
		x = 1
		y = 0
	end

	print(x)
	print(y)
end

function Lua_for_vim() end
