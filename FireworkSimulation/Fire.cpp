#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <vector>

#include "Fire.h"
#include "Random.h"
#include "DrawUtils.h"

Fire::Fire(int type,
	int definition,
	int nb_fires_child,
	float size,
	float mass,
	float damping,
	float age,
	cyclone::Vector3 color,
	cyclone::Vector3 shadow_color,
	cyclone::Vector3 position,
	cyclone::Vector3 velocity,
	cyclone::Vector3 acceleration)
{
	m_rule = new FireworksRule();

	m_type = type;
	m_definition = definition;
	m_nb_fires_child = nb_fires_child;
	m_size = size;
	m_mass = mass;
	m_damping = damping;
	m_acceleration = acceleration;
	m_age = age;
	m_position = position;
	m_velocity = velocity;
	m_color = color;
	m_shadow_color = shadow_color;

	initParticle();
}

void Fire::initParticle()
{
	m_particle = new cyclone::Particle();

	m_particle->setMass(m_mass);
	m_particle->setDamping(m_damping);
	m_particle->setAcceleration(m_acceleration);
	m_particle->setPosition(m_position);
	m_particle->setVelocity(m_velocity);
}

void Fire::setRule(FireworksRule *rule)
{
	static cyclone::Random crandom;

	m_type = rule->m_type;
	m_nb_fires_child = rule->m_nb_fires_child;
	m_age = crandom.randomReal(rule->m_minAge, rule->m_maxAge);
	m_particle->setDamping(rule->m_damping);
	m_particle->setVelocity(crandom.randomVector(rule->m_minVelocity, rule->m_maxVelocity));
}

void Fire::drawHistory()
{
	glLineWidth(2.0f);
	glPushMatrix();

	glBegin(GL_LINE_STRIP);
	for (unsigned int i = 0; i < m_history.size(); i += 2) {
		cyclone::Vector3 p = m_history[i];
		glVertex3f(p.x, p.y, p.z);
	}
	glEnd();
	glPopMatrix();
	glLineWidth(1.0f);
}

void Fire::putHistory()
{
	m_particle->getPosition(&m_position);
	
	if (m_history.size() < 30) {
		m_history.emplace_back(m_position);
	}
	else {
		m_history.pop_front();
		m_history.emplace_back(m_position);
	}
}

bool Fire::update(float duration)
{
	m_particle->integrate(duration);

	m_age -= duration;

	if (hitGround() || m_age < 0)
		return true;

	return false;
}

bool Fire::hitGround()
{
	m_particle->getPosition(&m_position);

	if (m_position.y < 0) {
		return true;
	}

	return false;
}

void Fire::draw(int shadow)
{
	m_particle->getPosition(&m_position); //get the current pos of particle
	
	putHistory();

	if (shadow == 1) {
		glColor3f(m_shadow_color.x, m_shadow_color.y, m_shadow_color.z);
	}
	else {
		glColor3f(m_color.x, m_color.y, m_color.z);
	}

	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glutSolidSphere(m_size, m_definition, m_definition);
	glPopMatrix();

	drawHistory();
}