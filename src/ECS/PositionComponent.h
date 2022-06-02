#pragma once
#include "Components.h"

class PositionComponent : public Component
{
private:
	int xpos;
	int ypos;
public:
	PositionComponent()
	{
		xpos = ypos = 0;
	}

	PositionComponent(int x, int y)
	{
		xpos = x;
		ypos = y;
	}


	void update() override
	{
		xpos++;
		ypos++;
	}

	int getX() { return xpos; }
	int getY() { return ypos; }
	
	void setX(int x){ xpos = x; }
	void setY(int y){ ypos = y; }

	void setXY(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
};