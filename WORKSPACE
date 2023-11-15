load("//third_party/bazel_skylib:workspace.bzl", "bazel_skylib")
load("//third_party/hedron_compile_commands:workspace.bzl", "hedron_compile_commands")
load("//third_party/rules_foreign_cc:workspace.bzl", "rules_foreign_cc")

bazel_skylib()
hedron_compile_commands()
rules_foreign_cc()

load("//third_party:repositories.bzl", "third_party_repositories")
third_party_repositories()
load("@rules_cuda//cuda:repositories.bzl", "register_detected_cuda_toolchains", "rules_cuda_dependencies")
rules_cuda_dependencies()
register_detected_cuda_toolchains()