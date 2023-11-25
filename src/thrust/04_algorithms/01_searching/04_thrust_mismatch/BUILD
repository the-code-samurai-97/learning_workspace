# Run with 'bazel run //examples/thrust:main'

load("@rules_cuda//cuda:defs.bzl", "cuda_library")

# thrust have code marked as __global__ or __kernel__
# so source for thrust should be built with cuda_library first
cuda_library(
    name = "thrust_cu",
    srcs = ["04_thrust_mismatch.cpp"],
    deps = ["@local_cuda//:thrust"],
        target_compatible_with = ["@platforms//os:linux"],
)

# Run with 'bazel run //examples/thrust:main'
cc_binary(
    name = "04_thrust_mismatch",
    deps = [":thrust_cu"],
        target_compatible_with = ["@platforms//os:linux"],
)
cc_binary(
    name = "04_mismatch",
    srcs = ["04_mismatch.cpp"],
)
