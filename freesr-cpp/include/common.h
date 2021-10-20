// Copyright (C) 2021, nonday. All rights reserved.
// 
// nonday <nonday@foxmail.com>
//

#ifndef COMMON_H_
#define COMMON_H_

#include <string>

typedef struct RecInfo_
{
    // [0,1]
    float confidence;
    // "" or real result
    std::string result;
}RecInfo;

#if defined(_MSC_VER)
//#define FREESR_EXPORT 1
#ifdef FREESR_EXPORT
#define FREESR_API __declspec(dllexport)  
#else
#define FREESR_API __declspec(dllimport)  
#endif
#else
#define FREESR_API
#endif

#endif // COMMON_H_
