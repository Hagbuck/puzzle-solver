/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */
/*						~ Traitement d'image ~ 								  */
/*					Corentin TROADEC - Anthony Vuillemin					  */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */


/* INCLUDES */
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include "inputReader.hpp"

/* DEFINE & NAMESPACE */
#define FINAL_IMAGE_HEIGHT 1000
#define FINAL_IMAGE_WIDTH 1900
#define SAVED_IMAGE_PAHT "./rebuilt_image.png"

using namespace std;
using namespace cv;


/* PROTOTYPES */
void loadAndPlaceFragment(InputEntry imgInfo,Mat &background);

/* - - - - - */
/*	 MAIN    */
/* - - - - - */
int main(int argc, char** argv){

	//Create main image -> this use to paste the fragments
	Mat grHistogram(FINAL_IMAGE_HEIGHT,FINAL_IMAGE_WIDTH, CV_8UC4, Scalar(0, 0, 0, 0));
	//Mat grHistogram = imread("./Michelangelo_ThecreationofAdam_1707x775.jpg", CV_LOAD_IMAGE_GRAYSCALE );


	//Get all fragments info and place correspond image in the main
	std::vector<InputEntry> entries = getEntriesFromFile("fragments.txt");
		for(int i = 0; i < entries.size(); ++i){
			loadAndPlaceFragment(entries[i],grHistogram);
		}

	//Show image
	imshow( "Display window", grHistogram );
	waitKey(0);
	//Write image in out
	imwrite(SAVED_IMAGE_PAHT, grHistogram );

	return 0;
}

/**
* @desc Apply a rotation to an image et return the result image
* @param &imageSource Image to rotate
* @param angle Rotation value to apply
*/
Mat rotateFragment(Mat const &imageSource,double angle){
	Point2f scr_center(imageSource.cols/2.0F,imageSource.rows/2.0F);
	Mat rot_mat = getRotationMatrix2D(scr_center,angle,1.0);
	Mat dst;
	warpAffine(imageSource,dst,rot_mat,imageSource.size());
	cvtColor(dst, dst, CV_BGR2BGRA);
	return dst;
}

/**
* @desc Load an image (corresponding to informations passsed) and past it in the background.
* @param imgInfo All informations about the image to load
* @param &background Main image in wich we paste the fragment image
*/
void loadAndPlaceFragment(InputEntry imgInfo,Mat &background){
	//Get the right fragment image
	string path = "./frag_eroded/frag_eroded_" + to_string(imgInfo.fragmentId) + ".png";
	Mat fragment = imread(path,IMREAD_UNCHANGED);
	//apply rotation
	Mat fragmentRotated = rotateFragment(fragment,imgInfo.rotation);

	//translate
	Mat mask;
	vector<Mat> rgb;

	//Before paste the image, we apply a mask to get some opacity
	if(fragmentRotated.channels() == 4 ){
		split(fragmentRotated,rgb);
		mask = rgb[3];
		fragmentRotated.copyTo(background(Rect(imgInfo.x - fragmentRotated.cols / 2.0F + 100 ,imgInfo.y - fragmentRotated.rows / 2.0F + 100, fragmentRotated.cols, fragmentRotated.rows)),mask);
	}
	//Just paste if there isn't some opacity
	else{
		fragmentRotated.copyTo(background(Rect(imgInfo.x - fragmentRotated.cols / 2.0F + 100 ,imgInfo.y - fragmentRotated.rows / 2.0F + 100, fragmentRotated.cols, fragmentRotated.rows)));
	}

}
