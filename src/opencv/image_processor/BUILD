filegroup(
    name = "images",
    srcs = [
        "new_paint_inter_linear.png",
        "new_paint_inter_nearest_.png",
    ],
)

cc_binary(
    name = "gradient_testing",
    srcs = [
        "main.cpp",
    ],
    data = [":images"],
    deps = [
        "@opencv",
    ],
)
