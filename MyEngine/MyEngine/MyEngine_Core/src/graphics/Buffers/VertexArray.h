#pragma once

//Include files
#include <GL/glew.h>
#include <vector>

#include "VertexBuffer.h"

namespace MyEngine { namespace graphics {

	class VertexArray
	{
		//Private functions
	private:
		GLuint m_ArrayID;
		std::vector<Buffer*> m_Buffers;

		//Public functions
	public:
		VertexArray();
		~VertexArray();
		void addBuffer(Buffer* buffer, GLuint index);
		void bind() const;
		void unbind()const;
	};

} }