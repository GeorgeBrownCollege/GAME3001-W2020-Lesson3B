#include "ship.h"
#include "Game.h"
#include "Util.h"
#include "GLM/gtx/rotate_vector.hpp"


ship::ship()
{
	TheTextureManager::Instance()->load("../Assets/textures/ship3.png",
		"ship", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("ship");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(400.0f, 300.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));
	//m_reset();
	setIsColliding(false);
	setType(GameObjectType::SHIP);
	setState(SteeringState::IDLE);
	m_maxSpeed = 1.0f;
	m_currentDirection = 0.0;
	m_turnSpeed = 2.0f;
	m_steerForce = 0.1f;

}


ship::~ship()
{
}

void ship::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("ship", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), m_currentDirection, 255, true);
}

void ship::m_checkState()
{
	switch (getState())
	{
	case SteeringState::IDLE:
		m_move();
		break;
	case SteeringState::SEEK:
		m_seek();
		//m_move();
		break;
	case SteeringState::ARRIVE:
		break;
	case SteeringState::AVOID:
		break;
	case SteeringState::FLEE:
		break;
	}
}

void ship::update()
{
	m_move();
	m_checkBounds();
}

void ship::clean()
{
}

void ship::turnRight()
{


}

void ship::turnLeft()
{

}

void ship::m_move()
{

	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void ship::m_checkBounds()
{

	if (getPosition().x > 800)
	{
		setPosition(glm::vec2(0.0f, getPosition().y));
	}

	if (getPosition().x < 0)
	{
		setPosition(glm::vec2(800.0f, getPosition().y));
	}

	if (getPosition().y > 600)
	{
		setPosition(glm::vec2(getPosition().x, 0.0f));
	}

	if (getPosition().y < 0)
	{
		setPosition(glm::vec2(getPosition().x, 600.0f));
	}

}

void ship::m_reset()
{

}

void ship::m_seek()
{
	
}
