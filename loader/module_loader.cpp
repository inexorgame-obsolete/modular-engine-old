#include "module_loader.hpp"

namespace inexor {
namespace module_loader {


	ModuleManager::ModuleManager()
	{

	}

	
	ModuleManager::~ModuleManager()
	{
		// Windows specific code
		#ifdef WIN32

			// Iterate through map and unload all libraries
			INEXOR_MODULE_MAP_ITERATOR it;
			for(it = inexor_modules.begin(); it != inexor_modules.end(); it++)
			{
				// Unload library
				FreeLibrary(it->second);
			}

		#endif

		// TODO: Add Linux code here!
		// TODO: Add Mac OS code here!
	}


	INEXOR_MODULE_LOADER_RETURN_CODE ModuleManager::LoadModule(const std::string module_name, std::string file_path)
	{
		// Windows specific code
		#ifdef WIN32
		
			// Convert std::string to Windows LPCWSTR (long pointer C wide string)
			std::wstring stemp = std::wstring(file_path.begin(), file_path.end());
			LPCWSTR lp_module_name = stemp.c_str();

			// Load DLL file
			HINSTANCE inexor_module = LoadLibrary(lp_module_name);

			if(0 != inexor_module)
			{
				// Loading module was successful!
				std::cout << "success: module " << module_name.c_str() << " has been loaded successfully!" << std::endl;

				// Add library to module map
				inexor_modules[module_name] = inexor_module;
			}
			else
			{
				std::cout << "error: could not load module " << module_name.c_str() << " !" << std::endl;
				return INEXOR_MODULE_LOADER_ERROR;
			}

		#endif

		// TODO: Add Linux code here!
		// TODO: Add Mac OS code here!

		return INEXOR_MODULE_LOADER_SUCCESS;
	}


	INEXOR_MODULE_LOADER_RETURN_CODE ModuleManager::UnloadModule(const std::string module_name)
	{
		// Look if this library exists
		INEXOR_MODULE_MAP_ITERATOR lookup = inexor_modules.find(module_name);

		if(lookup == inexor_modules.end())
		{
			std::cout << "error: unloading of module failed because module was not found!" << std::endl;
			return INEXOR_MODULE_LOADER_ERROR;
		}
		else
		{
			std::cout << "unloading module " << module_name.c_str() << std::endl;

			// Unload library
			FreeLibrary(lookup->second);

			// Delete from map
			inexor_modules.erase(module_name);
		}


		// TODO: Add Linux code here!
		// TODO: Add Mac OS code here!

		return INEXOR_MODULE_LOADER_SUCCESS;
	}

	/*
	template <typename T> T ModuleManager::GetFunction(const std::string module_name, const std::string function_name)
	{
		// Windows specific code!
		#ifdef WIN32
			
			// Lookup DLL module
			HINSTANCE hInst;
			INEXOR_MODULE_MAP_ITERATOR lookup = inexor_modules.find(module_name);

			if(lookup == inexor_modules.end())
			{
				std::cout << "error: could not find function " << function_name.c_str() << " because module " << module_name.c_str() << " was not found!" << std::endl;
				return std::nullpr;
			}
			else
			{
				std::cout << "looking for function " << function_name.c_str() << " in module " << module_name.c_str() << std::endl;
				// Search function in DLL
				T function_pointer = (T)GetProcAddress(lookup->second, function_name.c_str());
			}

		#endif
		return function_pointer;
	}
	*/

	#ifdef WIN32

	HINSTANCE ModuleManager::GetModule(const std::string module_name)
	{
		HINSTANCE hInst = 0;

		INEXOR_MODULE_MAP_ITERATOR lookup = inexor_modules.find(module_name);

		if(lookup == inexor_modules.end())
		{
			std::cout << "error: could not find module: " << module_name.c_str() << std::endl;
			return 0;
		}
		else
		{
			hInst = lookup->second;
		}

		return hInst;
	}

	#endif



};
};
