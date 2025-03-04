#pragma once
#include "../entities/entity.h"

#include <vector>

class EntityMenager {
public:
	void addEntity(Entity* e);
	void draw();
	void update();
private:
	std::vector<Entity*> m_entities;
};