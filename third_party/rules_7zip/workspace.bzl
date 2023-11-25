load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def rules_7zip():
    http_archive(
        name = "rules_7zip",
        strip_prefix = "rules_7zip-e00b15d3cb76b78ddc1c15e7426eb1d1b7ddaa3e",
        urls = ["https://github.com/zaucy/rules_7zip/archive/e00b15d3cb76b78ddc1c15e7426eb1d1b7ddaa3e.zip"],
        sha256 = "fd9e99f6ccb9e946755f9bc444abefbdd1eedb32c372c56dcacc7eb486aed178",
    )
