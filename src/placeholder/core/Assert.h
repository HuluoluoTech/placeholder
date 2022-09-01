#pragma once

#include "Base.h"
#include "Log.h"
#include <filesystem>

#define PL_ENABLE_ASSERTS
#ifdef PL_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define PL_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { PL##type##ERROR(msg, __VA_ARGS__); PL_DEBUGBREAK(); } }
	#define PL_INTERNAL_ASSERT_WITH_MSG(type, check, ...) PL_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define PL_INTERNAL_ASSERT_NO_MSG(type, check) PL_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", PL_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define PL_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define PL_INTERNAL_ASSERT_GET_MACRO(...) PL_EXPAND_MACRO( PL_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, PL_INTERNAL_ASSERT_WITH_MSG, PL_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define PL_ASSERT(...) PL_EXPAND_MACRO( PL_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define PL_CORE_ASSERT(...) PL_EXPAND_MACRO( PL_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define PL_ASSERT(...)
	#define PL_CORE_ASSERT(...)
#endif
