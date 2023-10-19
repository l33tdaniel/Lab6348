#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
    You are tasked with implementing a C++ program that performs various operations on square matrices using 
    functions and arrays (no classes or objects yet). Your program should read matrix data from a file, perform matrix operations, and output the results. 
    The max size of the square matrices should be defined as a static constant 100 but the actual size of the square matrix will be the first line of data, 
    and it will less than or equal to 100. For this assignment, you will write the following functions:
*/
void printAll(int userInputOne[][100], int userInputTwo[][100], int matrixLength){
        // printing out the first matrix
        cout << "Matrix One: " << endl;
        for (int i = 0; i < matrixLength; i++){
            for(int j = 0; j < matrixLength; j++){
                if(j!=matrixLength-1){
                    cout << userInputOne[i][j] << " ";
                }
                else{
                    cout << userInputOne[i][j] << endl;
                }
            }
        }
        // printing out the second matrix
        cout << "Matrix Two: " << endl;
        for (int i = 0; i < matrixLength; i++){
            for(int j = 0; j < matrixLength; j++){
                if(j!=matrixLength-1){
                    cout << userInputTwo[i][j] << " ";
                }
                else{
                    cout << userInputTwo[i][j] << endl;
                }
            }
        }
}
void substraction(int userInputOne[][100], int userInputTwo[][100], int matrixLength){
    int substractionMatrix[100][100];
    for(int i = 0; i < matrixLength; i++){
        for(int j = 0; j < matrixLength; j++){
            substractionMatrix[i][j] = (userInputOne[i][j] - userInputTwo[i][j]);
        }
    }

    cout << "Resultant Matrix Product" << endl;
    for (int i = 0; i < matrixLength; i++){
        for(int j = 0; j < matrixLength; j++){
            if(j!=matrixLength-1){
                cout << substractionMatrix[i][j] << " ";
            }
            else{
                cout << substractionMatrix[i][j] << endl;
            }
        }
    }
}
void multiplication(int userInputOne[][100], int userInputTwo[][100], int matrixLength){
    int multiplicativeMatrix[100][100];
    for (int i =0; i < matrixLength; i++){
        for (int j= 0; j < matrixLength; j++){
            for (int k =0; k < matrixLength; k++){
                multiplicativeMatrix[i][j] += userInputOne[i][k] * userInputTwo[k][j];
            }
        }
    }
    cout << "Resultant Matrix Product" << endl;
    for (int i = 0; i < matrixLength; i++){
        for(int j = 0; j < matrixLength; j++){
            if(j!=matrixLength-1){
                cout << multiplicativeMatrix[i][j] << " ";
            }
            else{
                cout << multiplicativeMatrix[i][j] << endl;
            }
        }
    }
}
void addition(int userInputOne[][100], int userInputTwo[][100], int matrixLength){
        int additionMatrix[100][100];
        for(int i = 0; i < matrixLength; i++){
            for(int j = 0; j < matrixLength; j++){
                additionMatrix[i][j] = (userInputOne[i][j] + userInputTwo[i][j]);
            }
        }
        cout << "Resultant Matrix From Addition: " << endl;
        for (int i = 0; i < matrixLength; i++){
            for(int j = 0; j < matrixLength; j++){
                if(j!=matrixLength-1){
                    cout << additionMatrix[i][j] << " ";
                }
                else{
                    cout << additionMatrix[i][j] << endl;
                }
            }
        }
}
int main() {
    cout << "Daniel Neugent\nLab #6: Matrix manipulation\n";
    int userInputOne[100][100];
    int userInputTwo[100][100];
	ifstream inputFile("matrix_input.txt");
    // Check if the file is open and accessible
    int matrixLength;
    inputFile >> matrixLength;

    if (!inputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }
    else{
        // if we hit this else statement, that means that the file has successfully been opened
        // getting all the info into the first matrix
        for (int i =0; i < matrixLength; i++){
            for (int j= 0; j < matrixLength; j++){
                inputFile >> userInputOne[i][j];
            }
        }
        // getting all the info into the second matrix
        for (int i =0; i < matrixLength; i++){
            for (int j= 0; j < matrixLength; j++){
                inputFile >> userInputTwo[i][j];
            }
        }
        // printing out the first matrix
        printAll(userInputOne, userInputTwo, matrixLength);
        addition(userInputOne, userInputTwo, matrixLength);
        multiplication(userInputOne, userInputTwo, matrixLength);
        substraction(userInputOne, userInputTwo, matrixLength);
        // building the tempMatrix for addition
    }
    return 0;
}
