filegroup(
    name = "images",
    srcs = [
        "base_1.png",
        "base_2.png",
        "base_1_rm.png",
        "base_2_rm.png",
        "base_1_cp_rm.png",
        "base_2_cp_rm.png",
        "base_1_cp.png",
        "base_2_cp.png",
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
    data = [":images"],
    deps = [
        "@eigen",
        "@opencv",
    ],
)
