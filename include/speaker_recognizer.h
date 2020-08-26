// Copyright (C) 2020, Xulg. All rights reserved.
// 
// xulg <xulg.ai@qq.com>
//

#ifndef SPEAKER_RECOGNIZER_H_
#define SPEAKER_RECOGNIZER_H_

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
    // 初始化
    // return：成功返回true,否则返回false
    bool Init();

    // 说话人验证
    // signal_1：PCM信号数据
    // signal_2：PCM信号数据
    // return：相似度，[-1,1]
    double VerifySpeaker(std::vector<double> signal_1, std::vector<double> signal_2);

    // 说话人验证
    // fpath_1：wav文件路径
    // fpath_2：wav文件路径
    // return：相似度，[-1,1]
    double VerifySpeaker(std::string fpath_1, std::string fpath_2);

	// 说话人注册
	// signal：PCM data，非归一化数据
	// speaker_name：注册名称
	// speaker_model：模型保存路径，为空则不保存到文件，仅注册到内存
	// return：成功返回true,否则返回false
	bool RegisterSpeaker(std::vector<double> signal, std::string speaker_name, std::string speaker_model = "");

    // 说话人注册
    // fpath：wav文件路径
    // speaker_name：注册名称
	// speaker_model：模型保存路径，为空则不保存到文件，仅注册到内存
	// return：成功返回true,否则返回false
    bool RegisterSpeaker(std::string fpath, std::string speaker_name, std::string speaker_model = "");

    // 说话人识别
    // signal：PCM信号数据，非归一化数据
    // threshold：陌生人阈值
    // return：根据threshold，返回空或者识别结果
    std::string RecognizeSpeaker(std::vector<double> signal);

    // 说话人识别
    // fpath：wav文件路径
    // return：返回空或者识别结果
    std::string RecognizeSpeaker(std::string fpath);

    // 获得最近一次的置信分数，[-1,1]
    double GetConfidence();	

private:
    // embedding data
    float* data_;
    // embedding size
    int ndim_;
    // speaker number
    int nspeaker_;
    // registered speakers
    std::vector<std::string> reg_speakers_;

    // latest confidence
    double confidence_; 
    // initialization
    bool init_;
};

#endif // SPEAKER_RECOGNIZER_H_
