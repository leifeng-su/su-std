#include<stdio.h>  
#include<string.h>  
  
int main(void)  
{  
    double db[10];  
    for (int i = -4; i < 260; ++i) 
    {  
        memset(db, i, sizeof(db));  
        printf("%4d: %e\n", i, db[0]);  
    }  
    return 0;  
} 
