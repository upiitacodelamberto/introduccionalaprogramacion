#include <stdio.h>

typedef 
struct myfloat{
  unsigned mantisa	:23;
  unsigned power	:8;
  unsigned sign		:1;
}MyFloat;
struct four_chars{
  unsigned char abcd0;
  unsigned char abcd1;
  unsigned char abcd2;
  unsigned char abcd3;
};
union UFloat{
  MyFloat MyF;	/* 4 bytes */
  struct four_chars FourChars;	/* 4 bytes */
};

/**
 * Imprime los bits de un int
 */
void show_bits(int);

long main(){
  int intA=10;
  show_bits(intA);
  printf("\n");
  float floatA=7.5;
  intA=*((int*)(&floatA));
  show_bits(intA);
  printf("\n");
  MyFloat MyF;
  printf("sizeof(MyF)=%d\n",sizeof(MyF));	/* sizeof(MyF)=4 */
  printf("sizeof(unsigned char)=%d\n",sizeof(unsigned char));/* sizeof(uchar)=1 */
  printf("sizeof(struct four_chars)=%d\n",sizeof(struct four_chars));/* sizeof(fchars)=4 */
  MyF=*((MyFloat*)(&floatA));
  union UFloat union_UFloat;
  union_UFloat.MyF=MyF;
  printf("%x\t",union_UFloat.FourChars.abcd0);
  printf("%x\t",union_UFloat.FourChars.abcd1);
  printf("%x\t",union_UFloat.FourChars.abcd2);
  printf("%x\t",union_UFloat.FourChars.abcd3);
  printf("\n");
  printf("sign=%x\n",union_UFloat.MyF.sign);
  printf("power=%x\n",union_UFloat.MyF.power);
  printf("mantisa=%x\n",union_UFloat.MyF.mantisa);

  floatA=-7.5;
  MyF=*((MyFloat*)(&floatA));
  union_UFloat.MyF=MyF;
  printf("%x\t",union_UFloat.FourChars.abcd0);
  printf("%x\t",union_UFloat.FourChars.abcd1);
  printf("%x\t",union_UFloat.FourChars.abcd2);
  printf("%x\t",union_UFloat.FourChars.abcd3);
  printf("\n");
  printf("sign=%x\n",union_UFloat.MyF.sign);
  printf("power=%x\n",union_UFloat.MyF.power);
  printf("mantisa=%x\n",union_UFloat.MyF.mantisa);

  MyF.sign=0x0;
  MyF.power=0x81;
  MyF.mantisa=0x710000;
  union_UFloat.MyF=MyF;
  printf("sign=%x\n",union_UFloat.MyF.sign);
  printf("power=%x\n",union_UFloat.MyF.power);
  printf("mantisa=%x\n",union_UFloat.MyF.mantisa);
  printf("MyF=%f\n",*((float*)(&MyF)));
  floatA=4.220703;
  MyF=*((MyFloat*)(&floatA));
  printf("MyF=%f\n",*((float*)(&MyF)));
  printf("sign=%x\n",MyF.sign);
  printf("power=%x\n",MyF.power);
  printf("mantisa=%x\n",MyF.mantisa);
  
  /* Escribamos el 0.5 usando MyF */
  MyF.sign=0;MyF.power=0x7e;MyF.mantisa=0x00;
  printf("MyF=%f\t",*((float*)(&MyF)));
  printf("sign=%x\t",MyF.sign);
  printf("power=%x\t",MyF.power);
  printf("mantisa=%x\n",MyF.mantisa);
  /* Escribamos el 0.25 usando MyF */
  MyF.sign=0;MyF.power=0x7d;MyF.mantisa=0x00;
  printf("MyF=%f\t",*((float*)(&MyF)));
  printf("sign=%x\t",MyF.sign);
  printf("power=%x\t",MyF.power);
  printf("mantisa=%x\n",MyF.mantisa);
  int i;
  for(i=0;i<20;i++){
    MyF.sign=0;MyF.power=0x7f-i;MyF.mantisa=0x00;
    printf("MyF=%f\t",*((float*)(&MyF)));
    printf("sign=%x\t",MyF.sign);
    printf("power=%x\t",MyF.power);
    printf("mantisa=%x\n",MyF.mantisa);
  }
  return 0;
}//end main()

void show_bits(int intTmp){
  int i;
  for(i=8*sizeof(int)-1;i>=0;i--){        //A1:
    printf("%d",((intTmp)>>i)&0x00000001);//A2:
  }                                       //A3:
}

