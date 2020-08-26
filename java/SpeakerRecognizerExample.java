// Example for FreeSR

import com.freesr.*;

public class SpeakerRecognizerExample{

	static {
		System.loadLibrary("freesr");
	}

	public static void main(String[] args){
		
		System.out.println("Example for FreeSR\nEnjoy It!");

		SpeakerRecognizer spk = new SpeakerRecognizer(16000);
		
		boolean ret = spk.Init();
		if(ret)
		{
			double confidence = spk.VerifySpeaker("english.wav", "english.wav");

			System.out.println("Verify confidence:" + confidence);
		}
	}
}
