# FreeSR: A Free Library for Speaker Recognition
This is a free library for ivector-based Speaker Recognition (Verification), which is completely implemented in C/C++. Simultaneously, you can extract speech features by FreeSR such as mfcc, fbank etc. More detailed information can be referred to [python_speech_features](https://github.com/jameslyons/python_speech_features). Most of implementations are similar between them, only in different language.


## Usage
```
mkdir build; cd build; cmake ..
```
The input is preferably raw data without normalization from wav (bitspersample 16bits and sample rate 16K).
More detailed information about usage of FreeSR can be referred to [speaker_recognizer.h](/include/speaker_recognizer.h)

[Example](/example/freesr-example.cc)

## Notes
Now Only Supported in Windows. It is compiled by VS2013.

## TODO
+ GMM-UBM
+ Android

## Dependency
+ [Eigen3](http://eigen.tuxfamily.org/index.php?title=Main_Page)


## Reference
The sample english.wav obtained from [python_speech_features](https://github.com/jameslyons/python_speech_features).
The english.pcm is raw data from english.wav
