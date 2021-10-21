# FreeSR: A Free Library for Speaker Recognition
This is a free library for Speaker Recognition (Verification), which is completely implemented in C/C++ by [ncnn](https://github.com/Tencent/ncnn). In addition, Speaker Gender Recognition is also implemented.
We also provide a example for java.

## FreeSR

|                | Windows (X64/Release) | Linux (X64) | Android      |
|----------------|-----------------|-------------|--------------|
|                | >=VS2015        | g++7.5.0   |  --    |
|Speaker Recognition(Verification)| &#10004;| &#10004; |  --    |
|Speaker Gender Recognition | &#10004; | &#10004;  |  --    |

## Usage
```
mkdir build; cd build; cmake.exe .. -G"Visual Studio 14 Win64"
```
The input is preferably raw data without normalization from wav (single channel, bitspersample 16bits and sample rate 16K).
More detailed information about usage of FreeSR can be referred to [speaker_recognizer.h](/freesr-cpp/include/speaker_recognizer.h).

[Example](/freesr-cpp/example/)
