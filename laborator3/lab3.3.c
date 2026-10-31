#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int* nums, int n, int i) {
    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest])
            largest = left;
        if (right < n && nums[right] > nums[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&nums[i], &nums[largest]);
        i = largest;
    }
}

void sortArray(int* nums, int n) {
   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(nums, n, i);

    for (int end = n - 1; end > 0; end--) {
        swap(&nums[0], &nums[end]);
        heapify(nums, end, 0);
    }
}

int main() {
    static int nums[50000];
    int n;

    printf("Introdu n: ");
    scanf("%d", &n);

    printf("Introdu elementele:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    sortArray(nums, n);

    printf("Rezultat: ");
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}