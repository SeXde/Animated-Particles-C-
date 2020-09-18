#pragma once
#include <SDL.h>
#include <string.h>


namespace abj
{

class Screen
{
	SDL_Window * m_window;
	SDL_Renderer * m_renderer;
	SDL_Texture * m_texture;
	Uint32 * m_buffer;
	SDL_Event m_event;

public:

	const static int WIDTH = 2560;
	const static int HEIGHT = 1440;

	Screen();
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue );
	void clear();
	bool processEvents();
	void close();
};

}

