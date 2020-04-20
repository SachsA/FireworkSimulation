#include "Fire.h"

#include <vector>

class Fireworks
{
public:
	Fireworks(int nb_fires_parent, int nb_fires_child);
	~Fireworks() = default;

	void update(float duration);  //Fire create/update
	
	void fire(); //create init Fires
	void fireChildren(Fire *parent); //create Child Fires
	
	void draw(int shadow);

	int m_nb_fires_parent;
	int m_nb_fires_child;

	FireworksRule m_rule[3];
	std::vector<Fire *> fireworks;
};