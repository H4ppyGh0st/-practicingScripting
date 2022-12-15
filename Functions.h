
#define MAX_LINE_LENGTH 1000
#define BUFFSIZE 256
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>



void printFormat(int seconds) {

    int days = (int)seconds / (24*3600);
    int hours = ( (int)seconds % (24*3600)) / 3600;
    int minutes = (( (int)seconds % (24*3600)) % 3600) / 60;
    int second = (( (int)seconds % (24*3600)) % 3600) % 60;

    printf("%dd %d:%d:%d \n", days, hours, minutes, second);
}


void readUserStat(){
    FILE    *textfile;
    char    line[MAX_LINE_LENGTH];
    int  user, nice, system, idle, x1, x2, x3, x4, x5, x6;
    
    textfile = fopen("/proc/stat", "r");
    if(textfile == NULL)
        return;
  
    fscanf(textfile, "cpu %d %d %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &x1, &x2, &x3, &x4,&x5,&x6);
  
    printf("-TimeIdle:\n");    
    printFormat(idle*100);
    printf("-TimeUser:\n");
    printFormat(user*100);
    printf("-TimeSystem:\n");
    printFormat(system*100);
    
    
    fclose(textfile);
}



void extractUpTimeSimple(){
  
  
  system("echo -UpTime:");  
  system("uptime -p"); 

}


void extractKernelVersion(){

  system("echo -kernel version:"); 
  system("uname -sr");  
}




char* extractWord(char* word , char* tipe, int presition, char* root)

{

    

      FILE *Fd;

      char fitxizen[30],palabra[30],texto[80];

      int i,tmp1,tmp2;
      
      bool go = true; 
      
      char buffer[BUFFSIZE+1];
      

      Fd=fopen(root,"r");

      if (Fd==NULL){

         printf("Error abriendo el fichero");
      }


      while (feof(Fd)==0 && go == true)

      {
            fgets(texto,80,Fd);

            for(i=0;i<strlen(texto);i++)

            {

               if (word[0]==texto[i])

               {

                  tmp1=0;

                  tmp2=i;

                  while ((word[tmp1]==texto[tmp2])&&(tmp2<strlen(texto))&&(tmp1!=strlen(word)))

                  {
                        tmp1++;

                        tmp2++;

                        if (tmp1==strlen(word)){
                        
                           printf("%s\n", tipe); 
                           
                           printf("%s",texto + (sizeof(word) + presition));
                           
        
                           fclose(Fd);
                           
                           return "";
                           
                           go = false; 
                           
                           break;
                           
                           }
                  }
               }
            }
      }

}



void extractCpuType(){

    
    
    extractWord("vendor_id", "-Type: ", 4, "/proc/cpuinfo");
    
}


void extractCpuModel(){
  
  extractWord("model name", "-Model: ", 5, "/proc/cpuinfo");
  
}


void extractChangeContext(){
    
  extractWord("ctxt", "-Changes Of Context: ", -3 , "/proc/stat");
 
  
}

void extractProcess(){

  extractWord("processes", "-processes: ", 2 , "/proc/stat");


}




void extractTimeBooted(){

    FILE    *textfile;
    char    line[MAX_LINE_LENGTH];
    int  user;
    
    textfile = fopen("/proc/stat", "r");
    if(textfile == NULL)
        return;
  
    fscanf(textfile, "btime %d", &user);
  

    printf("-Time when the system was booted:\n");
    printFormat(user*100);
    
    fclose(textfile);
    
    extractWord("btime", "-Time when the system was booted 'original format': ", -2, "/proc/stat");
    
    
}





