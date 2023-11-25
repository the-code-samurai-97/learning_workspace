load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def glew():
    http_archive(
        name = "glew",
        sha256 = "d4fc82893cfb00109578d0a1a2337fb8ca335b3ceccf97b97e5cc7f08e4353e1",
        urls = ["https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0.tgz"],
        build_file = "//third_party/glew:glew.BUILD.bzl",
        strip_prefix = "glew-2.2.0",
    )
