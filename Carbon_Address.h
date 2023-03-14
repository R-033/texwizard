#pragma once
#ifndef GAME_CARBON
#define GAME_CARBON
#endif

#define EntryPoint 0x87E926
#define WrongEntryPointErrorString "This .exe is not supported.\nPlease use v1.4 English nfsc.exe (6,88 MB (7.217.152 bytes))."

#define bStringHash_Addr 0x471050
#define CreateResourceFile_Addr 0x6B32C0
#define ResourceFileBeginLoading_Addr 0x6B5910
#define LoadGlobalChunks_Addr 0x6B6E00
#define GetTextureInfo_Addr 0x55CFD0

#define LoadGlobalChunks_Hook_Addr_1 0x6B776F

#define GetTextureInfo_Hook_Addr_1 0x44E3E2
#define GetTextureInfo_Hook_Addr_2 0x44E401
#define GetTextureInfo_Hook_Addr_3 0x45F3A1
#define GetTextureInfo_Hook_Addr_4 0x45F3C0
#define GetTextureInfo_Hook_Addr_5 0x4B6BC1
#define GetTextureInfo_Hook_Addr_6 0x4BABC8
#define GetTextureInfo_Hook_Addr_7 0x4BABF1
#define GetTextureInfo_Hook_Addr_8 0x4C457B
#define GetTextureInfo_Hook_Addr_9 0x55D149
#define GetTextureInfo_Hook_Addr_10 0x55D1B9
#define GetTextureInfo_Hook_Addr_11 0x55D22A
#define GetTextureInfo_Hook_Addr_12 0x55D27E
#define GetTextureInfo_Hook_Addr_13 0x55D28E
#define GetTextureInfo_Hook_Addr_14 0x55D348
#define GetTextureInfo_Hook_Addr_15 0x55D35B
#define GetTextureInfo_Hook_Addr_16 0x55D36E
#define GetTextureInfo_Hook_Addr_17 0x55D381
#define GetTextureInfo_Hook_Addr_18 0x55D394
#define GetTextureInfo_Hook_Addr_19 0x55D850
#define GetTextureInfo_Hook_Addr_20 0x55DA51
#define GetTextureInfo_Hook_Addr_21 0x55DA80
#define GetTextureInfo_Hook_Addr_22 0x55DB0D
#define GetTextureInfo_Hook_Addr_23 0x55DB8E
#define GetTextureInfo_Hook_Addr_24 0x55DD85
#define GetTextureInfo_Hook_Addr_25 0x55DE57
#define GetTextureInfo_Hook_Addr_26 0x55DF7F
#define GetTextureInfo_Hook_Addr_27 0x55E109
#define GetTextureInfo_Hook_Addr_28 0x570837
#define GetTextureInfo_Hook_Addr_29 0x5708A7
#define GetTextureInfo_Hook_Addr_30 0x57092E
#define GetTextureInfo_Hook_Addr_31 0x5709FE
#define GetTextureInfo_Hook_Addr_32 0x570B01
#define GetTextureInfo_Hook_Addr_33 0x570B51
#define GetTextureInfo_Hook_Addr_34 0x570BA1
#define GetTextureInfo_Hook_Addr_35 0x570BF1
#define GetTextureInfo_Hook_Addr_36 0x57F39E
#define GetTextureInfo_Hook_Addr_37 0x5822C1
#define GetTextureInfo_Hook_Addr_38 0x582302
#define GetTextureInfo_Hook_Addr_39 0x582325
#define GetTextureInfo_Hook_Addr_40 0x585385
#define GetTextureInfo_Hook_Addr_41 0x585F6C
#define GetTextureInfo_Hook_Addr_42 0x586032
#define GetTextureInfo_Hook_Addr_43 0x586542
#define GetTextureInfo_Hook_Addr_44 0x590C9E
#define GetTextureInfo_Hook_Addr_45 0x590DF6
#define GetTextureInfo_Hook_Addr_46 0x593630
#define GetTextureInfo_Hook_Addr_47 0x596DE5
#define GetTextureInfo_Hook_Addr_48 0x596F9E
#define GetTextureInfo_Hook_Addr_49 0x598FF6
#define GetTextureInfo_Hook_Addr_50 0x599010
#define GetTextureInfo_Hook_Addr_51 0x599452
#define GetTextureInfo_Hook_Addr_52 0x5996ED
#define GetTextureInfo_Hook_Addr_53 0x59AA73
#define GetTextureInfo_Hook_Addr_54 0x59F10C
#define GetTextureInfo_Hook_Addr_55 0x59F120
#define GetTextureInfo_Hook_Addr_56 0x59F482
#define GetTextureInfo_Hook_Addr_57 0x59F4AC
#define GetTextureInfo_Hook_Addr_58 0x59F789
#define GetTextureInfo_Hook_Addr_59 0x5D8654
#define GetTextureInfo_Hook_Addr_60 0x5D8744
#define GetTextureInfo_Hook_Addr_61 0x5E4F6E
#define GetTextureInfo_Hook_Addr_62 0x6B6F9E
#define GetTextureInfo_Hook_Addr_63 0x708E98
#define GetTextureInfo_Hook_Addr_64 0x70FB72
#define GetTextureInfo_Hook_Addr_65 0x70FB91
#define GetTextureInfo_Hook_Addr_66 0x70FBB0
#define GetTextureInfo_Hook_Addr_67 0x70FBCF
#define GetTextureInfo_Hook_Addr_68 0x70FBEE
#define GetTextureInfo_Hook_Addr_69 0x70FC72
#define GetTextureInfo_Hook_Addr_70 0x70FDCA
#define GetTextureInfo_Hook_Addr_71 0x70FE31
#define GetTextureInfo_Hook_Addr_72 0x71336C
#define GetTextureInfo_Hook_Addr_73 0x71CE22
#define GetTextureInfo_Hook_Addr_74 0x722D8C
#define GetTextureInfo_Hook_Addr_75 0x73AB2A
#define GetTextureInfo_Hook_Addr_76 0x73C267
#define GetTextureInfo_Hook_Addr_77 0x73C282
#define GetTextureInfo_Hook_Addr_78 0x73C29E
#define GetTextureInfo_Hook_Addr_79 0x73C2BA
#define GetTextureInfo_Hook_Addr_80 0x73D37E
#define GetTextureInfo_Hook_Addr_81 0x73DF85
#define GetTextureInfo_Hook_Addr_82 0x73E025
#define GetTextureInfo_Hook_Addr_83 0x73E125
#define GetTextureInfo_Hook_Addr_84 0x73E355
#define GetTextureInfo_Hook_Addr_85 0x73E4C5
#define GetTextureInfo_Hook_Addr_86 0x73E4E5
#define GetTextureInfo_Hook_Addr_87 0x73F9B2
#define GetTextureInfo_Hook_Addr_88 0x73F9D1
#define GetTextureInfo_Hook_Addr_89 0x73F9F0
#define GetTextureInfo_Hook_Addr_90 0x740CB7
#define GetTextureInfo_Hook_Addr_91 0x748230
#define GetTextureInfo_Hook_Addr_92 0x749A89
#define GetTextureInfo_Hook_Addr_93 0x749C38
#define GetTextureInfo_Hook_Addr_94 0x749C63
#define GetTextureInfo_Hook_Addr_95 0x74EB3B
#define GetTextureInfo_Hook_Addr_96 0x74F011
#define GetTextureInfo_Hook_Addr_97 0x7590AC
#define GetTextureInfo_Hook_Addr_98 0x7590DD
#define GetTextureInfo_Hook_Addr_99 0x7591B4
#define GetTextureInfo_Hook_Addr_100 0x759E7B
#define GetTextureInfo_Hook_Addr_101 0x75AA4C
#define GetTextureInfo_Hook_Addr_102 0x75AA68
#define GetTextureInfo_Hook_Addr_103 0x798F4E
#define GetTextureInfo_Hook_Addr_104 0x79ACE5
#define GetTextureInfo_Hook_Addr_105 0x79AD04
#define GetTextureInfo_Hook_Addr_106 0x79AD28
#define GetTextureInfo_Hook_Addr_107 0x79AD53
#define GetTextureInfo_Hook_Addr_108 0x7ACCB3
#define GetTextureInfo_Hook_Addr_109 0x7AEFF4
#define GetTextureInfo_Hook_Addr_110 0x7AF00D
#define GetTextureInfo_Hook_Addr_111 0x7AF026
#define GetTextureInfo_Hook_Addr_112 0x7AF03F
#define GetTextureInfo_Hook_Addr_113 0x7B117A
#define GetTextureInfo_Hook_Addr_114 0x7B11A7
#define GetTextureInfo_Hook_Addr_115 0x7B3685
#define GetTextureInfo_Hook_Addr_116 0x7B9CE6
#define GetTextureInfo_Hook_Addr_117 0x7BE2AA
#define GetTextureInfo_Hook_Addr_118 0x7C3C3F
#define GetTextureInfo_Hook_Addr_119 0x7C3C53
#define GetTextureInfo_Hook_Addr_120 0x7C3C67
#define GetTextureInfo_Hook_Addr_121 0x7C3CB2
#define GetTextureInfo_Hook_Addr_122 0x7C3E3A
#define GetTextureInfo_Hook_Addr_123 0x7C3E6C
#define GetTextureInfo_Hook_Addr_124 0x7C3E7C
#define GetTextureInfo_Hook_Addr_125 0x7D13A4
#define GetTextureInfo_Hook_Addr_126 0x7D13DF
#define GetTextureInfo_Hook_Addr_127 0x7D148B
#define GetTextureInfo_Hook_Addr_128 0x7D14E8
#define GetTextureInfo_Hook_Addr_129 0x7D15AF
#define GetTextureInfo_Hook_Addr_130 0x7D15F5
#define GetTextureInfo_Hook_Addr_131 0x7D758F
#define GetTextureInfo_Hook_Addr_132 0x7D75AE
#define GetTextureInfo_Hook_Addr_133 0x7D7637
#define GetTextureInfo_Hook_Addr_134 0x7D9DA9
#define GetTextureInfo_Hook_Addr_135 0x7D9DBC
#define GetTextureInfo_Hook_Addr_136 0x7DBA29
#define GetTextureInfo_Hook_Addr_137 0x7DBA55
#define GetTextureInfo_Hook_Addr_138 0x7DBA81
#define GetTextureInfo_Hook_Addr_139 0x7DBABC
#define GetTextureInfo_Hook_Addr_140 0x7DBAFB
#define GetTextureInfo_Hook_Addr_141 0x7DBB35
#define GetTextureInfo_Hook_Addr_142 0x7DBB4D
#define GetTextureInfo_Hook_Addr_143 0x7DBB6B
#define GetTextureInfo_Hook_Addr_144 0x7DBC2C
#define GetTextureInfo_Hook_Addr_145 0x7DBC46
#define GetTextureInfo_Hook_Addr_146 0x7DBC87
#define GetTextureInfo_Hook_Addr_147 0x7DBCA1
#define GetTextureInfo_Hook_Addr_148 0x7DBD27
#define GetTextureInfo_Hook_Addr_149 0x7DBD3D
#define GetTextureInfo_Hook_Addr_150 0x7DBD55
#define GetTextureInfo_Hook_Addr_151 0x7E5A73
#define GetTextureInfo_Hook_Addr_152 0x7E5A85
#define GetTextureInfo_Hook_Addr_153 0x813EBE
#define GetTextureInfo_Hook_Addr_154 0x83DED6
#define GetTextureInfo_Hook_Addr_155 0x84D584
#define GetTextureInfo_Hook_Addr_156 0x84D681

unsigned int(*bStringHash)(char* StringToHash) = (unsigned int(*)(char*))bStringHash_Addr;

DWORD* (__cdecl* CreateResourceFile)(int a1, int a2, int a3, int a4, int a5) = (DWORD * (__cdecl*)(int, int, int, int, int))CreateResourceFile_Addr;
int(__thiscall* ResourceFileBeginLoading)(DWORD* r, int unk1, int unk2) = (int(__thiscall*)(DWORD*, int, int))ResourceFileBeginLoading_Addr;

int(__fastcall* LoadGlobalChunks)() = (int(__fastcall*)())LoadGlobalChunks_Addr;

DWORD* (__cdecl* GetTextureInfo)(unsigned int hash, int returnDefault, int includeUnloadedTextures) = (DWORD * (__cdecl*)(unsigned int, int, int))GetTextureInfo_Addr;
