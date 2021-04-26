#include <stdio.h> 
#include <string.h>

int i, pilih, pmbyr, kmbl, jmlh, no, tmbh, akhir, kmbl1;
int total[30]; 
int ttlhrg=0, ukuran=0;
int hrg[4]={12000,10000,6000,9000};
char p[5];

int main ()
{  
    awal:   //label awal
    printf("====================================\n");
    printf("|                                   |\n");
    printf("|    Selamat Datang di Kafe 86 !    |\n");
    printf("|                                   |\n");
    printf("====================================\n\n");

    printf("1. Menu Kafe\n");
    printf("2. Pesan Menu\n");
    printf("3. Keluar dari Kafe\n");
    
    printf("\nMasukkan Pilihan Anda: ");
    scanf("%i", &pilih);

    //output untuk tiap pilihan user
    switch(pilih)   
    {
        //pilihan 1. Menu Kafe
        case 1:
        printf("========================================\n");
        printf("|                                       |\n");
        printf("|              Menu Kafe 86             |\n");
        printf("|                                       |\n");
        printf("========================================\n");
        printf("|Menu :                          Harga: |\n");
        printf("|1. Espresso                      12K   |\n");
        printf("|2. Coklat Hangat                 10K   |\n");
        printf("|3. Kentang Goreng                6K    |\n");
        printf("|4. Pancake                       9k    |\n");
        printf("========================================\n");
        printf("\n");
        goto awal;
        
        //pilihan 2. Pesan Menu
        case 2:
        menu:   //label menu
        printf("\nMasukkan nomor menu: ");
        scanf("%i", &no);

        //mencetak perintah sesuai input nomor menu
        if(no<1||no>4){                
            printf("Harap Masukkan Nomor Menu yang Sesuai!\n");
            goto menu;
        }
        else{
            printf("Masukkan Jumlah Menu: ");
            scanf("%i", &jmlh);
            total[i]=hrg[no-1]*jmlh;
            i++;
            ukuran=ukuran+1;
            goto lain;
        }
        
        bayar:  //label bayar
        for(i=0;i<ukuran;i++){
            ttlhrg=ttlhrg+total[i];
        }
        printf("\nTotal Harga:Rp. %i", ttlhrg);
        printf("\nMasukkan Jumlah Uang Anda:Rp. ");
        scanf("%i", &pmbyr);

        //menghitung uang kembali
        kmbl=pmbyr-ttlhrg;
        if(kmbl>=0){
            printf("\nKembalian Anda:Rp. %i\n", kmbl);
            printf("Terima Kasih Telah Membeli!");
            break;
        }
        else{
            kmbl1=kmbl*-1;
            printf("\nUang Anda Kurang:Rp. %i", kmbl1);
            goto tambah;
        }

        tambah:   //label tambah
        //untuk menambah uang pembayaran yang kurang
        printf("\nMasukkan Uang Tambahan:Rp. ");
        scanf("%i", &tmbh);
        akhir=tmbh-kmbl1;
        if(akhir>=0){
            printf("Kembalian Anda:Rp. %i\n", akhir);
            printf("Terima Kasih Telah Membeli!");
            break;
        }
        else{
            printf("Uang Tambahan Tidak Mencukupi!\n");
            goto tambah;
        }

        lain:   //label lain (Jika user ingin memesan menu lain)
        printf("\nApakah Anda Ingin Memesan Menu Lain? (y/t): ");
        scanf("%s", p); 
        if(strcmp(p,"y")==0||strcmp(p,"Y")==0){
            goto menu;          
        }
        else if(strcmp(p,"t")==0||strcmp(p,"T")==0){
            goto bayar;
        }
        else{
            printf("Masukkan pilihan yang benar...\n");
            goto lain;             
        }

        //pilihan 3. Keluar
        case 3:
        printf("Terima Kasih Telah Membeli!");
    }

    return 0;
}