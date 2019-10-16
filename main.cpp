#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include "inputReader.hpp"

#define FINAL_IMAGE_HEIGHT 1000
#define FINAL_IMAGE_WIDTH 1900

//775 - 1707

using namespace std;
using namespace cv;

void loadAndPlaceFragment(InputEntry imgInfo,Mat &background);


int main(int argc, char** argv){

	//CREATE MAIN IMAGE
	Mat grHistogram(FINAL_IMAGE_HEIGHT,FINAL_IMAGE_WIDTH, CV_8UC4, Scalar(0, 0, 0, 0));
	//Mat grHistogram = imread("./Michelangelo_ThecreationofAdam_1707x775.jpg", CV_LOAD_IMAGE_GRAYSCALE );

	Mat fragment = imread("./frag_eroded/frag_eroded_2.png");

	//Image can't be open
	if(! fragment.data ){
		cout <<  "Could not open or find the fragment image." << std::endl ;
		return -1;
	}


	else{



		//fragment.copyTo(grHistogram(Rect(640, 575, fragment.cols, fragment.rows)));
		std::vector<InputEntry> entries = getEntriesFromFile("fragments.txt");
		   for(int i = 0; i < entries.size(); ++i){
			   //cout << entries[i] << endl;
			   loadAndPlaceFragment(entries[i],grHistogram);
			   /*imshow( "Display window", grHistogram );
			   waitKey(0);*/
		   }

	}

	//imshow( "Display window", grHistogram );
	imwrite( "test.png", grHistogram );


	waitKey(0);

	return 0;
}

Mat rotateFragment(Mat const &imageSource,double angle){
	Point2f scr_center(imageSource.cols/2.0F,imageSource.rows/2.0F);
	Mat rot_mat = getRotationMatrix2D(scr_center,angle,1.0);
	Mat dst;
	warpAffine(imageSource,dst,rot_mat,imageSource.size());
	cvtColor(dst, dst, CV_BGR2BGRA);
	return dst;
}


void loadAndPlaceFragment(InputEntry imgInfo,Mat &background){
	cout << "[BACKGROUND SIZE] ~ " << background.cols << " - " << background.rows << "\n";
	//Get the right fragment image
	string path = "./frag_eroded/frag_eroded_" + to_string(imgInfo.fragmentId) + ".png";
	Mat fragment = imread(path,IMREAD_UNCHANGED);


	cout << endl << imgInfo << endl;

	//rotate
	Mat fragmentRotated = rotateFragment(fragment,imgInfo.rotation);
	cout << "Rotation ok \n";


	//translate
	Mat mask;
	vector<Mat> rgb;

	if(fragmentRotated.channels() == 4 ){
		split(fragmentRotated,rgb);
		mask = rgb[3];
		fragmentRotated.copyTo(background(Rect(imgInfo.x - fragmentRotated.cols / 2.0F + 100 ,imgInfo.y - fragmentRotated.rows / 2.0F + 100, fragmentRotated.cols, fragmentRotated.rows)),mask);
	}


	cout << "Placement ok \n";
}
