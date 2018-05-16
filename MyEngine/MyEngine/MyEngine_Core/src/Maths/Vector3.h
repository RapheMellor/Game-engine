#pragma once

//Include iostream
#include <iostream>

namespace MyEngine { namespace Maths {

		struct Vector3
		{
			float x, y, z;

			Vector3();
			//Set the Vector variables to const floats
			Vector3(const float& x, const float& y, const float& z);

			//Vector3 equation functions
			Vector3& add(const Vector3& other);
			Vector3& subtract(const Vector3& other);
			Vector3& multiply(const Vector3& other);
			Vector3& divide(const Vector3& other);

			//Operators
			friend Vector3& operator+(Vector3 left,const Vector3& right);
			friend Vector3& operator-(Vector3 left, const Vector3& right);
			friend Vector3& operator*(Vector3 left, const Vector3& right);
			friend Vector3& operator/(Vector3 left, const Vector3& right);

			//Bool operators
			bool operator==(const Vector3& other);
			bool operator!=(const Vector3& other);

			//Vector3 equation or equals operators
			Vector3& operator+=(const Vector3& other);
			Vector3& operator-=(const Vector3& other);
			Vector3& operator*=(const Vector3& other);
			Vector3& operator/=(const Vector3& other);

			friend std::ostream& operator<<(std::ostream& stream, const Vector3& vector);
		};

	}
}