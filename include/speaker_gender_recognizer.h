// Copyright (C) 2020, Xulg. All rights reserved.
// 
// xulg <xulg.ai@qq.com>
//

#ifndef SPEAKER_GENDER_RECOGNIZER_H_
#define SPEAKER_GENDER_RECOGNIZER_H_

#if defined(_MSC_VER)
//#define FREESR_EXPORT 1
#ifdef FREESR_EXPORT
#define FREESR_API __declspec(dllexport)  
#else
#define FREESR_API __declspec(dllimport)  
#endif
#else
#define FREESR_API
#endif

#include <string>
#include <vector>

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
    // 初始化
    // return：成功返回true,否则返回false
    bool Init();

	// 识别说话人性别
	// signal：PCM信号数据
	// return：female/male/""
	std::string RecognizeSpeakerGender(std::vector<double> signal);
	
	// 识别说话人性别
	// fpath：wav文件路径
	// return：female/male/""
	std::string RecognizeSpeakerGender(std::string fpath);

	// 获得最近一次的置信分数，[-1,1]
	double GetConfidence();	

private:
    // latest confidence
	double confidence_; 
    // initialization
	bool init_;
};

#endif // SPEAKER_GENDER_RECOGNIZER_H_
