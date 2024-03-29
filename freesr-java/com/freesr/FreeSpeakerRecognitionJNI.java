/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.freesr;

public class FreeSpeakerRecognitionJNI {
  public final static native void RecInfo_confidence_set(long jarg1, RecInfo jarg1_, float jarg2);
  public final static native float RecInfo_confidence_get(long jarg1, RecInfo jarg1_);
  public final static native void RecInfo_result_set(long jarg1, RecInfo jarg1_, String jarg2);
  public final static native String RecInfo_result_get(long jarg1, RecInfo jarg1_);
  public final static native long new_RecInfo();
  public final static native void delete_RecInfo(long jarg1);
  public final static native long new_SpeakerGenderRecognizer__SWIG_0(int jarg1);
  public final static native long new_SpeakerGenderRecognizer__SWIG_1();
  public final static native void delete_SpeakerGenderRecognizer(long jarg1);
  public final static native boolean SpeakerGenderRecognizer_Init(long jarg1, SpeakerGenderRecognizer jarg1_);
  public final static native long SpeakerGenderRecognizer_RecognizeSpeakerGender__SWIG_0(long jarg1, SpeakerGenderRecognizer jarg1_, double[] jarg2, int jarg3);
  public final static native long SpeakerGenderRecognizer_RecognizeSpeakerGender__SWIG_1(long jarg1, SpeakerGenderRecognizer jarg1_, String jarg2);
  public final static native long new_SpeakerRecognizer__SWIG_0(int jarg1);
  public final static native long new_SpeakerRecognizer__SWIG_1();
  public final static native void delete_SpeakerRecognizer(long jarg1);
  public final static native boolean SpeakerRecognizer_Init(long jarg1, SpeakerRecognizer jarg1_);
  public final static native double SpeakerRecognizer_Compare__SWIG_0(long jarg1, SpeakerRecognizer jarg1_, double[] jarg2, int jarg3, double[] jarg4, int jarg5);
  public final static native double SpeakerRecognizer_Compare__SWIG_1(long jarg1, SpeakerRecognizer jarg1_, String jarg2, String jarg3);
  public final static native boolean SpeakerRecognizer_RegisterSpeaker__SWIG_0(long jarg1, SpeakerRecognizer jarg1_, double[] jarg2, int jarg3, String jarg4, String jarg5, int jarg6);
  public final static native boolean SpeakerRecognizer_RegisterSpeaker__SWIG_1(long jarg1, SpeakerRecognizer jarg1_, double[] jarg2, int jarg3, String jarg4, String jarg5);
  public final static native boolean SpeakerRecognizer_RegisterSpeaker__SWIG_2(long jarg1, SpeakerRecognizer jarg1_, double[] jarg2, int jarg3, String jarg4);
  public final static native boolean SpeakerRecognizer_RegisterSpeaker__SWIG_3(long jarg1, SpeakerRecognizer jarg1_, String jarg2, String jarg3, String jarg4, int jarg5);
  public final static native boolean SpeakerRecognizer_RegisterSpeaker__SWIG_4(long jarg1, SpeakerRecognizer jarg1_, String jarg2, String jarg3, String jarg4);
  public final static native boolean SpeakerRecognizer_RegisterSpeaker__SWIG_5(long jarg1, SpeakerRecognizer jarg1_, String jarg2, String jarg3);
  public final static native long SpeakerRecognizer_RecognizeSpeaker__SWIG_0(long jarg1, SpeakerRecognizer jarg1_, double[] jarg2, int jarg3);
  public final static native long SpeakerRecognizer_RecognizeSpeaker__SWIG_1(long jarg1, SpeakerRecognizer jarg1_, String jarg2);
  public final static native int SpeakerRecognizer_FindSpeakerID(long jarg1, SpeakerRecognizer jarg1_, String jarg2);
  public final static native double SpeakerRecognizer_VerifySpeaker__SWIG_0(long jarg1, SpeakerRecognizer jarg1_, double[] jarg2, int jarg3, String jarg4);
  public final static native double SpeakerRecognizer_VerifySpeaker__SWIG_1(long jarg1, SpeakerRecognizer jarg1_, String jarg2, String jarg3);
  public final static native boolean SpeakerRecognizer_DeleteSpeaker(long jarg1, SpeakerRecognizer jarg1_, String jarg2);
  public final static native boolean SpeakerRecognizer_LoadSpeaker(long jarg1, SpeakerRecognizer jarg1_, String jarg2, String jarg3);
  public final static native int SpeakerRecognizer_GetRegisterSpeakerCount(long jarg1, SpeakerRecognizer jarg1_);
}
