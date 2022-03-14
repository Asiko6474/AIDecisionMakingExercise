#pragma once
#include "Character.h"
#include "MoveComponent.h"
#include "ActorArray.h"
#include "SeekBSComponent.h"
#include "FleeBSComponent.h"
class WanderBSComponent;

class Agent1 :
    public Character
{
public:
    /// <param name="x">The x position of the character</param>
    /// <param name="y">The y position of the character</param>
    /// <param name="name">The name of the character</param>
    /// <param name="maxForce">The maximum amount of force that can be applied to this character</param>
    /// <param name="maxSpeed">How fast this actor can go</param>
    /// <param name="health">The amount of health this character has</param>
    Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health);

    // Inherited from the Character class
    virtual void onCollision(Actor* actor) override;
    virtual void start() override;
    virtual void update(float deltaTime) override;
    virtual void onDeath();
    virtual void onDamageRecieved() {};

private:
    MoveComponent* m_moveComponent;
    SeekBSComponent* m_seekComponent;
    FleeBSComponent* m_fleeComponent;
    WanderBSComponent* m_wanderComponent;
    DynamicArray<SteeringComponent*> m_steeringComponent;
    MathLibrary::Vector2 m_force;
};

