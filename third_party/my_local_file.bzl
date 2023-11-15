def _my_local_file_impl(repository_ctx):
    repository_ctx.extract(repository_ctx.attr.src)
    repository_ctx.file("BUILD.bazel", repository_ctx.read(repository_ctx.attr.build_file))

my_local_file = repository_rule(
    attrs = {
        "src": attr.label(mandatory = True, allow_single_file = True),
        "build_file": attr.label(mandatory = True, allow_single_file = True),
    },
    implementation = _my_local_file_impl,
)
