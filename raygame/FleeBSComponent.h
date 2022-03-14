#pragma once
#include "SteeringComponent.h"
class FleeBSComponent :
	public SteeringComponent
{
public: 
	MathLibrary::Vector2 calculateForce() override;
};

