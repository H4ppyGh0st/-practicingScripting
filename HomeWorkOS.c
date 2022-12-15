#include <stdio.h>
#include<string.h>
#include "Functions.h"

int main(int argc, char *argv[])

{

    if (argc > 1 && strcmp(argv[1], "-s") == 0)
    {
        readUserStat();
        extractChangeContext(); 
        extractProcess();
        extractTimeBooted();

        
    
    }
    
    
    
  
    extractCpuType();
    extractCpuModel(); 
    extractUpTimeSimple();
    extractKernelVersion();
    
   
      
    
   

    return 0;
}
