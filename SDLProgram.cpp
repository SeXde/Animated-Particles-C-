//============================================================================
// Name        : SDLProgram.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <SDL.h>
#include "Screen.h"
#include <iostream>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Swarm.h"


using namespace abj;

// const static int WIDTH = GetSystemMetrics(0);
// const static int HEIGHT = GetSystemMetrics(1);

int main(int argc, char* argv[]) {


	srand(time(nullptr));

	Screen screen;

	if (!screen.init())
	{
		std::cout <<"Error initializing SDL."<<std::endl;
		return 1;
	}

	Swarm swarm;

	while(true)
	{

		screen.clear();
		swarm.update();

		int elapsed = SDL_GetTicks();
		unsigned char green = (unsigned char)(1+sin(elapsed*0.001)) * 128;
		unsigned char red = (unsigned char)(1+sin(elapsed*0.002)) * 128;
		unsigned char blue = (unsigned char)(1+sin(elapsed*0.003)) * 128;

		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0;i< Swarm::NPARTICLES;i++)
		{
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::WIDTH/2;
			int y = (particle.m_y + 1) * Screen::HEIGHT/2;
			screen.setPixel(x,y,255,255,255);
		}
		screen.update();

		if (!screen.processEvents())
		{
			break;
		}
	}



	screen.close();

    return 0;
}
