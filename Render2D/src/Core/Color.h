#pragma once

#include "vector.h"

#define RATE 21

namespace Blend
{
	/// 1 2 3 4 5 6 7 8 9 10 11 12
	/// . , - ~ : ; = ! * #  $  @

	struct Color
	{
		char sign;

		Color(int x)
			: sign(int(x/RATE))
		{}

		Color(char x)
			: sign(x)
		{}
	};
}