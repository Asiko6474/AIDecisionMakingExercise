#pragma once
#include "Component.h"

enum State
{
	HUNTBALL,
	HUNTENEMY,
	HUNTGOAL,
	DODGE
	
};

class SeekComponentZ;

class StateComponenetZ :
	public Component
{
public:
	void start() override;
	State getCurrentState() { return m_currentState; }
	State setCurrentState(State state) { state = m_currentState; return state; }

	void update(float deltaTime) override;

private:
	State m_currentState;
	SeekComponentZ* m_seekComponent;
	float m_seekForce;
	float m_wanderForce;
	float m_seekRange = 300;
	Actor* m_target;
};

