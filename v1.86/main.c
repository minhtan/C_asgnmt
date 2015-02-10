/*
  Name: Tetris game 
  Copyright: M.Tan
  Author: M.Tan
  Date: 01/03/13 17:12
  Description: Version 1.86
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
int LIMIT_H = 14, LIMIT_C = 12; // gioi han khung: hang, cot
int main(int argc, char *argv[]){
    system("MODE 32,16"); // chinh kich co man hinh console             
    do{ // bat dau choi 
        int ktq; // bien kiem tra de thoat khi dang choi
        int diem, speed; // diem, toc do chay man hinh
        int base[LIMIT_H][LIMIT_C]; // khung[gioi han hang][gioi han cot]
        int khoi[3][3]; // khoi
        int kn, kd; // vi tri khoi ngang, vi tri khoi doc
        do{      
            diem = 0; 
            speed = 800;
                          
            kt_kiluc();     
            
            menu_chinh(&speed);   
               
            system("cls");        
            khoi_taokhung(base);    
                
            int h, c, rd; // hang, cot, random   
            while ( kt_fullsao(1, 1, 1, LIMIT_C-2, base) ){ // Kiem tra dieu kien gameover        
                rd = khoi_taomoi(khoi);  
                                                
                kd = LIMIT_C/2-2;
                // bat dau in              
                for (kn = 0; kn <= LIMIT_H-3; kn ++){ 
                    for (h = 1; h <= LIMIT_H-1; h ++){
                        for (c = 0; c <= LIMIT_C-1; c ++){                
                            if ( c == 0 || c == LIMIT_C-1 ) // in khung
                               printf("|");
                            else if ( h == LIMIT_H-1 ) // in day
                               printf("-"); 
                            else if ( h >= kn && h <= kn+2 && c >= kd && c <= kd+2) // in khoi
                               khoi_in(h, c, base, khoi, &kn, &kd);                            
                            else if ( base[h][c] == 1 ) // in sao
                               printf("*");            
                            else if ( base[h][c] == 0 ) // in space   
                               printf(" ");                                            
                        }
                        printf("\n");
                    }
                    printf("\nDiem hien tai: %d", diem); 
                                
                    ktq = khoi_dichuyen(rd, base, khoi, &kn, &kd); 
                    if (ktq == 1)          
                       break;
                                
                    sleep(speed);
                    system("cls");    
                    if ( kt_cham(base, khoi, &kn, &kd) )
                       break;                                 
                }                                    
                if (ktq == 1)          
                   break;
                   
                diem = kt_an(diem, &speed, base); 
                
            }    
               
        }while (ktq != 0);  
              
        printf("\nGAME OVER!\n\n");    
        system("PAUSE");  
            
        kt_highscore(diem);   
        
    }while ( kt_choitiep() );
    return 0;
}
