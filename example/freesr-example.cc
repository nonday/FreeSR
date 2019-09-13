// Example for FreeSR

#include <stdio.h>

#include <iostream>
#include <vector>

#include "speaker_recognizer.h"

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

	SpeakerRecognizer spk(sr);
	bool ret = spk.Init("freesr-model.bin");
	if (!ret)
	{
		std::cout << "Failed to Init ..." << std::endl;
		return -1;
	}
		

	ret = spk.RegisterSpeaker(signal, "english", "english.model");

	std::string rec = spk.RecognizeSpeaker(signal);
	std::cout << "Recognize Result: " << rec << "  Score: " << spk.GetScore();

	return 0;
}

