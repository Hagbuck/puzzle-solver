/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */
/*						~ Traitement d'image ~ 								  */
/*					Corentin TROADEC - Anthony Vuillemin					  */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */


/* INCLUDES */
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include "inputReader.hpp"
#include <opencv2/opencv.hpp>
#include <stdexcept>

int DELTA_X=1;
int DELTA_Y=1;
int DELTA_A=1;

using namespace std;
using namespace cv;

/* PROTOTYPES */
bool checkIfExist(map<int, InputEntry> inputs,int key);
bool evalFragment(InputEntry firstFragment,InputEntry secondFragment,int dX,int dY,int dA);
int calcArea(vector<InputEntry> listFragments);

/* - - - - - - -*/
/*     MAIN  	*/
/* - - - - - - -*/
int main(int argc, char** argv){

	//Check entry parameters
	if(argc != 4){//not good number of paramters -> default mode
		string str_error = "[WARNING] ~ Invalid arguments number. Must be 4.";
		str_error += "\n[WARNING] ~ Format is `./script_path DELTA_X DELTA_Y DELTA_A`";
		str_error += "\n[INFO] ~ Default mode enable with parameters {"+to_string(DELTA_X)+","+to_string(DELTA_Y)+","+to_string(DELTA_A)+"}";
		cout << str_error << endl;

	}
	//custom mode
	else{
		DELTA_X = atoi(argv[1]);
		DELTA_Y = atoi(argv[2]);
		DELTA_A = atoi(argv[3]);

		string str_info = "[INFO] ~ Default mode disable with parameters {"+to_string(DELTA_X)+","+to_string(DELTA_Y)+","+to_string(DELTA_A)+"}";
		cout << str_info << endl;
	}
	cout << "= = = = = = = = = =" << endl;

	//Load data from sources in an hasmap
	map<int, InputEntry> fragments = getEntriesFromFileAsMap("fragments.txt");
	map<int, InputEntry> solution = getEntriesFromFileAsMap("solution.txt");

	//Used to save the fragment with the right position or not
	vector<InputEntry> fragmentsOK;
	vector<InputEntry> fragmentsKO;
	//Load the data from the solution in a vector
	vector<InputEntry> solutionVector = getEntriesFromFile("fragments.txt");

	//Parcour the element in our solution
	for (std::pair<int, InputEntry> element : solution) {

		//If this element exist in the right solution file & his position is in our tolerance interval
		if(checkIfExist(fragments,element.first) && evalFragment(element.second,fragments[element.first],DELTA_X,DELTA_Y,DELTA_A))
			fragmentsOK.push_back(element.second); //then we add this fragment in the list for the right positionned fragment

		else fragmentsKO.push_back(element.second);//Else he'll go in the KO list
	}

	//We calculate the total surface of good positionned fragment
	int surfaceOK=calcArea(fragmentsOK);
	cout << "[AREA FOR OK FRAGMENT] ~ " << surfaceOK << endl;
	//Same for the other (KO)
	int surfaceKO=calcArea(fragmentsKO);
	cout << "[AREA FOR KO FRAGMENT] ~ " << surfaceKO << endl;
	//Finally the area from the right solution
	int surfaceT = calcArea(solutionVector);
	cout << "[TOTAL AREA]           ~ " << surfaceT << endl;

	//We check the quality of this solution
	double res =  (((double)surfaceOK - (double)surfaceKO) / (double)surfaceT) * 100;
	cout << endl << "[SOLUTION QUALITY]     ~ " << res << "%" <<  endl;

	return 0;
}

/**
* @desc Parcour a list of fragment and calculate the combine area
* @param listFragments List of our fragments in a vector
* @return Total area for those fragments
*/
int calcArea(vector<InputEntry> listFragments){
	int totalArea = 0;

	//For each fragment in the list
	for(int i = 0; i < listFragments.size(); ++i){
		//Get the right fragment image
		string path = "./frag_eroded/frag_eroded_" + to_string(listFragments[i].fragmentId) + ".png";
		Mat fragment = imread(path,IMREAD_UNCHANGED);

		//Extract "alpha" matrix
		Mat alpha;
		extractChannel(fragment, alpha, 3);
		int cptZero=0;

		//Calculate the number of zero (no transparent pixel)
		for(int i=0; i< fragment.rows ; i++){
			for(int j=0;j<fragment.cols ;j++){
				if( (int)alpha.at<uchar>(i,i) == 0) cptZero++;
			}
		}
		//Update the total area = H *W - cptZero
		totalArea+=fragment.rows*fragment.cols-cptZero;
	}

	return totalArea;
}

/**
* @desc Check if the passed key is in the map given
* @param inputs map in wich search
* @param key Key to find
* @return boolean - true if key is in the map / false else
*/
bool checkIfExist(map<int, InputEntry> inputs,int key){
	return (inputs.count(key) > 0);
}


/**
* @desc Evaluate if the two fragments has the same position according from the delta passed
* @param firstFragment The first fragment to check
* @param secondFragment THe second fragment to check
* @param dX Delta for X values
* @param dY Delta for Y values
* @param dA Delata for radius/rotation values
* @return boolean - true if we consider the two fragments similars - else false
*/
bool evalFragment(InputEntry firstFragment,InputEntry secondFragment,int dX,int dY,int dA){
	return  abs(firstFragment.x - secondFragment.x) <= dX &&
			abs(firstFragment.y - secondFragment.y) <= dY &&
			abs(firstFragment.rotation - secondFragment.rotation) <= dA;
}
