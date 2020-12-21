#include "output.cpp"
void menu(int a, int b){
    int luachon;
    do{
        printf("----------------------menu------------------\n");
        printf("1.hoanvi\n");
        printf("2.Tong\n");
        printf("3.Hieu\n");
        printf("4.Tich\n");
        printf("5.Thuong\n");
        printf("6. Luy thua\n");
        printf("7.liet ke USC\n");
        printf("8.UCLN\n");
        printf("9.BCNN\n");
        printf("--------------------------------------------\n");
    // nhap lua chon
        printf("lua chon cua ban?");
        scanf("%d",&luachon);
        switch (luachon)
        {
        // case 1:
        //     hoanVi(a,b);
        //     printf("\n a = %d, b=%d",a,b);
        //     break;
        case 2:
            xuatTong(a,b);
            break;
        case 3:
            xuatHieu(a,b);
            break;
        case 4:
            xuatTich(a,b);
            break;
        case 5:
            xuatThuong(a,b);
            break;
        // case 6:
        //     xuatLuyThua(a,b);
        //     break;
        // case 7:
        //     lietKeUSC(a,b);
        //     break;
        // case 8:
        //     xuatUCLN(a,b);
        //     break;
        // case 9:
        //     xuatBCNN(a,b);
        //     break;
        default:
            printf("lua chon khong hop le!");
            break;
        }
        printf("\nBan co muon thoat ra khong(Nhan phim 0 de thoat!)?");
        scanf("%d",&luachon);
    }while(luachon);
}