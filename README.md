# DLLPluginsDemo
A Unreal 5 demo for creating a plugin that loads third-party dll files and external txt files.

This repository is for this blog: [How to Create a Plugin that Works with DLLs, Packaging, External Files](http://www.hyl3d.com/2022/12/29/ue5how-to-create-a-plugin-that-works-with-dll-packaging-paths/).

NOTES:

- (Optional) `External/MyMathLib` is an external third-party library project.
	1. Click `build_vs2022.bat` or `build_vs2019.bat` to build a Visual Studio project.
	2. Then build DLL files.
	3. Copy include and lib folders to `Plugins/MyMath/Source/ThirdParty/MyMathLib` to update the library.