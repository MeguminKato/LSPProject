#include "../LSPManager/manager.h"
#include <windows.h>
#include <tchar.h>
#include <iostream>
int main()
{
	printf("0: remove else install\n");
	auto lib = LoadLibrary(_T("./LSPManager.dll"));
	if (0 == getchar())
	{
		using uninstalllspFunc = LSPERROR(*)();
		uninstalllspFunc  uninstall_func = (uninstalllspFunc)GetProcAddress(lib, "RemoveLSP");
		LSPERROR error = uninstall_func();
	}
	else
	{
		using installlspFunc = LSPERROR(*)();
		installlspFunc install_func = (installlspFunc)GetProcAddress(lib, "InstallLSP");
		LSPERROR error = install_func();
	}

	FreeLibrary(lib);
}