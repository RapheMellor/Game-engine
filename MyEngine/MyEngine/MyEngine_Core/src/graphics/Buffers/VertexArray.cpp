//Include file
#include "VertexArray.h"

namespace MyEngine { namespace graphics {

	//Vertex array function
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_ArrayID);
	}

	//Vertex array destructor
	VertexArray::~VertexArray()
	{
		for (int i = 0; i < m_Buffers.size(); i++)
			delete m_Buffers[i];
	}

	//Add buffer function
	void VertexArray::addBuffer(Buffer* buffer, GLuint index)
	{
		bind();
		buffer->bind();

		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

		buffer->unbind();
		unbind();
	}

	//Bind vertex function
	void VertexArray::bind() const
	{
		glBindVertexArray(m_ArrayID);
	}

	//Unbind vertex function
	void VertexArray::unbind() const
	{
		glBindVertexArray(0);
	}

} }