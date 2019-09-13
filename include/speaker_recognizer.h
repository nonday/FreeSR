// 
// Copyright (C) 2019, Xulg. All rights reserved.
// 
// xulg <xulg.ai@qq.com>
//


#ifndef SPEAKER_RECOGNIZER_H_
#define SPEAKER_RECOGNIZER_H_

#ifdef DLL_API
	//nothing to do
#else 
	#define DLL_API __declspec(dllimport)
#endif



#include <string>
#include <vector>

#include "common.h"
#include "speech_features.h"


class DLL_API SpeakerRecognizer
{

public:
	
	SpeakerRecognizer(int sample_rate = 16000);

private:
	
	SpeakerRecognizer(const SpeakerRecognizer &);
	SpeakerRecognizer & operator=(const SpeakerRecognizer &);


public:
	
	~SpeakerRecognizer();

private:
	// 提取IVector
	Eigen::MatrixXd ExtractIVector(std::vector<double> signal);

public:
	// 初始化
	// model：model文件路径
	// reg_models_path：模型存放的路径
	// reg_speaker：模型对应的注册名称，顺序对应reg_models_path
	// return：成功返回true,否则返回false
	bool Init(std::string model, std::vector<std::string> reg_models_path = {}, std::vector<std::string> reg_speakers = {});
	
	// 注册说话人
	// signal：PCM data，非归一化数据
	// reg_speaker：注册名称
	// reg_path：模型保存路径，为空则不保存到文件，仅注册到内存
	// return：成功返回true,否则返回false
	bool RegisterSpeaker(std::vector<double> signal, std::string reg_speaker, std::string reg_path = "");

	// 识别说话人
	// signal：PCM信号数据
	// threshold：陌生人阈值
	// return：根据threshold，返回空或者识别结果
	std::string RecognizeSpeaker(std::vector<double> signal, double threshold = -99999.0);

	// 获得最近一次的最相似度
	double GetScore();



	// 添加说话人模型到内存，返回添加成功的数量
	// reg_models_path：模型路径
	// reg_speakers：模型对应的注册名称，顺序对应reg_models_path
	// return：返回成功的数量
	int AddModels(std::vector<std::string> reg_models_path = {}, std::vector<std::string> reg_speakers = {});


	// 获取已注册speaker
	std::vector<std::string> GetRegSpeakers();
	// 获取已注册人数
	int GetCountSpeakers();


	// 根据注册名称从内存中移除注册模型
	// reg_speaker：注册名称
	// return：成功返回true,否则返回false
	bool RemoveSpeakerByName(std::string reg_speaker);
	
	// 根据索引从内存中移除注册模型
	// index：注册模型的索引编号，从0开始
	// return：成功返回true,否则返回false
	bool RemoveSpeakerByIndex(int index);




	// TODO
	// 保存当前内存中的所有模型到文件
	// int SaveModels();




private:
	// 特征
	SpeechFeatures *speech_feat_;


	// 最近一次识别得分
	double score_;

	// Init  UBM  T  V  Plda
	Gmm ubm_;
	Eigen::MatrixXd T_;
	Eigen::MatrixXd  V_;
	Plda plda_;

	// 是否初始化
	bool init_;


	// 已注册的模型 MatrixX: ndim x 1
	std::vector<Eigen::MatrixXd> reg_models_;
	std::vector<std::string> reg_speakers_;

};

#endif // SPEAKER_RECOGNIZER_H_
