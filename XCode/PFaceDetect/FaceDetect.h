//
//  FaceDetect.h
//  PFaceDetect
//
//  Created by Bryan Chung on 21/9/12.
//  Copyright (c) 2012 Bryan Chung. All rights reserved.
//
#pragma once

#ifndef __PFaceDetect__FaceDetect__
#define __PFaceDetect__FaceDetect__

#include <iostream>
#include <jni.h>
#include "pFaceDetect_PFaceDetect.h"
#include <opencv2/opencv.hpp>

class CFaceDetect
{
private:
    CvHaarClassifierCascade *pCascade;
    CvMemStorage            *pStorage;
    int                     capW;
    int                     capH;
    
public:
    CvSeq                   *pFaces;
    double                  scale;
    
    CFaceDetect(void);
    ~CFaceDetect(void);
    void init(const char*, int, int);
    void check(int*);
    
};

#endif /* defined(__PFaceDetect__FaceDetect__) */
