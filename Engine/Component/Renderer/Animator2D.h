#pragma once
#include "Renderer.h"
#include "Resource/Animation/Animation2D.h"

namespace Engine
{
	class Animator2D
		: public Renderer
	{
	public:

		Animator2D();
		virtual ~Animator2D();

		virtual void Update() final;
		virtual bool Draw(Camera2D* _camera) final;

		void AddAnimation(std::string _key, Animation2D* _ani);
		Animation2D* FindAnimation(const std::string& _key);
		void ChangeAnimation(const std::string& _key, bool _loop = true);
		Animation2D* GetActiveAnimation() { return m_activeAnimation; }
		AnimationData GetAnimationData(int _index = -1) {
			if (_index == -1) return m_activeAnimation->GetFrameData()[currentFrame];
			else return m_activeAnimation->GetFrameData()[_index];
		}

		void GotoAndPlay(int _val);
		void GotoAndStop(int _val);
		void Play();
		void Stop();
		bool End();
		bool IsLoop() { return isLoop; }
		int  FrameSize();

		bool IndexEnter(int _index);

		int currentFrame;
		float frameCount;
		float countScale = 1.f;

		float alpha = 1.f;

	private:

		std::unordered_map<std::string, Animation2D*> m_animationList;
		Animation2D* m_activeAnimation;

		bool isLoop;
		bool isStop;
		int  enterFrame = -1;

	};
}