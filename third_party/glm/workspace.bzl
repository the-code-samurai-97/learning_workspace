load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def glm():
    GLM_VERSION = "0.9.9.8"

    http_archive(
        name = "glm",
        build_file = "@//third_party/glm:glm.BUILD.bzl",
        sha256 = "7d508ab72cb5d43227a3711420f06ff99b0a0cb63ee2f93631b162bfe1fe9592",
        strip_prefix = "glm-{}".format(GLM_VERSION),
        urls = ["https://github.com/g-truc/glm/archive/{}.tar.gz".format(GLM_VERSION)],
    )
