#include <deque>
#include "particle.h"

class FireworksRule
{
public:
	FireworksRule() = default;
	~FireworksRule() = default;

	void setParameters(unsigned type,
		unsigned nb_fires_child,
		cyclone::real minAge,
		cyclone::real maxAge,
		cyclone::real damping,
		const cyclone::Vector3 &minVelocity,
		const cyclone::Vector3 &maxVelocity);

	unsigned m_type;  //Fire type
	unsigned m_nb_fires_child; //how many Child Fires are spawned?
	
	cyclone::real m_minAge;  //minimum age of Fire
	cyclone::real m_maxAge; //maximum age of Fire
	cyclone::real m_damping; //Fire’s damping
	
	cyclone::Vector3 m_minVelocity; //minimum velocity of Fire
	cyclone::Vector3 m_maxVelocity; //maximum velocity of Fire
};