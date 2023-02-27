#include "Rock.h"
#include "ConsoleRenderer.h"

Rock::Rock()
{
	m_objType = new char[64];
	strcpy(m_objType, "Rock"); 
	sprite = RS_Rock;
}

Rock::~Rock()
{
	delete[] m_objType;
}