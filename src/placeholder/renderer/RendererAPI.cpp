#include "RendererAPI.h"

#include "../opengl/OpenGLRendererAPI.h"

namespace Placeholder {

	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
			case RendererAPI::API::None:    PL_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
		}

		PL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}