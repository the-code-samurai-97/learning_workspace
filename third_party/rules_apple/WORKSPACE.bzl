load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")


def build_bazel_rules_apple():
    http_archive(
        name = "build_bazel_rules_apple",
        sha256 = "b6e35b3b72b2b3d8ba432be502a224506913ba8a09242e86b2be7b60f785fb98",
        url = "https://github.com/bazelbuild/rules_apple/archive/c667615d935427cce70bb2c7146d800cc1c34ad9.tar.gz",
        strip_prefix = "rules_apple-c667615d935427cce70bb2c7146d800cc1c34ad9",
    )
