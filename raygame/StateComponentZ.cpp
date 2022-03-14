#include "StateComponentZ.h"
#include "Actor.h"
#include "SeekComponentZ.h"
#include "Transform2D.h"

void StateComponenetZ::start()
{
	Component::start();

	m_seekComponent = getOwner()->getComponent<SeekComponentZ>();
	m_seekForce = m_seekComponent->getSteeringForce();

	m_currentState = HUNTBALL;
}

void StateComponenetZ::update(float deltaTime)
{
	MathLibrary::Vector2 targetPos = m_seekComponent->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	
	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();

	bool targetInRange = distanceFromTarget <= m_seekRange;

	switch (m_currentState)
	{
	case HUNTBALL:
		m_seekComponent->setSteeringForce(100);
		break;
	case HUNTENEMY:
		m_seekComponent->setSteeringForce(150);
		
		break;
	case HUNTGOAL:
		m_seekComponent->setSteeringForce(50);
		break;
	case DODGE:
		m_seekComponent->setSteeringForce(200);
		break;
	}
}
