load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def rules_pcl():
    http_archive(
        name = "rules_pcl",
        url = "https://github.com/kgreenek/rules_pcl/archive/f7e08250e8adbaa873ac4b7579595eefa08bcf8a.tar.gz",
        sha256 = "ac6153541ab57eb66b6ac67a66925696a634209430bc43e15a904162d271bdf4",
        strip_prefix = "rules_pcl-f7e08250e8adbaa873ac4b7579595eefa08bcf8a",
    )
