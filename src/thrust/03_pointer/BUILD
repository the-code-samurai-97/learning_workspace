load("@rules_cuda//cuda:defs.bzl", "cuda_library")

# thrust have code marked as __global__ or __kernel__
# so source for thrust should be built with cuda_library first
cuda_library(
    name = "thrust_pointer",
    srcs = ["03_pointer.cu"],
    deps = ["@local_cuda//:thrust"],
        target_compatible_with = ["@platforms//os:linux"],
)

# Run with 'bazel run //examples/thrust:main'
cc_binary(
    name = "03_pointer",
    deps = [":thrust_pointer"],
        target_compatible_with = ["@platforms//os:linux"],
)