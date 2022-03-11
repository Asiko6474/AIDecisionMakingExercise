#pragma once
#include "SteeringComponent.h"
class SeekComponentZ :
	public Component
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

