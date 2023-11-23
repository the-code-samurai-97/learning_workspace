load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def rules_pcl():
    http_archive(
        name = "rules_pcl",
        url = "https://github.com/kgreenek/rules_pcl/archive/refs/tags/pcl-1.13.1-v1.tar.gz",
        sha256 = "06d2ed755fbf9ddd30f8bb3ed73f23ee6155d52e742d4e4a278c9458e9a3e17b",
        strip_prefix = "rules_pcl-pcl-1.13.1-v1",
    )
