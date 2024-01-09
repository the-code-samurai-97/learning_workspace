filegroup(
    name = "input_pcd",
    srcs = ["source_pointcloud.pcd"],
)

cc_binary(
    name = "open3d_example",
    srcs = ["main.cpp"],
    #    select({"@platforms//:linux_platform": ["@open3d"],"@platforms//os:macos": ["@open3d_macos"]}),
    data = [":input_pcd"],
    deps = [
        "@glfw",
        "@open3d_macos",
    ],
)
