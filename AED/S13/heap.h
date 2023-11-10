#ifndef INC_2023_II_HEAP_H
#define INC_2023_II_HEAP_H

#include <vector>

using namespace std;

class Heap{
private:
    vector<pair<int,int>> elements;
public:
    Heap() = default;
    ~Heap(){
        elements.clear();
    }

    int size(){
        return elements.size();
    }
    bool is_empty(){
        return  elements.empty();
    }
    void push(pair<int,int> value){
        elements.push_back(value);
        heapify_up(elements.size()-1);
    }
    void pop(){
        swap(elements[0] , elements[elements.size()-1]);
        elements.pop_back();
        heapify_down(0);
    }
    pair<int,int> top(){
        return elements[0];
    }
    void display(){
        for (int i = 0; i < elements.size(); ++i) {
            cout << int(elements[i].second) << " ";
        }
        cout << endl;
    }

private:
    int Parent(int i){
        return (i - 1) / 2;
    }

    int Left(int i){
        return (2 * i + 1);
    }

    int Right(int i){
        return (2 * i + 2);
    }
    void heapify_down(int i){
        int small = i;
        int left = Left(i);
        int right = Right(i);
        if (left < elements.size() && elements[small].second > elements[left].second){
            small = left;
        }
        if (right < elements.size() && elements[small].second >  elements[right].second){
            small = right;
        }
        if (small == right || small == left){
            swap(elements[i] , elements[small]);
            heapify_down(small);
        }
    }
    void heapify_up(int i){
        int parent= Parent(i);
        if (elements[parent].second > elements[i].second){
            swap(elements[i] , elements[parent]);
            heapify_up(parent);
        }
    }
};

#endif //INC_2023_II_HEAP_H
