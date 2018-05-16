#pragma once

//Include iostream
#include <iostream>

namespace MyEngine { namespace Maths {

		struct Vector2
		{
			float x, y;

			Vector2();
			//Set the Vector variables to const floats
			Vector2(const float& x, const float& y);

			//Vector2 equation functions
			Vector2& add(const Vector2& other);
			Vector2& subtract(const Vector2& other);
			Vector2& multiply(const Vector2& other);
			Vector2& divide(const Vector2& other);

			//Operators
			friend Vector2& operator+(Vector2 left,const Vector2& right);
			friend Vector2& operator-(Vector2 left, const Vector2& right);
			friend Vector2& operator*(Vector2 left, const Vector2& right);
			friend Vector2& operator/(Vector2 left, const Vector2& right);

			//Bool operators
			bool operator==(const Vector2& other);
			bool operator!=(const Vector2& other);

			//Vector2 equation or equals operators
			Vector2& operator+=(const Vector2& other);
			Vector2& operator-=(const Vector2& other);
			Vector2& operator*=(const Vector2& other);
			Vector2& operator/=(const Vector2& other);

			friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector);
		};

	}
}