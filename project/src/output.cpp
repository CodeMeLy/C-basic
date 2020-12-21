#include "calculation.cpp"
void xuatTong(int a, int b);
void xuatHieu(int a, int b);
void xuatTich(int a, int b);
void xuatThuong(int a, int b);
void xuatTong(int a, int b){
    int tong = tinhTong(a, b);
    printf("\n%d+%d = %d",a,b,tong);
}
void xuatHieu(int a, int b){
    int hieu = tinhHieu(a, b);
    printf("\n%d-%d = %d",a,b,hieu);
}
void xuatTich(int a, int b){
    int tich = tinhTich(a, b);
    printf("\n%d*%d = %d",a,b,tich);
}
void xuatThuong(int a, int b){
    int thuong = tinhThuong(a, b);
    printf("\n%d/%d = %d",a,b,thuong);
}