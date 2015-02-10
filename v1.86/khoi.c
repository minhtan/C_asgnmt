// Cac ham thao tac khoi
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "struct_score.h"
/* 
tao khung
gan gia tri cho khung, day va cac khoang trong
*/ 
void khoi_taokhung(int base[LIMIT_H][LIMIT_C]){
     int dh, dc;
     for (dh = 0; dh <= LIMIT_H-1; dh ++){
         for (dc = 0; dc <= LIMIT_C-1; dc ++){
             if ( dc == 0 || dc == LIMIT_C-1 || dh == LIMIT_H-1 )
                base[dh][dc] = 1;
             else 
                  base[dh][dc] = 0; 
         }
     }
}
// in khoi(hang, cot, khung, khoi, vi tri khoi ngang, vi tri khoi doc)
void khoi_in(int h, int c, int base[LIMIT_H][LIMIT_C], int khoi[3][3], int *kn, int *kd){
     int dh, dc;
     for (dh = 0; dh <= 2; dh ++){
         for (dc = 0; dc <= 2; dc ++){
             if ( h == (*kn)+dh && c == (*kd)+dc ){
                if ( khoi[dh][dc] == 1 )
                   printf("*");
                else if ( base[(*kn)+dh][(*kd)+dc] == 1 )
                     printf("*");
                else
                    printf(" ");  
             }
         }
     }                                                      
}
// xoay khoi
void khoi_xoay(int khoi[3][3]){
     int dh, dc;
     int khoitg[3][3];
     for (dh = 0; dh <= 2; dh ++)
         for (dc = 0; dc <=2; dc ++)
             khoitg[dh][dc] = khoi[dh][dc];
     for (dh = 0; dh <= 2; dh ++)
         for (dc = 0; dc <=2; dc ++)
             khoi[dh][dc] = khoitg[2-dc][dh];              
}
/* 
di chuyen khoi (chi so random khoi, khung, khoi, vi tri khoi ngang, vi tri khoi doc)
tra ve 1 de thoat khoi tro choi
*/
int khoi_dichuyen(int rd, int base[LIMIT_H][LIMIT_C], int khoi[3][3], int *kn, int *kd){
     char dich;
     int dh, dc;      
     while( kbhit() ){
            dich = getch();
            if ( dich == 'd' || dich == '3' ){ // sang phai
               for (dh = 2; dh >= 0; dh --){
                   for (dc = 2; dc >= 0; dc --){
                       if ( khoi[dh][dc] == 1 )
                       break;                                    
                   }
                   if ( base[(*kn)+dh][(*kd)+dc+1] == 1 )  
                      break;                             
               }
               if ( dh < 0){
                  (*kd) ++;                                               
               }
               fflush(stdin);
               //return 0;
            }
            else if ( dich == 'a' || dich == '1' ){ // sang trai
                 for (dh = 2; dh >= 0; dh --){
                     for (dc = 0; dc <= 2; dc ++){
                         if ( khoi[dh][dc] == 1 )
                            break;                                    
                     }
                     if ( base[(*kn)+dh][(*kd)+dc-1] == 1 )  
                        break;                             
                 }
                 if ( dh < 0){
                    (*kd) --;                                                
                 }
                 fflush(stdin);
                 //return 0;
            }
            else if ( dich == 's' || dich == '2' && (*kn)+4 < LIMIT_H-1 ){ // xuong 
                 for (dc = 0; dc <= 2; dc ++){  
                     for (dh = 2; dh >= 0; dh --){                            
                         if ( khoi[dh][dc] == 1 )
                            break;                                    
                     }
                     if ( base[(*kn)+dh+1][(*kd)+dc] == 1 &&  
                          (*kd) != 0 && (*kd)+2 != LIMIT_C-1 )  
                          break;                             
                 }
                 if ( dc > 2){
                    (*kn) ++;                                                
                 }
                 fflush(stdin);
                 //return 0;                       
            }
            else if ( dich == 'w' || dich == '5' && rd != 4 ){ // xoay
                 if ( kt_fullsao((*kn), (*kd), (*kn)+2, (*kd)+2, base) ){
                    khoi_xoay(khoi);
                 }
                 fflush(stdin);
                 //return 0;
            }                                                                                  
            else if ( dich == 'q' || dich == '7'){ // quit
                 return 1;                                
            }
            else if ( dich == 'p' || dich == '8'){ // pause
                 while ( 1 ){                         
                       while ( kbhit() ) 
                          dich = getch();
                       if ( dich == 'u' || dich == '9')
                          break;                           
                 }
                 fflush(stdin);
                 //return 0;
            }
     }
     return 0;                                   
}
/*
tao khoi moi
tra ve random de nhan biet khoi
*/
int khoi_taomoi(int khoi[3][3]){
     srand(time(NULL));
     int rd = ( rand() % 7 + rand() ) % 7;
     switch (rd){
            case 1: // khoi L nguoc
                 khoi[0][0] = 0; khoi[0][1] = 1; khoi[0][2] = 0;
                 khoi[1][0] = 0; khoi[1][1] = 1; khoi[1][2] = 0;
                 khoi[2][0] = 1; khoi[2][1] = 1; khoi[2][2] = 0;
                 break;
            case 2: // khoi L
                 khoi[0][0] = 0; khoi[0][1] = 1; khoi[0][2] = 0;
                 khoi[1][0] = 0; khoi[1][1] = 1; khoi[1][2] = 0;
                 khoi[2][0] = 0; khoi[2][1] = 1; khoi[2][2] = 1;
                 break;
            case 3: // khoi I
                 khoi[0][0] = 0; khoi[0][1] = 1; khoi[0][2] = 0;
                 khoi[1][0] = 0; khoi[1][1] = 1; khoi[1][2] = 0;
                 khoi[2][0] = 0; khoi[2][1] = 1; khoi[2][2] = 0;
                 break;
            case 4: // khoi vuong
                 khoi[0][0] = 0; khoi[0][1] = 0; khoi[0][2] = 0;
                 khoi[1][0] = 0; khoi[1][1] = 1; khoi[1][2] = 1;
                 khoi[2][0] = 0; khoi[2][1] = 1; khoi[2][2] = 1;
                 break;
            case 5: // khoi S
                 khoi[0][0] = 1; khoi[0][1] = 0; khoi[0][2] = 0;
                 khoi[1][0] = 1; khoi[1][1] = 1; khoi[1][2] = 0;
                 khoi[2][0] = 0; khoi[2][1] = 1; khoi[2][2] = 0;
                 break;
            case 6: // khoi S nguoc
                 khoi[0][0] = 0; khoi[0][1] = 0; khoi[0][2] = 1;
                 khoi[1][0] = 0; khoi[1][1] = 1; khoi[1][2] = 1;
                 khoi[2][0] = 0; khoi[2][1] = 1; khoi[2][2] = 0;
                 break;
            default: // khoi T
                    khoi[0][0] = 0; khoi[0][1] = 0; khoi[0][2] = 0;
                    khoi[1][0] = 0; khoi[1][1] = 1; khoi[1][2] = 0;
                    khoi[2][0] = 1; khoi[2][1] = 1; khoi[2][2] = 1;
                    break;
     }
     return (rd); 
}
