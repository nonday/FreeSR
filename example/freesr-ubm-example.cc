// gmm-ubm example for FreeSR

#include <stdio.h>

#include <iostream>
#include <vector>

#include "speaker_recognizer_gmm.h"

int main(int argc, char** argv)
{
	// smaple rate
	int sr = 8000;
	// signal data
	std::vector<double> signal;

	FILE* fp = fopen("english.pcm", "rb");
	if (NULL == fp)
	{
		return -1;
	}
	int buf;
	while (fread(&buf, sizeof(int), 1, fp) > 0)
	{
		signal.push_back(buf);
	}
	if (NULL != fp)
	{
		fclose(fp);
		fp = NULL;
	}


	SpeakerRecognizerGMM spk(sr);
	bool ret = spk.Init("freesr-ubm-model.bin");
	if (!ret)
	{
		std::cout << "Failed to init ..." << std::endl;
		return -1;
	}

	ret = spk.RegisterSpeaker(signal, "english", "english.gmm");
	if (!ret)
	{
		std::cout << "Failed to Register ..." << std::endl;
		return -1;
	}

	std::vector<std::string> fpaths = {"english.wav", "english.wav"};
	ret = spk.RegisterSpeaker(fpaths, "english_file", "english_file.gmm");
	if (!ret)
	{
		std::cout << "Failed to Register ..." << std::endl;
		return -1;
	}


	std::cout << "Recognize Speaker by raw data ..." << std::endl;
	std::string rec1 = spk.RecognizeSpeaker(signal);
	std::cout << "Recognize Result: " << rec1 << "  Score: " << spk.GetScore() << std::endl;

	std::cout << "Recognize Speaker by audio file ..." << std::endl;
	std::string rec2 = spk.RecognizeSpeaker("english.wav");
	std::cout << "Recognize Result: " << rec2 << "  Score: " << spk.GetScore() << std::endl;

	return 0;
}

