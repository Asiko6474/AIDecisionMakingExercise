#include "FleeBSComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "Agent.h"
#include "MoveComponent.h"

MathLibrary::Vector2 FleeBSComponent::calculateForce()
{
	MathLibrary::Vector2 directionToTarget = getOwner()->getTransform()->getWorldPosition()
		- getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 seekForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return seekForce;
}