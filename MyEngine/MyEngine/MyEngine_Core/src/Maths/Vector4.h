#pragma once

//Include iostream
#include <iostream>

namespace MyEngine { namespace Maths {

		struct Vector4
		{
			float x, y, z, w;

			Vector4() = default;
			//Set the Vector variables to const floats
			Vector4(const float& x, const float& y, const float& z, const float& w);

			//Vector4 equation functions
			Vector4& add(const Vector4& other);
			Vector4& subtract(const Vector4& other);
			Vector4& multiply(const Vector4& other);
			Vector4& divide(const Vector4& other);

			//Operators
			friend Vector4& operator+(Vector4 left,const Vector4& right);
			friend Vector4& operator-(Vector4 left, const Vector4& right);
			friend Vector4& operator*(Vector4 left, const Vector4& right);
			friend Vector4& operator/(Vector4 left, const Vector4& right);

			//Bool operators
			bool operator==(const Vector4& other);
			bool operator!=(const Vector4& other);

			//Vector4 equation or equals operators
			Vector4& operator+=(const Vector4& other);
			Vector4& operator-=(const Vector4& other);
			Vector4& operator*=(const Vector4& other);
			Vector4& operator/=(const Vector4& other);

			friend std::ostream& operator<<(std::ostream& stream, const Vector4& vector);
		};

	}
}