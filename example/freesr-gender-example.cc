// Speaker gender recognition example for FreeSR

#include "speaker_gender_recognizer.h"

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
    // suggest 16000
	SpeakerGenderRecognizer spk(8000);

	bool ret = spk.Init();
	if (!ret)
	{
		std::cout << "Failed to init ..." << std::endl;
		return -1;
	}
	std::cout << "Recognize speaker gender by FreeSR ..." << std::endl;
	std::string rec = spk.RecognizeSpeakerGender("english.wav");
	std::cout << "Recognize result: " << rec << "  confidence: " << spk.GetConfidence() << std::endl;
    
	return 0;
}
