#pragma once
#include "SteeringComponent.h"
class SeekBSComponent :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
	

private:
	MathLibrary::Vector2 m_seekPos;
};

