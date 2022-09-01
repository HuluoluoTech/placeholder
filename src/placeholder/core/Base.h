#pragma once

#include <memory>

#ifdef PL_DEBUG
	#if defined(HZ_PLATFORM_WINDOWS)
		#error "Platform doesn't support debugbreak yet!"
	#elif defined(PL_PLATFORM_UNIX)
	#else
	#endif

	#define PL_ENABLE_ASSERTS
#else
	#define PL_DEBUGBREAK()
#endif

#define BIT(x) (1 << x)
#define PL_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Placeholder {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#define PL_EXPAND_MACRO(x) x
#define PL_STRINGIFY_MACRO(x) #x
