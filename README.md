# PyTorch JIT

## Requirements
+ cmake == 3.13.3
+ scala == 2.12.8
+ java == 1.8.0

## Preparation
1. Upgrade PyTorch
```markdown
$ pip install --upgrade torch
```
2. Install requirements (Mac)
```markdown
$ brew upgrade
$ brew install scala
$ brew install cmake
$ brew install wget
```
3. Download libtorch
```markdown
$ wget https://download.pytorch.org/libtorch/cpu/libtorch-macos-latest.zip
$ unzip libtorch-macos-latest.zip
$ mv libtorch /path/to/project/freeze_cpp
$ rm libtorch-macos-latest.zip
```
4. Install mkl-ml library
```markdown
$ wget https://github.com/intel/mkl-dnn/releases/download/v0.17.2/mklml_mac_2019.0.1.20181227.tgz
$ tar -zxvf mklml_mac_2019.0.1.20181227.tgz
$ mv mklml_mac_2019.0.1.20181227/lib/* /path/to/project/freeze_cpp/libtorch/lib/
$ rm -rf mklml_mac_2019.0.1.20181227
$ rm mklml_mac_2019.0.1.20181227.tgz
```

## Tracing (in train_python directory)
1. make and training model
2. add tracing code at ```trace_model.py```
3. trace model by execution
```markdown
$ python trace_model.py
```

## make model loading script in serving module (in serve_scala directory)
1. make JNI corresponding function in ```EvalJNI.scala```
2. compile scala script
```markdown
$ cd /path/to/project/serve_scala
$ sbt compile
```
3. create java header (Mac)
```markdown
$ cd target/scala-2.12/classes
$ javah -cp /usr/local/Cellar/scala/2.12.8/libexec/lib/scala-library.jar:. EvalJNI
$ mv EvalJNI.h ../../../../freeze_cpp
```

## freeze with C++ (in freeze_cpp directory)
1. write ```model.cpp, model.hpp```
2. run cmake
```markdown
$ mkdir build
$ cd build
$ cmake -DCMAKE_PREFIX_PATH=/path/to/project/freeze_cpp/libtorch ..
$ make
$ ./binModel sample
```

## run serving module (in serve_scala directory)
1. copy ```trace_model.pth```
```markdown
$ cd /path/to/project/serve_scala
$ cp ../train_python/trace_model.pth src/main/resources
```
2. copy library file to serving module
```markdown
$ cp ../freeze_cpp/build/libModel.dylib lib
```
3. run ```EvalJNI.scala```

