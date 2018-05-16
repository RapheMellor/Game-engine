#pragma once

//Include files
#include "Vector3.h"
#include "Vector4.h"
#include "Maths_Functions.h"

namespace MyEngine { namespace Maths {

	struct matrix4
	{
		union
		{
			//Four by four matrices equalling sixteen
			float elements[4 * 4];
			//In columns of four
			Vector4 column[4];
		};

		matrix4();
		//Take values of the matrices in a diagonal
		matrix4(float diagonal);

		static matrix4 identity();
		matrix4& multiply(const matrix4& other);

		//Projection matricies
		static matrix4 orthographic(float left, float right, float top, float bottom, float near, float far);
		static matrix4 perspective(float fov, float aspectRatio, float near, float far);

		//Translation matricies
		static matrix4 translation(const Vector3& translation);
		static matrix4 rotation(float angle, const Vector3& axis);
		static matrix4 scale(const Vector3& scale);

		//Operators
		friend matrix4 operator*(matrix4 left, const matrix4& right);
		matrix4& operator*=(const matrix4& other);
	};

} }