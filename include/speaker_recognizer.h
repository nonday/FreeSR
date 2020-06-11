//
// Copyright (C) 2019-2020, Xulg. All rights reserved.
// 
// xulg <xulg.ai@qq.com>
// 

#ifndef SPEAKER_RECOGNIZER_H_
#define SPEAKER_RECOGNIZER_H_

#if defined(_MSC_VER)
//	#define FREESR_EXPORT 1
	#ifdef FREESR_EXPORT
		#define DLL_API __declspec(dllexport)  
	#else
		#define DLL_API __declspec(dllimport)  
	#endif
	
#else
	#define DLL_API
#endif

#include <string>
#include <vector>

#include <Eigen/Core>

#include "speech_features.h"


class DLL_API SpeakerRecognizer
{
public:
	SpeakerRecognizer(int sample_rate = 16000);

public:
	virtual ~SpeakerRecognizer();

private:
	SpeakerRecognizer(const SpeakerRecognizer &);
	SpeakerRecognizer & operator=(const SpeakerRecognizer &);


protected:
	// number of non silence frames
	int num_non_sil_frames_;
	// sample rate
	int sample_rate_;
	// speech feature
	SpeechFeatures *speech_feat_;
	// initialization
	bool init_;
	// latest score of similarity
	double score_;
	// speakers registered
	std::vector<std::string> reg_speakers_;

protected:
	// 提取语音特征 TODO...
	// signal：PCM data，非归一化数据
	// vad_model: 不同的vad处理方式，0/1/2
	// return：mfcc特征，ndim x nframes
	Eigen::MatrixXd ExtractSpeechFeat(std::vector<double> signal, int vad_model = 0);

	// 读取音频文件，单通道，16K
	// fpath：音频文件路径
	// return：音频文件的raw data
	std::vector<double> ReadAudioFile(std::string fpath);


public:
	// 获取已注册speaker名称
	std::vector<std::string> GetRegSpeakers();
	// 获取已注册人数
	int GetCountSpeakers();
	// 获得最近一次的最相似度分数
	double GetScore();	

public:
	// 初始化
	// model：模型路径
	// speaker_names：说话人模型对应的注册名称，顺序对应speaker_models
	// speaker_models：说话人模型存放的路径
	// return：成功返回true,否则返回false
	virtual bool Init(std::string model, std::vector<std::string> speaker_names = std::vector<std::string>(), std::vector<std::string> speaker_models = std::vector<std::string>()) = 0;
	
	// 注册说话人
	// signal：PCM data，非归一化数据
	// speaker_name：注册名称
	// speaker_model：模型保存路径，为空则不保存到文件，仅注册到内存
	// return：成功返回true,否则返回false
	virtual bool RegisterSpeaker(std::vector<double> signal, std::string speaker_name, std::string speaker_model = "") = 0;

	// 识别说话人
	// signal：PCM信号数据，非归一化数据
	// threshold：陌生人阈值
	// return：根据threshold，返回空或者识别结果
	virtual std::string RecognizeSpeaker(std::vector<double> signal, double threshold = -99999.0) = 0;

	// 加载说话人模型到内存，返回添加成功的数量
	// speaker_names：模型对应的注册名称，顺序对应speaker_models
	// speaker_models：模型路径
	// return：返回成功加载的模型数量
	virtual int LoadModels(std::vector<std::string> speaker_names = std::vector<std::string>(), std::vector<std::string> speaker_models = std::vector<std::string>()) = 0;

	// 根据注册名称从内存中移除注册模型
	// speaker_name：注册名称
	// return：成功返回true,否则返回false
	virtual bool RemoveSpeakerByName(std::string speaker_name) = 0;
	
	// 根据索引从内存中移除注册模型
	// index：注册模型的索引编号，从0开始
	// return：成功返回true,否则返回false
	virtual bool RemoveSpeakerByIndex(int index) = 0;

	// 注册说话人
	// fpaths：多个wav文件路径
	// speaker_name：注册名称
	// speaker_model：模型保存路径，为空则不保存到文件，仅注册到内存
	// return：成功返回true,否则返回false
	virtual bool RegisterSpeaker(std::vector<std::string> fpaths, std::string speaker_name, std::string speaker_model = "") = 0;

	// 识别说话人
	// fpath：wav文件路径
	// threshold：陌生人阈值
	// return：根据threshold，返回空或者识别结果
	virtual std::string RecognizeSpeaker(std::string fpath, double threshold = -99999.0) = 0;


};

#endif // SPEAKER_RECOGNIZER_H_
