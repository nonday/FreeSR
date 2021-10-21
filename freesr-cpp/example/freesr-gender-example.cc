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
    std::cout << "Recognize Speaker Gender Example by FreeSR ..." << std::endl;
    RecInfo rec = spk.RecognizeSpeakerGender("english.wav");
    std::cout << "Recognize result: " << rec.result << " | confidence: "<< rec.confidence << std::endl;
    
    return 0;
}
