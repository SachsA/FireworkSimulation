#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "stdio.h"
#include "math.h"
#include "3DUtils.h"
#include "DrawUtils.h"
#include "Particle.h"

#include "Vec3f.h"
#include "Viewer.h"
#include <vector>

#include "core.h"

class Mover
{
public:
	Mover(int size, int definition,
		float mass, float damping,
		cyclone::Vector3 position, cyclone::Vector3 velocity,
		cyclone::Vector3 acceleration,
		Color shadow_color, Color obj_color);
	~Mover() = default;

	void update(float duration);
	void windBlow();
	void reset();
	void draw(int shadow);
	void checkEdges();

	int m_run;
	int m_size;
	int m_definition;

	float m_mass;
	float m_damping;

	cyclone::Vector3 m_position;
	cyclone::Vector3 m_velocity;
	cyclone::Vector3 m_acceleration;

	cyclone::Vector3 m_position_save;
	cyclone::Vector3 m_velocity_save;
	cyclone::Vector3 m_acceleration_save;

	cyclone::Particle *m_particle;

	Color m_shadow_color;
	Color m_obj_color;
};