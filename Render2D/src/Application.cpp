#include "Core/Core.h"
#include "Graphics/Geometry/Geometry.h"

#include "Renderer.h"
#include "Window.h"
#include "Physics/Collision/Collision.h"

#include <Windows.h>
#include <iostream>

int main()
{
	Blend::Window* window = new Blend::Window();
	Blend::Renderer renderer(window);

	auto canvas = window->BlankFrame;

	Blend::Rectangle rec(3, 3, 3 + 10, 3 + 5, 'A');
	auto offset = Blend::vec2(1, 1);
	Blend::RecCollision recCollision(&rec, window);

	while(1)
	{
		renderer.Clear();
		recCollision.Listen(offset);
		rec.Offset(offset);
		renderer.Draw(rec.Fill(canvas));
		std::cout << std::endl;
		//std::cin.get();
		Sleep(20);
	}
}