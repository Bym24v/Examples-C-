#include <Windows.h>
#include <iostream>

void StartModding() {

	DWORD baseAddress = (DWORD)GetModuleHandle(0);

	printf("BaseAddress: 0x%x", baseAddress);

	while (true)
	{
		// vida
		*(DWORD*)(baseAddress + 0x22000) = 99999999;

		// oro
		*(DWORD*)(baseAddress + 0x22004) = 99999999;

		// diamantes
		*(DWORD*)(baseAddress + 0x22008) = 99999999;

		Sleep(100);
	}
}



BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserve) {

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Create Thread
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartModding, 0, 0, 0);
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}

	return true;
}