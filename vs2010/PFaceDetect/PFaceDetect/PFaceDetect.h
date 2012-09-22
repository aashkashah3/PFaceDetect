#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

#include "pFaceDetect_PFaceDetect.h"

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
