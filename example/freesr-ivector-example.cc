// Example for FreeSR

#include <stdio.h>

#include <iostream>
#include <vector>

#include "speaker_recognizer_ivector.h"

int main(int argc, char** argv)
{

	// smaple rate
	int sr = 8000;
	// raw data
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
	std::cout << "Signal length: "<< signal.size() << std::endl;

	SpeakerRecognizerIVector spk(sr);	
	bool ret = spk.Init("freesr-ivector-model.bin");
	if (!ret)
	{
		std::cout << "Failed to Init ..." << std::endl;
		return -1;
	}
		
	// 1.Raw data
	ret = spk.RegisterSpeaker(signal, "english", "english.model");
	if (!ret)
	{
		std::cout << "Failed to Register ..." << std::endl;
		return -1;
	}
	std::string rec = spk.RecognizeSpeaker(signal);
	std::cout << "Recognize Result: " << rec << "  Score: " << spk.GetScore()<< std::endl;;

	// remove
	std::cout << "Rgistered Speaker total["<< spk.GetCountSpeakers() << "] ..." << std::endl;
	if(spk.RemoveSpeakerByIndex(0))
	{
		std::cout << "Remove speaker id["<< 0 << "] ..." << std::endl;
	}
	std::cout << "Rgistered Speaker total["<< spk.GetCountSpeakers() << "] ..." << std::endl;
	
	
	// 2.Audio file
	std::vector<std::string> fpaths = {"english.wav"};
	ret = spk.RegisterSpeaker(fpaths, "english", "english.model");
	if (!ret)
	{
		std::cout << "Failed to Register ..." << std::endl;
		return -1;
	}
	rec = spk.RecognizeSpeaker("english.wav");
	std::cout << "Recognize Result: " << rec << "  Score: " << spk.GetScore() << std::endl;;

	std::cout << "Rgistered Speaker total["<< spk.GetCountSpeakers() << "] ..." << std::endl;

	return 0;
}

