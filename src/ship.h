#pragma once
#ifndef __Ship__
#define __Ship__

#include "GameObject.h"
#include "TextureManager.h"
#include "SoundManager.h"

class ship : public GameObject
{
public:
	ship();
	~ship();

	// Inherited via GameObject
	void draw() override;

	void update() override;

	void clean() override;

	void turnRight();
	void turnLeft();
	void m_move();

	//getters
	glm::vec2 getTarget();
	float getMaxSpeed();

	//setters
	void setTarget(glm::vec2 newTarget);
	void setMaxSpeed(float newMaxSpeed);

private:
	
	void m_checkState();
	void m_checkBounds();

	void m_reset();

	// steering behaviours
	void m_seek();
	void m_checkArrival();
	
	float m_maxSpeed;
	double m_currentDirection;
	float m_turnSpeed;
	float m_steerForce;
	
	glm::vec2 m_target;
};


#endif /* defined (__Ship__) */

