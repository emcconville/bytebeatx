/* Standard */
#include <signal.h>
/* System */
#if MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_11
#include <CoreAudio/CoreAudio.h>
#include <AudioToolbox/AudioToolbox.h>
#include <AudioUnit/AudioUnit.h>
#endif
/* Me */
#include "audio_io.h"
#include "beats.h"

OSStatus ByteBeat(void * inRefCon,
                  AudioUnitRenderActionFlags * ioActionFlags,
                  const AudioTimeStamp * inTimeStamp,
                  UInt32 inBusNumber,
                  UInt32 inNumberFrames,
                  AudioBufferList * ioData)
{
    sound_format_t * sound = (sound_format_t *)inRefCon;
    Float32 * outputBuffer = (Float32 *)ioData->mBuffers[0].mData;
    register int32_t t = sound->cursor;
    for(int i = 0; i < inNumberFrames; i++) {
        outputBuffer[i] = sound->cb(t);
        t++;
    }
    sound->cursor = t;
    for(int i = 1; i < ioData->mNumberBuffers; i++) {
        memcpy(ioData->mBuffers[i].mData,
               outputBuffer,
               ioData->mBuffers[i].mDataByteSize);
    }
    
    return noErr;
}

void audio_startup(AudioUnit * unit, session_t * session)
{
    OSStatus ok;
    AudioComponentDescription outputUnitDescription = {
        .componentType         = kAudioUnitType_Output,
        .componentSubType      = kAudioUnitSubType_DefaultOutput,
        .componentManufacturer = kAudioUnitManufacturer_Apple
    };
    AudioComponent outputComponent = AudioComponentFindNext(NULL, &outputUnitDescription);
    AudioComponentInstanceNew(outputComponent, unit);
    AudioUnitInitialize(*unit);
    
    
    AudioStreamBasicDescription ASBD = {
        .mSampleRate       = session->sound.sampleRate,
        .mFormatID         = kAudioFormatLinearPCM,
        .mFormatFlags      = kAudioFormatFlagsNativeFloatPacked,
        .mChannelsPerFrame = 1,
        .mFramesPerPacket  = 1,
        .mBitsPerChannel   = sizeof(Float32) * 8,
        .mBytesPerPacket   = sizeof(Float32),
        .mBytesPerFrame    = sizeof(Float32)
    };
    
    ok = AudioUnitSetProperty(*unit,
                              kAudioUnitProperty_StreamFormat,
                              kAudioUnitScope_Input,
                              0,
                              &ASBD,
                              sizeof(ASBD));
    if ( ok != noErr ) {
        fprintf(stderr, "Unable to assign Audio Stream Description propery.\n");
        raise(SIGABRT);
    }
    AURenderCallbackStruct callbackInfo = {
        .inputProc       = ByteBeat,
        .inputProcRefCon = &(session->sound),
    };
    
    ok = AudioUnitSetProperty(*unit,
                              kAudioUnitProperty_SetRenderCallback,
                              kAudioUnitScope_Global,
                              0,
                              &callbackInfo,
                              sizeof(callbackInfo));
    if ( ok != noErr ) {
        fprintf(stderr, "Unable to assign Program Callback propery.\n");
        raise(SIGABRT);
    }
    ok = AudioOutputUnitStart(*unit);
    if ( ok != noErr ) {
        fprintf(stderr, "Could not start audio output!\n");
        raise(SIGABRT);
    }
}

void audio_teardown(AudioUnit * unit)
{
    AudioOutputUnitStop(*unit);
    AudioUnitUninitialize(*unit);
    AudioComponentInstanceDispose(*unit);
}