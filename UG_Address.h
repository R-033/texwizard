#pragma once
#ifndef GAME_UG
#define GAME_UG
#endif

#define EntryPoint 0x670CB5
#define WrongEntryPointErrorString "This .exe is not supported.\nPlease use v1.4 English speed.exe (3,03 MB (3.178.496 bytes))."

#define bStringHash_Addr 0x567C70 // edx
#define CreateResourceFile_Addr 0x4482F0 
#define ResourceFileBeginLoading_Addr 0x448110 // edx, eax, ecx

#define LoadGlobalChunks_Addr 0x448650
#define GetTextureInfo_Addr 0x5461C0


#define LoadGlobalChunks_Hook_Addr_1 0x447285

#define GetTextureInfo_Hook_Addr_1 0x40287E
#define GetTextureInfo_Hook_Addr_2 0x402A40
#define GetTextureInfo_Hook_Addr_3 0x408635
#define GetTextureInfo_Hook_Addr_4 0x408665
#define GetTextureInfo_Hook_Addr_5 0x408695
#define GetTextureInfo_Hook_Addr_6 0x409BB9
#define GetTextureInfo_Hook_Addr_7 0x40E766
#define GetTextureInfo_Hook_Addr_8 0x40E929
#define GetTextureInfo_Hook_Addr_9 0x40EAAC
#define GetTextureInfo_Hook_Addr_10 0x4487B2
#define GetTextureInfo_Hook_Addr_11 0x4800F0
#define GetTextureInfo_Hook_Addr_12 0x480104
#define GetTextureInfo_Hook_Addr_13 0x490690
#define GetTextureInfo_Hook_Addr_14 0x49FF5F
#define GetTextureInfo_Hook_Addr_15 0x4A0E31
#define GetTextureInfo_Hook_Addr_16 0x4A476A
#define GetTextureInfo_Hook_Addr_17 0x4BA304
#define GetTextureInfo_Hook_Addr_18 0x4BB990
#define GetTextureInfo_Hook_Addr_19 0x4BB99F
#define GetTextureInfo_Hook_Addr_20 0x4E22AC
#define GetTextureInfo_Hook_Addr_21 0x4F20EB
#define GetTextureInfo_Hook_Addr_22 0x4F2377
#define GetTextureInfo_Hook_Addr_23 0x4F3161
#define GetTextureInfo_Hook_Addr_24 0x4F464F
#define GetTextureInfo_Hook_Addr_25 0x4F4765
#define GetTextureInfo_Hook_Addr_26 0x4F746B
#define GetTextureInfo_Hook_Addr_27 0x4F752B
#define GetTextureInfo_Hook_Addr_28 0x5072D5
#define GetTextureInfo_Hook_Addr_29 0x51BC24
#define GetTextureInfo_Hook_Addr_30 0x51BC43
#define GetTextureInfo_Hook_Addr_31 0x51BC5F
#define GetTextureInfo_Hook_Addr_32 0x51BC9C
#define GetTextureInfo_Hook_Addr_33 0x51BCB3
#define GetTextureInfo_Hook_Addr_34 0x51BCCA
#define GetTextureInfo_Hook_Addr_35 0x53F580
#define GetTextureInfo_Hook_Addr_36 0x53F9CE
#define GetTextureInfo_Hook_Addr_37 0x53FACD
#define GetTextureInfo_Hook_Addr_38 0x54479E
#define GetTextureInfo_Hook_Addr_39 0x545FC9
#define GetTextureInfo_Hook_Addr_40 0x546029
#define GetTextureInfo_Hook_Addr_41 0x5465A6
#define GetTextureInfo_Hook_Addr_42 0x5465B9
#define GetTextureInfo_Hook_Addr_43 0x5465CC
#define GetTextureInfo_Hook_Addr_44 0x5465DF
#define GetTextureInfo_Hook_Addr_45 0x5465F2
#define GetTextureInfo_Hook_Addr_46 0x56A3CD
#define GetTextureInfo_Hook_Addr_47 0x56A8A8
#define GetTextureInfo_Hook_Addr_48 0x56A8BF
#define GetTextureInfo_Hook_Addr_49 0x56AC67
#define GetTextureInfo_Hook_Addr_50 0x56ACB5
#define GetTextureInfo_Hook_Addr_51 0x56B07F
#define GetTextureInfo_Hook_Addr_52 0x589C2A
#define GetTextureInfo_Hook_Addr_53 0x58E651
#define GetTextureInfo_Hook_Addr_54 0x58E674
#define GetTextureInfo_Hook_Addr_55 0x58E68D
#define GetTextureInfo_Hook_Addr_56 0x58E6A9
#define GetTextureInfo_Hook_Addr_57 0x58E6C5
#define GetTextureInfo_Hook_Addr_58 0x58E6E1
#define GetTextureInfo_Hook_Addr_59 0x58E6FD
#define GetTextureInfo_Hook_Addr_60 0x5A9CFD
#define GetTextureInfo_Hook_Addr_61 0x5A9FEB
#define GetTextureInfo_Hook_Addr_62 0x5AA025
#define GetTextureInfo_Hook_Addr_63 0x5AA812
#define GetTextureInfo_Hook_Addr_64 0x5AA847
#define GetTextureInfo_Hook_Addr_65 0x5AA85D

#pragma runtime_checks( "", off )
DWORD ResourceFile_BeginLoading_Func_Addr = ResourceFileBeginLoading_Addr;
void __stdcall ResourceFileBeginLoading(void* ResourceFile, void* unk1, void* unk2)
{
	_asm
	{
		mov edx, ResourceFile
		mov ecx, unk2
		mov eax, unk1
		call ResourceFile_BeginLoading_Func_Addr
	}
}

DWORD bStringHash_EDX = 0;
DWORD bStringHash_Func_Addr = bStringHash_Addr;
unsigned int __stdcall bStringHash(char* StringToHash)
{
	unsigned int result;

	_asm
	{
		mov bStringHash_EDX, edx
		mov edx, StringToHash
		call bStringHash_Func_Addr
		mov result, eax
		mov edx, bStringHash_EDX
	}

	return result;
}

DWORD* (__cdecl* CreateResourceFile)(int a1, int a2, int a3, int a4, int a5) = (DWORD * (__cdecl*)(int, int, int, int, int))CreateResourceFile_Addr;

int(__fastcall* LoadGlobalChunks)() = (int(__fastcall*)())LoadGlobalChunks_Addr;

DWORD* (__cdecl* GetTextureInfo)(unsigned int hash, int returnDefault, int includeUnloadedTextures) = (DWORD * (__cdecl*)(unsigned int, int, int))GetTextureInfo_Addr;
