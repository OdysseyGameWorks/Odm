project "Odm"
        kind "StaticLib"
        language "C++"
        cppdialect "C++17"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "src/**.hpp",
            "src/**.inl",
            "src/**.cpp"
        }

        filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

        filter "configurations:Release"
            runtime "Release"
            optimize "on"
