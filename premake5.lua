workspace "Lupus"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug", -- full debug mode no optimizations
		"Release", -- acts like fast debug version with logging and optimizations enabled
		"Dist"  -- everything is stripped out, no logs or anything
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Lupus"
	location "%{prj.name}"
	kind "SharedLib" -- dll
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lppch.h"
	pchsource "Lupus/src/lppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/ThirdParty/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/utf-8" -- Add UTF-8 encoding option for all Windows builds to fix spdlog compilation

		defines
		{
			"LP_PLATFORM_WINDOWS",
			"LP_BUILD_DLL"
		}

	--	postbuildcommands
	--	{
	--		("{COPYFILE} %{cfg.buildtarget.relpath}   ../bin/" .. outputdir .. "/Sandbox")
	--	}

	filter "configurations:Debug"
		defines "LP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LP_DIST"
		optimize "On"

	------------------------------- Sandbox App -------------------------------
project "Sandbox"
	location "%{prj.name}"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Lupus/src",
		"Lupus/ThirdParty/spdlog/include"
	}

	links
	{
		"Lupus"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/utf-8" -- Add UTF-8 encoding option for all Windows builds to fix spdlog compilation

		defines
		{
			"LP_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPYFILE} ../bin/" .. outputdir .. "/Lupus/Lupus.dll %{cfg.targetdir}")
		}

	filter "configurations:Debug"
		defines "LP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LP_DIST"
		optimize "On"
