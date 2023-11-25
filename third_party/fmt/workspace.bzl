load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def fmt():
    http_archive(
        name = "fmt",
       sha256 = "deb0a3ad2f5126658f2eefac7bf56a042488292de3d7a313526d667f3240ca0a",
        urls = ["https://github.com/fmtlib/fmt/archive/refs/tags/10.1.0.tar.gz"],
        build_file = "//third_party/fmt:fmt.BUILD.bzl",
        strip_prefix = "fmt-10.1.0",
    )
