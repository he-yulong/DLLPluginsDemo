#pragma once

#if defined(DIST_DLL)
#define HYL_DLL __declspec(dllexport)
#else
#define HYL_DLL
#endif

class HYL_DLL MyMathLib
{
public:
	static float Add(float a, float b);
};