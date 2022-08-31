include(FetchContent)
FetchContent_Declare(	
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.x
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/.vendor/spdlog
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(spdlog)
# or
# find_package(spdlog)