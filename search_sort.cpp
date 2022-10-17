#include<iostream>
#include<time.h>
#include<fstream>
#include<string>
using namespace std;
//MERGE SORT
void Merge(long* a, long from, long mid, long to){
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
void MergeSort(long* a, long from, long to){
    if(from<to){
        long mid=(from+to)/2;
        MergeSort(a,from,mid);
        MergeSort(a,mid+1,to);
        Merge(a,from, mid, to);
    }
    return ;
}

void QuickSort(long* arr, long first, long last){
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
    if(first < j) QuickSort(arr, first, j);
    if(i < last) QuickSort(arr, i, last);
    return ;
}

void ShellSort(long* arr, long l, long r){
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

void ShakerSort(long* arr, long l, long r){
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

void Swap(long& a, long& b)
{
    long temp = a;
    a = b;
    b = temp;
}

void SelectionSort(long a[], long n)
{
    for (long i = 0; i < n - 1; i++)
    {
        long min = i;
        for (long j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            Swap(a[min], a[i]);
        }
    }
}
// Insertion Sort
void InsertionSort(long a[], long n)
{
    long current;
    for (long i = 1; i < n; i++)
    {
        current = a[i];
        long j = i - 1;
        while (j >= 0 && a[j] > current)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = current;
    }
}

// Binary Insertion Sort
// Ham tim kiem nhi phan
// long BinarySearch(long* a, long left, long right, long key)
// {
//     if (right >= left)
//     {
//         long mid = (left + right) / 2;
//         if (*(a + mid) == key)
//         {
//             return mid;
//         }
//         if (*(a + mid) > key)
//         {
//             return BinarySearch(a, left, mid - 1, key);
//         }
//         return BinarySearch(a, mid + 1, right, key);
//     }
// }
// Ham sap xep mang voi vi tri da tim kiem
// void BinaryInsertionSort(long a[], long n)
// {
//     long vt, j, key;
//     for (long i = 1; i < n; ++i)
//     {
//         j = i - 1;
//         key = a[i];
//         vt = BinarySearch(a, 0, j, key);
//         while (j >= vt)
//         {
//             a[j + 1] = a[j];
//             j = j - 1;
//         }
//         a[j + 1] = key;
//     }
// }

// Bubble Sort
void BubbleSort(long a[], long n)
{
    for (long i = 0; i < n - 1; i++)
    {
        for (long j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(a[j], a[j + 1]);
            }
        }
    }
}

// Radix Sort
// Tim phan tu lon nhat trong mang
long findMax(long a[], long n) {
    long max = a[0];
    for (long i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
// Ham sap xep cac phan tu theo thu tu so luong chu so
void CountSort(long arr[], long n, long exp)
{
    long *output= new long[n];
    long i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
// Ham chinh cua Radix Sort
void RadixSort(long a[], long n) {
    long max = findMax(a, n);
    for (long digit = 1; max / digit > 0; digit *= 10)
    {
        CountSort(a, n, digit);
    }
}

void FlashSort(long a[], long n)
{
    long min = a[0];
    long max = 0;
    long m = long(0.45 * n);
    long* A = new long[m];
    for (long i = 0; i < m; i++)
    {
        A[i] = 0;
    }
    for (long i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > a[max])
            max = i;
    }
    if (a[max] == min)
        return;
    double c = (double)(m - 1) / (a[max] - min);
    for (long i = 0; i < n; i++)
    {
        long k = long(c * (a[i] - min));
        ++A[k];
    }
    for (long i = 1; i < m; i++)
    {
        A[i] += A[i - 1];
    }
    Swap(a[max], a[0]);
    long nmove = 0;
    long j = 0;
    long k = m - 1;
    long t = 0;
    long flash;
    while (nmove < n - 1)
    {
        while (j > A[k] - 1)
        {
            j++;
            k = long(c * (a[j] - min));
        }
        flash = a[j];
        if (k < 0) break;
        while (j != A[k])
        {
            k = long(c * (flash - min));
            long hold = a[t = --A[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }
    delete[] A;
    InsertionSort(a, n);
}

//Cai Dat
long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}
long** createData(long n){
    //random
    long** data=new long*[3];
    data[0]= new long[n];
    for(long i=0; i<n; i++){
        data[0][i]= Rand(0,n);
    }

    //sorted
    data[1]= new long[n];
    for(long i=0; i<n; i++){
        data[1][i]=data[0][i];
    }
    QuickSort(data[1],0,n-1);

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
void copyData(long* data,long*& clone,long size){
    clone=new long [size];
    for(int i=0; i<size; i++){
        clone[i]=data[i];
    }
}
void saveAfterSort(long* data,const char* size,const char* state){
    clock_t start, end;
    long* clone;
    const char* NameOfSort[]={"SelectionSort","InsertionSort","BinaryInsertionSort","BubbleSort","ShakerSort",
     "ShellSort","HeapSort","MergeSort","QuickSort","CountingSort","RadixSort","FlashSort"};
    double timeUsed[12]={0};

    copyData(data,clone,stol(size));
    start=clock();
    SelectionSort(clone,stol(size));
    end=clock();
    timeUsed[0]=(double)(end-start) / CLOCKS_PER_SEC;
    writeToTXT(clone,timeUsed[0],NameOfSort[0],size,state);
    delete clone;

    copyData(data,clone,stol(size));
    start=clock();
    InsertionSort(clone,stol(size));
    end=clock();
    timeUsed[1]=(double)(end-start) / CLOCKS_PER_SEC;
    writeToTXT(clone,timeUsed[1],NameOfSort[1],size,state);
    delete clone;

    // start=clock();
    // BinaryInsertionSort(data,stol(size));
    // end=clock();
    // timeUsed[2]=(double)(end-start) / CLOCKS_PER_SEC;

    copyData(data,clone,stol(size));
    start=clock();
    BubbleSort(clone,stol(size));
    end=clock();
    timeUsed[3]=(double)(end-start) / CLOCKS_PER_SEC;
    writeToTXT(clone,timeUsed[3],NameOfSort[3],size,state);
    delete clone;

    copyData(data,clone,stol(size));
    start=clock();
    ShakerSort(clone,0,stol(size)-1);
    end=clock();
    timeUsed[4]=(double)(end-start) / CLOCKS_PER_SEC;
    writeToTXT(clone,timeUsed[4],NameOfSort[4],size,state);
    delete clone;

    copyData(data,clone,stol(size));
    start=clock();
    ShellSort(clone,0,stol(size)-1);
    end=clock();
    timeUsed[5]=(double)(end-start) / CLOCKS_PER_SEC;
    writeToTXT(clone,timeUsed[5],NameOfSort[5],size,state);
    delete clone;

    // start=clock();
    // HeapSort(data,0,stol(size)-1);
    // end=clock();
    //timeUsed[6]=(double)(end-start) / CLOCKS_PER_SEC;

    copyData(data,clone,stol(size));
    start=clock();
    MergeSort(clone, 0,stol(size)-1);
    end=clock();
    timeUsed[7]=(double)(end-start) / CLOCKS_PER_SEC;
    writeToTXT(clone,timeUsed[7],NameOfSort[7],size,state);
    delete clone;

    copyData(data,clone,stol(size));
    start=clock();
    QuickSort(clone,0,stol(size)-1);
    end=clock();
    timeUsed[8]=(double)(end-start) / CLOCKS_PER_SEC;
    writeToTXT(clone,timeUsed[8],NameOfSort[8],size,state);
    delete clone;

    // start=clock();
    // CountingSort(data,0,stol(size)-1);
    // end=clock();
    // timeUsed[9]=(double)(end-start) / CLOCKS_PER_SEC;

    copyData(data,clone,stol(size));
    start=clock();
    RadixSort(clone,stol(size));
    end=clock();
    timeUsed[10]=(double)(end-start) / CLOCKS_PER_SEC;
    writeToTXT(clone,timeUsed[10],NameOfSort[10],size,state);
    delete clone;

    copyData(data,clone,stol(size));
    start=clock();
    FlashSort(clone, stol(size));
    end=clock();
    timeUsed[11]=(double)(end-start) / CLOCKS_PER_SEC;
    writeToTXT(clone,timeUsed[11],NameOfSort[11],size,state);
    delete clone;
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