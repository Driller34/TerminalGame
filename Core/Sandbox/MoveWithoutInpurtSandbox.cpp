#include "../Graphic/Window.hpp"
#include "../GUI/Rectangle.hpp"
#include "../Utils/Vec.hpp"
#include "../Utils/Color.hpp"

int main()
{
	Window window(100, 100);
	gui::Rectangle rec(10, 10, Color{155, 155, 0, 255});
	Vec2i position = { 0, 0 };

	while(true)
	{
		position += {1, 1};

		window.clear();

		window.draw(rec, position);

		window.display();
	}
	return 0;
}