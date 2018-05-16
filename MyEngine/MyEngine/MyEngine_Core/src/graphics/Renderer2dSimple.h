#pragma once

//Include files
#include <deque>
#include "Renderer2d.h"

namespace MyEngine { namespace graphics {

		class Renderer2DSimple : public Renderer2D
		{
			//Private functions
		private:
			std::deque<const Renderable2D*> m_RenderQueue;

			//Public functions
		public:
			void submit(const Renderable2D* renderable) override;
			void flush() override;
		};

} }