#include "Rectangle.h"

#include "AABB.h"

namespace odm
{
	Rectangle::Rectangle(const AABB& aabb)
		: position(vec2(aabb.min)), size(vec2(aabb.GetSize()))
	{}
}