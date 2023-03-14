#pragma once
#ifndef GAME_PS
#define GAME_PS
#endif

//#define EntryPoint 0x828C25
#define WrongEntryPointErrorString "This .exe is not supported.\nPlease use a NOCD v1.1 NFS.exe."

#define bStringHash_Addr 0x436680
#define CreateResourceFile_Addr 0x6D6DE0
#define ResourceFileBeginLoading_Addr 0x6D9430
#define LoadGlobalChunks_Addr 0x6DA4D0
#define GetTextureInfo_Addr 0x459C10

#define LoadGlobalChunks_Hook_Addr_1 0x6DAC3A

#define GetTextureInfo_Hook_Addr_1 0x458969
#define GetTextureInfo_Hook_Addr_2 0x458A29
#define GetTextureInfo_Hook_Addr_3 0x459170
#define GetTextureInfo_Hook_Addr_4 0x4A2137
#define GetTextureInfo_Hook_Addr_5 0x4A215F
#define GetTextureInfo_Hook_Addr_6 0x4A8E3E
#define GetTextureInfo_Hook_Addr_7 0x4A8E74
#define GetTextureInfo_Hook_Addr_8 0x4A8EAB
#define GetTextureInfo_Hook_Addr_9 0x4A8EE1
#define GetTextureInfo_Hook_Addr_10 0x4A8F1B
#define GetTextureInfo_Hook_Addr_11 0x4A8F51
#define GetTextureInfo_Hook_Addr_12 0x4A8F8B
#define GetTextureInfo_Hook_Addr_13 0x4A8FC2
#define GetTextureInfo_Hook_Addr_14 0x4A8FFD
#define GetTextureInfo_Hook_Addr_15 0x4A903D
#define GetTextureInfo_Hook_Addr_16 0x4ABAE8
#define GetTextureInfo_Hook_Addr_17 0x4AD22D
#define GetTextureInfo_Hook_Addr_18 0x4AD25F
#define GetTextureInfo_Hook_Addr_19 0x4B411F
#define GetTextureInfo_Hook_Addr_20 0x4B417F
#define GetTextureInfo_Hook_Addr_21 0x4B819C
#define GetTextureInfo_Hook_Addr_22 0x4B992B
#define GetTextureInfo_Hook_Addr_23 0x4B9960
#define GetTextureInfo_Hook_Addr_24 0x4BDF5D
#define GetTextureInfo_Hook_Addr_25 0x4C32A5
#define GetTextureInfo_Hook_Addr_26 0x4C36CB
#define GetTextureInfo_Hook_Addr_27 0x4C36FF
#define GetTextureInfo_Hook_Addr_28 0x4C3731
#define GetTextureInfo_Hook_Addr_29 0x4C6CDB
#define GetTextureInfo_Hook_Addr_30 0x4C7379
#define GetTextureInfo_Hook_Addr_31 0x4EC514
#define GetTextureInfo_Hook_Addr_32 0x4EC533
#define GetTextureInfo_Hook_Addr_33J 0x5489D3
#define GetTextureInfo_Hook_Addr_34J 0x558618
#define GetTextureInfo_Hook_Addr_35 0x58DE6A
#define GetTextureInfo_Hook_Addr_36 0x58DF3A
#define GetTextureInfo_Hook_Addr_37 0x58E021
#define GetTextureInfo_Hook_Addr_38 0x58E091
#define GetTextureInfo_Hook_Addr_39 0x592B55
#define GetTextureInfo_Hook_Addr_40 0x59EA11
#define GetTextureInfo_Hook_Addr_41 0x59EA61
#define GetTextureInfo_Hook_Addr_42 0x5A0BFD
#define GetTextureInfo_Hook_Addr_43 0x5A216D
#define GetTextureInfo_Hook_Addr_44 0x5AD674
#define GetTextureInfo_Hook_Addr_45 0x5B5A82
#define GetTextureInfo_Hook_Addr_46 0x5B5A9C
#define GetTextureInfo_Hook_Addr_47 0x5B5FA2
#define GetTextureInfo_Hook_Addr_48 0x5B6279
#define GetTextureInfo_Hook_Addr_49 0x5D1ADF
#define GetTextureInfo_Hook_Addr_50 0x5D1C93
#define GetTextureInfo_Hook_Addr_51 0x6DA6A9
#define GetTextureInfo_Hook_Addr_52 0x6F92F2
#define GetTextureInfo_Hook_Addr_53 0x6F9311
#define GetTextureInfo_Hook_Addr_54 0x6F9330
#define GetTextureInfo_Hook_Addr_55 0x6F934F
#define GetTextureInfo_Hook_Addr_56 0x6F936E
#define GetTextureInfo_Hook_Addr_57 0x6FAE0D
#define GetTextureInfo_Hook_Addr_58 0x7433CD
#define GetTextureInfo_Hook_Addr_59 0x7535F6
#define GetTextureInfo_Hook_Addr_60 0x75360F
#define GetTextureInfo_Hook_Addr_61 0x753628
#define GetTextureInfo_Hook_Addr_62 0x753641
#define GetTextureInfo_Hook_Addr_63 0x754876
#define GetTextureInfo_Hook_Addr_64 0x758024
#define GetTextureInfo_Hook_Addr_65 0x75FC75
#define GetTextureInfo_Hook_Addr_66 0x7636A6
#define GetTextureInfo_Hook_Addr_67 0x76C2DF
#define GetTextureInfo_Hook_Addr_68 0x76C2F3
#define GetTextureInfo_Hook_Addr_69 0x76C307
#define GetTextureInfo_Hook_Addr_70 0x76C350
#define GetTextureInfo_Hook_Addr_71 0x76C54A
#define GetTextureInfo_Hook_Addr_72 0x76C57E
#define GetTextureInfo_Hook_Addr_73 0x76C58E
#define GetTextureInfo_Hook_Addr_74 0x77A6D2
#define GetTextureInfo_Hook_Addr_75 0x77E8D9
#define GetTextureInfo_Hook_Addr_76 0x77E8FF
#define GetTextureInfo_Hook_Addr_77 0x78289E
#define GetTextureInfo_Hook_Addr_78 0x782919
#define GetTextureInfo_Hook_Addr_79 0x782943
#define GetTextureInfo_Hook_Addr_80 0x782994
#define GetTextureInfo_Hook_Addr_81 0x7829DB
#define GetTextureInfo_Hook_Addr_82 0x782B0F
#define GetTextureInfo_Hook_Addr_83 0x782B2E
#define GetTextureInfo_Hook_Addr_84 0x782BA2
#define GetTextureInfo_Hook_Addr_85 0x785A29
#define GetTextureInfo_Hook_Addr_86 0x785A61
#define GetTextureInfo_Hook_Addr_87 0x785A88
#define GetTextureInfo_Hook_Addr_88 0x785AD0
#define GetTextureInfo_Hook_Addr_89 0x785AEF
#define GetTextureInfo_Hook_Addr_90 0x785B58
#define GetTextureInfo_Hook_Addr_91 0x785B70
#define GetTextureInfo_Hook_Addr_92 0x785B8E
#define GetTextureInfo_Hook_Addr_93 0x785C6C
#define GetTextureInfo_Hook_Addr_94 0x785C86
#define GetTextureInfo_Hook_Addr_95 0x785CC9
#define GetTextureInfo_Hook_Addr_96 0x785CE3
#define GetTextureInfo_Hook_Addr_97 0x785D62
#define GetTextureInfo_Hook_Addr_98 0x785D80
#define GetTextureInfo_Hook_Addr_99 0x785D9C
#define GetTextureInfo_Hook_Addr_100 0x787F60
#define GetTextureInfo_Hook_Addr_101 0x787F73
#define GetTextureInfo_Hook_Addr_102 0x78BE5E
#define GetTextureInfo_Hook_Addr_103 0x78BE70
#define GetTextureInfo_Hook_Addr_104 0x78C734
#define GetTextureInfo_Hook_Addr_105 0x7AFF26
#define GetTextureInfo_Hook_Addr_106P 0x01A17796
#define GetTextureInfo_Hook_Addr_107P 0x01A177B5
#define GetTextureInfo_Hook_Addr_108J 0x01A19F25
#define GetTextureInfo_Hook_Addr_109J 0x01DFA029

unsigned int(*bStringHash)(char* StringToHash) = (unsigned int(*)(char*))bStringHash_Addr;

DWORD* (__cdecl* CreateResourceFile)(int a1, int a2, int a3, int a4, int a5) = (DWORD * (__cdecl*)(int, int, int, int, int))CreateResourceFile_Addr;
int(__thiscall* ResourceFileBeginLoading)(DWORD* r, int unk1, int unk2) = (int(__thiscall*)(DWORD*, int, int))ResourceFileBeginLoading_Addr;

int(__fastcall* LoadGlobalChunks)() = (int(__fastcall*)())LoadGlobalChunks_Addr;

DWORD* (__cdecl* GetTextureInfo)(unsigned int hash, int returnDefault, int includeUnloadedTextures) = (DWORD * (__cdecl*)(unsigned int, int, int))GetTextureInfo_Addr;
