load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def glfw():
    http_archive(
        name = "glfw",
        urls = ["https://github.com/glfw/glfw/archive/refs/tags/3.3.8.tar.gz"],
        sha256 = "f30f42e05f11e5fc62483e513b0488d5bceeab7d9c5da0ffe2252ad81816c713",
        strip_prefix = "glfw-3.3.8",
        build_file = "//third_party/glfw:glfw.BUILD.bzl",
    )
