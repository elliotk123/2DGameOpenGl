#ifndef ENTITY_H
#define ENTITY_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Entity {
private:
	glm::vec2 _position;
	glm::vec2 _velocity;
	float _orientation;
	float _angularFrequency;

public:
	Entity(glm::vec2 position, 
		glm::vec2 velocity, 
		float orientation, 
		float angularFrequnecy
	);
	Entity::Entity();
	Entity(glm::vec2 position);
	Entity(glm::vec2 position, float orientation);
	float getOrientation()const;
	float getAngularFrequency()const;
	glm::vec2 getPosition()const;
	glm::vec2 getVelocity()const;
	void setVelocity(const glm::vec2 velocity);
	void setAngularFrequency(const float angularFrequency);
	void update(const glm::vec2 acceleration, const float angularAcceleration, const float deltaT);
	void transform(glm::mat4 &transform)const;
	glm::vec2 Entity::getDirection()const;
};
	
#endif 

