#include "StateMachineBSComponent.h"
#include "Actor.h"
#include "SeekBSComponent.h"
#include "Transform2D.h"
#include "FleeBSComponent.h"
#include "GameManager.h"
#include "Agent.h"
#include "WanderBSComponent.h"

void StateMachineBSComponent::start()
{
	m_seekComponent = getOwner()->getComponent<SeekBSComponent>();
	m_seekForce = m_seekComponent->getSteeringForce();

	m_fleeComponent = getOwner()->getComponent<FleeBSComponent>();
	m_fleeForce = m_fleeComponent->getSteeringForce();

	/*m_wanderComponent = getOwner()->getComponent<WanderBSComponent>();
	m_wanderForce = m_wanderComponent->getSteeringForce();*/
}

void StateMachineBSComponent::update(float deltaTime)
{
	MathLibrary::Vector2 targetPos = m_seekComponent->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();
	bool targetInRange = distanceFromTarget <= m_seekRange;
	bool targetTooClose = distanceFromTarget > m_fleeRange;

	switch (m_currentState)
	{
	case SEEK:
		m_seekComponent->setSteeringForce(m_seekForce);
		m_fleeComponent->setSteeringForce(0);
		//m_wanderComponent->setSteeringForce(0);
		
		if (targetInRange)
			setCurrentState(SEEK);;
		
		break;
	case FLEE:
		m_seekComponent->setSteeringForce(0);
		m_fleeComponent->setSteeringForce(m_fleeForce);
		//m_wanderComponent->setSteeringForce(0);
		if (targetTooClose)
			setCurrentState(FLEE);
		break;
	/*case WANDER:
		m_seekComponent->setSteeringForce(0);
		m_fleeComponent->setSteeringForce(0);
		m_wanderComponent->setSteeringForce(m_wanderForce);*/
	}
}
