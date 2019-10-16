#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>

#define FINAL_IMAGE_HEIGHT 775
#define FINAL_IMAGE_WIDTH 1707

using namespace std;
using namespace cv;

int main(int argc, char** argv){

	//CREATE MAIN IMAGE
	Mat grHistogram(FINAL_IMAGE_HEIGHT,FINAL_IMAGE_WIDTH, CV_8UC3, Scalar(0, 0, 0));

	Mat fragment = imread("./frag_eroded/frag_eroded_2.png");

	//Image can't be open
	if(! fragment.data ){
		cout <<  "Could not open or find the fragment image." << std::endl ;
		return -1;
	}

	//Image is open -> 575 640 -54.0116
	else{
		fragment.copyTo(grHistogram);
	}

	imshow( "Display window", grHistogram );
	waitKey(0);

	return 0;
}
