#pragma once
#include "Resource/Sprite/Sprite2D.h"
#include "Resource/Animation/Animation2D.h"
#include "Resource/AudioClip/FMODSound.h"
#include "Resource/Font/Font.h"

namespace Engine
{
	class ResourceManager
	{
	public:
		// ===================���ҽ� �߰�===================
		static Sprite2D* AddSprite2D(const std::wstring& _key, const std::wstring& _path, SpriteData _data = SpriteData());
		static Animation2D* AddAnimation2D(const std::wstring& _key, Sprite2D* _sprite, std::vector<AnimationData>& _data);
		static FMODSound* AddFMODSound(const std::wstring& _key, const std::wstring& _path, bool isLoop, int _group);
		static Font* AddFont(const std::wstring& _key, const std::wstring& _path);
		// ===================���ҽ� ��������===================
		static Sprite2D* GetSprite2D(const std::wstring& _key);
		static Animation2D* GetAnimation2D(const std::wstring& _key);
		static FMODSound* GetFMODSound(const std::wstring& _key);
		static Font* GetFont(const std::wstring& _key);
		// ===================���ҽ� ����===================
		static bool ReleaseSprite2D(const std::wstring& _key);
		static bool ReleaseAnimation2D(const std::wstring& _key);
		static bool ReleaseFMODSound(const std::wstring& _key);
		static bool ReleaseFont(const std::wstring& _key);

		// Asset�⺻ ���
		static void SetAssetPath(std::wstring _path) { m_assetPath = _path; }

		// ===================���ҽ� ��ü ����===================
		static void Clear();

	private:

		static std::wstring m_assetPath;
		static std::unordered_map<std::wstring, Sprite2D*> m_spriteMap;
		static std::unordered_map<std::wstring, Animation2D*> m_animationMap;
		static std::unordered_map<std::wstring, FMODSound*> m_audioMap;
		static std::unordered_map<std::wstring, Font*> m_fontMap;

	};
}