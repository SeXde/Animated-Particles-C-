/*
 * Screen.cpp
 *
 *  Created on: 17 sept. 2020
 *      Author: abj
 */

#include "Screen.h"
#include <iostream>
#include <string.h>

namespace abj
{

Screen::Screen():m_window(nullptr), m_renderer(nullptr), m_texture(nullptr), m_buffer(nullptr)
{

}



bool Screen::init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		std::cout <<"SDL cannot start correctly"<<std::endl;
		return false;
	}

	m_window = SDL_CreateWindow("SDL Window",0,0,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);

	if (!m_window)
	{
		std::cout <<"SDL window cannot be created"<<std::endl;
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC,WIDTH,HEIGHT);

	if (!m_renderer)

	{
		std::cout <<"SDL renderer cannot be created"<<std::endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (!m_texture)
	{
		std::cout <<"SDL texture cannot be created"<<std::endl;
		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		SDL_Quit();
		return false;
	}

	m_buffer = new Uint32[WIDTH*HEIGHT];

	memset(m_buffer,0,WIDTH*HEIGHT*sizeof(Uint32));

	return true;

}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
	{
		return;
	}
	Uint32 color = 0;
	color += red;
	color <<=8;
	color += green;
	color <<=8;
	color += blue;
	color <<=8;
	color += 0xFF;

	m_buffer[(y*WIDTH)+x] = color;

}

void Screen::update()
{
	SDL_UpdateTexture(m_texture,nullptr,m_buffer,WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer,m_texture,nullptr,nullptr);
	SDL_RenderPresent(m_renderer);
}

bool Screen::processEvents()
{


	while ( SDL_PollEvent(&m_event) )
	{
		if (m_event.type == SDL_QUIT)
		{
			return false;
		}
	}

	return true;

}

void Screen::close()
{

	delete [] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}

void Screen::clear()
{
	memset(m_buffer,0,WIDTH*HEIGHT*sizeof(Uint32));
}

}
