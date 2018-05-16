//Include file
#include "VertexBuffer.h"

namespace MyEngine { namespace graphics {

	Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componenetCount)
	{
		m_ComponenetCount = componenetCount;

		glGenBuffers(1, &m_BufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	//Bind buffer function
	void Buffer::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	}

	//Unbind buffer function
	void Buffer::unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	}

} }