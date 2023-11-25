cc_binary(
    name = "glfw_example",
    srcs = ["main.cpp"],
    deps = ["@glfw"],
)
cc_binary(
    name = "pcl_view",
    srcs = ["pcl_view.cpp"],
    deps = ["@pcl//:io","@glfw"],
    linkopts = ["-lGL"],
)