// Speaker recognition example for FreeSR

#include "speaker_recognizer.h"

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
	SpeakerRecognizer spk(16000);

    bool ret = spk.Init();
	if(!ret)
	{
		std::cout << "Failed to init ..." << std::endl;
		return -1;
	}

    std::cout << "Recognize speaker by FreeSR ..." << std::endl;

	double confidence = spk.VerifySpeaker("BAC009S0002W0123.wav", "BAC009S0002W0122.wav");
    std::cout << "Verify similarity: " << confidence << std::endl;

    ret = spk.RegisterSpeaker("BAC009S0002W0122.wav","S0002");
    if(!ret)
    {
        std::cout << "Failed to register ..." << std::endl;
		return -1;
    }
    ret = spk.RegisterSpeaker("BAC009S0003W0121.wav","S0003");
    if(!ret)
    {
        std::cout << "Failed to register ..." << std::endl;
		return -1;
    }

    std::string rec = spk.RecognizeSpeaker("BAC009S0002W0123.wav");
	std::cout << "BAC009S0002W0123 Recognize result: " << rec << "  confidence: " << spk.GetConfidence() << std::endl;
    
    rec = spk.RecognizeSpeaker("BAC009S0003W0122.wav");
	std::cout << "BAC009S0003W0122 Recognize result: " << rec << "  confidence: " << spk.GetConfidence() << std::endl;
    
	return 0;
}
