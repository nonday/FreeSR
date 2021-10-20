// Copyright (C) 2020-2021, nonday. All rights reserved.
// 
// nonday <nonday@foxmail.com>
//

#ifndef SPEAKER_GENDER_RECOGNIZER_H_
#define SPEAKER_GENDER_RECOGNIZER_H_

#include "common.h"

#include <string>
#include <vector>

class SpeakerGenderRecognizerImpl;

class FREESR_API SpeakerGenderRecognizer
{
public:
    SpeakerGenderRecognizer(int sample_rate=16000);

public:
    ~SpeakerGenderRecognizer();

private:
    SpeakerGenderRecognizer(const SpeakerGenderRecognizer &);
    SpeakerGenderRecognizer& operator=(const SpeakerGenderRecognizer &);

public:
    // Init
    bool Init();

    // Recognize Speaker Gender
    // signal: PCM data of wav and not normalize
    // return: Recognize result information, "" or female/male/nonspeech and confidence in [0,1]
    RecInfo RecognizeSpeakerGender(double signal[], int len);
    
    // Recognize Speaker Gender
    // fpath: file of wav
    // return: Recognize result information, "" or female/male/nonspeech and confidence in [0,1]
    RecInfo RecognizeSpeakerGender(std::string fpath);

private:
    SpeakerGenderRecognizerImpl* speaker_gender_recognizer_impl_;
};

#endif // SPEAKER_GENDER_RECOGNIZER_H_
