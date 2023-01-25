#pragma once

#include <vector>
#include <iostream>

namespace Blend
{
	struct Point
	{
		int x, y;
		char sign;
	};

	std::ostream& operator<<(std::ostream& stream, const Point& point)
	{
		stream << "(" << point.x << ", " << point.y << ")<" << point.sign << ">";
		return stream;
	}

	class Vertex
	{
	public:
		Vertex()
			: m_Data(nullptr), m_Count(0), m_Vertices(nullptr)
		{}
		~Vertex()
		{
			delete m_Vertices;
		}
		void VertexData(int* data, int count)
		{
			m_Data = data;
			m_Count = count;
		}

		void VertexAttribPointer()
		{
			m_Vertices = new std::vector<Point>;
			m_Vertices->reserve(m_Count);
			for (int i = 0; i < m_Count; i++)
			{
				m_Vertices->emplace_back(m_Data[3 * i], m_Data[3 * i + 1], m_Data[3 * i + 2]);
			}
		}

		void Print() const
		{
			for (const Point& p : *m_Vertices)
			{
				std::cout << p << std::endl;
			}
		}
	private:
		int* m_Data;
		int m_Count;
		std::vector<Point>* m_Vertices;
	};

}