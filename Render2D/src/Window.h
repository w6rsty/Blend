#pragma once

#include <array>

#include "Blend.h"

namespace Blend
{
	
	class Window
	{
	public:
		Window()
			: m_Width(WIDTH), m_Height(HEIGHT), m_Resolution(WIDTH * HEIGHT)
		{
			// Set blank frame(raw)
			for (int i = 0; i < m_Resolution; i++)
			{
				BlankFrame[i] = '.';
			}
			// Set first frame(in Renderer's constructor) 
		}

		void Init(char* frame)
		{
			ThisFrame = frame;
		}
		// Clear frame
		void Clear()
		{
			for (int i = 0; i < m_Resolution; i++)
			{
				BlankFrame[i] = '.';
			}
		}

		// Clear frame by certain character
		void ClearColor(char c)
		{
			for (int i = 0; i < m_Resolution; i++)
			{
				BlankFrame[i] = c;
			}
		}

		void UpdateFrame(char* frame)
		{
			NextFrame = frame;
		}

		void SwapFrame()
		{
			ThisFrame = NextFrame;
		}

		char* Frame() { return ThisFrame; }
	private:
		char* ThisFrame;
		char* NextFrame;
	public:
		// Raw frame data
		std::array<char,WIDTH*HEIGHT> BlankFrame;
		int m_Width, m_Height;
		int m_Resolution;
	};
}