#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks-inl.h>

namespace Placeholder
{
    std::shared_ptr<spdlog::logger> Log::_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::_ClientLogger;

    Log::Log()
    {}

    Log::~Log()
    {}

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        _CoreLogger = spdlog::stdout_color_mt("PLACEHOLDER", spdlog::color_mode::always);
        _CoreLogger->set_level(spdlog::level::trace);

        _ClientLogger = spdlog::stdout_color_mt("APP");
        _ClientLogger->set_level(spdlog::level::trace);
    }
}