#include <bits/stdc++.h>
#include "n2_bubble_puzurek.cpp"
#include "n2_gnome_gnomia.cpp"
#include "n2_selection_vibor.cpp"
#include "nlogn_heap_kucha.cpp"
#include "nlogn_merge_sliyanie.cpp"
#include "nlogn_quick_bistraya.cpp"

using namespace std;


int rand_uns(int min_, int max_) {
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    static mt19937 e(seed);
    uniform_int_distribution<int> d(min_, max_);
return d(e);
}

struct Arr{
int *data;
int siz;
};

ostream& operator<<(ostream& out, Arr arrr){
    for(int i = 0; i < arrr.siz; ++i){
        out << arrr.data[i] << ' ';
    }
    out << endl;
}

void arrShuffle(Arr *arr){
    vector<int> tmp(arr->siz, 0);
    for(int i = 0; i < arr->siz; ++i)
        tmp[i] = arr->data[i];
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 g(seed);

    shuffle(tmp.begin(), tmp.end(), g);

    for(int i = 0; i < arr->siz; ++i)
        arr->data[i] = tmp[i];
}

void sortOut(int maxSize, int turns, void Sort(int*, int), string name){
    Arr arr;
    arr.siz = 10;
    arr.data = new int[arr.siz];
    int delta = 10;
    long long time = 0;
    vector<pair<long long, long long>> logs;
    ofstream file;
    file.open("logs.txt", ios::app);

    for(; arr.siz <= maxSize ;){
        for(int i = 0; i < arr.siz; ++i) arr.data[i] = rand_uns(0, 1000*1000);

        for(int i = 0; i < turns; ++i){
            auto start_time = chrono::steady_clock::now();
            Sort(arr.data, arr.siz);
            auto end_time = chrono::steady_clock::now();
            auto period = end_time - start_time;
            time += period.count();
            arrShuffle(&arr);
        }
        logs.push_back(make_pair(time/turns, arr.siz));
        time = 0;

        if(arr.siz % (delta * 10) == 0) delta *= 10;
        arr.siz += delta;
        arr.data = new int[arr.siz];
        if(arr.siz > 10000) turns = 100;
    }

    file << name << endl;
    file << '[';
    for(auto log: logs) file << log.first << ", ";
    file << ']' << endl;

    file << '[';
    for(auto log: logs) file << log.second << ", ";
    file << ']' << endl;

    file.close();
}

int main()
{
    sortOut(1000, 1000, bubble, "Bubble Sort");
    sortOut(1000, 1000, gnom, "Gnome Sort");
    sortOut(1000, 1000, selection, "Selection Sort");
    sortOut(1000, 1000, heapSort, "Heap Sort");
    sortOut(1000, 1000, mergeSort, "Merge Sort");
    sortOut(1000, 1000, quickSort, "Quick Sort");

    return 0;
}


