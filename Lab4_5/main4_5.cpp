#include "tlist_iterator.cpp"

int main()
{
    int n;
    cout << "Enter number of sentences: ";
    cin >> n;
    cin.ignore();


    string sentence;
    TList list = initList();
    for (int i = 0; i < n; i++)
    {
        getline(cin, sentence);
        push(list, sentence);
    }

    TListIterator it = getBegin(list);
    string largest_sentence = "";
    string shortest_sentence = getValue(it);
    while (isValid(it))
    {
        if (getValue(it).size() > largest_sentence.size())
        {
            largest_sentence = getValue(it);
        }
        if (getValue(it).size() < shortest_sentence.size())
        {
            shortest_sentence = getValue(it);
        }
        moveNext(it);
    }

    cout << "Largest sentence: " << largest_sentence << endl;
    cout << "Shortest sentence: " << shortest_sentence << endl;

    return 0;
}