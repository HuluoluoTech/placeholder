#include "../plpch.h"
#include "IWindow.h"
#include "Window.h"

namespace Placeholder
{
	Scope<IWindow> IWindow::Create(const WindowProps& props)
	{
		return CreateScope<Window>(props);
	}

}