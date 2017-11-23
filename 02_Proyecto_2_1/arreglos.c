#include <stdio.h>

long main(){
     char charArray[20];
     charArray[0]='A';
     charArray[1]='l';
     charArray[2]='e';
     charArray[3]='a';
     charArray[4]=' ';
     charArray[5]='j';
     charArray[6]='a';
     charArray[7]='c';
     charArray[8]='t';
     charArray[9]='a';
     charArray[10]=' ';
     charArray[11]='e';
     charArray[12]='s';
     charArray[13]='t';
     charArray[14]='\n';
     charArray[15]='\0';
     int i=0;
     while(charArray[i]!='\0'){
         printf("%c",charArray[i]);
         i=i+1;
     }
     char charArr[]="No tengas prisa por repartir juicios \
sobre vida y muerte. Pues muchos vivos merecerian \
estar muertos y muchos muertos merecerian estar \
vivos\n\t\t\t\tGandalf the White\n";
     i=0;
     while(charArr[i]!='\0'){
         printf("%c",charArr[i]);
         i=i+1;
     }
     printf("%s",&charArr[0]);
     char *charPt="\"No hay racismo si no hay otras razas\"\
\n\t\t\t\tAdolf Hitler\n\n";
     printf("%s",charPt);
     //charPt[0]='S';charPt[1]='i';
     //charPt[18]=' ';charPt[19]=' ';
     //printf("%s",charPt);
     
     system("PAUSE");
     return 0;
}//end main()





