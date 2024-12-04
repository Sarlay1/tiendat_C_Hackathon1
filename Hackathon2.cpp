#include <stdio.h>

#define MAX 100

int arr[MAX][MAX];
int m, n; // Kich co cua ma tran

int nhap_mang() {
    printf("Nhap so hang: ");
    scanf("%d", &m);
    printf("Nhap so cot: ");
    scanf("%d", &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap phan tu arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    return 0;
}

int in_mang() {
    printf("Ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int bien_va_tich() {
    int tich = 1;
    printf("Cac phan tu tren duong bien: ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                printf("%d ", arr[i][j]);
                tich *= arr[i][j];
            }
        }
    }
    printf("\nTich cac phan tu tren duong bien: %d\n", tich);
    return tich;
}

int duong_cheo_chinh() {
    printf("Cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < m && i < n; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
    return 0;
}

int duong_cheo_phu() {
    printf("Cac phan tu tren duong cheo phu: ");
    for (int i = 0; i < m && i < n; i++) {
        printf("%d ", arr[i][n - i - 1]);
    }
    printf("\n");
    return 0;
}

int sap_xep_cheo_chinh() {
    int size = (m < n) ? m : n;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i][i] > arr[j][j]) {
                int temp = arr[i][i];
                arr[i][i] = arr[j][j];
                arr[j][j] = temp;
            }
        }
    }
    printf("Da sap xep duong cheo chinh theo thu tu tang dan.\n");
    return 0;
}

int tim_kiem() {
    int x, found = 0;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == x) {
                printf("Phan tu %d o vi tri [%d][%d]\n", x, i, j);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong ma tran.\n", x);
    }
    return found;
}

int main() {
    int chon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In cac phan tu tren duong bien va tinh tich\n");
        printf("4. In cac phan tu tren duong cheo chinh\n");
        printf("5. In cac phan tu tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua no\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);

        if (chon == 1) nhap_mang();
        else if (chon == 2) in_mang();
        else if (chon == 3) bien_va_tich();
        else if (chon == 4) duong_cheo_chinh();
        else if (chon == 5) duong_cheo_phu();
        else if (chon == 6) sap_xep_cheo_chinh();
        else if (chon == 7) tim_kiem();
        else if (chon == 8) printf("Thoat chuong trinh\n");
        else printf("Lua chon khong hop le\n");
    } while (chon != 8);
    return 0;
}

