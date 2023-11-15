

filegroup(
    name = "model_filegroup",
    srcs = ["network_output.png"],
)
cc_binary(
    name = "line_detect",
    srcs = [
        "main.cpp",
        "LineFitting.cpp",
        "LineFitting.hpp"
    ],
    data = [":model_filegroup"],
    copts = [
        "-Wno-deprecated-declarations",
        "-Wno-unused-parameter",
        "-Wno-unused-variable",
        "-Wno-address",
    ],
    deps = [
        "@opencv",
    ],
)