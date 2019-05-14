//
//  test_functions.hpp
//  Projekt2_PAMSI
//
//  Created by Michał on 02.04.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#ifndef test_functions_hpp
#define test_functions_hpp

using namespace std;

//------------------------------------------------------------------------------------
//Checking the correctness of sorting
/*  Type *_arr <- pointer at the beginning of the array
    int _array_size <- number of elements in the array
    bool _ascending <- variable that determines the sorting method
 
    if _ascending == true: Checking the ordering in ascending order
    if _ascending == false: Checking the ordering in descending order
*/
template <typename Type>
bool sorted_array(Type *_arr, int _array_size, bool _ascending){
    
    switch((int)_ascending){
            
        case true:
            for(int i=0; i<_array_size-1; ++i){
                if(_arr[i]>_arr[i+1]) return false;
            }
            return true;
            
        case false:
            for(int i=0; i<_array_size-1; ++i){
                if(_arr[i]<_arr[i+1]) return false;
            }
            return true;
    }
    return false;
}
//------------------------------------------------------------------------------------
//Fill the array's with random elements 0-100
void insert_random_array(int **_tab,int _number_of_arrays,int _array_size){
    for(int i=0; i<_number_of_arrays; ++i){
        _tab[i] = new int [_array_size];
        
        for(int j = 0; j < _array_size; ++j){
            _tab[i][j]=rand()%100;
        }
    }
}
//------------------------------------------------------------------------------------
//Print array
template <typename Type>
void print_array(Type *_tab,int _array_size){
    for(int i=0; i<_array_size; ++i){
        cout<<_tab[i]<<" ";
    }
}
//------------------------------------------------------------------------------------
//Create array
int **create_array(int _number_of_arrays, int _size_of_arrays){
    int **array = new int* [_number_of_arrays];
    for (int i = 0; i < _number_of_arrays; i++){
        array[i] = new int [_size_of_arrays];
    }
    return array;
}
//------------------------------------------------------------------------------------
// MergeSort test
template <typename Type>
void MergeSort_test(Type **_arr,int _number_of_arrays,int _array_size){
    cout<<endl<<"----------MergeSort efficiency test----------"<<endl;
    cout<<endl<<"Number of array's: "<<_number_of_arrays<<endl;
    cout<<"Size of array's: "<<_array_size<<endl;
    cout<<"----------------------------------------------"<<endl;
    
//Test 1: 25%, 50%, 75%, 95%, 99%, 99.7% of the initial elements of the array are sorted
    cout<<endl<<"TEST 1: 25%, 50%, 75%, 95%, 99%, 99.7% of "<<endl;
    cout<<"the initial elements of the array are sorted: "<<endl<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 25% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,(_array_size*0.25)-1,true);
    }
    cout<<"25%:"<<endl;
    //MergeSort test
    double start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    double stop = clock();
    double time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 50% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,(_array_size*0.5)-1,true);
    }
    cout<<endl<<"50%:"<<endl;
    //MergeSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 75% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,(_array_size*0.75)-1,true);
    }
    cout<<endl<<"75%:"<<endl;
    //MergeSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 95% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,(_array_size*0.95)-1,true);
    }
    cout<<endl<<"95%:"<<endl;
    //MergeSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 99% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,(_array_size*0.99)-1,true);
    }
    cout<<endl<<"99%:"<<endl;
    //MergeSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 99.7% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,(_array_size*0.997)-1,true);
    }
    cout<<endl<<"99.7%:"<<endl;
    //MergeSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    
//Test 2: All elements of the arrays are random
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    cout<<endl<<"TEST 2: All elements of the arrays are random: "<<endl<<endl;
    //MergeSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    cout<<"----------------------------------------------"<<endl;
    
