// Copyright (C) 2020-2021, nonday. All rights reserved.
// 
// nonday <nonday@foxmail.com>
//

#ifndef SPEAKER_RECOGNIZER_H_
#define SPEAKER_RECOGNIZER_H_

#include "common.h"

#include <string>
#include <vector>

class SpeakerRecognizerImpl;

class FREESR_API SpeakerRecognizer
{
public:
    SpeakerRecognizer(int sample_rate=16000);

public:
    ~SpeakerRecognizer();

private:
    SpeakerRecognizer(const SpeakerRecognizer &);
    SpeakerRecognizer& operator=(const SpeakerRecognizer &);

public:
    // Must be init firstly
    bool Init();

    // Compare similarity of audio data
    // signal_1: data of PCM and not normalize
    // signal_2: data of PCM and not normalize
    // return: similarity of signal_1 and signal_2, value in [0,1]
    double Compare(double signal_1[], int len_1, double signal_2[], int len_2);    
    
    // Compare similarity of audio file
    // fpath_1: file path of wav
    // fpath_2: file path of wav
    // return: similarity of fpath_1 and fpath_2, value in [0,1]
    double Compare(std::string fpath_1, std::string fpath_2);

    // Register Speaker by audio data
    // signal: PCM data without normalize
    // id: unique register id
    // model: if not empty, save model file to the path. Otherwise, don't save model file, only register to memory
    // update: when update is 0, if id not exists, register new id, else replace old model of id   
    //         when update is 1, if id not exists, register new id, else updata the model of id, average of new and old model vector of id.
    // return: true or false
    bool RegisterSpeaker(double signal[], int len, std::string id, std::string model = "", int update = 0);

    // Register Speaker by audio file
    // fpath: file path of wav
    // id: unique register id
    // model: if not empty, save model file to the path. Otherwise, don't save model file, only register to memory
    // update: when update is 0, if id not exists, register new id, else replace old model of id   
    //         when update is 1, if id not exists, register new id, else updata the model of id, average of new and old model vector of id.
    // return: true or false
    bool RegisterSpeaker(std::string fpath, std::string id, std::string model = "", int update = 0);

    // Recognize Speaker by audio data
    // signal: PCM data without normalize
    // return: Recognize result information
    RecInfo RecognizeSpeaker(double signal[], int len);

    // Recognize Speaker by audio file
    // fpath: file path of wav
    // return: Recognize result information
    RecInfo RecognizeSpeaker(std::string fpath);

    // Find index of the id
    // return: -1, or >=0
    int FindSpeakerID(std::string id);
    
    // Verify fpath or signal whether is speaker id
    // if id not exist, will return 0.0
    // return: confidence in [0,1]
    double VerifySpeaker(double signal[], int len, std::string id);
    double VerifySpeaker(std::string fpath, std::string id);

    // delete registered id only from memory
    // id: unique register id
    // return: true or false
    bool DeleteSpeaker(std::string id);

    // load speaker feat from model file
    // id: unique register id, otherwise failed to load [replace the vector of exist id]
    // model: model file of id
    // return: true or false
    bool LoadSpeaker(std::string id, std::string model);

    // Total register speaker
    int GetRegisterSpeakerCount();

private:
    SpeakerRecognizerImpl* speaker_recognizer_impl_;
};

#endif // SPEAKER_RECOGNIZER_H_
