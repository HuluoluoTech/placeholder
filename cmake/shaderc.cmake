include(FetchContent)
FetchContent_Declare(	
    shaderc
    GIT_REPOSITORY https://github.com/google/shaderc.git
    GIT_TAG v2022.2
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/.vendor/shaderc
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(shaderc)