/* 
========================== WARNING ==========================
read the instructions commented very carefully
the main objective of this quiz is to modify ONLY the "check_if_car_fits" function so that it will
return correct data as stated in the comment below.
=============================================================
*/

#include <vector>
#include <iostream>

using namespace std;

/*------------------------------------------------------------------

modify this function so that it will return true if given the car dimensions car_dimensions[0] (row) and car_dimensions[1] (column)
can fit in the parking_spot where 1 denotes obstacles and 0 denotes empty space where car can be parked.

------------------------------------------------------------------*/
bool check_if_car_fits(vector<vector<int>> parking_spot, vector<int> car_dimensions)
{
    
    bool result = 0;
    int x = 0;
    int y = 0;
    int z = 0;

    for (int i = 0; i < parking_spot.size(); i++){
        for (int j = 0; j < parking_spot.at(i).size(); j++){
            if (j == 0){
                z = parking_spot.at(i).at(j); 
            }
            if (j != 0){
                if (parking_spot.at(i).at(j) == 0){
                    if (z == parking_spot.at(i).at(j)){
                        x = x + 1;
                    }
                }
                z = parking_spot.at(i).at(j);
            }   
        }

        if (x >= car_dimensions.at(0) - 1){
            y++;
        }
        
        x = 0;
    }
    
    if(car_dimensions.at(1) <= y){
        result = 1;
    }
    
	return result;
}

int main()
{

//====================== DO NOT MODIFY THE CODE HERE test =======================

	vector<vector<int>> parking_spot = {{1,1,1,1,1,0},
										{1,0,0,0,0,0},
										{1,0,0,0,0,1},
										{1,0,1,0,0,1}};

	vector<int> car_dimensions = {3,2};
	cout << "test 1: " << check_if_car_fits(parking_spot, car_dimensions) << endl;
	//expected result: 1

	parking_spot = {{1,1,1,1,1,0},
					{1,0,0,0,0,0},
					{1,0,0,0,0,0},
					{1,0,0,0,0,0},
					{1,0,1,0,0,1}};

	car_dimensions = {5,2};
	cout << "test 2: " << check_if_car_fits(parking_spot, car_dimensions) << endl;
	//expected result: 1

	parking_spot = {{1,1,1,1,1,0},
					{1,0,0,0,0,0},
					{1,0,0,1,0,0},
					{1,0,0,0,0,0},
					{1,0,1,0,0,1}};

	car_dimensions = {4,3};
	cout << "test 3: " << check_if_car_fits(parking_spot, car_dimensions) << endl;
	//expected result: 0

	parking_spot = {{0,1,1,1,1,0},
					{0,0,0,0,0,0},
					{0,0,0,0,0,0},
					{1,0,0,0,0,0},
					{1,0,1,0,0,1}};

	car_dimensions = {6,2};
	cout << "test 4: " << check_if_car_fits(parking_spot, car_dimensions) << endl;
	//expected result: 1

	parking_spot = {{0,1,1,1,1,0},
    		        {1,1,1,1,0,0},
    		        {0,1,1,1,1,0},
    		        {1,0,0,0,0,0},
    		        {1,0,0,0,0,1}};
    		        
    car_dimensions = {3,2};
    cout << "test 5: " << check_if_car_fits(parking_spot, car_dimensions) << endl;
    //expected result: 1
    
    parking_spot = {{0,1,1,1,1,0},
    		        {1,1,1,1,0,0},
    		        {0,1,1,1,1,0},
    		        {1,0,0,0,0,0},
    		        {1,0,0,0,0,1}};
    		        
    car_dimensions = {3,3};
    cout << "test 6: " << check_if_car_fits(parking_spot, car_dimensions) << endl;
    //expected result: 0
    
     parking_spot = {{0,1,1,1,1,0},
    		         {1,1,1,1,0,0},
    		         {0,1,0,0,0,0},
    		         {1,0,0,0,0,0},
    		         {1,1,0,0,0,1}};
    		        
    car_dimensions = {3,3};
    cout << "test 7: " << check_if_car_fits(parking_spot, car_dimensions) << endl;
    //expected result: 1
    
    parking_spot = {{0,1,1,1,1,0},
    		        {1,1,1,1,0,0},
    		        {0,1,0,0,0,0},
    		        {1,0,0,0,0,0},
    		        {1,1,0,0,0,1}};
    		        
    car_dimensions = {4,3};
    cout << "test 8: " << check_if_car_fits(parking_spot, car_dimensions) << endl;
    //expected result: 0
	
/*------------------------------------------------------------------

	you can add more test below the line

------------------------------------------------------------------*/


    return 0;
}