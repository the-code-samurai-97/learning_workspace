load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def open3d():
    http_archive(
        name = "open3d",
        sha256 = "e473031c64ef744f639418321f7731e799a61b1da2fc7b0902e87bbb14a8f16f",
        urls = ["https://github.com/isl-org/Open3D/releases/download/v0.17.0/open3d-devel-linux-x86_64-cxx11-abi-cuda-0.17.0.tar.xz"],
        build_file = "//third_party/open3d:open3d.BUILD.bzl",
        strip_prefix = "open3d-devel-linux-x86_64-cxx11-abi-cuda-0.17.0",
    )


#
    #    http_archive(
    #            name = "open3d",
    #            sha256 = select({"@platforms//os:macos": ["e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"],
    #                            "@platforms//os:linux": ["e473031c64ef744f639418321f7731e799a61b1da2fc7b0902e87bbb14a8f16f"]}),
    #            urls = select({"@platforms//os:macos": ["https://github.com/isl-org/Open3D/releases/download/v0.17.0/open3d-devel-darwin-x86_64-0.17.0.tar.xz"],
    #                           "@platforms//os:linux": ["https://github.com/isl-org/Open3D/releases/download/v0.17.0/open3d-devel-linux-x86_64-cxx11-abi-cuda-0.17.0.tar.xz"]}),
    #            build_file = "//third_party/open3d:open3d.BUILD.bzl",
    #            strip_prefix = select({"@platforms//os:macos": ["open3d-devel-darwin-x86_64-0.17.0"],
    #                                "@platforms//os:linux": ["open3d-devel-linux-x86_64-cxx11-abi-cuda-0.17.0"]}),

    #    )