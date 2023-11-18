load("@rules_cuda//cuda:defs.bzl", "cuda_library")

# thrust have code marked as __global__ or __kernel__
# so source for thrust should be built with cuda_library first
cuda_library(
    name = "thrust_vector",
    srcs = ["01_vector.cu"],
    deps = ["@local_cuda//:thrust"],
)

# Run with 'bazel run //examples/thrust:main'
cc_binary(
    name = "01_vector",
    deps = [":thrust_vector"],
)