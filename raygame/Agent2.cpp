#include "Agent2.h"
#include "SpriteComponent.h"
#include "GameManager.h"
#include "Goal.h"
#include "MoveComponent.h"
#include "SteeringComponent.h"
#include "SeekComponentZ.h"

Agent2::Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/enemy.png"));
	m_seekComponent = new SeekComponentZ();
}

void Agent2::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent2::start()
{
	Character::start();
	//add steering behaviours here
	m_seekComponent = addComponent<SeekComponentZ>();
	m_seekComponent->setSteeringForce(50);
	m_currentState = HUNTBALL;
}

void Agent2::update(float deltaTime)
{
	Character::update(deltaTime);


	switch (m_currentState)
	{
	case HUNTBALL:
	
		m_seekComponent->setTarget(GameManager::getInstance()->getBall());
		m_seekComponent->setSteeringForce(100);

		if (getHasBall())
			m_currentState = HUNTGOAL;
		
		if (GameManager::getInstance()->getAgent1()->getHasBall());
			m_currentState = HUNTENEMY;

		break;

	case HUNTENEMY:
		m_seekComponent->setSteeringForce(150);
		m_seekComponent->setTarget(GameManager::getInstance()->getAgent1());
		break;
	case HUNTGOAL:
		m_seekComponent->setSteeringForce(50);
		m_seekComponent->setTarget(GameManager::getInstance()->getLeftGoal());
		break;
	case DODGE:
		m_seekComponent->setSteeringForce(200);
		break;
	}
}

void Agent2::onDeath()
{
	Character::onDeath();

}