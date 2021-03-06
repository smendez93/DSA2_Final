#include "Wall.h"

#define LONG_SIDE 0.6f
#define SHORT_SIDE 0.2f

Wall::Wall()
{
}


Wall::Wall(vector2 pos, int t, int ind)
{
	//initializing variables
	position = vector3(pos.x * SIZE, 0.f, pos.y * SIZE); //upper left corner of one unit
	type = (wallType)t;
	m4Transform = IDENTITY_M4;

	//keeping track of what number wall we are on 
	name = "wall" + std::to_string(ind);

	matrix4 m4Scale = glm::scale(IDENTITY_M4, scale) * glm::rotate(IDENTITY_M4, 90.f, REAXISX);
	matrix4 m4Rotation = IDENTITY_M4;

	//note that walls draw from the center
	switch (type)
	{
	case down:
		m4Rotation = glm::rotate(IDENTITY_M4, 270.f, REAXISY);
		position.x += SIZE / 2.f;
		position.y += 0.4f;
		position.z += SIZE;
		m_v3Bounds = vector3(LONG_SIDE, 0.f, SHORT_SIDE);
		break;
	case right:
		position.x += SIZE;
		position.y += 0.4f;
		position.z += SIZE / 2.f;
		m_v3Bounds = vector3(SHORT_SIDE, 0.f, LONG_SIDE);
		break;
	case none:		
		break;
	}

	m4Transform = glm::translate(position) * m4Rotation * m4Scale;
}	

Wall::~Wall()
{
}

vector3 Wall::GetCenterGlobal()
{
	return position;
}

vector3 Wall::GetHalfWidth()
{
	return m_v3Bounds;
}

