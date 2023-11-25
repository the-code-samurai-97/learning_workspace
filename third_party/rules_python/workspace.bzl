load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def rules_python():
    http_archive(
        name = "rules_python",
        sha256 = "e85ae30de33625a63eca7fc40a94fea845e641888e52f32b6beea91e8b1b2793",
        strip_prefix = "rules_python-0.27.1",
        url = "https://github.com/bazelbuild/rules_python/archive/refs/tags/0.27.1.tar.gz",
    )