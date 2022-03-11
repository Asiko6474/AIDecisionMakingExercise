#pragma once
#include "SteeringComponent.h"
class SeekBSComponent :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

