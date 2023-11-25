cc_library(
    name = "open3d",
    hdrs = glob(["include/open3d/**"]),
    srcs = select({
        "@platforms//os:macos": ["lib/libOpen3D.dylib"],
        "@platforms//os:linux": ["lib/libOpen3D.so"],
    }),
    includes = ["include"],
    deps = ["@eigen", "@fmt", "@glfw", "@glew"],
    visibility = ["//visibility:public"],
)
