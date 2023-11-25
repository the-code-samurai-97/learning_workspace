load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def com_github_zaucy_rules_vulkan():
    # Replace with latest repository commit hash
    RULES_VULKAN_COMMIT = "2185587d8cd9e765794ea499344f0233237af1b0"

    http_archive(
        name = "com_github_zaucy_rules_vulkan",
        strip_prefix = "rules_vulkan-{}".format(RULES_VULKAN_COMMIT),
        url = "https://github.com/zaucy/rules_vulkan/archive/{}.zip".format(RULES_VULKAN_COMMIT),
        patches = ["//third_party/rules_vulkan:rules_vulkan.patch"],
        patch_args = ["-p1"],
    )
