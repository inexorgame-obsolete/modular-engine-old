// Inexor modular system prototype

#ifndef INEXOR_MODULE_LOADER_HEADER_FILE
#define INEXOR_MODULE_LOADER_HEADER_FILE

#include <unordered_map>
#include <iostream>

// On Windows we will use DLL files
// For WIN32 macro usage see https://msdn.microsoft.com/de-de/library/b0084kay.aspx
#ifdef WIN32
   #include <Windows.h>
#endif

#include "return_codes.hpp"


namespace inexor {
namespace module_loader {

	typedef std::unordered_map<std::string, HINSTANCE> INEXOR_MODULE_MAP;
	typedef INEXOR_MODULE_MAP::const_iterator INEXOR_MODULE_MAP_ITERATOR;

	// A module manager for 
	class ModuleManager
	{
		private:
			// Lets use an unordered map to map from std::string to module instance
			// Please note that the module instance is of type HINSTANCE on Windows!
			#ifdef WIN32
				INEXOR_MODULE_MAP inexor_modules;
			#endif
		
			// TODO: Add Linux code here!
			// TODO: Add Mac OS code here!

		public:
			ModuleManager();

			~ModuleManager();

			// TODO: Move semantics: use references instead!
			INEXOR_MODULE_LOADER_RETURN_CODE LoadModule(const std::string, const std::string);

			INEXOR_MODULE_LOADER_RETURN_CODE UnloadModule(const std::string);

			// HIGHLY EXPERIMENTAL!
			//template <typename T> T GetFunction(const std::string, const std::string);

			HINSTANCE GetModule(const std::string);

	};


};
};

#endif // INEXOR_MODULE_LOADER_HEADER_FILE
