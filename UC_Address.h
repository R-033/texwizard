#pragma once
#ifndef GAME_UC
#define GAME_UC
#endif

#define EntryPoint 0x8AEC55
#define WrongEntryPointErrorString "This .exe is not supported.\nPlease use v1.0.0.1 STEAM nfs.exe (10,0 MB (10.584.064 bytes))."

#define bStringHash_Addr 0x4B3ED0
#define CreateResourceFile_Addr 0x6AC350
#define ResourceFileBeginLoading_Addr 0x6AE570
#define LoadGlobalAChunks_Addr 0x6AE680
#define GetTextureInfo_Addr 0x53CF30

#define SharedStringPoolAllocate_Addr 0x4B4BA0

#define LoadGlobalAChunks_Hook_Addr_1 0x6AF043

#define GetTextureInfo_Hook_Addr_1J 0x53DF50
#define GetTextureInfo_Hook_Addr_2 0x53DF98
#define GetTextureInfo_Hook_Addr_3 0x53DFAB
#define GetTextureInfo_Hook_Addr_4 0x53DFBE
#define GetTextureInfo_Hook_Addr_5 0x53DFD1
#define GetTextureInfo_Hook_Addr_6 0x53DFE4
#define GetTextureInfo_Hook_Addr_7 0x53EA93
#define GetTextureInfo_Hook_Addr_8 0x53EDAD
#define GetTextureInfo_Hook_Addr_9 0x53F172
#define GetTextureInfo_Hook_Addr_10 0x53F3E9
#define GetTextureInfo_Hook_Addr_11 0x53F439
#define GetTextureInfo_Hook_Addr_12 0x53F508
#define GetTextureInfo_Hook_Addr_13 0x53F5FF

unsigned int(*bStringHash)(char* StringToHash) = (unsigned int(*)(char*))bStringHash_Addr;

DWORD* (__cdecl* CreateResourceFile)(int a1, int a2, int a3, int a4, int a5) = (DWORD * (__cdecl*)(int, int, int, int, int))CreateResourceFile_Addr;
int(__thiscall* ResourceFileBeginLoading)(DWORD* r, int unk1, int unk2) = (int(__thiscall*)(DWORD*, int, int))ResourceFileBeginLoading_Addr;

int(__fastcall* LoadGlobalAChunks)() = (int(__fastcall*)())LoadGlobalAChunks_Addr;

DWORD* (__cdecl* GetTextureInfo)(unsigned int hash, int returnDefault, int includeUnloadedTextures) = (DWORD * (__cdecl*)(unsigned int, int, int))GetTextureInfo_Addr;

unsigned int(*SharedStringPoolAllocate)(const char* String) = (unsigned int(*)(const char*))SharedStringPoolAllocate_Addr;