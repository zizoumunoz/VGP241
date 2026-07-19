
#include <iostream>
#include <Array.h>
#include <Vector.h>
int main()
{
    std::cout << "Hello World!\n";

    Array<int, 10> myCustomArray;
    Vector<int> myVec;
    myVec.Resize(10);
    for (size_t i = 0; i < myVec.Size(); i++)
    {
        std::cout << (myVec[i] += rand()) << "\n";
    }

    std::cout << "\n\n";

    myVec.PopBack();
    myVec.PopBack();

    for (size_t i = 0; i < myVec.Size(); i++)
    {
        std::cout << myVec[i] << "\n";
    }

    //for (size_t i = 0; i < myCustomArray.Size(); i++)
    //{
    //    myCustomArray[i] = 0;
    //    std::cout << myCustomArray[i] << " ";
    //}

    //std::cout << "\n";

    //for (size_t i = 0; i < myCustomArray.Size(); i++)
    //{
    //    myCustomArray[i] = rand() % 10;
    //    std::cout << myCustomArray[i] << " ";
    //}

    //std::cout << "\n";

    //Array<int, 10> otherArray;

    //otherArray = myCustomArray;
    //for (size_t i = 0; i < otherArray.Size(); i++)
    //{
    //    otherArray[i] += 5;
    //    std::cout << otherArray[i] << " ";
    //}


    // Build array of 10 ints
    // initialize them to 0
    // iterate through them all and set the values to random numbers
    // create a new array of 10 ints
    // make it equal to the initial array
    // iterate through all the elements and add 5 (print the numbers
    // 

}
