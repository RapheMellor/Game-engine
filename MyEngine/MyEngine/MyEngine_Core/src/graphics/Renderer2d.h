#pragma once

//Include files
#include <GL/glew.h>
#include "Renderable2d.h"
#include "../Maths/Matrix4.h"

namespace MyEngine { namespace graphics {

	class Renderer2D
	{
		//Protected functions
	protected:
		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void flush() = 0;
	};

} }