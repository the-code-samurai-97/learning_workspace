#RUN 

###install
```
sudo apt-get install libglew-dev libc6-dev libx11-dev libpthread-stubs0-dev 

```

```
cd learning_workspace && bazel build //...
```
#Query the Modules
```angular2html
bazel query "@module//:*" | grep -v -e .cpp -e .hpp -e .c -e .S -e .so -e .ipp -e .h -e .bazel
#example
bazel query "@boost//:*" | grep -v -e .cpp -e .hpp -e .c -e .S -e .so -e .ipp -e .h -e .bazel
```

###Docker
```angular2html
docker build --platform linux/amd64 -t ubuntu-bazel .
docker run --platform linux/amd64 -it --rm -v ~/dev/learning_workspace:/home/nonrootuser/workspace ubuntu-bazel bash
```