# Run with 'bazel run //examples/thrust:main'

load("@rules_cuda//cuda:defs.bzl", "cuda_library")

# thrust have code marked as __global__ or __kernel__
# so source for thrust should be built with cuda_library first
cuda_library(
    name = "thrust_cu",
    srcs = ["01_thrust_find.cu"],
    deps = ["@local_cuda//:thrust"],
)

# Run with 'bazel run //examples/thrust:main'
cc_binary(
    name = "01_thrust_find",
    deps = [":thrust_cu"],
)
cc_binary(
    name = "01_find",
    srcs = ["01_find.cpp"],
)