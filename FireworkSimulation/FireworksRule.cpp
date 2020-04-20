#include "FireworksRule.h"

void FireworksRule::setParameters(unsigned type,
	unsigned payloadCount,
	cyclone::real minAge,
	cyclone::real maxAge,
	cyclone::real damping,
	const cyclone::Vector3 &minVelocity,
	const cyclone::Vector3 &maxVelocity)
{
	m_type = type;
	m_nb_fires_child = payloadCount;
	m_minAge = minAge;
	m_maxAge = maxAge;
	m_damping = damping;
	m_minVelocity = minVelocity;
	m_maxVelocity = maxVelocity;
}