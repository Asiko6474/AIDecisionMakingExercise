#pragma once
#include "Component.h"

enum State
{
	SEEK,
	FLEE
	//WANDER
};

class SeekBSComponent;
class FleeBSComponent;
//class WanderBSComponent;

class StateMachineBSComponent :
	public Component
{
	void start() override;

	State getCurrentState() { return m_currentState; }
	void setCurrentState(State state) { m_currentState = state; }

	void update(float deltaTime) override;

private:
	State m_currentState;
	SeekBSComponent* m_seekComponent;
	FleeBSComponent* m_fleeComponent;
	//WanderBSComponent* m_wanderComponent;
	//float m_wanderForce;
	float m_seekForce;
	float m_fleeForce;
	float m_seekRange = 100;
	float m_fleeRange = 100;
};

