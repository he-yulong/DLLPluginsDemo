workspace "MyMathLib"
	configurations { "Debug", "Release", "Dist" }
	platforms "x64"
	architecture "x86_64"
	startproject "MyMathLib"
	location "project-files"
	filter "configurations:Debug"
		defines { "DEBUG" }
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines { "NDEBUG" }
		runtime "Release"
		optimize "on"
		symbols "off"

	filter "configurations:Dist"
		defines { "NDEBUG" }
		runtime "Release"
		optimize "on"
		symbols "off"

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "MyMathLib"
	kind "SharedLib"
	language "C++"
	cppdialect "C++latest"
	staticruntime "off"
	location "project-files"
	
	targetdir("lib")
	objdir ("bin-int/%{outputdir}/%{prj.name}")
	
	files
	{
		"include/**.h",
		"src/**.cpp",
		"premake5.lua"
	}

	includedirs
	{
		"include/",
	}

	defines { "DIST_DLL" }

	filter "system:windows"
		systemversion "latest"