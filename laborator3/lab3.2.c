#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n) {
    int i = m - 1;     
    int j = n - 1;     
    int k = m + n - 1;  

    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
}

int main() {
    int m, n;

    printf("Introdu m: ");
    scanf("%d", &m);
    printf("Introdu n: ");
    scanf("%d", &n);

    int nums1[400] = {0};
    int nums2[200];

    printf("Introdu cele %d elemente din nums1:\n", m);
    for (int i = 0; i < m; i++)
        scanf("%d", &nums1[i]);

    printf("Introdu cele %d elemente din nums2:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums2[i]);

    merge(nums1, m, nums2, n);

    printf("Rezultat: ");
    for (int i = 0; i < m + n; i++)
        printf("%d ", nums1[i]);
    printf("\n");

    return 0;
}