filegroup(
    name = "model_filegroup",
    srcs = [
        "base_1.png",
        "base_2.png",
    ],
)

cc_binary(
    name = "sift_feature",
    srcs = [
        "sift_main.cpp",
    ],
    copts = [
        "-Wno-deprecated-declarations",
        "-Wno-unused-parameter",
        "-Wno-unused-variable",
        "-Wno-address",
    ],
    data = [":model_filegroup"],
    deps = [
        "@opencv",
    ],
)
