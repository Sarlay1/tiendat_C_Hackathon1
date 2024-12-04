#include <stdio.h>

#define Max 100

int arr[Max];
int n = 0;

int la_nguyen_to(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int nhap_mang() {
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    return n;
}

int in_mang() {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

int tim_gia_tri_lon_nhat() {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    printf("Gia tri lon nhat: %d\n", max);
    return max;
}

int in_so_nguyen_to() {
    int co_nguyen_to = 0;
    for (int i = 0; i < n; i++) {
        if (la_nguyen_to(arr[i])) {
            printf("%d ", arr[i]);
            co_nguyen_to = 1;
        }
    }
    if (!co_nguyen_to) printf("Khong co so nguyen to\n");
    else printf("\n");
    return co_nguyen_to;
}

int them_phan_tu() {
    if (n >= Max) return -1;
    int x;
    printf("Nhap gia tri can them: ");
    scanf("%d", &x);
    arr[n++] = x;
    return x;
}

int xoa_phan_tu() {
    int vi_tri;
    printf("Nhap vi tri phan tu can xoa: ");
    scanf("%d", &vi_tri);
    if (vi_tri < 0 || vi_tri >= n) return -1;
    for (int i = vi_tri; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    return vi_tri;
}

int sap_xep_tang_dan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 0;
}

int tim_kiem_phan_tu() {
    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d o vi tri %d\n", x, i);
            return i;
        }
    }
    printf("Phan tu khong ton tai trong mang\n");
    return -1;
}

int main() {
    int chon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In gia tri cac phan tu\n");
        printf("3. In gia tri lon nhat\n");
        printf("4. In cac phan tu la so nguyen to\n");
        printf("5. Them mot phan tu vao mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu\n");
        printf("9. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        if (chon == 1) nhap_mang();
        else if (chon == 2) in_mang();
        else if (chon == 3) tim_gia_tri_lon_nhat();
        else if (chon == 4) in_so_nguyen_to();
        else if (chon == 5) them_phan_tu();
        else if (chon == 6) xoa_phan_tu();
        else if (chon == 7) sap_xep_tang_dan();
        else if (chon == 8) tim_kiem_phan_tu();
        else if (chon == 9) printf("Thoat chuong trinh\n");
        else printf("Lua chon khong hop le\n");
    } while (chon != 9);
    return 0;
}

