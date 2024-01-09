load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def eigen():
    http_archive(
        name = "eigen",
        sha256 = "8586084f71f9bde545ee7fa6d00288b264a2b7ac3607b974e54d13e7162c1c72",
        strip_prefix = "eigen-3.4.0",
        urls = ["https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz"],
        build_file = "//third_party/eigen:eigen.BUILD.bzl",
    )
