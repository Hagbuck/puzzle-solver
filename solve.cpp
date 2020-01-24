#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>

#define DETETION_SENSIBILITY 50

using namespace std;
using namespace cv;

void loadAndPlaceFragment(int idx);

void logger(string type,string msg){
	cout << "["<< type << "] ~ " << msg << "\n";
}


int main(int argc, char** argv){

	Mat imageIn = imread( argv[1], IMREAD_UNCHANGED );


	if(! imageIn.data ){
        	cout <<  "Could not open or find the image" << std::endl ;
        	return -1;
   	}

    vector<KeyPoint> keypoints;

	Ptr<FastFeatureDetector> detector=FastFeatureDetector::create(DETETION_SENSIBILITY);
	vector<Mat> descriptor;

	detector->detect(imageIn,keypoints,Mat());
	drawKeypoints(imageIn, keypoints, imageIn);

	// string str = "Nombre de points d'intérêts : " + to_string(keypoints.size());
	// logger("INFO",str);
	// imshow( "Display window", imageIn);
	// waitKey(0);


	loadAndPlaceFragment(9);


	return 0;
}


void loadAndPlaceFragment(int idx){

	//Get the right fragment image
	string path = "./frag_eroded/frag_eroded_" + to_string(idx) + ".png";
	Mat fragment = imread(path,IMREAD_UNCHANGED);

	string str_try = "Tentative de placement de " + path;
	logger("INFO",str_try);

	//Apply alpha
	Mat fragmentAlpha = fragment;
	//translate
	Mat mask;
	vector<Mat> rgb;
	Mat test;

	logger("INFO","Application du masque alpha.");
	//Before paste the image, we apply a mask to get some opacity
	if(fragmentAlpha.channels() == 4 ){
		split(fragmentAlpha,rgb);
		mask = rgb[3];
		fragmentAlpha.copyTo(test, mask);
	}

	logger("INFO","Recherche de zones d'intérêts.");
	vector<KeyPoint> keypoints;
	Ptr<FastFeatureDetector> detector=FastFeatureDetector::create(DETETION_SENSIBILITY);
	vector<Mat> descriptor;
	detector->detect(fragmentAlpha,keypoints,Mat());

	drawKeypoints(test, keypoints, test);

	string str = "Nombre de points d'intérêts pour "+path+" : " + to_string(keypoints.size());
	logger("INFO",str);

	imshow( "Display window", test);
	waitKey(0);

}
