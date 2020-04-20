#include "Mover.h"

Mover::Mover(int size, int definition,
	float mass, float damping,
	cyclone::Vector3 position, cyclone::Vector3 velocity,
	cyclone::Vector3 acceleration,
	Color shadow_color, Color obj_color)
{
	m_size = size;
	m_definition = definition;
	m_mass = mass;
	m_damping = damping;
	m_position = position;
	m_velocity = velocity;
	m_acceleration = acceleration;
	m_shadow_color = shadow_color;
	m_obj_color = obj_color;

	m_position_save = m_position;
	m_velocity_save = m_velocity;
	m_acceleration_save = m_acceleration;

	m_particle = new cyclone::Particle();
	m_particle->setMass(m_mass);
	m_particle->setDamping(m_damping);
	reset();
}

void Mover::update(float duration)
{
	m_particle->integrate(duration);

	checkEdges();
}

//Add wind blowing
void Mover::windBlow()
{
	cyclone::Vector3 wind(1.0f, 0, 0);
	m_particle->addForce(wind);
}

void Mover::reset()
{
	m_particle->setPosition(m_position_save);
	m_particle->setVelocity(m_velocity_save);
	m_particle->setAcceleration(m_acceleration_save);
}

void Mover::draw(int shadow)
{
	m_particle->getPosition(&m_position); //get the current pos of particle

	if (shadow == 1) {
		glColor3f(m_shadow_color.r, m_shadow_color.g, m_shadow_color.b);
	}
	else {
		glColor3f(m_obj_color.r, m_obj_color.g, m_obj_color.b);
	}

	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glutSolidSphere(m_size, m_definition, m_definition);
	glPopMatrix();
}

void Mover::checkEdges()
{
	m_particle->getPosition(&m_position);
	m_particle->getVelocity(&m_velocity);

	if (m_position.y < m_size) {
		m_velocity.y = -m_velocity.y;
		m_particle->setVelocity(m_velocity);

		m_particle->setPosition(m_position.x, m_size, m_position.z);
	}

	if (m_position.x + m_size >= 100) {
		m_velocity.x = -m_velocity.x;
		m_particle->setVelocity(m_velocity);
	}
}