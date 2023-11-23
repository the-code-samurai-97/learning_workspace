load("@rules_cuda//cuda:defs.bzl", "cuda_library")

package(default_visibility = ["//visibility:public"])

cuda_library(
    name = "kernel",
    srcs = ["kernel.cu"],
    hdrs = ["kernel.h"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":kernel"],
)

cc_binary(
    name = "deviceQuery",
    srcs = ["deviceQuery.cpp"],
    deps = ["@local_cuda//:cuda_runtime"],
)
