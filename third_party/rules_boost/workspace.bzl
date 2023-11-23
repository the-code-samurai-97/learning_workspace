load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def boost_deps():
    http_archive(
        name = "com_github_nelhage_rules_boost",
        url = "https://github.com/nelhage/rules_boost/archive/8a2609acaa1f1317a8b9d9b5d566e8e98c3bf343.tar.gz",
        sha256 = "bb0d686145a1580fbbd029ef575f534cb770328e14d85880cc6db11f9586e1c4",
        strip_prefix = "rules_boost-8a2609acaa1f1317a8b9d9b5d566e8e98c3bf343",
    )
