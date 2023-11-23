#RUN 
```
cd learning_workspace && bazel build //...
```
#Query the Modules
```angular2html
bazel query "@module//:*" | grep -v -e .cpp -e .hpp -e .c -e .S -e .so -e .ipp -e .h -e .bazel
#example
bazel query "@boost//:*" | grep -v -e .cpp -e .hpp -e .c -e .S -e .so -e .ipp -e .h -e .bazel
```

