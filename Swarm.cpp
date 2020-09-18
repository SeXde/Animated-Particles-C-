/*
 * Swarm.cpp
 *
 *  Created on: 17 sept. 2020
 *      Author: abj
 */

#include "Swarm.h"
#

namespace abj {

Swarm::Swarm() {

	m_pParticles = new Particle[NPARTICLES];

}

void Swarm::update()
{
	for (int i = 0;i<Swarm::NPARTICLES;i++)
		{
			m_pParticles[i].update();
		}
}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

} /* namespace abj */
