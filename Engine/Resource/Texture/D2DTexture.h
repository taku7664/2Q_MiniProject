#pragma once
#include "Texture2D.h"

namespace Engine
{
	class D2DTexture 
		: public Texture2D
	{
	public:
		ID2D1Bitmap* GetTextrue() { return m_texture; }
	private:
		ID2D1Bitmap* m_texture;
	};
}