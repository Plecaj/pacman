#include "entityMenager.h"

void EntityMenager::addEntity(Entity* e){
	this->m_entities.push_back(e);
}

void EntityMenager::draw(){
	for (auto& entity : m_entities) {
		entity->draw();
	}
}

void EntityMenager::update(){
	for (auto& entity : m_entities) {
		entity->update();
	}
}
