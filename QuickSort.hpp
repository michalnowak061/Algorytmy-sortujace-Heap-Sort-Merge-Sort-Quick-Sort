//
//  QuickSort.hpp
//  Projekt2_PAMSI
//
//  Created by Michał on 26.03.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

//------------------------------------------------------------------------------------
//Swap elements in an array
/*  Type *_arr  <- pointer at the beginning of the array
    int _index1 <- the number of the first element in the array that we want to change
    int _index2 <- the number of the second element in the array that we want to change
*/
template <typename Type>
void replace(Type *_arr,int _index1,int _index2){
    Type aux = _arr[_index1]; // <- auxiliary variable
    //exchange
    _arr[_index1] = _arr[_index2];
    _arr[_index2] = aux;
}
//------------------------------------------------------------------------------------
//Selects the element to be used for dividing. Moves all the smaller elements
//to the left of this element, and greater than or equal to the right
/*  Type *_arr <- pointer at the beginning of the array
    int _left  <- the number of the first element of the left part of the array
    int _right <- the number of the last element of the right part of the array
    bool _ascending <- variable that determines the sorting method
 
    if _ascending == true: sorting in ascending order
    if _ascending == false: sorting in descending order
*/
template <typename Type>
int divide(Type *_arr,int _left,int _right,bool _ascending){
    Type pivot = _arr[_left];   // <- pivot
    int i = _left;              // <- left side iterator
    int j = _right;             // <- right side iterator
    
    while(1){
        switch((int)_ascending){
            case true: //sorting in ascending order
                while (_arr[j] > pivot) j--;
                while (_arr[i] < pivot) i++;
                if (i < j){
                    replace(_arr,i,j);
                    i++;
                    j--;
                }
                else return j;  // <- point of division
                break;
                
            case false: //sorting in descending order
                while (_arr[j] < pivot) j--;
                while (_arr[i] > pivot) i++;
                if (i < j){
                    replace(_arr,i,j);
                    i++;
                    j--;
                }
                else return j; // <- point of division
                break;
        }
    }

}
//------------------------------------------------------------------------------------
//QuickSort
/*  Type *_arr <- pointer at the beginning of the array
    int _left  <- the number of the first element of the left part of the array
    int _right <- the number of the last element of the right part of the array
    bool _ascending <- variable that determines the sorting method
 
    if _ascending == true:  sorting in ascending order
    if _ascending == false: sorting in descending order
*/
template <typename Type>
void quick_sort(Type *_arr,int _left,int _right,bool _ascending){
    //subarray is longer than one
    if(_right > _left){
        //separate and remember the separation point
        int i = divide(_arr,_left,_right,_ascending);
        //sorting left side
        quick_sort(_arr,_left,i,_ascending);
        //sorting right side
        quick_sort(_arr,i+1,_right,_ascending);
    }
}
//------------------------------------------------------------------------------------
#endif /* QuickSort_hpp */
