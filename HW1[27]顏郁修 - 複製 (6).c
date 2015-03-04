#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(void){
	int sum = 0, i, num, flag=1, ch;
    char SID[11];
    char english[27]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int mapEnglish[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    
    do{
    	printf("1.判斷身分證真偽\n2.隨機產生身分證\n3.退出\n");
    	scanf(" %d", &num);
    	
		switch(num){
    		case 1:
    			printf("請輸入身分證號:");
    			scanf(" %s",SID);
    			
    			for(i=0;i<26;i++){
    				if(SID[0] == english[i]||SID[0] == english[i]+32){
    					ch = mapEnglish[i];
    				}
    			}
    			sum = (ch/10)+((ch%10)*9);
    			
    			for(i=1;i<9;i++){
    				sum += (SID[i]-48) * (9-i);
    			}
    			sum += SID[9]-48;
    			
    			if(sum % 10 == 0){
    				printf("real\n");
    			}
    			else{
    				printf("fake,請將最後一碼改為%d\n",(10-(sum-(SID[9]-48))%10)%10);
    			}
    			break;
    		
			case 2:
				srand(time(NULL));
                SID[0] = (rand()%26) + 65;
                
				for(i=1;i<=8;i++){
                	SID[i] = rand() % 10 + 48;
                }
                
                for(i=0;i<26;i++){
                	if(SID[0] == english[i]||SID[0] == english[i]+32){
                		ch = mapEnglish[i];
                	}
                }
				sum = (ch/10)+(ch%10)*9;
                
                for(i=1;i<=8;i++){
                	sum += (SID[i]-48)*(9-i);
                }
                
                SID[9] = (10- (sum % 10)) + 48;
                SID[10] = '\0';
                
                printf("%s\n",SID);
                
                break;
                
                default:
                	flag=0;
    	}
    }while(flag);
    
    system("pause");
    return 0;
} 
