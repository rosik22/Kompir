#include <iostream>
using namespace std;

void qSort(int a[], int from, int to){
    int j = from, k = to, mid = a[(from+to)/2], buf;
    cout<<"Копие, граници на дял от "<<from<<" до "<<to<<endl;
    cout<<"Еталон: "<<mid<<endl;
    do{
        while(a[j] < mid) j++;
    
        while(a[k] > mid) k--;
    
        if(j <= k){
            cout<<"Размяна на "<<a[j]<<" и "<<a[k]<<endl;
            buf = a[j];
            a[j] = a[k];
            a[k] = buf;
            j++; k--;
        }
    }while(j <= k);
    cout<<"Край на размените"<<endl;

    cout<<"Потъване наляво"<<endl;
    if(k==from) cout<<"Дъно. Изплуване"<<endl;
    else if(k > from) qSort(a, from, k);

    cout<<"Потъване надясно"<<endl;
    if(j==to) cout<<"Дъно. Изплуване"<<endl;
    if(j < to) qSort(a, j, to);
}

int main(){
    int arr[7] = {1,4,3,8,9,3,12};
    cout<<"Начално състояние на масива: ";
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    qSort(arr,0,6);
    
    cout<<endl<<"Крайно състояние на масива: ";
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}