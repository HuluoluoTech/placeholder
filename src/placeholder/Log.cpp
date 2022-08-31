#include "Log.h"

namespace Placeholder
{
    static std::shared_ptr<spdlog::logger> Log::_CoreLogger;
    static std::shared_ptr<spdlog::logger> Log::_ClientLogger;

    Log::Log()
    {}

    Log::~Log()
    {}

    vodi Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        _CoreLogger = spdlog::stdout_color_mt("PLACEHOLDER");
        _CoreLogger->set_level(spdlog::level::trace);

        _ClientLogger = spdlog::stdout_color_mt("APP");
        _ClientLogger->set_level(spdlog::level::trace);
    }
}