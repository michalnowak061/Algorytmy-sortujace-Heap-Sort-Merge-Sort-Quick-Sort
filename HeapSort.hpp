//
//  HeapSort.hpp
//  Projekt2_PAMSI
//
//  Created by Michał on 26.03.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#ifndef HeapSort_hpp
#define HeapSort_hpp

//------------------------------------------------------------------------------------
//Moving elements down the mound
/*  Type *_arr <- pointer at the beginning of the array
    int _start <- first element in heap
    int _end   <- last element in heap
    bool _ascending <- variable that determines the sorting method

    if _ascending == true:  sorting in ascending order
    if _ascending == false: sorting in descending order
*/
template <typename Type>
void shift_down(Type *_arr,int _start,int _end,bool _ascending){
    int root_index = _start;
    
    switch((int)_ascending){
        case true:  //sorting in ascending order
            //if the parents are smaller than the children, move them down the heap
            while( (root_index * 2 + 1) <= _end){
                int child_index = (root_index * 2) + 1;
    
                if (child_index + 1 <= _end && _arr[child_index] < _arr[child_index + 1]){
                    child_index = child_index + 1;
                }
                if (_arr[root_index] < _arr[child_index]){
                    replace(_arr,root_index,child_index);
                    root_index = child_index;
                }else return;
            }
            
        case false: //sorting in descending order
            //if the parents are bigger than the children move them down the heap
            while(( (root_index * 2) + 1) <= _end){
                int child_index = (root_index * 2) + 1;
                
                if (child_index + 1 <= _end && _arr[child_index] > _arr[child_index + 1]){
                    child_index = child_index + 1;
                }
                if (_arr[root_index] > _arr[child_index]){
                    replace(_arr,root_index,child_index);
                    root_index = child_index;
                }else return;
            }
    }
}
//------------------------------------------------------------------------------------
//Build maximum heap
/*  Type *_arr <- pointer at the beginning of the array
    int _array_size <- number of elements in the array
    bool _ascending <- variable that determines the sorting method
 
    if _ascending == true:  sorting in ascending order
    if _ascending == false: sorting in descending order
*/
template <typename Type>
void build_heap(Type *_arr,int _array_size,bool _ascending){
    for(int i = _array_size/2; i >= 0; --i){
        shift_down(_arr,i,_array_size-1,_ascending);
    }
}
//------------------------------------------------------------------------------------
//HeapSort
/*  Type *_arr <- pointer at the beginning of the array
    int _array_size <- number of elements in the array
    bool _ascending <- variable that determines the sorting method
 
    if _ascending == true:  sorting in ascending order
    if _ascending == false: sorting in descending order
*/
template <typename Type>
void heap_sort(Type *_arr,int _array_size,bool _ascending){
    build_heap(_arr,_array_size,_ascending);
    
    int end = _array_size-1;
    while (end > 0){
        //swap the maximum and last elements
        replace(_arr,end,0);
        //skip the last element
        end = end-1;
        //restore the structure of the maximum heap
        shift_down(_arr,0,end,_ascending);
    }
}
//------------------------------------------------------------------------------------
#endif /* HeapSort_hpp */
