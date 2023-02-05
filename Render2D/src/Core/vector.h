#pragma once

#include <iostream>

namespace Blend
{

	struct vec2
	{
		int x, y;

		vec2(int x = 0, int y = 0)
			: x(x), y(y)
		{}

		vec2(int v)
			: x(v), y(v)
		{}

		vec2& operator + (const vec2& other)
		{
			return *(new vec2(x + other.x, y + other.y));
		}

		vec2& operator - (const vec2& other)
		{
			return *(new vec2(x - other.x, y - other.y));
		}

		int operator * (const vec2& other)
		{
			return x * other.x + y * other.y;
		}

		vec2& normalize(const vec2& other)
		{
			return *(new vec2(other.x / (other.x + other.y), other.y / (other.x + other.y)));
		}
	};

	struct vec3
	{
		int x, y, z;

		vec3(int x, int y, int z)
			: x(x), y(y), z(z)
		{}

		vec3(int v)
			: x(v), y(v), z(v)
		{}

		vec3(const vec2& other, int z)
			: x(other.x), y(other.y), z(z)
		{}

		vec3(int x, const vec2& other)
			: x(x), y(other.x), z(other.y)
		{}

		vec3& operator + (const vec3& other)
		{
			return *(new vec3(x + other.x, y + other.y, z + other.z));
		}

		vec3& operator - (const vec3& other)
		{
			return *(new vec3(x - other.x, y - other.y, z - other.z));
		}

		int operator * (const vec3& other)
		{
			return x * other.x + y * other.y + z * other.z;
		}

		vec3& normalize(const vec3& other)
		{
			return *(new vec3(other.x / (other.x + other.y + other.z), other.y / (other.x + other.y + other.z), other.z / (other.x + other.y + other.z)));
		}
	};
}

std::ostream& operator<<(std::ostream& s, const Blend::vec2& other)
{
	s << other.x << ", " << other.y;
	return s;
}

std::ostream& operator<<(std::ostream& s, const Blend::vec3& other)
{
	s << other.x << ", " << other.y << ", " << other.z;
	return s;
}