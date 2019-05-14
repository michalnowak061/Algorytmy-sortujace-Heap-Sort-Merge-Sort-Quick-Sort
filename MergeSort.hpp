//
//  MergeSort.hpp
//  Projekt2_PAMSI
//
//  Created by Michał on 26.03.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

//------------------------------------------------------------------------------------
/*  Type *_tab  <- pointer at the beginning of the subarray
    int _left   <- the number of the first element of the left part of the subarray
    int _center <- the number of the middle element of the subarray
    int _right  <- the number of the last element of the right part of the subarray
    bool _ascending <- variable that determines the sorting method
 
    if _ascending == true: sorting in ascending order
    if _ascending == false: sorting in descending order
 */
template <typename Type>
void merge(Type *_arr,int _left,int _center,int _right,bool _ascending){
    
    Type *temp_arr = new Type[_right-_left+1]; // <- temporary array
    
    int i = _left;       // <- left side iterator
    int j = _center+1;   // <- right side iterator
    int k = 0;           // <- the temporary array iterator
    
    //copy elements to the temporary array
    while(i <= _center && j <=_right){
        switch((int)_ascending){
            case true:  //sorting in ascending order
                if(_arr[i] <= _arr[j]){
                    temp_arr[k++] = _arr[i++];
                }else temp_arr[k++] = _arr[j++];
                break;
                
            case false: //sorting in descending order
                if(_arr[i] >= _arr[j]){
                    temp_arr[k++] = _arr[i++];
                }else temp_arr[k++] = _arr[j++];
                break;
        }
    }
    //copy the remaining elements
    while(i <= _center)
        temp_arr[k++] = _arr[i++];
    while(j <= _right)
        temp_arr[k++] = _arr[j++];
    //copy the mergered temporary array to the original array
    for(k = 0, i = _left; i <= _right; ++i, ++k)
        _arr[i] = temp_arr[k];
    
    free(temp_arr); //free memory
    temp_arr = NULL;
}
//------------------------------------------------------------------------------------
/*  Type *_arr <- pointer at the beginning of the array
    int _left  <- the number of the first element of the left part of the array
    int _right <- the number of the last element of the right part of the array
    bool _ascending <- variable that determines the sorting method
 
    if _ascending == true: sorting in ascending order
    if _ascending == false: sorting in descending order
*/
template <typename Type>
void merge_sort(Type *_arr,int _left,int _right,bool _ascending){
    int center = (_left+_right)/2; // <-center of the subarray
    
    if(_left < _right){ //the array has more than one element
        //sort the left part of the subarray
        merge_sort(_arr,_left,center,_ascending);
        //sort the right part of the subarray
        merge_sort(_arr,center+1,_right,_ascending);
        //merge the left and right part
        merge(_arr,_left,center,_right,_ascending);
    }
}
//------------------------------------------------------------------------------------
#endif /* MergeSort_hpp */
