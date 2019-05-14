//
//  main.cpp
//  Projekt2_PAMSI
//
//  Created by Michał on 26.03.2018.
//  Copyright © 2018 Michał. All rights reserved.

#include <iostream>

#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "HeapSort.hpp"
#include "test_functions.hpp"

using namespace std;


int main(void) {
    
    int number_of_arrays = 100;
    int size_of_arrays = 10000;
        
    int **arr = create_array(number_of_arrays,size_of_arrays);
    
    int choice=0;
    
    cout<<endl<<"Number of array's: "<<number_of_arrays<<endl;
    cout<<"Size of array's: "<<size_of_arrays<<endl;
    cout<<endl<<"-----Program functions:-----"<<endl;
    cout<<"1.Change the size of the array's"<<endl;
    cout<<"2.Mergesort test"<<endl;
    cout<<"3.Quicksort test"<<endl;
    cout<<"4.Heapsort test"<<endl;
    cout<<"9.Exit"<<endl;
    
    while(1){
        
        cout<<"(Functions->press 8) > ";
        cin>>choice;
        if(choice==9){
            cout<<"Program ended with exit code 0"<<endl;
            break;
        }
        
        switch(choice){
            case 1:
                cout<<"Size of array's: ";
                cin>>size_of_arrays;
                break;
            case 2:
                MergeSort_test(arr,number_of_arrays,size_of_arrays);
                break;
            case 3:
                QuickSort_test(arr,number_of_arrays,size_of_arrays);
                break;
            case 4:
                HeapSort_test(arr,number_of_arrays,size_of_arrays);
                break;
            case 8:
                cout<<endl<<"Number of array's: "<<number_of_arrays<<endl;
                cout<<"Size of array's: "<<size_of_arrays<<endl;
                cout<<endl<<"-----Program functions:-----"<<endl;
                cout<<"1.Change the size of the array's"<<endl;
                cout<<"2.Mergesort test"<<endl;
                cout<<"3.Quicksort test"<<endl;
                cout<<"4.Heapsort test"<<endl;
                cout<<"9.Exit"<<endl;
                break;
        }
    }
    
    free(arr); //free memory
    arr = NULL;
    
    return 0;
}
