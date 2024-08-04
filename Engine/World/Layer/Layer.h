#pragma once
#include "World/Object/Object.h"
#include "World/Object/Actor/Actor.h"

namespace Engine
{
	class Layer
	{
	public:

		Layer(LayerTag _type);
		~Layer();

		void FixedUpdate();
		void EarlyUpdate();
		void Update();
		void LateUpdate();
		void Render();
		void StateUpdate();

		LayerTag GetLayerTag() { return m_layerTag; }
		std::vector<Object*>& GetObjectList() { return m_objectList; }

	private:

		LayerTag m_layerTag;
		std::vector<Object*> m_objectList;
		// 내부적으로 쓰는 코드들
		void ProcessDestroy(std::vector<Object*>& _objList);
		void SortingObject();

	};
}