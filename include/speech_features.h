// 
// Copyright (C) 2019-2020, Xulg. All rights reserved.
// 
// xulg <xulg.ai@qq.com>
//

#ifndef SPEECH_FEATURES_H_
#define SPEECH_FEATURES_H_

#include <vector>
#include <Eigen/Dense>

#define M_PI 3.14159265358979323846  /* pi */
#define EPS 0.000000000001

class SpeechFeatures
{
public:
	
	SpeechFeatures(int sample_rate = 16000, 
					float win_len = 0.025, float win_step = 0.01, 
					int nfilt = 26, int nfft = 512,
					float pre_emphasis_coef = 0.97, 
					int cep_lifter = 22, int num_cep=13,
					int win_type = -1);
	
	~SpeechFeatures();

private:
	SpeechFeatures(const SpeechFeatures &);
	SpeechFeatures & operator=(const SpeechFeatures &);


public:

	// Compute MFCC features from an audio signal
	Eigen::MatrixXd Mfcc(std::vector<double> signal, bool add_energy=true);

	// Compute Mel-filterbank energy features from an audio signal
	Eigen::MatrixXd Fbank(std::vector<double> signal);

	// Compute log Mel - filterbank energy features from an audio signal
	Eigen::MatrixXd LogFbank(std::vector<double> signal);

	// Compute delta features from a feature vector sequence
	// feat: nframes x ndim
	Eigen::MatrixXd Delta(Eigen::MatrixXd feat,int N);

	// Voice Activity Detection
	// 返回vad后非静音的signal
	std::vector<double> VadSignal(std::vector<double> signal, double energy_threshold = 1000,
		double energy_mean_scale = 0.2,
		int frames_context = 5,
		double proportion_threshold = 0.8);

	// Voice Activity Detection
	// 返回vad后非静音帧的index
	std::vector<int> VadIndex(std::vector<double> signal, double energy_threshold = 1000,
		double energy_mean_scale = 0.2,
		int frames_context = 5,
		double proportion_threshold = 0.8);

private:

	// convert a value in Hertz to Mels.
	double Hz2mel(double hz);
	// convert a value in Mels to Hertz.
	double Mel2hz(double mel);

	// get a window function such as the Hamming window.
	Eigen::MatrixXd GetWinFun(int n, int type = -1);

	// apply a cepstral lifter the the matrix of cepstra
	Eigen::MatrixXd Lifter(Eigen::MatrixXd cepstra, int cep_lifter=22);

private:

	// the sample rate of signal, default is 16k.
	int sample_rate_;
	
	// apply preemphasis filter with preemph as coefficient. 0 is no filter, default is 0.97.
	float pre_emphasis_coef_;
	
	// the length of the analysis window in seconds, default is 0.025s.
	float win_len_;
	
	// the step between successive windows in seconds, default is 0.01s.
	float win_step_;

	// the number of filters in the filterbank,default 26.
	int nfilt_;

	// the FFT size,default is 512.
	int nfft_;

	// apply a lifter to final cepstral coefficients. 0 is no lifter, default is 22.
	int cep_lifter_;
	// the number of cepstrum to return, default 13
	int num_cep_;

	// apply a window function such as the Hamming window to each frame.
	int window_funciton_type_;

	
	Eigen::MatrixXd fbank_;
	Eigen::VectorXd energy_;

};

#endif // SPEECH_FEATURES_H_

