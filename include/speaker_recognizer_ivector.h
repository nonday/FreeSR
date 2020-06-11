// 
// Copyright (C) 2019, Xulg. All rights reserved.
// 
// xulg <xulg.ai@qq.com>
//

#ifndef SPEAKER_RECOGNIZER_IVECTOR_H_
#define SPEAKER_RECOGNIZER_IVECTOR_H_


#include <string>
#include <vector>

#include <Eigen/Core>

#include "speaker_recognizer.h"
#include "common.h"

class DLL_API SpeakerRecognizerIVector: public SpeakerRecognizer
{
public:
	SpeakerRecognizerIVector(int sample_rate = 16000);

public:
	virtual ~SpeakerRecognizerIVector();

private:
	SpeakerRecognizerIVector(const SpeakerRecognizerIVector &);
	SpeakerRecognizerIVector & operator=(const SpeakerRecognizerIVector &);


public:
	// 初始化
	// model：模型路径
	// speaker_names：说话人模型对应的注册名称，顺序对应speaker_models
	// speaker_models：说话人模型存放的路径
	// return：成功返回true,否则返回false
	virtual bool Init(std::string model, std::vector<std::string> speaker_names = std::vector<std::string>(), std::vector<std::string> speaker_models = std::vector<std::string>());
	
	// 注册说话人
	// signal：PCM data，非归一化数据
	// speaker_name：注册名称
	// speaker_model：模型保存路径，为空则不保存到文件，仅注册到内存
	// return：成功返回true,否则返回false
	virtual bool RegisterSpeaker(std::vector<double> signal, std::string speaker_name, std::string speaker_model = "");

	// 识别说话人
	// signal：PCM信号数据
	// threshold：陌生人阈值
	// return：根据threshold，返回空或者识别结果
	virtual std::string RecognizeSpeaker(std::vector<double> signal, double threshold = -99999.0);

	// 加载说话人模型到内存，返回添加成功的数量
	// speaker_names：模型对应的注册名称，顺序对应speaker_models
	// speaker_models：模型路径
	// return：返回成功加载的模型数量
	virtual int LoadModels(std::vector<std::string> speaker_names = std::vector<std::string>(), std::vector<std::string> speaker_models = std::vector<std::string>());

	// 根据注册名称从内存中移除注册模型
	// speaker_name：注册名称
	// return：成功返回true,否则返回false
	virtual bool RemoveSpeakerByName(std::string speaker_name);
	
	// 根据索引从内存中移除注册模型
	// index：注册模型的索引编号，从0开始
	// return：成功返回true,否则返回false
	virtual bool RemoveSpeakerByIndex(int index);

	// 注册说话人
	// fpaths：多个wav文件路径
	// speaker_name：注册名称
	// speaker_model：模型保存路径，为空则不保存到文件，仅注册到内存
	// return：成功返回true,否则返回false
	virtual bool RegisterSpeaker(std::vector<std::string> fpaths, std::string speaker_name, std::string speaker_model = "");

	// 识别说话人
	// fpath：wav文件路径
	// threshold：陌生人阈值
	// return：根据threshold，返回空或者识别结果
	virtual std::string RecognizeSpeaker(std::string fpath, double threshold = -99999.0);

private:
	// 提取IVector
	Eigen::MatrixXd ExtractIVector(Eigen::MatrixXd feat);

private:

	// Init  UBM  T  V  Plda
	Gmm ubm_;
	Eigen::MatrixXd T_;
	Eigen::MatrixXd V_;
	Plda plda_;

	// 已注册的模型 MatrixX: ndim x 1
	std::vector<Eigen::MatrixXd> reg_models_;

};

#endif // SPEAKER_RECOGNIZER_IVECTOR_H_
