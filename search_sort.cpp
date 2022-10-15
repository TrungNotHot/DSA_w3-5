#include<iostream>
#include<time.h>
#include<fstream>
#include<string>
using namespace std;
void merge(long* a, long from, long mid, long to){
    long first1=from, last1=mid;
    long first2=mid+1,last2=to;
    long index=from;
    long* aux=new long[to+1];
    while(first1<=last1 && first2<=last2){
        if(a[first1]<=a[first2]){
            aux[index++]=a[first1++];
        }
        else{
            aux[index++]=a[first2++];
        }
    }
    while(first1<=last1){
        aux[index++]=a[first1++];
    }
    while(first2<=last2){
        aux[index++]=a[first2++];
    }
    for(long i=from; i<=to;i++){
        a[i]=aux[i];
    }
    delete aux;
}
void mergeSort(long* a, long from, long to){
    if(from<to){
        long mid=(from+to)/2;
        mergeSort(a,from,mid);
        mergeSort(a,mid+1,to);
        merge(a,from, mid, to);
    }
    return ;
}
void quickSort(long* arr, long first, long last){
    long pivot=arr[(first+last)/2];
    long i=first, j=last;
    while(i<=j){
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<=j){
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }
    if(first < j) quickSort(arr, first, j);
    if(i < last) quickSort(arr, i, last);
    return ;
}
void shellSort(long* arr, long l, long r){
    for(long gap=(r-l+1)/2; gap>0; gap/=2){
        for(long i=gap; i<=r; i+=1){
            long temp=arr[i];
            long j;
            for(j=i; j>=gap && arr[j-gap]>temp; j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
    return;
}
void shakerSort(long* arr, long l, long r){
    long left=l;
    long right=r;
    long k=0;
    for(long i=left;i<right; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
            k=i;
        }
    }
    right=k;
    for(long i=right; i>left; i--){
        if(arr[i]<arr[i-1]){
            swap(arr[i], arr[i - 1]);
			k = i;
        }
    }
    left=k;
}
void sort( long* arr, long n){
    for(long i=0; i<n-1 ;i++){
        for( long j=i+1; j<n; j++){
            if(arr[i]>arr[j]) swap(arr[i], arr[j]);
        }
    }
}
long** createData(long n){
    //random
    long** data=new long*[3];
    data[0]= new long[n];
    for(long i=0; i<n; i++){
        data[0][i]=rand() % n;
    }

    //sorted
    data[1]= new long[n];
    for(long i=0; i<n; i++){
        data[1][i]=data[0][i];
    }
    quickSort(data[1],0,n-1);

    //reversed
    data[2]= new long[n];
    for(long i=0; i<n; i++){
        data[2][i]=data[1][n-1-i];
    }

    return data;
}
void writeToTXT(long* data, double timeUsed,const char* str,const char* size,const char* state){
    ofstream fout;

    //Format string c
    char path[200];
    snprintf(path,200,"C:\\Users\\trung\\OneDrive - VNU-HCMUS\\Attachments\\LapTrinh\\Nam2-1\\TH CTDL\\DSA_w3-5\\FILE\\%s_%s_%s.txt",str,state,size);

    fout.open(path);
    for(long i =0; i<stol(size); i++){
        fout<<data[i]<<" ";
    }
    fout<<endl;
    fout<<timeUsed*1000;
    fout.close();
}
void saveAfterSort(long* data,const char* size,const char* state){
    clock_t start, end;
    double timeUsed;
    const char* NameOfSort[]={"selectionSort","insertionSort","binaryInsertionSort","bubbleSort","shakerSort",
     "shellSort","heapSort","mergeSort","quickSort","countingSort","radixSort","flashSort"};
    start=clock();
    mergeSort(data,0,stol(size)-1);
    end=clock();
    timeUsed=(double)(end-start) / CLOCKS_PER_SEC;

    writeToTXT(data,timeUsed,NameOfSort[0],size,state);
}
void process(){
    long Size_set[]={1000,3000,10000,30000,100000};
    const char* state_set[]={"sorted","reversed","random"};

    for(long size=0; size<5; size++){
        long** data=createData(Size_set[size]);

        //Chuyển long sang const char*
        string s = to_string(Size_set[size]);
        char const* pchar = s.c_str();

        for(long state=0; state<3; state++){
            if(state_set[state]=="sorted"){
                saveAfterSort(data[1],pchar,state_set[state]);
            }

            if(state_set[state]=="reversed"){
                saveAfterSort(data[2],pchar,state_set[state]);
            }

            if(state_set[state]=="random"){
                saveAfterSort(data[0],pchar,state_set[state]);
            }
        }
    }
}
int main(){
    process();
    cout<<"end";
    return 0;
}