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
		if(!ret)
		{
			System.out.println("Failed to init ...");
			return ;
		}
		
		double confidence = spk.Compare("BAC009S0002W0123.wav", "BAC009S0002W0122.wav");;
		System.out.println("Compare similarity: " + confidence);

		ret = spk.RegisterSpeaker("BAC009S0002W0122.wav", "S0002");
		if(!ret)
		{
			System.out.println("Failed to register ...");
			return ;
		}

		ret = spk.RegisterSpeaker("BAC009S0003W0121.wav", "S0003");
		if(!ret)
		{
			System.out.println("Failed to register ...");
			return ;
		}

		System.out.println("Register Speaker Total: "+spk.GetRegisterSpeakerCount());

		RecInfo rec = spk.RecognizeSpeaker("BAC009S0002W0123.wav");
		System.out.println("Recognize result:" + rec.getResult() + " | confidence:" + rec.getConfidence());
		
		rec = spk.RecognizeSpeaker("BAC009S0003W0122.wav");
		System.out.println("Recognize result:" + rec.getResult() + " | confidence:" + rec.getConfidence());
		
		confidence = spk.VerifySpeaker("BAC009S0003W0122.wav", "S0003");
		System.out.println("BAC009S0003W0122.wav on S0003, Verify confidence:" + confidence);
		
		confidence = spk.VerifySpeaker("BAC009S0003W0122.wav", "S0002");
		System.out.println("BAC009S0003W0122.wav on S0002, Verify confidence:" + confidence);
	}
}
