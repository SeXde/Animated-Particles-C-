#pragma once

#include "Particle.h"

namespace abj
{

class Swarm
{

	Particle *  m_pParticles;

public:
	Swarm();
	virtual ~Swarm();
	const static int NPARTICLES = 5000;
	void update();
	Particle * const getParticles(){return m_pParticles;};
};

} /* namespace abj */

