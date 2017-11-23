#include "funrecursiva.h"

 typo factorial(typo n){
   if(n==1){
     return 1;
   }else{
     return n*factorial(n-1);
   }
 }

 typo nPm(typo nObj,typo dmNm){
   typo nu=factorial(nObj);
   typo de=factorial(nObj-dmNm);
   return nu/de;
 }
