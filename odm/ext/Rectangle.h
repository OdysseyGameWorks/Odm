#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Vector2f.h"
#include "../Vector3f.h"

namespace odm
{
	struct AABB;
	struct Rectangle
	{
		union
		{
			vec2 position;
			struct
			{
				float x;  // Horizontal position.
				float y;  // Vertical position.
			};
		};
		union
		{
			vec2 size;
			struct
			{
				float width;
				float height;
			};
		};

		/// Creates a Rectangle.\n
		/// Sets the position to CENTER 0, 0.\n
		/// Sets the scale to ZERO 0-width, 0-height.
		Rectangle();

		/// Creates a Rectangle of specified size at given location.
		/// @param position The position of the topmost ( top - left ) corner.
		/// @param size The size of this of this Rectangle.
		/// @note Remember the position that is set is of Top-left corner.
		Rectangle(const vec2& position, const vec2& size);

		/// Creates a Rectangle of specified size at given location.
		/// @param x_pos The Horizontal position of the topmost ( top - left ) corner.
		/// @param y_pos The Vertical position of the topmost ( top - left ) corner.
		/// @param width The Horizontal size of this of this Rectangle.
		/// @param height The Vertical size of this of this Rectangle.
		/// @note Remember the position that is set is of Top-left corner.
		Rectangle(float x_pos, float y_pos, float width, float height);

		// Creates a Rectangle from an Axis Aligned Bounding Box.
		Rectangle(const AABB& aabb);

		bool operator==(const Rectangle& other) const;
		bool operator!=(const Rectangle& other) const;

		bool operator<(const Rectangle& other) const;
		bool operator>(const Rectangle& other) const;

		/// Whether or not this rectangle Intersects with other rectangle.
		/// @param rect This Rectangle would be checked for intersection.
		/// @returns True if the rectangles intersects each other.
		bool Intersects(const Rectangle& rect) const;

		/// Whether or not the vec2 point is inside this rectangle.
		/// @param point The point to be checked for content.
		/// @returns True if the point is inside this rectangle.
		bool Contains(const vec2& point) const;

		/// Whether or not the vec3 point is inside this rectangle.
		/// @param point The point to be checked for content.
		/// @returns True if the point is inside this rectangle.
		/// @note It ignores the z-index of the point.
		bool Contains(const vec3& point) const;

		/// Gets the Minimum Boundary of this Rectangle;
		vec2 GetMinimumBound() const { return position - size; }
		/// Gets the Maximum Boundary of this Rectangle;
		vec2 GetMaximumBound() const { return position + size; }

	};

	typedef Rectangle Rect;


	inline Rectangle::Rectangle()
		: position(vec2()), size(vec2())
	{}

	inline Rectangle::Rectangle(const vec2& position, const vec2& size)
		: position(position), size(size)
	{}

	inline Rectangle::Rectangle(float x_pos, float y_pos, float width, float height)
		: position(vec2(x_pos, y_pos)), size(vec2(width, height))
	{}

	inline bool Rectangle::Intersects(const Rectangle& rect) const {
		return (size > rect.position && position < rect.size) || (position > rect.size && size < rect.position);
	}

	inline bool Rectangle::Contains(const vec2& point) const {
		return point > GetMinimumBound() && point < GetMaximumBound();
	}

	inline bool Rectangle::Contains(const vec3& point) const {
		return Contains(vec2(point));
	}

	inline bool Rectangle::operator==(const Rectangle& other) const {
		return position == other.position && size == other.size;
	}

	inline bool Rectangle::operator!=(const Rectangle& other) const {
		return !(*this == other);
	}

	inline bool Rectangle::operator<(const Rectangle& other) const
	{
		return size < other.size;
	}

	inline bool Rectangle::operator>(const Rectangle& other) const {
		return size > other.size;
	}
}

#endif /* end of include guard: RECTANGLE_H  */
