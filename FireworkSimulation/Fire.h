#include "FireworksRule.h"

class Fire
{
public:
	Fire(int type,
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
		cyclone::Vector3 acceleration);
	~Fire() = default;

	void initParticle();

	void setRule(FireworksRule *rule); //create fire with rule
	
	bool update(float duration);     //return bool
	bool hitGround();
	
	void draw(int shadow);

	void drawHistory();
	void putHistory();  //Save current position in the m_history

	int m_type;  //Fire type (0=Init Fire, 1=Child fire) -> set in the constructor
	int m_definition;
	int m_nb_fires_child;

	float m_size;  // Fire size (0.5)
	float m_mass;
	float m_damping;

	float m_age;  //Fire’s current age

	std::deque <cyclone::Vector3> m_history; //history saving

	cyclone::Vector3 m_position;
	cyclone::Vector3 m_velocity;
	cyclone::Vector3 m_acceleration;

	cyclone::Vector3 m_color; //Fire color
	cyclone::Vector3 m_shadow_color; //Shadow color

	cyclone::Particle * m_particle;

	FireworksRule * m_rule;//Which rule this particle is influenced by?
};