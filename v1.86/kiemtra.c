// Cac ham kiem tra
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "struct_score.h"
/* 
kt_fullsao(bat dau ngang, bat dau doc, ket thuc ngang, ket thuc doc, khung)
kiem tra 1 hoac nhieu hang co chua day sao hay khong,
tra ve 1 neu tat ca cac hang chua day sao, 0 neu co khoang trong
*/
int kt_fullsao(int bdn, int bdd, int lmn, int lmd, int base[LIMIT_H][LIMIT_C]){
    int dh, dc;
    for (dh = bdn; dh <= lmn; dh ++){
        for (dc = bdd; dc <= lmd; dc ++)
            if ( base[dh][dc] == 1 )
               break;
    }
    if (dh > lmn && dc > lmd)
       return(1);
    else
        return(0);   
}
/*
kiem tra an(diem, speed, khung)
tra ve diem, tang speed theo diem tuong ung
*/
int kt_an(int diem, int *speed, int base[LIMIT_H][LIMIT_C]){
     int dh, dc, ah;
     for (dh = LIMIT_H-2; dh >= 1; dh --){
        for (dc = 1; dc <= LIMIT_C-2; dc ++)
            if (base[dh][dc] != 1)
               break;
        if (dc > LIMIT_C-2){
              for (ah = dh; ah > 1; ah --){
                  for (dc = 1; dc <= LIMIT_C-2; dc ++)
                      base[ah][dc] = base[ah-1][dc];                     
              }
              diem += 10;
              *speed -= 10;
              dh ++;             
        }
    }
    return(diem);    
}
/* 
kiem tra va cham(khung, khoi, vi tri khoi ngang, vi tri khoi doc)
tra ve 1 neu cham day, 0 neu khong cham
*/
int kt_cham(int base[LIMIT_H][LIMIT_C], int khoi[3][3], int *kn, int *kd){
    int dh, dc;           
    if ( khoi[2][0] == 1 && base[(*kn)+3][(*kd)] == 1 || 
       khoi[2][1] == 1 && base[(*kn)+3][(*kd)+1] == 1 || 
       khoi[2][2] == 1 && base[(*kn)+3][(*kd)+2] == 1 ||
       khoi[1][0] == 1 && base[(*kn)+2][(*kd)] == 1 ||
       khoi[1][1] == 1 && base[(*kn)+2][(*kd)+1] == 1 ||
       khoi[1][2] == 1 && base[(*kn)+2][(*kd)+2] == 1 ||
       khoi[0][0] == 1 && base[(*kn)+1][(*kd)] == 1 ||
       khoi[0][1] == 1 && base[(*kn)+1][(*kd)+1] == 1 ||
       khoi[0][2] == 1 && base[(*kn)+1][(*kd)+2] == 1 ){
       for (dh = 0; dh <= 2; dh ++)
           for (dc = 0; dc <= 2; dc ++) 
               if ( base[(*kn)+dh][(*kd)+dc] != 1 )
                  base[(*kn)+dh][(*kd)+dc] = khoi [dh][dc];
       return (1);        
    }
    else 
         return (0);
}
// kiem tra - tao file ki luc
void kt_kiluc(){
     struct score kl;
     FILE *tt;
     if ( (tt = fopen("highscore.tan", "r")) == NULL ){
          kl.diem = 0;
          strcpy(kl.ten, "none");
          tt = fopen("highscore.tan", "w");
             fwrite(&kl, sizeof(struct score), 1, tt);
          fclose(tt);
     }
}
// kiem tra ki luc
void kt_highscore(int diem){
     struct score kl;
     FILE *tt;
     tt = fopen("highscore.tan", "r+w");
        fread (&kl, sizeof(struct score), 1, tt);
        if ( diem != 0 && diem > kl.diem ){
           system("cls");
           kl.diem = diem;                          
           printf("\nNEW HIGH SCORE!\nNhap ten: ");
           gets (kl.ten);
           rewind(tt);
           fwrite (&kl, sizeof(struct score), 1, tt);
        }
     fclose(tt);
}
/*
kiem tra choi tiep
tra ve 1 de tiep tuc, 0 de thoat
*/
int kt_choitiep(){
    char lc;
    while ( lc < 49 || lc > 50 ){
          system("cls");
          printf("\nTiep tuc ?");
          printf("\n1 - Choi tiep\n2 - Nghi");
          printf("\nLua chon: ");          
          scanf("%c", &lc);
          fflush(stdin);
          if ( lc == '1' ){
             return 1;             
          }
          if ( lc == '2' )
             return 0;
    } 
}
