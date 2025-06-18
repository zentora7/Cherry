workspace "Cherry"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist",
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Cherry/vendor/GLFW/include"
IncludeDir["Glad"] = "Cherry/vendor/Glad/include"

include "Cherry/vendor/GLFW"
include "Cherry/vendor/Glad"

project "Cherry"
	location "Cherry"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "crpch.h"
	pchsource "Cherry/src/crpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/utf-8"

		defines
		{
			"CR_PLATFORM_WINDOWS",
			"CR_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "CR_DEBUG"
		symbols "On"
		staticruntime "off"
		runtime "Debug"

	filter "configurations:Release"
		defines "CR_RELEASE"
		optimize "On"
		staticruntime "off"
		runtime "Release"

	filter "configurations:Dist"
		defines "CR_DIST"
		optimize "On"
		staticruntime "off"
		runtime "Release"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Cherry/vendor/spdlog/include",
		"Cherry/src"
	}

	links
	{
		"Cherry",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/utf-8"

		defines
		{
			"CR_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "CR_DEBUG"
		symbols "On"
		staticruntime "off"
		runtime "Debug"

	filter "configurations:Release"
		defines "CR_RELEASE"
		optimize "On"
		staticruntime "off"
		runtime "Release"

	filter "configurations:Dist"
		defines "CR_DIST"
		optimize "On"
		staticruntime "off"
		runtime "Release"
	