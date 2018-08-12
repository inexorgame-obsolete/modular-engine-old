// Inexor modular system prototype
#include <iostream>
using namespace std;

// Module loader
#include "loader/module_loader.hpp"

// Create an instance of the module manager
// TODO: Make it a singleton class!
inexor::module_loader::ModuleManager modman;

// TODO: Do we need this macro here?
#ifdef WIN32
	// We need to find this in the DLL file!
	typedef int (*TestFunction)(int,int);
#endif

int main(int argc, char* argh[])
{
	#ifdef WIN32

	// Load test module
	modman.LoadModule("test", "G:/modular-engine/MODULE/module-test.DLL");
	HINSTANCE handle = modman.GetModule("test");

	TestFunction test = (TestFunction) GetProcAddress(handle, "TestFunction");

	// This should be 30!
	cout << test(10,20) << endl;

	#endif

	cin.get();
	return 0;
}
