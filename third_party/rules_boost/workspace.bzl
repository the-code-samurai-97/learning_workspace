load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def boost_deps():
    http_archive(
        name = "com_github_nelhage_rules_boost",
        url = "https://github.com/nelhage/rules_boost/archive/e877fba3c424a128167fb6d771fa3dd6fe316079.tar.gz",
        sha256 = "b1eeeec3f2d45ebf57ae3a4eee523aefca062ab4da71b35aafe73270b4316d49",
        strip_prefix = "rules_boost-e877fba3c424a128167fb6d771fa3dd6fe316079",
    )
    ## boost 1.81.0 commit-id -
    ## boost 1.82.0 commit-id - e877fba3c424a128167fb6d771fa3dd6fe316079
    ## boost 1.83.0 commit-id - 96e9b631f104b43a53c21c87b01ac538ad6f3b48
