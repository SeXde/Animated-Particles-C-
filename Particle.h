#pragma once

namespace abj
{


class Particle
{

public:
	double m_x;
	double m_y;

	double m_xspeed;
	double m_yspeed;

	Particle();
	virtual ~Particle();
	void update();
};

}
