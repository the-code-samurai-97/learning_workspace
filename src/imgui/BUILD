load("@rules_cc//cc:defs.bzl", "cc_library", "objc_library")

filegroup(
    name = "common_headers",
    srcs = glob(["include/*.h"]),
)

cc_library(
    name = "imgui_vulkan",
    srcs = [
        "backends/imgui_impl_glfw.cpp",
        "backends/imgui_impl_glfw.h",
        "backends/imgui_impl_vulkan.cpp",
        "backends/imgui_impl_vulkan.h",
        "imgui.cpp",
        "imgui.h",
        "imgui_demo.cpp",
        "imgui_draw.cpp",
        "imgui_tables.cpp",
        "imgui_widgets.cpp",
        ":common_headers",
    ],
    defines = ["__APPLE__"],
    local_defines = ["__APPLE__"],
    deps = [
        "@glfw",
        "@vulkan_sdk//:vulkan",
    ],
)

cc_binary(
    name = "imgui_demo_glfw_vulkan",
    srcs = [
        "examples/example_glfw_vulkan/main.cpp",
    ],
    deps = [":imgui_vulkan"],
)

objc_library(
    name = "imgui_metal",
    srcs = [
        "backends/imgui_impl_glfw.cpp",
        "backends/imgui_impl_metal.mm",
        "examples/example_glfw_metal/main.mm",
        "imgui.cpp",
        "imgui_demo.cpp",
        "imgui_draw.cpp",
        "imgui_tables.cpp",
        "imgui_widgets.cpp",
    ],
    hdrs = [
        "backends/imgui_impl_glfw.h",
        "backends/imgui_impl_metal.h",
        "imgui.h",
        ":common_headers",
    ],
    copts = ["-fno-objc-arc"],
    linkopts = [
        "-framework Metal",
        "-framework MetalKit",
        "-framework Cocoa",
        "-framework IOKit",
        "-framework CoreVideo",
        "-framework QuartzCore",
    ],
    deps = ["@glfw"],
)

cc_binary(
    name = "imgui_demo_apple_metal",
    deps = [":imgui_metal"],
)
