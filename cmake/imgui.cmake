include(FetchContent)
FetchContent_Declare(	
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.88
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/.vendor/imgui
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(imgui)