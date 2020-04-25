# FreeSR: A Free Library for Speaker Recognition
This is a free library for Speaker Recognition (Verification), which is completely implemented in C/C++. In addition, Speaker Gender Recognition is also implemented by GMM-UBM.

Simultaneously, you can extract speech features by FreeSR such as mfcc, fbank etc. More detailed information can be referred to [python_speech_features](https://github.com/jameslyons/python_speech_features). Most of implementations are similar between them, only in different language.

## Supported Platform

|                | Windows (win32) | Linux (X64) | Android      |
|----------------|-----------------|-------------|--------------|
|                | >=VS2013        | gcc>=4.9.4  |  --          |
|   GMM-UBM      | &#10004;        | &#10004;    |  &#10004;    |
|   i-vector     | &#10004;        | &#10004;    |  &#10004;    |
|   x-vector     | --        |--    |  --    |


## Usage
```
mkdir build; cd build; cmake ..
```
The input is preferably raw data without normalization from wav (bitspersample 16bits and sample rate 16K).
More detailed information about usage of FreeSR can be referred to [speaker_recognizer.h](/include/speaker_recognizer.h).

[Example](/example/)

## Notes
For Windows, it is compiled by VS2013/Release/32bit. The debug version can be found [here](https://share.weiyun.com/5prBEuQ).

For Android, the so library can be found [here](https://share.weiyun.com/5O9BdLP).

When use VS2013, maybe you need to change the line wrap format of header files in [include](/include/) to Windows from UNIX,


## Dependency
+ [Eigen3](http://eigen.tuxfamily.org/index.php?title=Main_Page)


## Reference
The sample english.wav obtained from [python_speech_features](https://github.com/jameslyons/python_speech_features).
The english.pcm is raw data from english.wav

