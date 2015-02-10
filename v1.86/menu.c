// Cac ham menu
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "struct_score.h"
// menu chinh
int menu_chinh(int *speed){
     char lc;
     while ( lc < 49 || lc > 53){
         system("cls");  
         printf("\n   --- Tetris by M.Tan :D ---\n");
         printf("\nMenu:");
         printf("\n1 - Huong dan");
         printf("\n2 - Bat dau choi");
         printf("\n3 - Tuy chinh");
         printf("\n4 - Ki luc");
         printf("\n5 - Thoat");
         printf("\nLua chon: ");
         scanf("%c", &lc);
         fflush(stdin);
         if (lc == '1')
            lc = menu_huongdan();
         if (lc == '2')
            return(0);
         if (lc == '3')
            lc = menu_option(speed);          
         if (lc == '4')
            lc = menu_highscore(); 
         if (lc == '5')
            exit(0);
     }
}
// menu huong dan
int menu_huongdan(){
     system("cls");
     printf("\nAn 'a' hoac '1' de sang trai,");
     printf("\n   'd' hoac '3' de sang phai,");
     printf("\n   's' hoac '2' de xuong,");
     printf("\n   'w' hoac '5' de xoay,");
     printf("\n   'p' hoac '8' de tam dung,");
     printf("\n   'u' hoac '9' de tiep tuc,");
     printf("\n   'q' hoac '7' de quay lai.");              
     printf("\n\n");
     system("PAUSE");
     return 0;
}
// menu tuy chinh
int menu_option(int *speed){
     char lc;
     while ( lc < 49 || lc > 53){
         system("cls");
         printf("\nChon do kho:");
         printf("\n1 - Rat de");
         printf("\n2 - De");
         printf("\n3 - Kho");
         printf("\n4 - Rat kho");
         printf("\n5 - Quay lai");
         printf("\nLua chon: ");
         scanf("%c", &lc); 
         fflush(stdin);
         if (lc == '1'){
            *speed = 800;
            printf("\nDa chon muc do: Rat de\n\n");
            system("PAUSE");
            break;
         }
         if (lc == '2'){
            *speed = 700;
            printf("\nDa chon muc do: De\n\n");
            system("PAUSE");
            break;
         }
         if (lc == '3'){
            *speed = 500;
            printf("\nDa chon muc do: Kho\n\n");
            system("PAUSE");
            break;
         }
         if (lc == '4'){
            *speed = 400;
            printf("\nDa chon muc do: Rat kho\n\n");
            system("PAUSE");
            break;
         }
         if (lc == '5')
            break;
     }
     return 0;
}
// menu ki luc
int menu_highscore(){
     struct score kl;
     system("cls");
     FILE *tt;
     tt = fopen("highscore.tan", "r");
        fread (&kl, sizeof(struct score), 1, tt);
        printf("\nKi luc hien tai:");
        printf("\nTen  : %s", kl.ten);
        printf("\nDiem : %d", kl.diem);
     fclose(tt);
     printf("\n\n");
     system("PAUSE");
     return 0;
}
