#include <iostream>
#include <vector>
using namespace std;

enum ears{small, medium, large};

class maimuna{
    ears e;
public:
    maimuna(): e(medium){};
    maimuna(ears e1): e(e1) {}
    bool operator == (maimuna& m){
        return (e == m.e);
    }
};

template<typename T>

class Set{
    T* elements;
    int size;
public:
    Set() : size(0), elements(nullptr){};
    void add(T e) {
        if (size == 0) elements = new T[1];
        if (contains(e)) return;
        size++;
        T* elements1 = new T[size];
        for (int i=0; i<size-1; i++){
            elements1[i] = elements[i];
        }
        elements1[size-1] = e;
        delete[] elements;
        elements = elements1;
    }
    bool contains(T n){
        for(int i=0;i<size; i++){
            if(n == elements[i]) return true;
        }
        return false;
    }
    int get_size() {return size;}
};


int main(){
    Set<maimuna> s;
    maimuna m1(small), m2(large), m3;
    s.add(m1);
    s.add(m2);
    s.add(m3);
    cout<<s.get_size()<<endl;
    return 0;
}
 