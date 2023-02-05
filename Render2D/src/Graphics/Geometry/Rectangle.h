#pragma once

#include "../../Core/Core.h"
#include "../../Blend.h"

#include <array>

namespace Blend
{
	class Rectangle
	{
	public:
		Blend::Coordinate a, b;
		Blend::Color color;
	public:
		Rectangle(int x1, int y1, int x2, int y2, char color)
			: a(x1, y1), b(x2, y2), color(color)
		{}

		/*void Line(RAW raw) const
		{
			for (int i = 0; i < HEIGHT; i++)
			{
				for (int j = 0; j < WIDTH; j++)
				{

				}
			}
		}*/

		RAW Fill(RAW raw) const
		{
			for (int i = 0; i < HEIGHT; i++)
			{
				if (i >= a.y && i <= b.y)
				{
					for (int j = a.x; j <= b.x; j++)
					{
						if (j<WIDTH)
						{
							raw[i * WIDTH + j] = color.sign;
						}
					}
				}
			}
			return raw;
		}

		void Offset(vec2 offset)
		{
			a.x += offset.x;
			a.y += offset.y;
			b.x += offset.x;
			b.y += offset.y;
		}
	};
}