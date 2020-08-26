# FreeSR: A Free Library for Speaker Recognition
This is a free library for Speaker Recognition (Verification), which is completely implemented in C/C++. In addition, Speaker Gender Recognition is also implemented.

## FreeSR

|                | Windows (X64/Release) | Linux (X64) | Android      |
|----------------|-----------------|-------------|--------------|
|                | >=VS2015        | --    |  --    |
|Speaker Recognition(Verification)| &#10004;        | --    |  &#10004;    |
|Speaker Gender Recognition | &#10004;        | --    |  &#10004;    |


## Usage
```
mkdir build; cd build; cmake.exe .. -G"Visual Studio 14 Win64"
```
The input is preferably raw data without normalization from wav (single channel, bitspersample 16bits and sample rate 16K).
More detailed information about usage of FreeSR can be referred to [speaker_recognizer.h](/include/speaker_recognizer.h).

[Example](/example/)

## Notes
For Windows, it is compiled by VS2015/X64/Release. When use VS, maybe you need to change the line wrap format of header files in [include](/include/) to Windows from UNIX,

## Dependency
+ [ncnn](https://github.com/Tencent/ncnn)

## Reference
The sample english.wav obtained from [python_speech_features](https://github.com/jameslyons/python_speech_features).
