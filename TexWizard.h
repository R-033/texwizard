#include "Helpers.h"
#include <map>
#include "json/json.h"
#include <fstream>
#include <iostream>

std::vector<char*> packList = {};
std::map<unsigned int, unsigned int> textureMap = {};

unsigned int(*bStringHash)(char* StringToHash) = (unsigned int(*)(char*))0x460BF0;

DWORD* (__cdecl* CreateResourceFile)(int a1, int a2, int a3, int a4, int a5) = (DWORD * (__cdecl*)(int, int, int, int, int))0x65FD30;
int(__thiscall* ResourceFileBeginLoading)(DWORD* r, int unk1, int unk2) = (int(__thiscall*)(DWORD*, int, int))0x6616F0;

int(__fastcall* LoadGlobalChunks)() = (int(__fastcall*)())0x664780;

DWORD*(__cdecl* GetTextureInfo)(unsigned int hash, int returnDefault, int includeUnloadedTextures) = (DWORD*(__cdecl*)(unsigned int, int, int))0x503400;

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
	injector::MakeCALL(0x6660c0, LoadPacks, true);

	// replace all GetTextureInfo calls
	injector::MakeCALL(0x450d8d, ReplaceTexture, true);
	injector::MakeCALL(0x5035e9, ReplaceTexture, true);
	injector::MakeCALL(0x5037c8, ReplaceTexture, true);
	injector::MakeCALL(0x5037db, ReplaceTexture, true);
	injector::MakeCALL(0x5037ee, ReplaceTexture, true);
	injector::MakeCALL(0x503801, ReplaceTexture, true);
	injector::MakeCALL(0x503814, ReplaceTexture, true);
	injector::MakeCALL(0x503dae, ReplaceTexture, true);
	injector::MakeCALL(0x504fc8, ReplaceTexture, true);
	injector::MakeCALL(0x5051f5, ReplaceTexture, true);
	injector::MakeCALL(0x5052f7, ReplaceTexture, true);
	injector::MakeCALL(0x50535e, ReplaceTexture, true);
	injector::MakeCALL(0x505a2d, ReplaceTexture, true);
	injector::MakeCALL(0x5152c7, ReplaceTexture, true);
	injector::MakeCALL(0x515337, ReplaceTexture, true);
	injector::MakeCALL(0x5153be, ReplaceTexture, true);
	injector::MakeCALL(0x51548e, ReplaceTexture, true);
	injector::MakeCALL(0x5156a1, ReplaceTexture, true);
	injector::MakeCALL(0x515741, ReplaceTexture, true);
	injector::MakeCALL(0x517a15, ReplaceTexture, true);
	injector::MakeCALL(0x51f562, ReplaceTexture, true);
	injector::MakeCALL(0x56feee, ReplaceTexture, true);
	injector::MakeCALL(0x57229c, ReplaceTexture, true);
	injector::MakeCALL(0x579464, ReplaceTexture, true);
	injector::MakeCALL(0x579554, ReplaceTexture, true);
	injector::MakeCALL(0x585ca2, ReplaceTexture, true);
	injector::MakeCALL(0x586012, ReplaceTexture, true);
	injector::MakeCALL(0x5912c2, ReplaceTexture, true);
	injector::MakeCALL(0x591376, ReplaceTexture, true);
	injector::MakeCALL(0x59a166, ReplaceTexture, true);
	injector::MakeCALL(0x59a180, ReplaceTexture, true);
	injector::MakeCALL(0x59a5f2, ReplaceTexture, true);
	injector::MakeCALL(0x59a885, ReplaceTexture, true);
	injector::MakeCALL(0x6648f5, ReplaceTexture, true);
	injector::MakeCALL(0x6bf552, ReplaceTexture, true);
	injector::MakeCALL(0x6bf571, ReplaceTexture, true);
	injector::MakeCALL(0x6bf590, ReplaceTexture, true);
	injector::MakeCALL(0x6bf609, ReplaceTexture, true);
	injector::MakeCALL(0x6bf775, ReplaceTexture, true);
	injector::MakeCALL(0x6bf7e1, ReplaceTexture, true);
	injector::MakeCALL(0x6c58e0, ReplaceTexture, true);
	injector::MakeCALL(0x6c5aac, ReplaceTexture, true);
	injector::MakeCALL(0x6d03cc, ReplaceTexture, true);
	injector::MakeCALL(0x6d1d6e, ReplaceTexture, true);
	injector::MakeCALL(0x6d1d8d, ReplaceTexture, true);
	injector::MakeCALL(0x6d1dac, ReplaceTexture, true);
	injector::MakeCALL(0x6d4407, ReplaceTexture, true);
	injector::MakeCALL(0x6d471d, ReplaceTexture, true);
	injector::MakeCALL(0x6dae65, ReplaceTexture, true);
	injector::MakeCALL(0x6dc38c, ReplaceTexture, true);
	injector::MakeCALL(0x7222de, ReplaceTexture, true);
	injector::MakeCALL(0x737103, ReplaceTexture, true);
	injector::MakeCALL(0x738210, ReplaceTexture, true);
	injector::MakeCALL(0x73c6d0, ReplaceTexture, true);
	injector::MakeCALL(0x74953b, ReplaceTexture, true);
	injector::MakeCALL(0x7496b8, ReplaceTexture, true);
	injector::MakeCALL(0x74972b, ReplaceTexture, true);
	injector::MakeCALL(0x74910d, ReplaceTexture, true);
	injector::MakeCALL(0x749a43, ReplaceTexture, true);
	injector::MakeCALL(0x749a53, ReplaceTexture, true);
	injector::MakeCALL(0x75fc0c, ReplaceTexture, true);
	injector::MakeCALL(0x75fc1f, ReplaceTexture, true);
	injector::MakeCALL(0x75fc8c, ReplaceTexture, true);
	injector::MakeCALL(0x75fc9e, ReplaceTexture, true);
	injector::MakeCALL(0x7a352f, ReplaceTexture, true);
	injector::MakeCALL(0x7b3320, ReplaceTexture, true);
}