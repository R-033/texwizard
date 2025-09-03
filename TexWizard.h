#pragma once
#include "Helpers.h"
#include <map>
#include "json/json.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <Windows.h>
#include <set>
#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")

#ifdef GAME_UG
#include "UG_Address.h"
#endif
#ifdef GAME_UG2
#include "UG2_Address.h"
#endif
#ifdef GAME_MW
#include "MW_Address.h"
#endif
#ifdef GAME_CARBON
#include "Carbon_Address.h"
#endif
#ifdef GAME_PS
#include "PS_Address.h"
#endif
#ifdef GAME_UC
#include "UC_Address.h"
#endif

std::vector<char*> packList = {};
std::map<unsigned int, unsigned int> textureMap = {};

static bool open_rel_or_up(std::ifstream& ifs, const std::string& rel)
{
	ifs.open(rel, std::ios::in | std::ios::binary);
	if (ifs.is_open()) return true;
	ifs.clear();
	ifs.open("..\\" + rel, std::ios::in | std::ios::binary);
	return ifs.is_open();
}

static bool try_read_json_file(const std::string& relPath, Json::Value& outRoot, std::string* optErr = nullptr)
{
	std::ifstream ifs;
	if (!open_rel_or_up(ifs, relPath))
	{
		if (optErr) *optErr = "open failed";
		return false;
	}
	Json::CharReaderBuilder b;
	JSONCPP_STRING errs;
	bool ok = parseFromStream(b, ifs, &outRoot, &errs);
	if (!ok && optErr) *optErr = errs.c_str();
	return ok;
}

static void parse_key_or_hex_to_hash(const std::string& s, unsigned int& outHash)
{
	if (s.size() > 2 && (s[0] == '0') && (s[1] == 'x' || s[1] == 'X'))
	{
		std::istringstream conv(s.substr(2));
		conv >> std::hex >> outHash;
		return;
	}
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());
	outHash = bStringHash(c);
	delete[] c;
}

static std::string dirname_of(const std::string& p)
{
	size_t pos = p.find_last_of("\\/");
	return (pos == std::string::npos) ? std::string(".") : p.substr(0, pos);
}

static std::string join_path(const std::string& a, const std::string& b)
{
	if (a.empty()) return b;
	char last = a.back();
	if (last == '\\' || last == '/') return a + b;
	return a + "\\" + b;
}

static bool try_read_json_file_resolved(const std::string& path, Json::Value& outRoot)
{
	std::ifstream ifs(path, std::ios::in | std::ios::binary);
	if (!ifs.is_open())
	{
		std::string up = std::string("..\\") + path;
		ifs.open(up, std::ios::in | std::ios::binary);
		if (!ifs.is_open()) return false;
	}
	Json::CharReaderBuilder b;
	JSONCPP_STRING errs;
	return parseFromStream(b, ifs, &outRoot, &errs);
}

static std::string exe_dir()
{
	char buf[MAX_PATH]{ 0 };
	DWORD n = GetModuleFileNameA(NULL, buf, MAX_PATH);
	if (n == 0 || n >= MAX_PATH) return ".";
	std::string s(buf);
	size_t p = s.find_last_of("\\/");
	return (p == std::string::npos) ? std::string(".") : s.substr(0, p);
}


DWORD* __cdecl ReplaceTexture(unsigned int hash, int returnDefault, int includeUnloadedTextures)
{
	if (textureMap.count(hash) > 0)
		hash = textureMap[hash];

	return GetTextureInfo(hash, returnDefault, includeUnloadedTextures);
}

int __fastcall LoadPacks()
{
#ifdef GAME_UC
	int result = LoadGlobalAChunks();
#else
	int result = LoadGlobalChunks();
#endif

	// https://github.com/xan1242/xnfsmodfiles
	for (int index = 0; index < (int)packList.size(); index++)
	{
		DWORD* r = CreateResourceFile((int)packList[index], 1, 0, 0, 0);
#ifdef GAME_UC
		r[10] = 0x2000;
		r[11] = *(int*)0xD3BDD4;
		r[9] = SharedStringPoolAllocate(packList[index]);
#endif
		ResourceFileBeginLoading(r, 0, 0);
	}

	return result;
}

