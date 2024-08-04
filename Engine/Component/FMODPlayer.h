#pragma once
#include "Component.h"
#include "../Resource/AudioClip/FMODSound.h"

namespace Engine
{
	class FMODPlayer
		: public Component
	{
	public:
		virtual ~FMODPlayer() {}
		FMODSound* AddAudio(std::string _key, FMODSound* _sound);
		FMODSound* FindAudio(std::string _key);

		void Play(FMODSound* _sound);
		void Play(std::string _key);
		void Stop();
		void SetVolume(float _volume);

	private:

		FMOD::Channel* m_channel;
		std::unordered_map<std::string, FMODSound*> m_audioList;

	};
}