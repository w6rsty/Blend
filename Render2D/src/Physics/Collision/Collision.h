#pragma once

#include "../../Core/Core.h"
#include "../../Graphics/Geometry/Geometry.h"
#include "../../Window.h"

namespace Blend
{

	class RecCollision
	{;
	private:
		Rectangle* rec;
		Coordinate a, b;
		int WindowWidth, WindowHeight;
	public:
		RecCollision(Rectangle* rec, Window* window)
			: rec(rec), a(a), b(b) , WindowWidth(window->m_Width), WindowHeight(window->m_Height)
		{}

		void Listen(vec2& offset)
		{
			if (rec->a.y == 0 || rec->b.y == WindowHeight - 1) // Top and bottom
			{
				offset.y = -offset.y;
			}
			if (rec->a.x == 0 || rec->b.x == WindowWidth - 1) // Left and right
			{
				offset.x = -offset.x;
			}
		}
	};
}