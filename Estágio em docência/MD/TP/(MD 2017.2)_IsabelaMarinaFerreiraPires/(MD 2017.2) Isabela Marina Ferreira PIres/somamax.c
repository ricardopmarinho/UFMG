#include <stdlib.h>
#include <stdio.h>

int main()
{
	int cont,vrf=0;
	int num;
	int sec[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int somax=0;
	int i, j;


	scanf("%d", &num);
	if (num>=3 && num<=20)
	{
		for(cont=0;cont<num;cont++)
		{
			scanf("%d", &sec[cont]);   //entrada da sequência
		} 

	 
//********************************************************************************************************	
        for(cont=0;cont<num;cont++)
        {
    	  if(sec[cont]<0) 
          {
    	    vrf++;  //verifica os números negativos
          }
        }

        cont=0;

        if(vrf==0)                     //se todos os números forem positivos, a soma máxima será a soma total de todos
        {
          for(cont=0;cont<num;cont++)
          {
      	     somax=somax+sec[cont];
          }
        printf("Soma: %d\n", somax);
        printf("Os valores de entrada sao todos positivos.");
        }

        else if(vrf==num)  // se todos os números forem negativos, a soma maxima é 0
        {
    	  somax=0;
    	  printf("Soma: %d\n", somax);
    	  printf("Os valores de entrada sao todos negativos.");
        }
//*********************************************************************************************************    
        else
        { 
    	  while(num-1!=0)
    	  {
    	  somax=0;
    	  // fazer para os vinte e colcoar um if de teste para avaliar ate onde o programa deve rodar
    	  // colocar um while e decremento de num ate 0, e um if de teste ao final de cada for para ver 
    	  //o valor de num
          for(cont=0;cont<num;cont++)       
          {
           if(somax<=sec[cont])
           {
               somax=sec[cont];
               i=cont+1;
               j=cont+1;
           }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1];
               i=cont+1;
               j=cont+2;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2];
               i=cont+1;
               j=cont+3;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3];
               i = cont+1;
               j = cont+4;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

         for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4];
               i = cont+1;
               j = cont+5;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5];
               i = cont+1;
               j = cont+6;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6];
               i = cont+1;
               j = cont+7;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7];
               i = cont+1;
               j = cont+8;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8];
               i = cont+1;
               j = cont+9;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9];
               i = cont+1;
               j = cont+10;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10];
               i = cont+1;
               j = cont+11;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11];
               i = cont+1;
               j = cont+12;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12];
               i = cont+1;
               j = cont+13;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13];
               i = cont+1;
               j = cont+14;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;
          
          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]+sec[cont+14]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]+sec[cont+14];
               i = cont+1;
               j = cont+15;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]+sec[cont+14]+sec[cont+15]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]+sec[cont+14]+sec[cont+15];
               i = cont+1;
               j = cont+16;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]+sec[cont+14]+sec[cont+15]+sec[cont+16]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]+sec[cont+14]+sec[cont+15]+sec[cont+16];
               i = cont+1;
               j = cont+17;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]+sec[cont+14]+sec[cont+15]+sec[cont+16]+sec[cont+17]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]+sec[cont+14]+sec[cont+15]+sec[cont+16]+sec[cont+17];
               i = cont+1;
               j = cont+18;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

          for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]+sec[cont+14]+sec[cont+15]+sec[cont+16]+sec[cont+17]+sec[cont+18]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]+sec[cont+14]+sec[cont+15]+sec[cont+16]+sec[cont+17]+sec[cont+18];
               i = cont+1;
               j = cont+19;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

for(cont=0;cont<num;cont++)       
          {
    	    if(somax<=(sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]+sec[cont+14]+sec[cont+15]+sec[cont+16]+sec[cont+17]+sec[cont+18]+sec[cont+19]))
    	    {
    	    	
               somax=sec[cont]+sec[cont+1]+sec[cont+2]+sec[cont+3]+sec[cont+4]+sec[cont+5]+sec[cont+6]+sec[cont+7]+sec[cont+8]+sec[cont+9]+sec[cont+10]+sec[cont+11]+sec[cont+12]+sec[cont+13]+sec[cont+14]+sec[cont+15]+sec[cont+16]+sec[cont+17]+sec[cont+18]+sec[cont+19];
               i = cont+1;
               j = cont+20;
    	    }
          }
          num--;                           // decrementa valor de num pra descobrir o numero
          if(num==0) break;

         }
          printf("Soma: %d\n", somax);
          printf("Indices: %d %d\n", i, j);
        }
    }
    return 0;
}
