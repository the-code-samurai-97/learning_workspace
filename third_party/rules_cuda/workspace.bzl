load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def rules_cuda():
        http_archive(
            name = "rules_cuda",
            sha256 = "63ba2219104f73bca2ad1d4886df9afa404a14a7339395e629d0ef115c770c56",
            strip_prefix = "rules_cuda-1a2ec3d1ffacf3c462b69c2bbac91111d1752d21",
            urls = ["https://github.com/bazel-contrib/rules_cuda/archive/1a2ec3d1ffacf3c462b69c2bbac91111d1752d21.tar.gz"],
        )