//Test 3: All elements of the array already sorted but in reverse order
    cout<<endl<<"TEST 3: All elements of the array already"<<endl;
    cout<<"sorted but in reverse order: "<<endl<<endl;
    start = clock();
    //MergeSort test
    for(int i=0; i<_number_of_arrays; ++i){
        merge_sort(_arr[i],0,_array_size-1,false);
        cout<<sorted_array(_arr[i],_array_size,false);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
   cout<<"----------------------------------------------"<<endl;
}
//------------------------------------------------------------------------------------
//QuickSort test
template <typename Type>
void QuickSort_test(Type **_arr,int _number_of_arrays,int _array_size){
    cout<<endl<<"----------QuickSort efficiency test----------"<<endl;
    cout<<endl<<"Number of array's: "<<_number_of_arrays<<endl;
    cout<<"Size of array's: "<<_array_size<<endl;
    cout<<"----------------------------------------------"<<endl;
    
    //Test 1: 25%, 50%, 75%, 95%, 99%, 99.7% of the initial elements of the array are sorted
    cout<<endl<<"TEST 1: 25%, 50%, 75%, 95%, 99%, 99.7% of "<<endl;
    cout<<"the initial elements of the array are sorted: "<<endl<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 25% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,(_array_size*0.25)-1,true);
    }
    cout<<"25%:"<<endl;
    //QuickSort test
    double start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    double stop = clock();
    double time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 50% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,(_array_size*0.5)-1,true);
    }
    cout<<endl<<"50%:"<<endl;
    //QuickSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 75% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,(_array_size*0.75)-1,true);
    }
    cout<<endl<<"75%:"<<endl;
    //QuickSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 95% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,(_array_size*0.95)-1,true);
    }
    cout<<endl<<"95%:"<<endl;
    //QuickSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 99% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,(_array_size*0.99)-1,true);
    }
    cout<<endl<<"99%:"<<endl;
    //QuickSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 99.7% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,(_array_size*0.997)-1,true);
    }
    cout<<endl<<"99.7%:"<<endl;
    //QuickSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Test 2: All elements of the arrays are random
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    cout<<endl<<"TEST 2: All elements of the arrays are random: "<<endl<<endl;
    //QuickSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,_array_size-1,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    cout<<"----------------------------------------------"<<endl;
    
    //Test 3: All elements of the array already sorted but in reverse order
    cout<<endl<<"TEST 3: All elements of the array already"<<endl;
    cout<<"sorted but in reverse order: "<<endl<<endl;
    start = clock();
    //QuickSort test
    for(int i=0; i<_number_of_arrays; ++i){
        quick_sort(_arr[i],0,_array_size-1,false);
        cout<<sorted_array(_arr[i],_array_size,false);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    cout<<"----------------------------------------------"<<endl;
}
//------------------------------------------------------------------------------------
template <typename Type>
void HeapSort_test(Type **_arr,int _number_of_arrays,int _array_size){
    cout<<endl<<"-----------HeapSort efficiency test-----------"<<endl;
    cout<<endl<<"Number of array's: "<<_number_of_arrays<<endl;
    cout<<"Size of array's: "<<_array_size<<endl;
    cout<<"----------------------------------------------"<<endl;
    
    //Test 1: 25%, 50%, 75%, 95%, 99%, 99.7% of the initial elements of the array are sorted
    cout<<"TEST 1: 25%, 50%, 75%, 95%, 99%, 99.7% of "<<endl;
    cout<<"the initial elements of the array are sorted: "<<endl<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 25% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size*0.25,true);
    }
    cout<<"[25%]:"<<endl;
    //HeapSort test
    double start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    double stop = clock();
    double time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 50% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],(_array_size*0.5),true);
    }
    cout<<endl<<"[50%]:"<<endl;
    //HeapSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 75% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size*0.75,true);
    }
    cout<<endl<<"[75%]:"<<endl;
    //HeapSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 95% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size*0.95,true);
    }
    cout<<endl<<"[95%]:"<<endl;
    //HeapSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 99% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size*0.99,true);
    }
    cout<<endl<<"[99%]:"<<endl;
    //HeapSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    //Sort 99.7% of the array's elements
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size*0.997,true);
    }
    cout<<endl<<"[99.7%]:"<<endl;
    //HeapSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    cout<<"----------------------------------------------"<<endl;
    
    //Test 2: All elements of the arrays are random
    //Fill the arrays with random elements
    insert_random_array(_arr,_number_of_arrays,_array_size);
    cout<<"TEST 2: All elements of the arrays are random: "<<endl<<endl;
    //HeapSort test
    start = clock();
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size,true);
        cout<<sorted_array(_arr[i],_array_size,true);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    cout<<"----------------------------------------------"<<endl;
    
    //Test 3: All elements of the array already sorted but in reverse order
    cout<<"TEST 3: All elements of the array already"<<endl;
    cout<<"sorted but in reverse order: "<<endl<<endl;
    start = clock();
    //HeapSort test
    for(int i=0; i<_number_of_arrays; ++i){
        heap_sort(_arr[i],_array_size,false);
        cout<<sorted_array(_arr[i],_array_size,false);
    }
    stop = clock();
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<endl<<"Execution time: "<<time<<"sec."<<endl;
    cout<<"----------------------------------------------"<<endl;
}
//------------------------------------------------------------------------------------

#endif /* test_functions_hpp */
