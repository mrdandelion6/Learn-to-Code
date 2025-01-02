local M = {}

-- default configuration
M.defaults = {
	enabled = true,
	timeout = 1000,
	debug = false,
	mappings = {
		next = "n",
		prev = "p",
	},
}

-- private state
local state = {
	initialized = false,
	config = {},
}

-- private functions
local function validate_config(user_config)
	-- check for invalid options
	for key, _ in pairs(user_config) do
		if M.defaults[key] == nil then
			error(string.format("Invalid option: %s", key))
		end
	end
end

local function merge_configs(user_config)
	-- merge user config with defaults
	local config = {}
	for key, value in pairs(M.defaults) do
		config[key] = user_config[key] or value
	end
	return config
end

-- setup function that users call to initialize with their config
function M.setup(user_config)
	if state.initialized then
		error("Already initialized")
		return
	end

	user_config = user_config or {}
	validate_config(user_config)
	state.config = merge_configs(user_config)
	state.initialized = true

	-- initialize your module
	if state.config.enabled then
		-- do initialization stuff
	end
end

-- public API that depends on setup
function M.do_something()
	if not state.initialized then
		error("Must call setup() first")
		return
	end

	if state.config.debug then
		print("Debug mode enabled")
	end
end

return M
