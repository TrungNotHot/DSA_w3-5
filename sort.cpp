#include<iostream>
using namespace std;

// Selection Sort
void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
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
void InsertionSort(int a[], int n)
{
    int current;
    for (int i = 1; i < n; i++)
    {
        current = a[i];
        int j = i - 1;
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
int BinarySearch(int* a, int left, int right, int key)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;
        if (*(a + mid) == key)
        {
            return mid;
        }
        if (*(a + mid) > key)
        {
            return BinarySearch(a, left, mid - 1, key);
        }
        return BinarySearch(a, mid + 1, right, key);
    }
}
// Ham sap xep mang voi vi tri da tim kiem
void BinaryInsertionSort(int a[], int n)
{
    int vt, j, key;
    for (int i = 1; i < n; ++i)
    {
        j = i - 1;
        key = a[i];
        vt = BinarySearch(a, 0, j, key);
        while (j >= vt)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Bubble Sort
void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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
int findMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

// Ham sap xep cac phan tu theo thu tu so luong chu so
void CountingSort(int a[], int n, int digit) {
    const int max = 10;
    int A[5];
    int count[max];
    for (int i = 0; i < max; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[(a[i] / digit) % 10]++;
    }
    for (int i = 1; i < max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) 
    {
        A[count[(a[i] / digit) % 10] - 1] = a[i];
        count[(a[i] / digit) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = A[i];
    }
}

// Ham chinh cua Radix Sort
void RadixSort(int a[], int n) {
    int max = findMax(a, n);
    for (int digit = 1; max / digit > 0; digit *= 10)
    {
        CountingSort(a, n, digit);
    }
}

// Flash Sort
void FlashSort(int a[], int n)
{
    int min = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int* A = new int[m];
    for (int i = 0; i < m; i++)
    {
        A[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > a[max])
            max = i;
    }
    if (a[max] == min)
        return;
    double c = (double)(m - 1) / (a[max] - min);
    for (int i = 0; i < n; i++)
    {
        int k = int(c * (a[i] - min));
        ++A[k];
    }
    for (int i = 1; i < m; i++)
    {
        A[i] += A[i - 1];
    }
    Swap(a[max], a[0]);
    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (nmove < n - 1)
    {
        while (j > A[k] - 1)
        {
            j++;
            k = int(c * (a[j] - min));
        }
        flash = a[j];
        if (k < 0) break;
        while (j != A[k])
        {
            k = int(c * (flash - min));
            int hold = a[t = --A[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }
    delete[] A;
    InsertionSort(a, n);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
}

int main()
{
	int a[] = { 10,5,15,25,20 };
	int n = sizeof(a)/sizeof(a[0]);
    //SelectionSort(a, n);
    //InsertionSort(a, n);
    //BinaryInsertionSort(a, n);
    //BubbleSort(a, n);
    //RadixSort(a, n);
    //FlashSort(a, n);
	printArray(a, n);
	return 0;
}
