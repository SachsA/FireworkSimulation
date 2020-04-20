#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Random.h"
#include "Fireworks.h"

Fireworks::Fireworks(int nb_fires_parent, int nb_fires_child)
{
	m_nb_fires_parent = nb_fires_parent;
	m_nb_fires_child = nb_fires_child;

	m_rule[0].setParameters(1, 20, 0.5f, 5.4f, 0.9f, cyclone::Vector3(-5, 10, -5), cyclone::Vector3(5, 15, 5));
	m_rule[1].setParameters(1, 40, 0.5f, 10.4f, 0.2f, cyclone::Vector3(-15, 5, -5), cyclone::Vector3(15, 6, 15));
	m_rule[2].setParameters(1, 25, 0.5f, 12.4f, 0.7f, cyclone::Vector3(-5, 0, -5), cyclone::Vector3(5, 5, 5));
}

void Fireworks::fire()
{
	static cyclone::Random crandom;

	int type = 0;
	int definition = 30;

	float size = 0.2f;
	float mass = 1.0f;
	float damping = 0.99f;

	cyclone::Vector3 acceleration = cyclone::Vector3(cyclone::Vector3::GRAVITY);

	for (int i = 0; i < m_nb_fires_parent; i++) {
		float age = crandom.randomReal(0.5f, 3.0f);

		cyclone::Vector3 position = crandom.randomVector(cyclone::Vector3(-5, 10, -5), cyclone::Vector3(5, 10, 5));
		cyclone::Vector3 velocity = crandom.randomVector(cyclone::Vector3(0, 0, 0), cyclone::Vector3(10, 30, 10));

		cyclone::Vector3 color = crandom.randomVector(cyclone::Vector3(0, 0, 0), cyclone::Vector3(1, 1, 1));
		cyclone::Vector3 shadow_color = cyclone::Vector3(0.1, 0.1, 0.1);

		Fire *fire = new Fire(type, definition, m_nb_fires_child, size, mass, damping, age, color, shadow_color, position, velocity, acceleration);
		fireworks.emplace_back(fire);
	}
}

void Fireworks::fireChildren(Fire *parent)
{
	static cyclone::Random crandom;

	int type = 1;
	int definition = 30;

	float size = 0.1f;
	float mass = 1.0f;
	float damping = 0.9f;

	cyclone::Vector3 acceleration = cyclone::Vector3(cyclone::Vector3::GRAVITY);

	for (int i = 0; i < parent->m_nb_fires_child; i++) {
		float age = crandom.randomReal(0.5f, 12.0f);

		cyclone::Vector3 position = parent->m_position;
		cyclone::Vector3 velocity = parent->m_velocity + crandom.randomVector(cyclone::Vector3(-5, 10, -5), cyclone::Vector3(5, 15, 5));

		cyclone::Vector3 color = parent->m_color;
		cyclone::Vector3 shadow_color = cyclone::Vector3(0.1, 0.1, 0.1);

		Fire *fire = new Fire(type, definition, m_nb_fires_child, size, mass, damping, age, color, shadow_color, position, velocity, acceleration);
		fire->setRule(&m_rule[rand() % 3]);
		fireworks.emplace_back(fire);
	}
}

void Fireworks::update(float duration)
{
	std::vector<Fire * >::iterator iter;
	std::vector<Fire *> remove;
	
	for (iter = fireworks.begin(); iter != fireworks.end();) {
		Fire * m = *iter;
		if (m->update(duration)) {
			if (m->m_type == 0)
				remove.emplace_back(m);				
			iter = fireworks.erase(iter);
		}
		else {
			++iter;
		}
	}

	for (iter = remove.begin(); iter != remove.end();) {
		Fire * m = *iter;
		if (m->update(duration)) {
			fireChildren(m);
			iter = remove.erase(iter);
		}
		else {
			++iter;
		}
	}

	remove.clear();
}

void Fireworks::draw(int shadow)
{
	std::vector<Fire * >::iterator iter;

	for (iter = fireworks.begin(); iter != fireworks.end();) {
		Fire *m = *iter;

		m->draw(shadow);

		++iter;
	}
}