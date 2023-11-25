load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def opencv():
    http_archive(
        name = "opencv",
        sha256 = "1ec1cba65f9f20fe5a41fda1586e01c70ea0c9a6d7b67c9e13edf0cfe2239277",
        urls = ["https://github.com/opencv/opencv/archive/refs/tags/4.6.0.tar.gz"],
        build_file = "//third_party/opencv:opencv.BUILD.bzl",
        strip_prefix = "opencv-4.6.0",
    )
