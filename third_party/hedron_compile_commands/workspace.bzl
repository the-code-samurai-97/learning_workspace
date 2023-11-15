load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def hedron_compile_commands():
    http_archive(
        name = "hedron_compile_commands",
        sha256 = "2f6c129770dbc7a0bb53057b8a225ee1eb275bf27e05504b683f8d96d2c877c9",
        strip_prefix = "bazel-compile-commands-extractor-12440540f4461cac006a357257d698aed74a2423",
        urls = ["https://github.com/hedronvision/bazel-compile-commands-extractor/archive/12440540f4461cac006a357257d698aed74a2423.tar.gz"],
    )
