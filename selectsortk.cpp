/*
Title: Select Sort k
Abstract: Write a program called select-sort-k.cpp that modifies the selection sort algorithm to sort the first k smallest elements 
of the array with n elements (k <= n, the value of k will be entered by the user). 
Your program should read the integer numbers from an input file, store them in an array (dynamic), 
and display the k smallest elements in sorted order
Author: Mark Mariscal
ID: 7198
Date: 02/01/2020
*/


#include<iostream>
#include<fstream>
using namespace std;
void selection(int arr[], int size, int c)
{
   int low, temp, minIndex;
   int i, j;
   for (i = 0;i < c;i++)
   {
       minIndex = i;
       low = arr[i];
       for (j = i + 1;j < size;j++)
       {
           if (arr[j] < low)
           {
              minIndex = j;
              low = arr[j];
           }
       }
     if(minIndex != i){
         temp = arr[minIndex];
         arr[minIndex] = arr[i];
         arr[i] = temp;
     }
   }
}

int main()
{

    ifstream myFile;
    string fileName;
    int size, c;
    int *array; //pointer with array
    int num;
    int count; // gives us the count of the array length 
    int kvalue;
  
    cout << "Enter input file name: "; //asks input
    cin >> fileName; // recieves input
    myFile.open(fileName.c_str()); //opens the file
    if (myFile >> num) // if there is an input then count reads first line
    {
      count = num;
    }
    array = new int [count]; //array with count , create size of array
    count = 0;
    while(myFile >> num) //start after first line
    {
        array[count] = num;//adds number to array
        count++;
    }
    myFile.close();//closes file 

     cout << "Enter the value k: ";
    cin >> kvalue ;
  
  selection(array, count, kvalue);
  cout << "Output:";
  for(int i = 0; i < kvalue; i++){
      if(i > 0){
        cout << ",";
        }
        cout << array[i];
      
  }
   delete[] array;
   return 0;
}