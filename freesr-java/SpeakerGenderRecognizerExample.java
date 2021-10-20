// Example for FreeSR

import com.freesr.*;

public class SpeakerGenderRecognizerExample{

	static {
		System.loadLibrary("freesr");
	}

	public static void main(String[] args){
		
		System.out.println("Example for FreeSR\nEnjoy It!");

		SpeakerGenderRecognizer spk = new SpeakerGenderRecognizer(8000);
		
		boolean init = spk.Init();
		if(init)
		{
			RecInfo rec = spk.RecognizeSpeakerGender("english.wav");
			
			System.out.println("Recognize result:" + rec.getResult() + " | confidence:" + rec.getConfidence());
		}
	}
}
