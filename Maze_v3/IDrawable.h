#pragma once
#include "DrawMatrix.h"
class IDrawable
{
public:
	virtual void Draw(DrawMatrix* matrix) {};
};	