#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Array
{
    T* arr;
    int size;
    int n;

public:
    Array(int ssize)
    {
        size = ssize;
        n = 0;
        arr = new T[size];
    }

    void insert(T v)
    {
        if (n == size)
        {
            cout << "Array is full. Cannot insert more items." << endl;
            return;
        }
        arr[n] = v;
        n++;
    }

    int search(T v)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == v)
                return i;
        }
        return -1;
    }

    void remove(T v)
    {
        int index = search(v);

        if (index == -1)
        {
            cout << "Item not found." << endl;
            return;
        }

        for (int i = index; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        n--;
        cout << "Item removed successfully." << endl;
    }
};

class Word
{
public:
    string word;
    string definition;
    string partOfSpeech;

    Word()
    {
        word = "";
        definition = "";
        partOfSpeech = "";
    }

    Word(string w, string d, string p)
    {
        word = w;
        definition = d;
        partOfSpeech = p;
    }

    void display()
    {
        cout << "Word: " << word << endl;
        cout << "Definition: " << definition << endl;
        cout << "Part of Speech: " << partOfSpeech << endl;
    }

    bool operator==(Word w)
    {
        string a = word;
        string b = w.word;

        for (int i = 0; i < a.length(); i++)
            if (a[i] >= 'A' && a[i] <= 'Z')
                a[i] += 32;

        for (int i = 0; i < b.length(); i++)
            if (b[i] >= 'A' && b[i] <= 'Z')
                b[i] += 32;

        return a == b;
    }

    friend ostream& operator<<(ostream& out, Word w)
    {
        out << "Word: " << w.word << ", Definition: " << w.definition << ", Part of Speech: " << w.partOfSpeech;
        return out;
    }
};

int main()
{
    Array<Word> vocab(15);
    Word words[15];

    int count;
    cout << "How many words do you want to enter: ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        string w, d, p;

        cout << "Enter word: ";
        getline(cin, w);

        cout << "Enter definition: ";
        getline(cin, d);

        cout << "Enter part of speech: ";
        getline(cin, p);

        Word temp(w, d, p);

        if (vocab.search(temp) != -1)
        {
            cout << "Word already in vocabulary" << endl;
        }
        else
        {
            vocab.insert(temp);
            words[i] = temp;
        }
    }

    string removeWord;
    cout << "Enter word to remove: ";
    getline(cin, removeWord);

    Word r(removeWord, "", "");
    vocab.remove(r);

    string searchWord;
    cout << "Enter word to search: ";
    getline(cin, searchWord);

    Word s(searchWord, "", "");
    int index = vocab.search(s);

    if (index != -1)
    {
        words[index].display();
    }
    else
    {
        cout << "Word not found." << endl;
    }

    return 0;
}