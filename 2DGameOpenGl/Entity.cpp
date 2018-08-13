#include "Entity.h"

Entity::Entity(
	glm::vec2 position,
	glm::vec2 velocity,
	float orientation,
	float angularFrequency
) 
{
	_position = position;
	_velocity = velocity;
	_orientation = orientation;
	_angularFrequency = angularFrequency;

}
Entity::Entity() : Entity(glm::vec2(0, 0), glm::vec2(0, 0), 0, 0) {};
Entity::Entity(glm::vec2 position) :Entity(position, glm::vec2(0, 0), 0.0, 0.0) {};
Entity::Entity(glm::vec2 position, float orientation) : Entity(position, glm::vec2(0.0, 0.0), orientation, 0.0f) {};
float Entity::getOrientation()const {
	return _orientation;
}
float Entity::getAngularFrequency()const {
	return _angularFrequency;
}
glm::vec2 Entity::getPosition()const {
	return _position;
}
glm::vec2 Entity::getVelocity()const {
	return _velocity;
}
void Entity::setVelocity(const glm::vec2 velocity) {
	_velocity = velocity;
}
void Entity::setAngularFrequency(const float angularFrequency) {
	_angularFrequency = angularFrequency;
}
void Entity::update(const glm::vec2 acceleration, const float angularAcceleration, float deltaT) {
	_position += _velocity*deltaT;
	_orientation += _angularFrequency*deltaT;
	_velocity += acceleration*deltaT;
	_angularFrequency += angularAcceleration*deltaT;
}

void Entity::transform(glm::mat4 &transform)const {
	transform = glm::rotate(transform, _orientation, glm::vec3(0.0f, 0.0f, 1.0f));
	transform = glm::translate(transform, glm::vec3(_position, 0.0f));
}