#pragma once


#ifdef CR_PLATFORM_WINDOWS
	#ifdef CR_BUILD_DLL
		#define CHERRY_API __declspec(dllexport)
	#else 
		#define CHERRY_API __declspec(dllimport)
	#endif
#else
	#error Cherry only supports Windows for now
#endif