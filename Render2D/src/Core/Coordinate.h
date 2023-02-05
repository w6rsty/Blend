#pragma once

#include "vector.h"

namespace Blend
{

	struct Coordinate
	{
		int x, y;

		Coordinate(int x,int y)
			:x(x) , y(y)
		{}

		vec2 ToVec()
		{
			return { x,y };
		}
	};
}