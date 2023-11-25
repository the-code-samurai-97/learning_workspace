cc_library(
    name = "fmt",
    srcs = [
        "src/format.cc",
    ],
    hdrs = glob(["include/fmt/*.h"]),
    includes = ["include", "src"],
    visibility = ["//visibility:public"],
)
