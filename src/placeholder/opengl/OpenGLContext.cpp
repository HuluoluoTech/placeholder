#include "../plpch.h"
#include <glad/glad.h>

#include "OpenGLContext.h"
#include <GLFW/glfw3.h>

namespace Placeholder {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		PL_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		PL_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PL_CORE_ASSERT(status, "Failed to initialize Glad!");

		PL_CORE_INFO("OpenGL Info:");
		PL_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		PL_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		PL_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		PL_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Placeholder requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		PL_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}
