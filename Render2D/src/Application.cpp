#include <array>

#include "Vertex.h"
#include "Renderer.h"
#include "Window.h"


int main()
{
	Blend::Window* window = new Blend::Window();
	Blend::Renderer* renderer = new Blend::Renderer(window);
	char c = 'a';
	while (1)
	{
		window->ClearColor(c);

		system("cls");
		renderer->Draw();
		std::cin >> c;
	}
	return 0;
}