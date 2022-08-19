#include<iostream>
using namespace std;

void Heapify(int* a, int i,int n) {
	if (2 * i + 1 >= n) return;
	int p = 2 * i + 1;
	if (p + 1 < n && a[p] < a[p + 1]) p = p + 1;
	if (a[p] > a[i]) {
		swap(a[i], a[p]);
		Heapify(a, p, n);
	}
}

void HeapSort(int* a, int n) {
	for (int i = (n - 1) / 2; i >= 0; i--) {
		Heapify(a, i, n);
	}
	for (int j = n - 1; j > 0; j--) {
		swap(a[0], a[j]);
		Heapify(a, 0, j);
	}
}

int main() {
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
	HeapSort(a, n);
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	delete[] a;
	return 0;
}