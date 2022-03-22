-- Spark Engine config

workspace "Spark"
    architecture "x64"
    configurations
    {
        "Debug",   -- dev mode
        "Test",    -- release standard, with debugging tools
        "Release"
    }
    startproject "Sparkle"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Spark"
    location "Spark"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "sppch.h"
    pchsource "%{prj.name}/src/sppch.cpp"

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "%{prj.name}",
        "%{prj.name}/src",
        "%{prj.name}/src",
    }

    filter "system:Windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SP_PLATFORM_WINDOWS",
            "SP_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{MKDIR} ../bin/" .. outputdir .. "/Sparkle"),
            ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sparkle/Spark.dll")
        }

    filter "configurations:Debug"
        defines "SP_DEBUG"
        buildoptions "/MDd"
        symbols "On"

        defines
        {
            "SP_ASSERT_ENABLED"
        }

    filter "configurations:Release"
        defines "SP_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "SP_DIST"
        buildoptions "/MD"
        optimize "On" 

project "Sparkle"
    location "Sparkle"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "Spark",
        "Spark/src",
        "Spark/lib/splog"
    }

    links
    {
        "Spark"
    }

    filter "system:Windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SP_PLATFORM_WINDOWS",
            "SP_BUILD_DLL"
        }

    filter "configurations:Debug"
        defines "SP_DEBUG"
        buildoptions "/MDd"
        symbols "On"

        defines
        {
            "SP_ASSERT_ENABLED"
        }

    filter "configurations:Release"
        defines "SP_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "SP_DIST"
        buildoptions "/MD"
        optimize "On" 