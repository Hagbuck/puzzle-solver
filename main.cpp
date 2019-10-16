#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>

#include "inputReader.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv){

    std::vector<InputEntry> entries = getEntriesFromFile("fragments.txt");
    for(int i = 0; i < entries.size(); ++i){
        cout << entries[i] << endl;
    }

    Mat imageIn = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
    
    if(! imageIn.data )                              // Check for invalid input
        {
            cout <<  "Could not open or find the image" << std::endl ;
            return -1;
    }   
                
    imshow( "Display window", imageIn );             
    waitKey(0);         
    
    return 0;
}


