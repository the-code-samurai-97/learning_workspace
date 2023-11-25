load("@pip_deps//:requirements.bzl", "requirement")

py_binary(
    name = "python_example",
    srcs = ["python_example.py"],
    deps = [requirement("numpy"),requirement("matplotlib"),requirement("scipy"),requirement("scikit-learn")],
)

py_binary(
    name = "matplotlib_example",
    srcs = ["matplotlib_example.py"],
    deps = [requirement("matplotlib")]
    #add PySide2 for linux
)

py_binary(
    name = "polygon",
    srcs = ["polygon.py"],
    deps = [requirement("matplotlib")]
    #add PySide2 for linux
)