void Init()
{
	SetCurrentDirectoryA(exe_dir().c_str());

	const char* roots[2] = { "TexturePacks", "scripts\\TexturePacks" };
	std::set<std::string> seenJson;

	for (int r = 0; r < 2; ++r)
	{
		char pattern[MAX_PATH]{ 0 };
		snprintf(pattern, sizeof(pattern), "%s\\*.json", roots[r]);

		WIN32_FIND_DATAA fd{};
		HANDLE hFind = FindFirstFileA(pattern, &fd);
		if (hFind == INVALID_HANDLE_VALUE) continue;

		do
		{
			if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				continue;

			std::string jsonPath = join_path(roots[r], fd.cFileName);

			std::string jsonKey = jsonPath;
			for (auto& c : jsonKey) if (c == '/') c = '\\';
			if (seenJson.count(jsonKey)) continue;
			seenJson.insert(jsonKey);

			std::string fname(fd.cFileName);
			size_t dot = fname.find_last_of('.');
			std::string base = (dot == std::string::npos) ? fname : fname.substr(0, dot);


			std::string bin1 = std::string("TexturePacks\\") + base + ".bin";
			std::string bin1U = std::string("TexturePacks\\") + base + ".BIN";
			std::string bin2 = std::string("scripts\\TexturePacks\\") + base + ".bin";
			std::string bin2U = std::string("scripts\\TexturePacks\\") + base + ".BIN";

			std::string binResolved;
			if (PathFileExistsA(bin1.c_str()))  binResolved = bin1;
			else if (PathFileExistsA(bin1U.c_str())) binResolved = bin1U;
			else if (PathFileExistsA(bin2.c_str()))  binResolved = bin2;
			else if (PathFileExistsA(bin2U.c_str())) binResolved = bin2U;
			else
			{
				std::string msg =
					"BIN not found for pack: " + base +
					"\nChecked:\n  " + bin1 + "\n  " + bin1U + "\n  " + bin2 + "\n  " + bin2U;
				MessageBoxA(NULL, msg.c_str(), "TexWizard", MB_ICONERROR);
				continue;
			}

			char* dataPathChar = new char[binResolved.length() + 1];
			strcpy(dataPathChar, binResolved.c_str());
			packList.push_back(dataPathChar);

			Json::Value root;
			if (!try_read_json_file_resolved(jsonPath, root))
			{
				std::string msg = "Failed to parse pack JSON: " + jsonPath;
				MessageBoxA(NULL, msg.c_str(), "TexWizard", MB_ICONERROR);
				continue;
			}

			const Json::Value& textures = root["textures"];
			for (Json::ArrayIndex i = 0; i < textures.size(); i++)
			{
				const Json::Value& item = textures[i];
				if (!item.isArray() || item.size() < 2) continue;

				unsigned int keyHash = 0, valHash = 0;
				parse_key_or_hex_to_hash(item[0].asString(), keyHash);
				parse_key_or_hex_to_hash(item[1].asString(), valHash);
				textureMap[keyHash] = valHash;
			}

		} while (FindNextFileA(hFind, &fd));
		FindClose(hFind);
	}

	//Legacy support
	{
		Json::Value root;
		if (try_read_json_file("TexWizard.json", root, nullptr))
		{
			const Json::Value& packs = root["packs"];
			for (Json::ArrayIndex i = 0; i < packs.size(); i++)
			{
				const std::string packRoot = packs[i].asString();

				const std::string configPath = packRoot + "\\meta.json";
				const std::string dataPath = packRoot + "\\textures.bin";

				Json::Value meta;
				if (!try_read_json_file(configPath, meta, nullptr))
				{
					std::string msg = "Failed to open legacy pack config " + configPath;
					MessageBoxA(NULL, msg.c_str(), "TexWizard", MB_ICONERROR);
					continue;
				}

				char* dataPathChar = new char[dataPath.length() + 1];
				strcpy(dataPathChar, dataPath.c_str());
				packList.push_back(dataPathChar);

				const Json::Value& textures = meta["textures"];
				for (Json::ArrayIndex j = 0; j < textures.size(); j++)
				{
					const Json::Value& item = textures[j];
					if (!item.isArray() || item.size() < 2) continue;

					const std::string key = item[0].asString();
					const std::string value = item[1].asString();

					unsigned int keyHash = 0;
					unsigned int valHash = 0;
					parse_key_or_hex_to_hash(key, keyHash);
					parse_key_or_hex_to_hash(value, valHash);
					textureMap[keyHash] = valHash;
				}
			}
		}
	}

#ifdef GAME_UC
	// replace LoadGlobalAChunks call
	injector::MakeJMP(LoadGlobalAChunks_Hook_Addr_1, LoadPacks, true);
#else
	// replace LoadGlobalChunks call
	injector::MakeCALL(LoadGlobalChunks_Hook_Addr_1, LoadPacks, true);
#endif
	
	// replace all GetTextureInfo calls
#ifdef GAME_UC
	injector::MakeJMP(GetTextureInfo_Hook_Addr_1J, ReplaceTexture, true);
#else
	injector::MakeCALL(GetTextureInfo_Hook_Addr_1, ReplaceTexture, true);
#endif
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

#ifndef GAME_UC
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
#ifdef GAME_PS
	injector::MakeJMP(GetTextureInfo_Hook_Addr_33J, ReplaceTexture, true);
	injector::MakeJMP(GetTextureInfo_Hook_Addr_34J, ReplaceTexture, true);
#else
	injector::MakeCALL(GetTextureInfo_Hook_Addr_33, ReplaceTexture, true);
	injector::MakeCALL(GetTextureInfo_Hook_Addr_34, ReplaceTexture, true);
#endif
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

#if (defined (GAME_PS) ||defined (GAME_CARBON) || defined (GAME_MW) || defined (GAME_UG2))
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
#endif
	
#if (defined (GAME_PS) ||defined (GAME_CARBON))
	
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
	
#endif

#ifdef GAME_PS
	injector::WriteMemory(GetTextureInfo_Hook_Addr_106P, &ReplaceTexture, true);
	injector::WriteMemory(GetTextureInfo_Hook_Addr_107P, &ReplaceTexture, true);
	injector::MakeJMP(GetTextureInfo_Hook_Addr_108J, ReplaceTexture, true);
	injector::MakeJMP(GetTextureInfo_Hook_Addr_109J, ReplaceTexture, true);
#endif

#ifdef GAME_CARBON

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

#endif
}