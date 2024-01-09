# About

This repository serves as a public testing ground for Bazel and other related technologies. Feel free to experiment, contribute, and learn from the codebase. If you have any questions or suggestions, please open an issue or contribute to the discussions.

Happy learning! 🚀
# RUN - Learning Workspace with Bazel

Welcome to the RUN repository! This is a public GitHub repository designed to help you learn and experiment with Bazel and other related technologies. The repository includes instructions for installation, querying modules, and running in a Docker container.

## Install

```bash
sudo apt-get install libglew-dev libc6-dev libx11-dev libpthread-stubs0-dev
```
``` bash
cd learning_workspace && bazel build //...
```
## Query the Modules
```bash
bazel query "@module//:*" | grep -v -e .cpp -e .hpp -e .c -e .S -e .so -e .ipp -e .h -e .bazel

```
Example
```bash
bazel query "@boost//:*" | grep -v -e .cpp -e .hpp -e .c -e .S -e .so -e .ipp -e .h -e .bazel
```
## Docker
```bash
docker build --platform linux/amd64 -t ubuntu-bazel .
docker run --platform linux/amd64 -it --rm -v ~/dev/learning_workspace:/home/nonrootuser/workspace ubuntu-bazel bash
```