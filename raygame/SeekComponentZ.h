#pragma once
#include "SteeringComponent.h"
class SeekComponentZ :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

