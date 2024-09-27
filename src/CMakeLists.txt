add_executable(clang_deprecation_warning
    clang_deprecation_warning.cpp
    pimpl_with_make_shared.cpp
    pimpl_with_shared_ptr.cpp
)

target_include_directories(clang_deprecation_warning
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}")