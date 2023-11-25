load("@rules_cuda//cuda:defs.bzl", "cuda_library")

# thrust have code marked as __global__ or __kernel__
# so source for thrust should be built with cuda_library first

cuda_library(
    name = "thrust_cu",
    srcs = select({"@platforms//os:linux": ["thrust.cu"],"@platforms//os:macos": []}),
    #srcs = ["thrust.cu"],
    defines = [] + select({
                    "@rules_cuda//cuda:is_enabled": ["CUDA_ENABLED"],
                    "//conditions:default": ["CUDA_DISABLED"],
                }),
    deps = [] + select({
                    "@rules_cuda//cuda:is_enabled": ["@local_cuda//:thrust"],
                    "//conditions:default": []}),

    target_compatible_with = ["@platforms//os:linux"],

)

# Run with 'bazel run //examples/thrust:main'
cc_binary(
    name = "main",
    defines = [] + select({
                "@rules_cuda//cuda:is_enabled": ["CUDA_ENABLED"],
                "//conditions:default": ["CUDA_DISABLED"],
            }),
    deps = [] + select({
                "@rules_cuda//cuda:is_enabled": [":thrust_cu"],
                "//conditions:default": []}),
    target_compatible_with = ["@platforms//os:linux"],

)