// Inexor module: "test"

#ifndef INEXOR_MODULE_TEST_HEADER_FILE
#define INEXOR_MODULE_TEST_HEADER_FILE

#include <iostream>

#ifdef WIN32
	#define DLL_EXPORT
#endif

namespace inexor {
namespace module_test {

	// Windows specific code
	#ifdef WIN32

		#if defined DLL_EXPORT
		#define DECLDIR __declspec(dllexport)
		#else
		#define DECLDIR __declspec(dllimport)
		#endif
     
		extern "C"
		{
			DECLDIR int TestFunction(int a, int b);
		}

	#endif 

// Namespaces
};
};

#endif // INEXOR_MODULE_TEST_HEADER_FILE
