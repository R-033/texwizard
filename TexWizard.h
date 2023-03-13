#include "Helpers.h"
#include <map>
#include "json/json.h"
#include <fstream>
#include <iostream>

#ifdef GAME_MW
#include "MW_Address.h"
#endif

#ifdef GAME_CARBON
#include "Carbon_Address.h"
#endif

std::vector<char*> packList = {};
std::map<unsigned int, unsigned int> textureMap = {};

unsigned int(*bStringHash)(char* StringToHash) = (unsigned int(*)(char*))bStringHash_Addr;

DWORD* (__cdecl* CreateResourceFile)(int a1, int a2, int a3, int a4, int a5) = (DWORD * (__cdecl*)(int, int, int, int, int))CreateResourceFile_Addr;
int(__thiscall* ResourceFileBeginLoading)(DWORD* r, int unk1, int unk2) = (int(__thiscall*)(DWORD*, int, int))ResourceFileBeginLoading_Addr;

int(__fastcall* LoadGlobalChunks)() = (int(__fastcall*)())LoadGlobalChunks_Addr;

DWORD*(__cdecl* GetTextureInfo)(unsigned int hash, int returnDefault, int includeUnloadedTextures) = (DWORD*(__cdecl*)(unsigned int, int, int))GetTextureInfo_Addr;

DWORD* __cdecl ReplaceTexture(unsigned int hash, int returnDefault, int includeUnloadedTextures)
{
	if (textureMap.count(hash) > 0)
	{
		hash = textureMap[hash];
	}

	return GetTextureInfo(hash, returnDefault, includeUnloadedTextures);
}

int __fastcall LoadPacks()
{
	int result = LoadGlobalChunks();

	// https://github.com/xan1242/xnfsmodfiles
	for (int index = 0; index < packList.size(); index++)
	{
		DWORD* r = CreateResourceFile((int)packList[index], 1, 0, 0, 0);
		ResourceFileBeginLoading(r, 0, 0);
	}

	return result;
}

void Init()
{
	// load config
	std::ifstream ifs;
	ifs.open("TexWizard.json");

	Json::CharReaderBuilder builder;
	Json::Value root;
	JSONCPP_STRING errs;
	if (!parseFromStream(builder, ifs, &root, &errs))
	{
		MessageBoxA(NULL, "Failed to parse TexWizard configuration.", "TexWizard", MB_ICONERROR);
		return;
	}

	// load texture packs
	Json::Value packs = root["packs"];

	for (int index = 0; index < packs.size(); index++)
	{
		Json::Value pack = packs[index];

		Json::String packString = pack.asString();

		std::string packRoot = packString.c_str();

		std::string configPath = packRoot + "\\meta.json";
		std::string dataPath = packRoot + "\\textures.bin";

		std::ifstream ifs2;
		ifs2.open("..\\" + configPath);

		Json::CharReaderBuilder builder2;
		Json::Value root2;

		JSONCPP_STRING errs2;
		if (!parseFromStream(builder2, ifs2, &root2, &errs2))
		{
			MessageBoxA(NULL, ((std::string)"Failed to parse texture pack configuration " + configPath).c_str(), "TexWizard", MB_ICONERROR);
			continue;
		}

		char* dataPathChar = new char[dataPath.length() + 1];
		strcpy(dataPathChar, dataPath.c_str());

		packList.push_back(dataPathChar);

		Json::Value textures = root2["textures"];

		for (int index = 0; index < textures.size(); index++)
		{
			Json::Value texture = textures[index];

			Json::String key = texture[0].asString();
			Json::String value = texture[1].asString();

			char* keyChar = new char[key.length() + 1];
			strcpy(keyChar, key.c_str());

			char* valueChar = new char[value.length() + 1];
			strcpy(valueChar, value.c_str());

			textureMap[bStringHash(keyChar)] = bStringHash(valueChar);
		}
	}

	// replace LoadGlobalChunks call
	injector::MakeCALL(LoadGlobalChunks_Hook_Addr_1, LoadPacks, true);
	
	// replace all GetTextureInfo calls
	injector::MakeCALL(GetTextureInfo_Hook_Addr_1, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_2, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_3, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_4, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_5, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_6, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_7, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_8, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_9, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_10, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_11, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_12, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_13, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_14, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_15, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_16, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_17, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_18, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_19, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_20, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_21, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_22, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_23, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_24, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_25, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_26, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_27, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_28, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_29, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_30, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_31, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_32, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_33, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_34, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_35, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_36, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_37, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_38, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_39, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_40, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_41, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_42, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_43, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_44, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_45, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_46, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_47, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_48, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_49, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_50, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_51, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_52, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_53, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_54, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_55, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_56, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_57, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_58, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_59, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_60, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_61, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_62, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_63, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_64, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_65, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_66, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_67, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_68, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_69, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_70, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_71, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_72, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_73, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_74, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_75, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_76, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_77, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_78, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_79, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_80, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_81, ReplaceTexture, true);
	
#ifdef GAME_CARBON
	
	injector::MakeCALL(GetTextureInfo_Hook_Addr_82, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_83, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_84, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_85, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_86, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_87, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_88, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_89, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_90, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_91, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_92, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_93, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_94, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_95, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_96, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_97, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_98, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_99, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_100, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_101, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_102, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_103, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_104, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_105, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_106, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_107, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_108, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_109, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_110, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_111, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_112, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_113, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_114, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_115, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_116, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_117, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_118, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_119, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_120, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_121, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_122, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_123, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_124, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_125, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_126, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_127, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_128, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_129, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_130, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_131, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_132, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_133, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_134, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_135, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_136, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_137, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_138, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_139, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_140, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_141, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_142, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_143, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_144, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_145, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_146, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_147, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_148, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_149, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_150, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_151, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_152, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_153, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_154, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_155, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_156, ReplaceTexture, true);

#endif
}