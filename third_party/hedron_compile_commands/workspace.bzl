load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def hedron_compile_commands():
    http_archive(
        name = "hedron_compile_commands",
        sha256 = "05f7fb324290c147ed29361a6a6fef7459c61816084fc07b3676a9639f4fcab7",
        strip_prefix = "bazel-compile-commands-extractor-eca42c63700fccdc49cf58177e0a96f0f6075a68",
        urls = ["https://github.com/hedronvision/bazel-compile-commands-extractor/archive/eca42c63700fccdc49cf58177e0a96f0f6075a68.tar.gz"],
    )
