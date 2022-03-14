#pragma once
#include "SteeringComponent.h"
#include "Transform2D.h"
#include <Vector2.h>
class Actor;

class WanderBSComponent :
	public SteeringComponent
{
public:
	WanderBSComponent(float circleDistance, float circleRadius, float wanderForce);
	MathLibrary::Vector2 calculateForce() override;

private:
	float m_circleDistance = 0;
	float m_circleRadius = 0;
	float m_wanderAngle = 0;

	MathLibrary::Vector2 m_target;
	MathLibrary::Vector2 m_circlePosition;
};

