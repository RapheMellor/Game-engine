//All needed inlcude files
#include "src/graphics/window.h"
#include "src/Maths/Maths.h"
#include "src/graphics/Shader.h"
#include "src/graphics/Buffers/VertexBuffer.h"
#include "src/graphics/Buffers/IndexBuffer.h"
#include "src/graphics/Buffers/VertexArray.h"
#include "src/graphics/Renderer2d.h"
#include "src/graphics/Renderer2dSimple.h"

int main()
{
	//All used namespaces
	using namespace MyEngine;
	using namespace graphics;
	using namespace Maths;
	
	//Size and name of window
	Window window("window", 800, 600);
	//Colour of the background
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	//Orthographic matrix test
	matrix4 ortho = matrix4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	//Includes and enables the shader files
	Shader shader("src/Shaders/Basic.vert", "src/Shaders/Basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", matrix4::translation(Vector3(4, 3, 0)));

	//Sets the values for the sprites to the Renderable2D
	Renderable2D sprite(Maths::Vector3(5, 5, 0), Maths::Vector2(4, 4), Maths::Vector4(1, 0, 1, 1), shader);
	Renderable2D sprite2(Maths::Vector3(6, 3, 0), Maths::Vector2(2, 5), Maths::Vector4(0.4, 0.9, 0.1, 1), shader);
	Renderer2DSimple renderer;

	//Set the shader values
	shader.setUniform2f("light_pos", Vector2(8.0f, 2.5f));
	shader.setUniform4f("colour", Vector4(0.5f, 0.8f, 0.8f, 1.0f));

	while (!window.closed())
	{
		window.clear();
		//Set the mouse position to x and y then gets mouse position
		double x, y;
		window.getMousePosition(x, y);
		//Sets the light position
		shader.setUniform2f("light_pos", Vector2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		//Tell the renderer to print the correct sprites
		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		//Destroys any unnecessary data not being used
		renderer.flush();

		window.update();
	}

	return 0;
}
