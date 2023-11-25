load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "platforms",
    sha256 = "8150406605389ececb6da07cbcb509d5637a3ab9a24bc69b1101531367d89d74",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/platforms/releases/download/0.0.8/platforms-0.0.8.tar.gz",
        "https://github.com/bazelbuild/platforms/releases/download/0.0.8/platforms-0.0.8.tar.gz",
    ],
)

load("//third_party/bazel_skylib:workspace.bzl", "bazel_skylib")

bazel_skylib()

load("//third_party/hedron_compile_commands:workspace.bzl", "hedron_compile_commands")
load("//third_party/rules_foreign_cc:workspace.bzl", "rules_foreign_cc")

hedron_compile_commands()

rules_foreign_cc()

# Tell Bazel about our toolchains so it can resolve them based on values passed
# in --platform, --host_platform, and --execution_platforms options.
register_toolchains()

# Tell Bazel that //:linux_platform is allowed execution platform - that our
# host system or remote execution service can handle that platform.
register_execution_platforms()
#-------------------------------------------------------------
# Python
#-------------------------------------------------------------

load("//third_party/rules_python:workspace.bzl", "rules_python")

rules_python()

load("@rules_python//python:repositories.bzl", "py_repositories")

py_repositories()

load("@rules_python//python:repositories.bzl", "python_register_toolchains")

python_register_toolchains(
    name = "python_3_11",
    python_version = "3.11",
)

load("@python_3_11//:defs.bzl", "interpreter")
load("@rules_python//python:pip.bzl", "pip_parse")

pip_parse(
    name = "pip_deps",
    python_interpreter_target = interpreter,
    quiet = False,
    requirements_lock = "@//:requirements_linux.txt",
    #    requirements_linux = "//:requirements_linux.txt",
)

load("@pip_deps//:requirements.bzl", "install_deps")

install_deps()

load("@rules_python//python:pip.bzl", "compile_pip_requirements")

#-------------------------------------------------------------
# apple
#-------------------------------------------------------------
load("//third_party/rules_apple:WORKSPACE.bzl", "build_bazel_rules_apple")

build_bazel_rules_apple()

load("@build_bazel_rules_apple//apple:repositories.bzl", "apple_rules_dependencies")

apple_rules_dependencies()

load("@build_bazel_rules_swift//swift:repositories.bzl", "swift_rules_dependencies")

swift_rules_dependencies()

load("@build_bazel_rules_swift//swift:extras.bzl", "swift_rules_extra_dependencies")

swift_rules_extra_dependencies()

load("@build_bazel_apple_support//lib:repositories.bzl", "apple_support_dependencies")

apple_support_dependencies()

#-------------------------------------------------------------
# Emscripten
#-------------------------------------------------------------

http_archive(
    name = "emsdk",
    sha256 = "8b5b3433eb732dcc7643a2707a12fd5cbe793a5dadbbae9a60c24a737a78fe33",
    strip_prefix = "emsdk-3.1.45/bazel",
    url = "https://github.com/emscripten-core/emsdk/archive/refs/tags/3.1.45.tar.gz",
)

load("@emsdk//:deps.bzl", emsdk_deps = "deps")

emsdk_deps()

load("@emsdk//:emscripten_deps.bzl", emsdk_emscripten_deps = "emscripten_deps")

emsdk_emscripten_deps(emscripten_version = "3.1.45")

load("@emsdk//:toolchains.bzl", "register_emscripten_toolchains")

register_emscripten_toolchains()
#-------------------------------------------------------------
# Third Party Dependencies
#-------------------------------------------------------------

load("//third_party:repositories.bzl", "third_party_repositories")

third_party_repositories()

#-------------------------------------------------------------
# Cuda
#-------------------------------------------------------------

load("@rules_cuda//cuda:repositories.bzl", "register_detected_cuda_toolchains", "rules_cuda_dependencies")

rules_cuda_dependencies()

register_detected_cuda_toolchains()

#-------------------------------------------------------------
# Boost
#-------------------------------------------------------------

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")

boost_deps()
#-------------------------------------------------------------
# 7zip
#-------------------------------------------------------------

load("@rules_7zip//:setup.bzl", "setup_7zip")

setup_7zip()
#-------------------------------------------------------------
# rules vulkan
#-------------------------------------------------------------

load("@com_github_zaucy_rules_vulkan//:repo.bzl", "vulkan_repos")

vulkan_repos()

#-------------------------------------------------------------
# PCL
#-------------------------------------------------------------

load("@rules_pcl//bzl:repositories.bzl", "pcl_repositories")

pcl_repositories()

load("@rules_pcl//bzl:init_deps.bzl", "pcl_init_deps")

pcl_init_deps()
