#include "Agent1.h"
#include "SpriteComponent.h"
#include "Goal.h"
#include "GameManager.h"
#include "SeekBSComponent.h"
#include "Actor.h"
#include "MoveComponent.h"
#include "GameManager.h"
#include "Agent.h"
#include "WanderBSComponent.h"
#include "StateMachineBSComponent.h"
#include "FleeBSComponent.h"

Agent1::Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/player.png"));
}

void Agent1::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent1::start()
{
	Character::start();

	//add steering behaviours here

	m_moveComponent = addComponent<MoveComponent>();
	//Seek Component Added
	m_seekComponent = addComponent<SeekBSComponent>();
	m_seekComponent->setSteeringForce(50);
	m_seekComponent->setTarget(GameManager::getInstance()->getBall());
	

	/*m_fleeComponent = addComponent<FleeBSComponent>();
	m_fleeComponent->setTarget();*/
	
	/*WanderBSComponent* wanderComponent = new WanderBSComponent(100, 100, 100);
	wanderComponent = addComponent<WanderBSComponent>();
	addComponent<WanderBSComponent>();*/
	//addComponent<StateMachineBSComponent>();

}

void Agent1::update(float deltaTime)
{
	Character::update(deltaTime);
	if (getHasBall())
	{
		
		//m_seekComponent->setTarget(GameManager::getInstance()->getRightGoal());
		//m_fleeComponent->setTarget(GameManager::getInstance()->getAgent2());
	}
}

void Agent1::onDeath()
{
	Character::onDeath();

}
