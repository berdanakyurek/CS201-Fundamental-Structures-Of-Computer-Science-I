//Berdan Akyurek
//21600904
//CS01 HW2

#include <iostream>
#include <ctime>
using namespace std;

int linearSearch( int* arr, int N, int value )
{
    for ( int i = 0; i < N; i++)
        if ( arr[i] == value )
            return i;

    return -1;
}

int binarySearch( int* arr, int N, int value )
{
    int low = 0, high = N - 1;
    while ( low <= high ) 
    {
        int mid = (low + high) / 2;
        if ( arr[ mid ] < value )         
            low = mid + 1;
        else if ( arr[ mid ] > value )         
            high = mid - 1;
        else
            return mid;

    }
    return -1;

}

int main()
{
    //Declerations
    int N = 100000;
    int value = -1;

    int* array = new int[N];
    int linearResult;
    int binaryResult;

    for(int i = 0 ; i < N ; i ++ )
        array[i] = i;

    cout << "Results for N = " << N << endl;
    cout << "-----------------" << endl;
    cout << "Linear Search" << endl;
    cout << "-----------------" << endl;
    
    //Store the starting time
    double duration;
    clock_t startTime = clock();

    //Code block
    linearResult = linearSearch( array, N, value );

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "The index of " << value << ": " << linearResult << endl;
    cout << "-----------------" << endl;

    cout << "Binary Search" << endl;
    cout << "-----------------" << endl;
    
    //Store the starting time
    startTime = clock();
    //Code block
    
    binaryResult = binarySearch( array, N, value );

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "The index of " << value << ": " << binaryResult << endl;
    cout << "-----------------" << endl;

    delete[] array;
    return 0;
}



