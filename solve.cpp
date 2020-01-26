#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <map>
using namespace cv;
using namespace std;


std::vector< DMatch > getMatchingPossibility(Mat p_obj,Mat p_scene);
void showMatches(Mat img_object,std::vector<KeyPoint> keypoints_object,Mat img_scene,std::vector<KeyPoint> keypoints_scene,	std::vector< DMatch > good_matches);

int main(int argc, char** argv)
{
    Mat img_scene = imread("Michelangelo_ThecreationofAdam_1707x775.jpg", CV_LOAD_IMAGE_GRAYSCALE);

    if (!img_scene.data){std::cout << " --(!) Error reading images " << std::endl; return -1;}

	std::map<std::string, DMatch> mapMatch;

	for(int i = 0; i < 327 ; ++i){

		string path = "frag_eroded/frag_eroded_"+to_string(i)+".png";
		Mat this_img = imread(path, CV_LOAD_IMAGE_GRAYSCALE);
		std::vector< DMatch > this_match = getMatchingPossibility(this_img,img_scene);

		if(this_match.size() > 0){
			cout << "[MATCH] ~ " << to_string(this_match.size()) << " for " << path << endl;

			if(this_match.size() == 1 ){ //save proposition in list
				mapMatch[path] = this_match[0];
			}
			else{

			}
		}

	}
    return 0;
}


std::vector< DMatch > getMatchingPossibility(Mat p_obj,Mat p_scene){
	Mat img_object = p_obj;
	Mat img_scene = p_scene;

	if (!img_object.data || !img_scene.data)
	{
		std::vector< DMatch > empty;
		std::cout << " --(!) Error reading images " << std::endl; return empty;
	}

	//-- Step 1: Detect the keypoints using SURF Detector
	Ptr<FeatureDetector> detector = ORB::create();

	std::vector<KeyPoint> keypoints_object, keypoints_scene;

	detector->detect(img_object, keypoints_object);
	detector->detect(img_scene, keypoints_scene);

	//-- Step 2: Calculate descriptors (feature vectors)
	Ptr<DescriptorExtractor> extractor = ORB::create();

	Mat descriptors_object, descriptors_scene;

	extractor->compute(img_object, keypoints_object, descriptors_object);
	extractor->compute(img_scene, keypoints_scene, descriptors_scene);

	//-- Step 3: Matching descriptor vectors using FLANN matcher
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce");
	std::vector< DMatch > matches;
	matcher->match(descriptors_object, descriptors_scene, matches);

	double max_dist = 0; double min_dist = 150;

	//-- Quick calculation of max and min distances between keypoints
	for (int i = 0; i < descriptors_object.rows; i++)
	{
		double dist = matches[i].distance;
		if (dist < min_dist) min_dist = dist;
		if (dist > max_dist) max_dist = dist;
	}

	//-- Draw only "good" matches (i.e. whose distance is less than 3*min_dist )
	std::vector< DMatch > good_matches;

	for (int i = 0; i < descriptors_object.rows; i++)
	{
		if (matches[i].distance < 3 * min_dist)
		{
			good_matches.push_back(matches[i]);
		}
	}

	// if(good_matches.size() > 0 )
	// 	showMatches(img_object,keypoints_object,img_scene,keypoints_scene,good_matches);
	return good_matches;
}


void showMatches(
	Mat img_object,std::vector<KeyPoint> keypoints_object,
	Mat img_scene,std::vector<KeyPoint> keypoints_scene,
	std::vector< DMatch > good_matches){
	    Mat img_matches;

	    drawMatches(img_object, keypoints_object, img_scene, keypoints_scene, good_matches, img_matches, Scalar::all(-1), Scalar::all(-1), std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

	    //-- Localize the object
	    std::vector<Point2f> obj;
	    std::vector<Point2f> scene;

	    for (int i = 0; i < good_matches.size(); i++)
	    {
	        //-- Get the keypoints from the good matches
	        obj.push_back(keypoints_object[good_matches[i].queryIdx].pt);
	        scene.push_back(keypoints_scene[good_matches[i].trainIdx].pt);
	    }

	    Mat H = findHomography(obj, scene, CV_RANSAC);

	    //-- Get the corners from the image_1 ( the object to be "detected" )
	    std::vector<Point2f> obj_corners(4);
	    obj_corners[0] = cvPoint(0, 0); obj_corners[1] = cvPoint(img_object.cols, 0);
	    obj_corners[2] = cvPoint(img_object.cols, img_object.rows); obj_corners[3] = cvPoint(0, img_object.rows);
	    std::vector<Point2f> scene_corners(4);

	    if(!H.empty()) {
	        perspectiveTransform(obj_corners, scene_corners, H);
	        //-- Draw lines between the corners (the mapped object in the scene - image_2 )
	        line(img_matches, scene_corners[0] + Point2f(img_object.cols, 0), scene_corners[1] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
	        line(img_matches, scene_corners[1] + Point2f(img_object.cols, 0), scene_corners[2] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
	        line(img_matches, scene_corners[2] + Point2f(img_object.cols, 0), scene_corners[3] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
	        line(img_matches, scene_corners[3] + Point2f(img_object.cols, 0), scene_corners[0] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);

	    }


	    //-- Show detected matches
	    imshow("Good Matches & Object detection", img_matches);
		waitKey(0);
}
