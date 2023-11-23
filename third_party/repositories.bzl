load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")
load("//third_party/opencv:workspace.bzl", "opencv")
load("//third_party/rules_cuda:workspace.bzl", "rules_cuda")
load("//third_party/rules_boost:workspace.bzl", "boost_deps")
load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

def third_party_repositories():
    hedron_compile_commands_setup()

    opencv()
    rules_cuda()

    boost_deps()

    rules_foreign_cc_dependencies()
