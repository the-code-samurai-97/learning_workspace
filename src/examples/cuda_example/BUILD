
load("@rules_cuda//cuda:defs.bzl", "cuda_library")

cuda_library(
    name = "kernel",
    hdrs = select({
            "@rules_cuda//cuda:is_enabled": ["kernel.h"],
            "//conditions:default": []}),
    srcs =  select({
                   "@rules_cuda//cuda:is_enabled": ["kernel.cu"],
                   "//conditions:default": []}),
    target_compatible_with = ["@platforms//os:linux"],

)

cc_binary(
    name = "main",
    srcs =  select({
                       "@rules_cuda//cuda:is_enabled": ["main.cpp"],
                       "//conditions:default": []}),
    deps = select({
        "@rules_cuda//cuda:is_enabled": [":kernel"],
        "//conditions:default": []}),
    target_compatible_with = ["@platforms//os:linux"],


)

cc_binary(
    name = "deviceQuery",
    srcs = ["deviceQuery.cpp"],
    deps = select({
            "@rules_cuda//cuda:is_enabled": ["@local_cuda//:cuda_runtime"],
            "//conditions:default": []}),
    target_compatible_with = ["@platforms//os:linux"],

)