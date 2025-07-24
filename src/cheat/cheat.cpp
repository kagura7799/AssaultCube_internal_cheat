#include "cheat.hpp"

// TODO: player struct, enemy struct

Memory mem = Memory();

void setPlayerHp(int value)
{
	mem.WriteMem(mem.playerBase + 0xec, value);
}

void setEndlessAmmo(int value)
{
	for (const auto& [_, offset] : entityOffsets["weapons"])
		mem.WriteMem(mem.playerBase + offset, value);
}

void setRecoil()
{
	uintptr_t INST_CHANGE_VIEWY = 0xC2EC3;
	std::vector<uint8_t> nopBytes = { 0x90, 0x90, 0x90, 0x90, 0x90 };

	WriteProcessMemory(mem.hProcess, (LPVOID)(mem.baseAddress + INST_CHANGE_VIEWY), nopBytes.data(), nopBytes.size(), NULL);
}