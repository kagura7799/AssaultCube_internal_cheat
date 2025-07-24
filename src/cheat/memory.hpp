#include <Windows.h>
#include <string>
#include <TlHelp32.h>
#include <iostream>

class Memory
{
private:
	HWND hwnd;
	DWORD pid;

	uintptr_t getModuleBaseAddress(DWORD pid, const std::wstring& moduleName);

public:
	Memory();

	HANDLE hProcess;
	uintptr_t playerBase;
	uintptr_t baseAddress;

	void WriteMem(uintptr_t address, int value);
	void ReadMem(uintptr_t address, int value);
};