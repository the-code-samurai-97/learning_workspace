DARWIN_LINKOPTS = [
    "-framework OpenGL",
    "-framework Cocoa",
    "-framework IOKit",
    "-framework CoreFoundation",
]
cc_library(
    name = "open3d_macos",
    hdrs = glob(["include/open3d/**"]),
    srcs = ["lib/libOpen3D.dylib"],
    includes = ["include"],
    deps = ["@eigen", "@fmt", "@glfw", "@glew"],
    linkopts = DARWIN_LINKOPTS,
    visibility = ["//visibility:public"],
)
