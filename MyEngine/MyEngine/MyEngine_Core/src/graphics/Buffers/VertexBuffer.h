#pragma once

//Include file
#include <GL/glew.h>

namespace MyEngine { namespace graphics {

	class Buffer
	{
		//Private functions
	private:
		GLuint m_BufferID;
		GLuint m_ComponenetCount;
	
		//Public functions
	public:
		Buffer(GLfloat* data, GLsizei count, GLuint componenetCount);

		void bind() const;
		void unbind() const;

		inline GLuint getComponentCount() const { return m_ComponenetCount;  }
	};

} }