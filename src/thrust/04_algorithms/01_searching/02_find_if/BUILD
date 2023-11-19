# Run with 'bazel run //examples/thrust:main'

load("@rules_cuda//cuda:defs.bzl", "cuda_library")

# thrust have code marked as __global__ or __kernel__
# so source for thrust should be built with cuda_library first
cuda_library(
    name = "thrust_cu",
    srcs = ["02_thrust_find_if.cu"],
    deps = ["@local_cuda//:thrust"],
)

# Run with 'bazel run //examples/thrust:main'
cc_binary(
    name = "02_thrust_find_if",
    deps = [":thrust_cu"],
)
cc_binary(
    name = "02_find_if",
    srcs = ["02_find_if.cpp"],
)
