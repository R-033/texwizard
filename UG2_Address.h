#pragma once
#ifndef GAME_UG2
#define GAME_UG2
#endif

#define EntryPoint 0x75BCC7
#define WrongEntryPointErrorString "This .exe is not supported.\nPlease use v1.2 NTSC speed2.exe (4,57 MB (4.800.512 bytes))."

#define bStringHash_Addr 0x43DB50
#define CreateResourceFile_Addr 0x57CEF0
#define ResourceFileBeginLoading_Addr 0x57BD70
#define LoadGlobalChunks_Addr 0x57FB40
#define GetTextureInfo_Addr 0x4901D0


#define LoadGlobalChunks_Hook_Addr_1 0x57ED99

#define GetTextureInfo_Hook_Addr_1 0x4398C8
#define GetTextureInfo_Hook_Addr_2 0x44823E
#define GetTextureInfo_Hook_Addr_3 0x448252
#define GetTextureInfo_Hook_Addr_4 0x448266
#define GetTextureInfo_Hook_Addr_5 0x490319
#define GetTextureInfo_Hook_Addr_6 0x49034A
#define GetTextureInfo_Hook_Addr_7 0x49035D
#define GetTextureInfo_Hook_Addr_8 0x490370
#define GetTextureInfo_Hook_Addr_9 0x490383
#define GetTextureInfo_Hook_Addr_10 0x490396
#define GetTextureInfo_Hook_Addr_11 0x4905E0
#define GetTextureInfo_Hook_Addr_12 0x4907C5
#define GetTextureInfo_Hook_Addr_13 0x490897
#define GetTextureInfo_Hook_Addr_14 0x4908FE
#define GetTextureInfo_Hook_Addr_15 0x49126D
#define GetTextureInfo_Hook_Addr_16 0x491CCE
#define GetTextureInfo_Hook_Addr_17 0x495DA5
#define GetTextureInfo_Hook_Addr_18 0x4A2430
#define GetTextureInfo_Hook_Addr_19 0x4A2479
#define GetTextureInfo_Hook_Addr_20 0x4A5375
#define GetTextureInfo_Hook_Addr_21 0x4AFE22
#define GetTextureInfo_Hook_Addr_22 0x4AFE78
#define GetTextureInfo_Hook_Addr_23 0x4B0358
#define GetTextureInfo_Hook_Addr_24 0x4B2560
#define GetTextureInfo_Hook_Addr_25 0x4B25B6
#define GetTextureInfo_Hook_Addr_26 0x4B53B0
#define GetTextureInfo_Hook_Addr_27 0x4BE463
#define GetTextureInfo_Hook_Addr_28 0x4BE4B9
#define GetTextureInfo_Hook_Addr_29 0x4C6704
#define GetTextureInfo_Hook_Addr_30 0x4C67F4
#define GetTextureInfo_Hook_Addr_31 0x4CDDBD
#define GetTextureInfo_Hook_Addr_32 0x4CDF5A
#define GetTextureInfo_Hook_Addr_33 0x4F68ED
#define GetTextureInfo_Hook_Addr_34 0x50B50F
#define GetTextureInfo_Hook_Addr_35 0x50BBF2
#define GetTextureInfo_Hook_Addr_36 0x50CB7E
#define GetTextureInfo_Hook_Addr_37 0x50CC3E
#define GetTextureInfo_Hook_Addr_38 0x5109FE
#define GetTextureInfo_Hook_Addr_39 0x510A1D
#define GetTextureInfo_Hook_Addr_40 0x510A39
#define GetTextureInfo_Hook_Addr_41 0x510A55
#define GetTextureInfo_Hook_Addr_42 0x51BEFC
#define GetTextureInfo_Hook_Addr_43 0x53688A
#define GetTextureInfo_Hook_Addr_44 0x536ADE
#define GetTextureInfo_Hook_Addr_45 0x536D0E
#define GetTextureInfo_Hook_Addr_46 0x53B9B0
#define GetTextureInfo_Hook_Addr_47 0x57FBFA
#define GetTextureInfo_Hook_Addr_48 0x5B98C2
#define GetTextureInfo_Hook_Addr_49 0x5B98E1
#define GetTextureInfo_Hook_Addr_50 0x5B9900
#define GetTextureInfo_Hook_Addr_51 0x5B993C
#define GetTextureInfo_Hook_Addr_52 0x5B995A
#define GetTextureInfo_Hook_Addr_53 0x5B9978
#define GetTextureInfo_Hook_Addr_54 0x5B9996
#define GetTextureInfo_Hook_Addr_55 0x5B99B4
#define GetTextureInfo_Hook_Addr_56 0x5B99D2
#define GetTextureInfo_Hook_Addr_57 0x5BC706
#define GetTextureInfo_Hook_Addr_58 0x5BC8B0
#define GetTextureInfo_Hook_Addr_59 0x5BCA2A
#define GetTextureInfo_Hook_Addr_60 0x5C5762
#define GetTextureInfo_Hook_Addr_61 0x5C73C8
#define GetTextureInfo_Hook_Addr_62 0x5C7BDC
#define GetTextureInfo_Hook_Addr_63 0x5CBB46
#define GetTextureInfo_Hook_Addr_64 0x5CF6A1
#define GetTextureInfo_Hook_Addr_65 0x5D32AA
#define GetTextureInfo_Hook_Addr_66 0x60C7F5
#define GetTextureInfo_Hook_Addr_67 0x613074
#define GetTextureInfo_Hook_Addr_68 0x613092
#define GetTextureInfo_Hook_Addr_69 0x61D7AD
#define GetTextureInfo_Hook_Addr_70 0x61DAA7
#define GetTextureInfo_Hook_Addr_71 0x61DB0A
#define GetTextureInfo_Hook_Addr_72 0x61DE9D
#define GetTextureInfo_Hook_Addr_73 0x61DED3
#define GetTextureInfo_Hook_Addr_74 0x61DEE3
#define GetTextureInfo_Hook_Addr_75 0x62064A
#define GetTextureInfo_Hook_Addr_76 0x638700
#define GetTextureInfo_Hook_Addr_77 0x638713
#define GetTextureInfo_Hook_Addr_78 0x638827
#define GetTextureInfo_Hook_Addr_79 0x638858
#define GetTextureInfo_Hook_Addr_80 0x638877
#define GetTextureInfo_Hook_Addr_81 0x638889

unsigned int(*bStringHash)(char* StringToHash) = (unsigned int(*)(char*))bStringHash_Addr;

DWORD* (__cdecl* CreateResourceFile)(int a1, int a2, int a3, int a4, int a5) = (DWORD * (__cdecl*)(int, int, int, int, int))CreateResourceFile_Addr;
int(__thiscall* ResourceFileBeginLoading)(DWORD* r, int unk1, int unk2) = (int(__thiscall*)(DWORD*, int, int))ResourceFileBeginLoading_Addr;

int(__fastcall* LoadGlobalChunks)() = (int(__fastcall*)())LoadGlobalChunks_Addr;

DWORD* (__cdecl* GetTextureInfo)(unsigned int hash, int returnDefault, int includeUnloadedTextures) = (DWORD * (__cdecl*)(unsigned int, int, int))GetTextureInfo_Addr;
