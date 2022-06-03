#pragma once
#include "Components.h"
#include "../headers/Vector2D.h"

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int speed = 3;

	TransformComponent(){}

	TransformComponent(float x, float y) : position(x, y) {}

	void init() override
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

};