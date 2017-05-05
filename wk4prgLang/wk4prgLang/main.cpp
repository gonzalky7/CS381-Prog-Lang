//
//  main.cpp
//  wk4prgLang
//
//  Created by Kyleen Gonzalez on 4/26/17.
//  Copyright © 2017 Kyleen Gonzalez. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <array>



const int tenK = 10000;

using namespace std;

void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}
void heapsort(int *a, int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
}
void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}

void selectionSort(int array[]) {
        for(int x=0; x<tenK; x++) {
            int index_of_min = x;
            for(int y=x; y<tenK; y++) {
                if(array[index_of_min]>array[y]) {
                    index_of_min = y;
                }
            }
            int temp = array[x];
    
            array[x] = array[index_of_min];
    
            array[index_of_min] = temp;
    
        }
}
void bubbleSort(int arr[]){
    for(int x = 0; x < tenK; x++) {
        for(int y=0; y < tenK - 1; y++) {
            if(arr[y] > arr[y+1]) {
                int temp = arr[y+1];
                arr[y+1] = arr[y];
                arr[y] = temp;
            }
        }
    }
}

void insertionSort(int array[]){
    
    for(int x=0; x<tenK; x++){
        int index_of_min = x;
        
        for(int y=x; y<tenK; y++){
            if(array[index_of_min]>array[y]){
                index_of_min = y;
            }
        }
        int temp = array[x];
        
        array[x] = array[index_of_min];
        
        array[index_of_min] = temp;
    }
}

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}



int main() {
    
    int firstAlg[tenK], secondAlg[tenK], thirdAlg[tenK], fourthAlg[tenK], fifthAlg[tenK];
    clock_t start1, start2, start3, start4, start5;
    double duration1, duration2, duration3, duration4, duration5;
    
    
    /* Code to read in txt file */
    ifstream infile;
    infile.open("Values.txt");
    
    if (!infile) {
        cerr << "Unable to open file C\n";
        exit(1);   // call system to stop
    }
    /* end code read text file */
    
    /* FIlling array with data from text file */
    for (int i = 0; i < tenK ; ++i) {
            if (!(infile >> firstAlg[i])) {
                cerr << "Unexpected end of file\n" << endl;
                exit(1);   // call system to stop
            }
    }
    /* End filling array with data */
    copy(firstAlg, firstAlg + tenK, secondAlg); //Making different arrays because arrays become sorted and cannot be used for the next algo
    copy(firstAlg, firstAlg + tenK, thirdAlg);
    copy(firstAlg, firstAlg + tenK, fourthAlg);
    copy(firstAlg, firstAlg + tenK, fifthAlg);
    
    /* ----------------- Begin bubble sort ---------------- */
    start1 = clock();
    
    bubbleSort(firstAlg);
    
    duration1 = (clock() - start1 ) / (double) CLOCKS_PER_SEC;
    
    cout<<"First slowest sorting algorithm. Bubble sort duration is: "<< duration1 <<'\n';
    /* ------------- End bubble sort ------------------- */
    cout <<endl;
    /* ----------------- Begin Selection sort ---------------- */
    start2 = clock();
    
    selectionSort(secondAlg);
    
    duration2 = (clock() - start2 ) / (double) CLOCKS_PER_SEC;
    
    cout<<"Second slowest sorting algorithm.  Selection sort duration is: "<< duration2 <<'\n';
    /* ----------------- End Selction sort ---------------- */
     cout <<endl;
    /* ------------- Begin Insertion sort ------------------- */
    start3 = clock();
    
    insertionSort(thirdAlg);
    
    duration3 = (clock() - start3 ) / (double) CLOCKS_PER_SEC;
    
    cout<<"Third fastest sorting algorithm. Insertion sort duration is: "<< duration3 <<'\n';
    /* ------------- End Insertion sort ------------------- */
    cout <<endl;
    
    start5 = clock();
    
    build_maxheap(fifthAlg,tenK);
    heapsort(fifthAlg, tenK);
    
    duration5 = (clock() - start5 ) / (double) CLOCKS_PER_SEC;
    
    cout<<"Second fastest sorting algorithm. Heap sort duration is: "<< duration5 <<'\n';
    /* ------------- End Heap sort ------------------- */
    cout <<endl;
     /* ----------------- Begin quick sort ---------------- */
    
    start4 = clock();
    
    quickSort(fourthAlg, 0, 9999);
    
    duration4 = (clock() - start4 ) / (double) CLOCKS_PER_SEC;
    
    cout<<"First fastest sorting algorithm. Quick sort duration is: "<< duration4 <<'\n';
    /* ------------- End quick sort ------------------- */
    cout <<endl;
    
    return 0;
}

