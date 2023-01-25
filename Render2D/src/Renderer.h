#pragma once

#include "Window.h"

#include <array>
#include <iostream>

namespace Blend
{
	class Renderer
	{
	public:
		Renderer(Window* window)
		{
			// Initialize window
			m_Window = window;
			m_Window->Init(this->Render(m_Window->BlankFrame, WIDTH, HEIGHT));
		}

		template<int N>
		char* Render(std::array<char, N> raw,int x = WIDTH, int y = HEIGHT)
		{
			char* result = new char[N + y + 1];
			for (int i = 0; i < y; i++)
			{
				for (int j = 0; j < x; j++)
				{
					result[j + (x + 1) * i] = raw[j + x * i];
				}
				result[x + (x + 1) * i] = '\n';
			}
			result[N + y] = 0;
			return result;
		}

		void Update(RAW raw)
		{
			m_Window->UpdateFrame(this->Render(raw));
		}

		void Draw()
		{
			std::cout << m_Window->Frame();
			this->Update(m_Window->BlankFrame);
			m_Window->SwapFrame();
		}
	private:
		Window* m_Window;
	};
}