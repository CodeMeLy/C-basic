int tinhTong(int a, int b);
int tinhHieu(int a, int b);
int tinhTich(int a, int b);
float tinhThuong(int a, int b);
int tinhTong(int a, int b){
    return a+b;
}
int tinhHieu(int a, int b){
    return a-b;
}
int tinhTich(int a, int b){
    return a*b;
}
float tinhThuong(int a, int b){
    float thuong = 0;
    if(b == 0){
        printf("\n error: b=0");
    }
    else
    {
        thuong = (float)a/b;
    }
    return thuong;
}