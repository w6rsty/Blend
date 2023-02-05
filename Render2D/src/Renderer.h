#pragma once

#include "Blend.h"
#include "Window.h"

#include <array>
#include <iostream>
#include <Windows.h>

namespace Blend
{
	class Renderer
	{
		// To create a Renderer, you must have a Window first!
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

		void Clear()
		{
			m_Window->Clear();
			Sleep(90);
			system("cls");
		}

		void Draw(RAW raw)
		{
			std::cout << m_Window->Frame();
			this->Update(raw);
			m_Window->SwapFrame();
		}
	private:
		Window* m_Window;
	};
}