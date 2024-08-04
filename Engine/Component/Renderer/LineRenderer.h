#include "../Component.h"

namespace Engine
{
	class LineRenderer
		: public Component
	{
	public:

		LineRenderer();
		virtual ~LineRenderer() {}

		void SetLineColor(Color4 _color);

		virtual bool Draw(Camera2D* _camera) final;

		float   lineWidth = 1.0f;
		Color4  m_linecolor;
		Vector2 startPos;	 // 시작지점	
		Vector2 endPos;		 // 끝지점
	private:
	};
}