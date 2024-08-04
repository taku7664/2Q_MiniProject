#include "pch.h"
#include "ResourceManager.h"

namespace Engine
{
	std::wstring ResourceManager::m_assetPath = L"Asset/";
	std::unordered_map<std::wstring, Sprite2D*>	 ResourceManager::m_spriteMap;
	std::unordered_map<std::wstring, Animation2D*> ResourceManager::m_animationMap;
	std::unordered_map<std::wstring, FMODSound*>   ResourceManager::m_audioMap;
	std::unordered_map<std::wstring, Font*>		 ResourceManager::m_fontMap;

	Sprite2D* ResourceManager::AddSprite2D(const std::wstring& _key, const std::wstring& _path, SpriteData _data)
	{
		std::wstring temp = m_assetPath + _path;
		Sprite2D* _sprite = GetSprite2D(_key);
		if (_sprite != nullptr)
		{
			return _sprite;
		}
		else
		{
			_sprite = new Sprite2D(_key, temp, ResourceType::Sprite2D, _data);
			m_spriteMap.insert(std::make_pair(_key, _sprite));
		}
		return _sprite;
	}

	Animation2D* ResourceManager::AddAnimation2D(const std::wstring& _key, Sprite2D* _sprite, std::vector<AnimationData>& _data)
	{
		Animation2D* _anime = GetAnimation2D(_key);
		if (_anime != nullptr)
		{
			return _anime;
		}
		else
		{
			_anime = new Animation2D(_key, ResourceType::Animation2D, _sprite, _data);
			m_animationMap.insert(std::make_pair(_key, _anime));
		}
		return _anime;
	}

	FMODSound* ResourceManager::AddFMODSound(const std::wstring& _key, const std::wstring& _path, bool isLoop, int _group)
	{
		std::wstring temp = L"Asset/" + _path;
		FMODSound* _audio = GetFMODSound(_key);
		if (_audio != nullptr)
		{
			return _audio;
		}
		else
		{
			_audio = new FMODSound(_key, temp, ResourceType::AudioClip, isLoop, _group);
			m_audioMap.insert(std::make_pair(_key, _audio));
		}
		return _audio;
	}

	Font* ResourceManager::AddFont(const std::wstring& _key, const std::wstring& _path)
	{
		std::wstring temp = L"Asset/" + _path;
		Font* _font = GetFont(_key);
		if (_font != nullptr)
		{
			return _font;
		}
		else
		{
			_font = new Font(_key, temp, ResourceType::Font);
			m_fontMap.insert(std::make_pair(_key, _font));
		}
		return _font;
	}

	Sprite2D* ResourceManager::GetSprite2D(const std::wstring& _key)
	{
		auto it = m_spriteMap.find(_key);

		if (it == m_spriteMap.end())
			return nullptr;

		return it->second;
	}

	Animation2D* ResourceManager::GetAnimation2D(const std::wstring& _key)
	{
		std::unordered_map<std::wstring, Animation2D*>::iterator it = m_animationMap.find(_key);

		if (it == m_animationMap.end())
			return nullptr;

		return it->second;
	}

	FMODSound* ResourceManager::GetFMODSound(const std::wstring& _key)
	{
		std::unordered_map<std::wstring, FMODSound*>::iterator it = m_audioMap.find(_key);

		if (it == m_audioMap.end())
			return nullptr;

		return it->second;
	}

	Font* ResourceManager::GetFont(const std::wstring& _key)
	{
		std::unordered_map<std::wstring, Font*>::iterator it = m_fontMap.find(_key);

		if (it == m_fontMap.end())
			return nullptr;

		return it->second;
	}

	bool ResourceManager::ReleaseSprite2D(const std::wstring& _key)
	{
		auto it = m_spriteMap.find(_key);
		if (it == m_spriteMap.end())
			return false;
		delete (*it).second;
		m_spriteMap.erase(it);
		return true;
	}

	bool ResourceManager::ReleaseAnimation2D(const std::wstring& _key)
	{
		auto it = m_animationMap.find(_key);
		if (it == m_animationMap.end())
			return false;
		delete (*it).second;
		m_animationMap.erase(it);
		return true;
	}

	bool ResourceManager::ReleaseFMODSound(const std::wstring& _key)
	{
		auto it = m_audioMap.find(_key);
		if (it == m_audioMap.end())
			return false;
		delete (*it).second;
		m_audioMap.erase(it);
		return true;
	}

	bool ResourceManager::ReleaseFont(const std::wstring& _key)
	{
		auto it = m_fontMap.find(_key);
		if (it == m_fontMap.end())
			return false;
		delete (*it).second;
		m_fontMap.erase(it);
		return true;
	}

	void ResourceManager::Clear()
	{
		for (auto it = m_spriteMap.begin(); it != m_spriteMap.end(); ++it)
		{
			delete it->second;
		}
		m_spriteMap.clear();
		for (auto it = m_animationMap.begin(); it != m_animationMap.end(); ++it)
		{
			delete it->second;
		}
		m_animationMap.clear();
		for (auto it = m_audioMap.begin(); it != m_audioMap.end(); ++it)
		{
			delete it->second;
		}
		m_audioMap.clear();
		for (auto it = m_fontMap.begin(); it != m_fontMap.end(); ++it)
		{
			delete it->second;
		}
		m_fontMap.clear();
	}
}