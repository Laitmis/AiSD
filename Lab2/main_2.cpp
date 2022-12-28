#include <iostream>
using namespace std;

#include "lab_2.cpp"


int main()
{
    Stack stack = initList();

    int n, count = 0;
    char letter;

    cout << "Enter number of letters: ";
    cin >> n;

    cout << "Enter letters: ";
    for (int i = 0; i < n; i++)
    {
        cin >> letter;
        push(stack, letter);
    }

    cout << "Enter letter that we are counting: ";
    cin >> letter;

    while (!isEmpty(stack))
        if (pop(stack) == letter) count++;

    cout << "Result: " << count << endl;

    return 0;
}
