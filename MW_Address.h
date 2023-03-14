#pragma once
#ifndef GAME_MW
#define GAME_MW
#endif

#define EntryPoint 0x7C4040
#define WrongEntryPointErrorString "This .exe is not supported.\nPlease use v1.3 English speed.exe (5,75 MB (6.029.312 bytes))."

#define bStringHash_Addr 0x460BF0
#define CreateResourceFile_Addr 0x65FD30
#define ResourceFileBeginLoading_Addr 0x6616F0
#define LoadGlobalChunks_Addr 0x664780
#define GetTextureInfo_Addr 0x503400


#define LoadGlobalChunks_Hook_Addr_1 0x6660c0

#define GetTextureInfo_Hook_Addr_1 0x4465B2
#define GetTextureInfo_Hook_Addr_2 0x450d8d
#define GetTextureInfo_Hook_Addr_3 0x503579
#define GetTextureInfo_Hook_Addr_4 0x5035e9
#define GetTextureInfo_Hook_Addr_5 0x50364A
#define GetTextureInfo_Hook_Addr_6 0x5036AE
#define GetTextureInfo_Hook_Addr_7 0x5036BE
#define GetTextureInfo_Hook_Addr_8 0x5037c8
#define GetTextureInfo_Hook_Addr_9 0x5037db
#define GetTextureInfo_Hook_Addr_10 0x5037ee
#define GetTextureInfo_Hook_Addr_11 0x503801
#define GetTextureInfo_Hook_Addr_12 0x503814
#define GetTextureInfo_Hook_Addr_13 0x503dae
#define GetTextureInfo_Hook_Addr_14 0x504F4D
#define GetTextureInfo_Hook_Addr_15 0x504fc8
#define GetTextureInfo_Hook_Addr_16 0x5051f5
#define GetTextureInfo_Hook_Addr_17 0x5052f7
#define GetTextureInfo_Hook_Addr_18 0x50535e
#define GetTextureInfo_Hook_Addr_19 0x505a2d
#define GetTextureInfo_Hook_Addr_20 0x5152c7
#define GetTextureInfo_Hook_Addr_21 0x515337
#define GetTextureInfo_Hook_Addr_22 0x5153be
#define GetTextureInfo_Hook_Addr_23 0x51548e
#define GetTextureInfo_Hook_Addr_24 0x515651
#define GetTextureInfo_Hook_Addr_25 0x5156F1
#define GetTextureInfo_Hook_Addr_26 0x5156a1
#define GetTextureInfo_Hook_Addr_27 0x515741
#define GetTextureInfo_Hook_Addr_28 0x517a15
#define GetTextureInfo_Hook_Addr_29 0x51f562
#define GetTextureInfo_Hook_Addr_30 0x56feee
#define GetTextureInfo_Hook_Addr_31 0x57229c
#define GetTextureInfo_Hook_Addr_32 0x579464
#define GetTextureInfo_Hook_Addr_33 0x579554
#define GetTextureInfo_Hook_Addr_34 0x585ca2
#define GetTextureInfo_Hook_Addr_35 0x586012
#define GetTextureInfo_Hook_Addr_36 0x5912c2
#define GetTextureInfo_Hook_Addr_37 0x591376
#define GetTextureInfo_Hook_Addr_38 0x59a166
#define GetTextureInfo_Hook_Addr_39 0x59a180
#define GetTextureInfo_Hook_Addr_40 0x59a5f2
#define GetTextureInfo_Hook_Addr_41 0x59a885
#define GetTextureInfo_Hook_Addr_42 0x6648f5
#define GetTextureInfo_Hook_Addr_43 0x6C57F6
#define GetTextureInfo_Hook_Addr_44 0x6D1C72
#define GetTextureInfo_Hook_Addr_45 0x6D740E
#define GetTextureInfo_Hook_Addr_46 0x6bf552
#define GetTextureInfo_Hook_Addr_47 0x6bf571
#define GetTextureInfo_Hook_Addr_48 0x6bf590
#define GetTextureInfo_Hook_Addr_49 0x6bf609
#define GetTextureInfo_Hook_Addr_50 0x6bf775
#define GetTextureInfo_Hook_Addr_51 0x6bf7e1
#define GetTextureInfo_Hook_Addr_52 0x6c58e0
#define GetTextureInfo_Hook_Addr_53 0x6c5aac
#define GetTextureInfo_Hook_Addr_54 0x6d03cc
#define GetTextureInfo_Hook_Addr_55 0x6d1d6e
#define GetTextureInfo_Hook_Addr_56 0x6d1d8d
#define GetTextureInfo_Hook_Addr_57 0x6d1dac
#define GetTextureInfo_Hook_Addr_58 0x6d4407
#define GetTextureInfo_Hook_Addr_59 0x6d471d
#define GetTextureInfo_Hook_Addr_60 0x6dae65
#define GetTextureInfo_Hook_Addr_61 0x6dc38c
#define GetTextureInfo_Hook_Addr_62 0x7222de
#define GetTextureInfo_Hook_Addr_63 0x737103
#define GetTextureInfo_Hook_Addr_64 0x738210
#define GetTextureInfo_Hook_Addr_65 0x739EEA
#define GetTextureInfo_Hook_Addr_66 0x739F17
#define GetTextureInfo_Hook_Addr_67 0x73c6d0
#define GetTextureInfo_Hook_Addr_68 0x74910d
#define GetTextureInfo_Hook_Addr_69 0x74953b
#define GetTextureInfo_Hook_Addr_70 0x7496b8
#define GetTextureInfo_Hook_Addr_71 0x74972b
#define GetTextureInfo_Hook_Addr_72 0x749a43
#define GetTextureInfo_Hook_Addr_73 0x749a53
#define GetTextureInfo_Hook_Addr_74 0x75fc0c
#define GetTextureInfo_Hook_Addr_75 0x75fc1f
#define GetTextureInfo_Hook_Addr_76 0x75fc8c
#define GetTextureInfo_Hook_Addr_77 0x75fc9e
#define GetTextureInfo_Hook_Addr_78 0x7B42DF
#define GetTextureInfo_Hook_Addr_79 0x7B432D
#define GetTextureInfo_Hook_Addr_80 0x7a352f
#define GetTextureInfo_Hook_Addr_81 0x7b3320

unsigned int(*bStringHash)(char* StringToHash) = (unsigned int(*)(char*))bStringHash_Addr;

DWORD* (__cdecl* CreateResourceFile)(int a1, int a2, int a3, int a4, int a5) = (DWORD * (__cdecl*)(int, int, int, int, int))CreateResourceFile_Addr;
int(__thiscall* ResourceFileBeginLoading)(DWORD* r, int unk1, int unk2) = (int(__thiscall*)(DWORD*, int, int))ResourceFileBeginLoading_Addr;

int(__fastcall* LoadGlobalChunks)() = (int(__fastcall*)())LoadGlobalChunks_Addr;

DWORD* (__cdecl* GetTextureInfo)(unsigned int hash, int returnDefault, int includeUnloadedTextures) = (DWORD * (__cdecl*)(unsigned int, int, int))GetTextureInfo_Addr;
