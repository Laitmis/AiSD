#include <iostream>

using namespace std;

#include "lab_3_queue.cpp"

int main()
{
    Queue *q = initQueue( );

    int n;
    cout << "Enter number of letters: ";
    cin >> n;

    char letter;
    for(int i = 0; i < n; ++i)
    {
        cin >> letter;
        push(q, letter);
    }

    cout << "Enter letter that we are counting: ";
    cin >> letter;

    int count = 0;
    while(!isEmpty(q))
        if (pop(q) == letter) count++;

    cout << "Result: " << count;

    return 0;
}
