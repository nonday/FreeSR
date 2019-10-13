// Example for FreeSR

#include <stdio.h>

#include <iostream>
#include <vector>

#include "speaker_recognizer_gmm.h"

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

	SpeakerRecognizerGMM spk(sr);	
	bool ret = spk.Init("freesr-ubm-model.bin",{"female","male"},{"female.model","male.model"});
	if (!ret)
	{
		std::cout << "Failed to Init ..." << std::endl;
		return -1;
	}
	
	std::cout << "Rgistered model total["<< spk.GetCountSpeakers() << "] ..." << std::endl;
	
	// 1.Raw data
	std::string rec = spk.RecognizeSpeaker(signal);
	std::cout << "Recognize Result: " << rec << "  Score: " << spk.GetScore()<< std::endl;;

	// 2.Audio file
	rec = spk.RecognizeSpeaker("english.wav");
	std::cout << "Recognize Result: " << rec << "  Score: " << spk.GetScore() << std::endl;;

	return 0;
}

