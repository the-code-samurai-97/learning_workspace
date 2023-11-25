load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def rules_vtk():
    http_archive(
        name = "vtk",
        build_files = ["third_party/rules_vtk/vtk.BUILD.bzl"],
        sha256 = "8586084f71f9bde545ee7fa6d00288b264a2b7ac3607b974e54d13e7162c1c72",
        strip_prefix = "VTK-73c92857af780d20acd3ddf646c62e6dba0cde83",
        urls = ["https://github.com/Kitware/VTK/commit/73c92857af780d20acd3ddf646c62e6dba0cde83.tar.gz"],
    )
