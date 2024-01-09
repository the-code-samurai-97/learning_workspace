load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def open3d_macos():
    http_archive(
        name = "open3d_macos",
        sha256 = "d4ad56efc3429dfd7aa7e8e0253c1d0f55b4eac7bef5edc69b3cf2356e0dd058",
        urls = ["https://github.com/isl-org/Open3D/releases/download/v0.18.0/open3d-devel-darwin-arm64-0.18.0.tar.xz"],
        build_file = "//third_party/open3d_macos:open3d.BUILD.bzl",
        strip_prefix = "open3d-devel-darwin-arm64-0.18.0",
    )

#        http_archive(
#                name = "open3d",
#                sha256 = select({"@platforms//os:macos": ["3f6455881a38b170c7bba0622019137aaf359dcee374626ed000d4e7f8dfdd49"],
#                                "@platforms//os:linux": ["e473031c64ef744f639418321f7731e799a61b1da2fc7b0902e87bbb14a8f16f"]}),
#                urls = select({"@platforms//os:macos": [["https://github.com/isl-org/Open3D/releases/download/v0.17.0/open3d-devel-darwin-x86_64-0.17.0.tar.xz"]],
#                               "@platforms//os:linux": [["https://github.com/isl-org/Open3D/releases/download/v0.17.0/open3d-devel-linux-x86_64-cxx11-abi-cuda-0.17.0.tar.xz"]]}),
#                build_file = "//third_party/open3d:open3d.BUILD.bzl",
#                strip_prefix = select({"@platforms//os:macos": ["open3d-devel-darwin-x86_64-0.17.0"],
#                                    "@platforms//os:linux": ["open3d-devel-linux-x86_64-cxx11-abi-cuda-0.17.0"]}),
#
#        )
