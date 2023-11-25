load("@rules_foreign_cc//foreign_cc:cmake.bzl", "cmake")

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

cmake(
    name = "glew",
    working_directory = "build/cmake",
    lib_source = "//:all_srcs",
    generate_args = ["-GNinja"],
    tags = ["requires-network"],
    out_include_dir = "include/GL",
    out_shared_libs = ["libGLEW.2.2.0.dylib","libGLEW.2.2.dylib","libGLEW.dylib"],
    visibility = ["//visibility:public"],
)