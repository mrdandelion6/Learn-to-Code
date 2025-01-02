local M = {}
local counter = 0

function M.greet()
	return "greeting from examples/init.lua"
end

function M.increment()
	counter = counter + 1
	print("incremented to " .. counter)
end

return M
