#include "../LSPManager/manager.h"
#include <windows.h>
#include <tchar.h>
#include <iostream>
int main()
{
	printf("0: remove ,1 install\n");
	auto lib = LoadLibrary(_T("./LSPManager.dll"));
	if (0 == getchar())
	{
		using uninstalllspFunc = LSPERROR(*)();
		uninstalllspFunc  uninstall_func = (uninstalllspFunc)GetProcAddress(lib, "RemoveLSP");
		LSPERROR error = uninstall_func();
	}
	else
	{
		using AddRule = LSPERROR (*)(const char* name, const char* value);
		AddRule add_rule_func = (AddRule)GetProcAddress(lib, "AddRule");
		add_rule_func("59.36.121.161:80","127.0.0.1:1920");
	//	add_rule_func("59.36.121.161:80", "127.0.0.1:1920");
		add_rule_func("113.96.209.105:8080", "127.0.0.1:1920");
		add_rule_func("183.3.224.146:80","127.0.0.1:1920");

		using installlspFunc = LSPERROR(*)();
		installlspFunc install_func = (installlspFunc)GetProcAddress(lib, "InstallLSP");
		LSPERROR error = install_func();
	}

	FreeLibrary(lib);
}