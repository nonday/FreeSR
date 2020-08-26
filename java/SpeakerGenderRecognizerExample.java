// Example for FreeSR

import com.freesr.*;

public class SpeakerGenderRecognizerExample{

	static {
		System.loadLibrary("freesr");
	}

	public static void main(String[] args){
		
		System.out.println("Example for FreeSR\nEnjoy It!");

		SpeakerGenderRecognizer spk = new SpeakerGenderRecognizer(8000);
		
		boolean ret = spk.Init();
		if(ret)
		{
			String rec = spk.RecognizeSpeakerGender("english.wav");
			
			System.out.println("Recognize result:" + rec + " | confidence:" + spk.GetConfidence());
		}
	}
}
