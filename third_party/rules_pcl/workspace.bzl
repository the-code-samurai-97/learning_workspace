load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def rules_pcl():
    http_archive(
        name = "rules_pcl",
        url = "https://github.com/kgreenek/rules_pcl/archive/v1.1.0.tar.gz",
        sha256 = "987dd22ac4637093414ff2b9291d0e9e29f3ef156a12d5471eedaa2d5beb0a93",
        strip_prefix = "rules_pcl-1.1.0",
    )
