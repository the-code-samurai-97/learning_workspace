filegroup(
    name = "pcds",
    srcs = [
        "source_pointcloud.pcd",
        "target_pointcloud.pcd",
    ],
)

cc_binary(
    name = "register_pointcloud",
    srcs = ["registration_pointcloud.cpp"],
    data = [":pcds"],
    deps = [
        "@boost//:filesystem",
        "@boost//:program_options",
        "@pcl//:common",
        "@pcl//:io",
        "@pcl//:registration",
        "@open3d",
        "@glfw",
    ],
)
