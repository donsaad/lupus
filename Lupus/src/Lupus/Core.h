#pragma once

#ifdef LP_PLATFORM_WINDOWS
	#ifdef LP_BUILD_DLL
		#define LUPUS_API __declspec(dllexport)
	#else
		#define LUPUS_API __declspec(dllimport)
	#endif
#else
	#error Lupus only supports Windows OS!
#endif

#define BIT(x) (1 << x)
