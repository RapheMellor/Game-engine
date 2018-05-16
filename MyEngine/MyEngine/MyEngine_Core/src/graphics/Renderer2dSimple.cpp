//Include file
#include "Renderer2dSimple.h"

namespace MyEngine { namespace graphics {

	//Submit function allows you to add sprites to be rendered into a queue that will be rendered one after the other
	void Renderer2DSimple::submit(const Renderable2D* renderable)
	{
		m_RenderQueue.push_back(renderable);
	}

	//Flush function goes through the submit queue to check if the queue is empty then renders all sprites that where in the queue
	void Renderer2DSimple::flush()
	{
		while (!m_RenderQueue.empty())
		{
			const Renderable2D* renderable = m_RenderQueue.front();
			renderable->getVAO()->bind();
			renderable->getIBO()->bind();

			renderable->getShader().setUniformMat4("ml_matrix", Maths::matrix4::translation(renderable->getPosition()));
			glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, 0);

			renderable->getIBO()->unbind();
			renderable->getVAO()->unbind();

			m_RenderQueue.pop_front();
		}
	}

} }