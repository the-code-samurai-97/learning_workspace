load("@rules_pcl//bzl:pcl.bzl", "pcl_config")

pcl_config()

cc_binary(
    name = "pcl_example",
    srcs = ["main.cpp"],
    deps = [
        "@pcl//:common",
    ],
)
