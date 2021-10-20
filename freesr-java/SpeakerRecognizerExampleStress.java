// Example for FreeSR

import com.freesr.*;

public class SpeakerRecognizerExampleStress{

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
		
		int n = 500;
		for(int i=0; i<n; i++)
		{
			ret = spk.RegisterSpeaker("BAC009S0002W0122.wav","S0002-"+i);
			if(!ret)
			{
				System.out.println("Failed to register ...");
				return ;
			}

			ret = spk.RegisterSpeaker("BAC009S0003W0121.wav","S0003-"+i);
			if(!ret)
			{
				System.out.println("Failed to register ...");
				return ;
			}
		}

		System.out.println("Register Speaker Total: "+spk.GetRegisterSpeakerCount());

		long startTime = System.nanoTime();
		RecInfo rec = spk.RecognizeSpeaker("BAC009S0002W0123.wav");
		long endTime = System.nanoTime();

		long duration = (endTime - startTime);  //divide by 1000000 to get milliseconds.
		double ms = duration/1000000.0;
		
		System.out.println("Recognize result:" + rec.getResult() + " | confidence:" + rec.getConfidence() + " | Cost Time(ms):" +ms);
	}
}
