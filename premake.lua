
-- Generate with: premake5 vs2026
-- Requires Premake 5.0-beta7 or later, which includes the vs2026 action.

require("../../vendor/autoconf")

local aap_librw = "vendor/librw"

-- Returns a table of glob patterns covering all source file types for a directory.
local function add_source_files(prefix)
	return {
		prefix .. "/*.cpp",
		prefix .. "/*.h",
		prefix .. "/*.c",
		prefix .. "/*.ico",
		prefix .. "/*.rc",
	}
end

-- Configures post-build copy, debug working directory, and debug command.
local function set_paths(game_path, executable_path)
	if not game_path then return end

	postbuildcommands {
		'{COPYFILE} "%{cfg.buildtarget.abspath}" "' .. game_path .. '%{cfg.buildtarget.name}"'
	}

	debugdir(game_path)

	if executable_path then
		debugcommand(game_path .. "$(TargetFileName)")
		local subdir = executable_path:match("^(.+/)") or ""
		debugdir(game_path .. subdir)
	end
end

-- All source/include directories used by the lcsr project.
-- Modifying this list automatically updates both files{} and includedirs{}.
local lcsr_directories_list = {
	"src",
	"src/animation",
	"src/audio",
	"src/audio/eax",
	"src/audio/oal",
	"src/buildings",
	"src/collision",
	"src/control",
	"src/core",
	"src/entities",
	"src/math",
	"src/modelinfo",
	"src/objects",
	"src/peds",
	"src/renderer",
	"src/rw",
	"src/save",
	"src/skel",
	"src/skel/glfw",
	"src/text",
	"src/vehicles",
	"src/weapons",
	"src/extras",
	"src/fakerw",
}

-- ============================================================

workspace "lcsr"
	system 						"windows"
	architecture 			"amd64"
	language 					"C++"
	startproject 			"lcsr"
	location 					"build"
	symbols 					"Full"
	staticruntime 		"off"
	configurations	 	{ "Debug", "Release" }
	platforms 				{ "x64" }
	
	filter {}
	
	filter "configurations:Debug"
  	defines { "DEBUG", "LCSR_DEBUG" }

  filter "configurations:Release"
		defines { "NDEBUG", "LCSR_MASTER" }
		optimize "Speed"

	filter  {}
	defines { "RW_D3D9", "LIBRW", "USE_D3D9", "AUDIO_OAL" }

-- ============================================================

project "librw"
	kind "StaticLib"
	targetname "rw"
	targetdir(path.join(aap_librw, "lib/win-amd64-librw_d3d9-oal/%{cfg.buildcfg}"))

	files {
		path.join(aap_librw, "src/*.*"),
		path.join(aap_librw, "src/*/*.*"),
		path.join(aap_librw, "src/gl/*/*.*"),
  }

  filter "platforms:x64"
    architecture "amd64"

	filter "system:windows"
		toolset       "msc-v145"
		defines       { "_CRT_SECURE_NO_WARNINGS", "_CRT_NONSTDC_NO_DEPRECATE" }
		buildoptions  { "/Zc:sizedDealloc-" }
		staticruntime "on"

	filter  {}

-- ============================================================

project "lcsr"
	kind 				"WindowedApp"
	targetname 	"dbg"
	targetdir 	"bin/%{cfg.platform}/%{cfg.buildcfg}"
	dependson 	"librw"

	-- Source files: expand all directories.
	for _, dir in ipairs(lcsr_directories_list) do
    files(add_source_files(dir))
  end

	-- Mirror the same directory list for header search paths.
	includedirs(lcsr_directories_list)

	-- GitSHA1.cpp is generated at pre-build time; list it explicitly.
  files { "src/extras/GitSHA1.cpp" }

	-- Copy the built executable to the game folder if the env var is set.
	local game_directory = os.getenv("LCSR_GAME_DIR")
	if game_directory then
		set_paths(game_directory .. "/", "%{cfg.buildtarget.name}")
	end

	filter "system:windows"
		toolset       	"msc-v145"
		includedirs    	{ "src/skel/win" }
		buildoptions   	{ "/Zc:sizedDealloc-" }
		linkoptions    	{ "/SAFESEH:NO" }
		characterset   	"MBCS"
		targetextension ".exe"
		staticruntime  	"on"

		files(add_source_files("src/skel/win"))

		prebuildcommands {
			'pwsh -NoProfile -ExecutionPolicy Bypass -File "%{prj.location}..\\scripts\\Write-GitHeadCommit.ps1" "%{prj.location}..\\src\\extras\\GitSHA1.cpp"'
		}
		
		-- Vendor headers and libs (for now unconditional — single variant)
		includedirs {
			aap_librw,
			"vendor/openal-soft/include",
			"vendor/mpg123/include",
			"vendor/libsndfile/include",
		}

		libdirs {
			"vendor/librw/lib/win-amd64-librw_d3d9-oal/%{cfg.buildcfg}",
			"vendor/openal-soft/libs/Win64",
			"vendor/mpg123/lib/Win64",
			"vendor/libsndfile/lib/Win64",
		}

		links { "rw", "d3d9" }

	filter {}