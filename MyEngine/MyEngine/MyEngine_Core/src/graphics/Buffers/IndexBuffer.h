#pragma once

//Include file
#include <GL/glew.h>

namespace MyEngine { namespace graphics {

		class IndexBuffer
		{
			//Private functions
		private:
			GLuint m_BufferID;
			GLuint m_Count;

			//Public functions
		public:
			IndexBuffer(GLushort* data, GLsizei count);

			void bind() const;
			void unbind() const;

			inline GLuint getCount() const { return m_Count; }
		};

} }