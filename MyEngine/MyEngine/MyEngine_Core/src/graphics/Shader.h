#pragma once

//Include files
#include <iostream>
#include "../Utils/FileUtils.h"
#include <GL/glew.h>
#include <vector>
#include "../Maths/Maths.h"

namespace MyEngine { namespace graphics {

	class Shader
	{
		//Private functions
	private:
		GLuint m_ShaderID;
		const char* m_VertPath;
		const char* m_FragPath;

		//Public functions
	public:
		Shader(const char* vertpath, const char* fragPath);
		~Shader();
		
		GLint getUniformLocation(GLchar* name);

		//Uniform functions for all vector classes
		void setUniform1f(const GLchar* name, float value);
		void setUniform1i(const GLchar* name, int value);
		void setUniform2f(const GLchar* name, const Maths::Vector2& vector);
		void setUniform3f(const GLchar* name, const Maths::Vector3& vector);
		void setUniform4f(const GLchar* name, const Maths::Vector4& vector);

		void setUniformMat4(const GLchar* name, const Maths::matrix4& matrix);

		//Enable and Disable shader functions
		void enable() const;
		void disable() const;

		//Private functions
	private:
		GLuint load();
		GLint getUniformLocation(const GLchar* name);
	};

} }