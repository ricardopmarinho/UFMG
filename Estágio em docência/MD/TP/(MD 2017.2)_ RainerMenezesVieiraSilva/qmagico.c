#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main()
{
int N=3,i;
while(N==3 || N==4 || N==5)
{
scanf("%i",&N);
	if(N==3)
	{
	    printf("n:%i, Soma=15\n",N);
		int vetor[9],numeroini=1;
		vetor[4] = 5;
		srand(time(NULL));
		while((numeroini%2)!=0)
		{
			numeroini = 1+(rand()%8);
		}
		vetor[0] = numeroini;
		vetor[8] = 15-(numeroini+5);
		numeroini=1;
		while(numeroini%2!=0 || numeroini==vetor[0] || numeroini==vetor[8])
		{
			numeroini = 1+(rand()%8);
		}
		vetor[2] = numeroini;
		vetor[6] = 15-(numeroini+5);
		vetor[1] = 15-(vetor[0]+vetor[2]);
		vetor[3] = 15-(vetor[0]+vetor[6]);
		vetor[7] = 15-(vetor[6]+vetor[8]);
		vetor[5] = 15-(vetor[2]+vetor[8]);
		for(i=0;i<9;i++)
		{
			printf("%i ",vetor[i]);
			if(((i+1)%3)==0 && i>0)
			{
				printf("\n");
			}
		}
	}
	else if(N==4)
	{
	    printf("n:%i, Soma=34\n",N);
		int vetor[15],numeroini=1,i;
			i = 1+(rand()%3);
			if(i==1)
			{
				vetor[0] = numeroini;
				vetor[15] = 16;
				vetor[5] = 6;
				vetor[10] = 11;
						//numeroini = 1+(rand()%15);
						numeroini = 4;
						i = 1+(rand()%2);
						//i = 2;
								if(i==1)
								{
									vetor[3] = numeroini;
									vetor[12] = 13;
									vetor[6] = 7;
									vetor[9] = 10;
									vetor[4] = 12;
									vetor[8] = 8;
									vetor[1] = 15;
									vetor[2] = 14;
									vetor[7] = 9;
									vetor[11] = 5;
									vetor[13] = 3;
									vetor[14] = 2;
									for(i=0;i<16;i++)
									{
										printf("%i ",vetor[i]);
										if((i+1)%4==0 && i>0)
										{
											printf("\n");
										}
									}
								}
								else
								{
									vetor[12] = numeroini;
									vetor[3] = 13;
									vetor[9] = 7;
									vetor[6] = 10;
									vetor[1] = 12;
									vetor[2] = 8;
									vetor[4] = 15;
									vetor[7] = 3;
									vetor[8] = 14;
									vetor[11] = 2;
									vetor[13] = 9;
									vetor[14] = 5;
									for(i=0;i<16;i++)
									{
										printf("%i ",vetor[i]);
										if((i+1)%4==0 && i>0)
										{
											printf("\n");
										}
									}
								}
			}
			else if(i==2)
			{
				vetor[3] = numeroini;
				vetor[12] = 16;
				vetor[6] = 6;
				vetor[9] = 11;
						numeroini =4;
						i = 1+(rand()%2);
						//i = 2;
                        if(i==1)
                        {
                            vetor[0] = numeroini;
                            vetor[5] = 7;
                            vetor[10] = 10;
                            vetor[15] = 13;
                            vetor[1] = 14;
                            vetor[2] = 15;
                            vetor[4] = 9;
                            vetor[8] = 5;
                            vetor[7] = 12;
                            vetor[11] = 8;
                            vetor[13] = 2;
                            vetor[14] = 3;
									for(i=0;i<16;i++)
									{
										printf("%i ",vetor[i]);
										if((i+1)%4==0 && i>0)
										{
											printf("\n");
										}
									}
                        }
                        else
                        {
                            vetor[15] = numeroini;
                            vetor[0] = 13;
                            vetor[5] = 10;
                            vetor[10] = 7;
                            vetor[1] = 8;
                            vetor[2] = 12;
                            vetor[4] = 3;
                            vetor[8] = 2;
                            vetor[13] = 5;
                            vetor[14] = 9;
                            vetor[7] = 15;
                            vetor[11] = 14;
									for(i=0;i<16;i++)
									{
										printf("%i ",vetor[i]);
										if((i+1)%4==0 && i>0)
										{
											printf("\n");
										}
									}
                        }
			}
			else if(i==3)
			{
				vetor[12] = numeroini;
				vetor[3] = 16;
				vetor[9] = 6;
				vetor[6] = 11;
				numeroini =4;
						i = 1+(rand()%2);
						//i = 1;
                        if(i==1)
                        {
                            vetor[0] = numeroini;
                            vetor[5] = 7;
                            vetor[10] = 10;
                            vetor[15] = 13;
                            vetor[1] = 9;
                            vetor[2] = 5;
                            vetor[4] = 14;
                            vetor[8] = 15;
                            vetor[7] = 2;
                            vetor[11] = 3;
                            vetor[13] = 12;
                            vetor[14] = 8;
									for(i=0;i<16;i++)
									{
										printf("%i ",vetor[i]);
										if((i+1)%4==0 && i>0)
										{
											printf("\n");
										}
									}
                        }
                        else
                        {
                            vetor[15] = numeroini;
                            vetor[0] = 13;
                            vetor[5] = 10;
                            vetor[10] = 7;
                            vetor[1] = 3;
                            vetor[2] = 2;
                            vetor[4] = 8;
                            vetor[8] = 12;
                            vetor[13] = 15;
                            vetor[14] = 14;
                            vetor[7] = 5;
                            vetor[11] = 9;
									for(i=0;i<16;i++)
									{
										printf("%i ",vetor[i]);
										if((i+1)%4==0 && i>0)
										{
											printf("\n");
										}
									}
                        }

			}
			else if(i==4)
			{
				vetor[15] = numeroini;
				vetor[0] = 16;
				vetor[5] = 11;
				vetor[10] = 6;
				//numeroini = 1+(rand()%15);
						numeroini = 4;
						i = 1+(rand()%2);
						//i = 1;
								if(i==1)
								{
									vetor[3] = numeroini;
									vetor[12] = 13;
									vetor[6] = 7;
									vetor[9] = 10;
									vetor[4] = 2;
									vetor[8] = 3;
									vetor[1] = 5;
									vetor[2] = 9;
									vetor[7] = 14;
									vetor[11] = 15;
									vetor[13] = 8;
									vetor[14] = 12;
									for(i=0;i<16;i++)
									{
										printf("%i ",vetor[i]);
										if((i+1)%4==0 && i>0)
										{
											printf("\n");
										}
									}
								}
								else
								{
									vetor[12] = numeroini;
									vetor[3] = 13;
									vetor[9] = 7;
									vetor[6] = 10;
									vetor[1] = 2;
									vetor[2] = 3;
									vetor[4] = 5;
									vetor[7] = 8;
									vetor[8] = 9;
									vetor[11] = 12;
									vetor[13] = 14;
									vetor[14] = 15;
									for(i=0;i<16;i++)
									{
										printf("%i ",vetor[i]);
										if((i+1)%4==0 && i>0)
										{
											printf("\n");
										}
									}
								}
			}
	}
    else if(N==5)
    {
        printf("n:%i, Soma=65\n",N);
    	int vetor[25],i,numeroini=11;
		i = rand()%4+1;
		vetor[12] = 13;
		if(i==1)
		{
			vetor[0] = numeroini;
			vetor[6] = 12;
			vetor[18] = 14;
			vetor[24] = 15;
			i = (rand()%2)+1;
			numeroini = 3;
				if(i==1)
				{
					vetor[4] = numeroini;
					vetor[8] = 8;
					vetor[16] = 18;
					vetor[20] =  23;
					vetor[1] = 24;
					vetor[2] = 7;
					vetor[3] = 20;
					vetor[5] = 4;
					vetor[7] = 25;
					vetor[9] = 16;
					vetor[10] = 17;
					vetor[11] = 5;
					vetor[13] = 21;
					vetor[14] = 9;
					vetor[15] = 10;
					vetor[17] = 1;
					vetor[19] = 22;
					vetor[21] = 6;
					vetor[22] = 19;
					vetor[23] =  2;
						for(i=0;i<25;i++)
							{
								printf("%i ",vetor[i]);
								if((i+1)%5==0 && i>0)
									{
										printf("\n");
									}
							}
				}
				else
				{
					vetor[20] = numeroini;
					vetor[16] = 8;
					vetor[8] = 18;
					vetor[4] =  23;
					vetor[5] = 24;
					vetor[10] = 7;
					vetor[15] = 20;
					vetor[1] = 4;
					vetor[11] = 25;
					vetor[21] = 16;
					vetor[23] = 22;
					vetor[7] = 5;
					vetor[17] = 21;
					vetor[22] = 9;
					vetor[3] = 10;
					vetor[13] = 1;
					vetor[2] = 17;
					vetor[9] = 6;
					vetor[14] = 19;
					vetor[19] =  2;
						for(i=0;i<25;i++)
							{
								printf("%i ",vetor[i]);
								if((i+1)%5==0 && i>0)
									{
										printf("\n");
									}
							}
				}
		}
		else if(i==2)
		{
			vetor[4] = numeroini;
			vetor[8] = 12;
			vetor[16] = 14;
			vetor[20] = 15;
			i = rand()%2+1;
			numeroini = 3;
				if(i==1)
				{
					vetor[0] = numeroini;
					vetor[6] = 8;
					vetor[18] = 18;
					vetor[24] =  23;
					vetor[3] = 24;
					vetor[2] = 7;
					vetor[1] = 20;
					vetor[9] = 4;
					vetor[7] = 25;
					vetor[5] = 16;
					vetor[14] = 17;
					vetor[13] = 5;
					vetor[11] = 21;
					vetor[10] = 9;
					vetor[19] = 10;
					vetor[17] = 1;
					vetor[15] = 22;
					vetor[23] = 6;
					vetor[22] = 19;
					vetor[21] =  2;
						for(i=0;i<25;i++)
							{
								printf("%i ",vetor[i]);
								if((i+1)%5==0 && i>0)
									{
										printf("\n");
									}
							}
				}
				else
				{
					vetor[24] = numeroini;
					vetor[18] = 8;
					vetor[6] = 18;
					vetor[0] =  23;
					vetor[9] = 24;
					vetor[14] = 7;
					vetor[19] = 20;
					vetor[3] = 4;
					vetor[7] = 25;
					vetor[23] = 16;
					vetor[21] = 22;
					vetor[13] = 5;
					vetor[17] = 21;
					vetor[22] = 9;
					vetor[1] = 10;
					vetor[11] = 1;
					vetor[2] = 17;
					vetor[5] = 6;
					vetor[10] = 19;
					vetor[15] =  2;
						for(i=0;i<25;i++)
							{
								printf("%i ",vetor[i]);
								if((i+1)%5==0 && i>0)
									{
										printf("\n");
									}
							}
				}
		}
		else if(i==3)
        {
            vetor[20] = numeroini;
			vetor[16] = 12;
			vetor[8] = 14;
			vetor[4] = 15;
			i = rand()%2+1;
			numeroini = 3;
				if(i==1)
				{
					vetor[0] = numeroini;
					vetor[6] = 8;
					vetor[18] = 18;
					vetor[24] =  23;
					vetor[15] = 24;
					vetor[10] = 7;
					vetor[5] = 20;
					vetor[21] = 4;
					vetor[11] = 25;
					vetor[1] = 16;
					vetor[22] = 17;
					vetor[17] = 5;
					vetor[7] = 21;
					vetor[2] = 9;
					vetor[23] = 10;
					vetor[13] = 1;
					vetor[3] = 22;
					vetor[19] = 6;
					vetor[14] = 19;
					vetor[9] =  2;
						for(i=0;i<25;i++)
							{
								printf("%i ",vetor[i]);
								if((i+1)%5==0 && i>0)
									{
										printf("\n");
									}
							}
				}
				else
				{
					vetor[24] = numeroini;
					vetor[18] = 8;
					vetor[6] = 18;
					vetor[0] =  23;
					vetor[21] = 24;
					vetor[22] = 7;
					vetor[23] = 20;
					vetor[15] = 4;
					vetor[17] = 25;
					vetor[19] = 16;
					vetor[9] = 22;
					vetor[11] = 5;
					vetor[13] = 21;
					vetor[14] = 9;
					vetor[5] = 10;
					vetor[7] = 1;
					vetor[10] = 17;
					vetor[1] = 6;
					vetor[2] = 19;
					vetor[3] =  2;
						for(i=0;i<25;i++)
							{
								printf("%i ",vetor[i]);
								if((i+1)%5==0 && i>0)
									{
										printf("\n");
									}
							}
				}
        }
        else if(i==4)
        {
            vetor[24] = numeroini;
			vetor[18] = 12;
			vetor[6] = 14;
			vetor[0] = 15;
			i = rand()%2+1;
			numeroini = 3;
				if(i==1)
				{
					vetor[4] = numeroini;
					vetor[8] = 8;
					vetor[16] = 18;
					vetor[20] =  23;
					vetor[19] = 24;
					vetor[14] = 7;
					vetor[9] = 20;
					vetor[23] = 4;
					vetor[13] = 25;
					vetor[3] = 16;
					vetor[22] = 17;
					vetor[17] = 5;
					vetor[7] = 21;
					vetor[2] = 9;
					vetor[21] = 10;
					vetor[11] = 1;
					vetor[1] = 22;
					vetor[15] = 6;
					vetor[10] = 19;
					vetor[5] =  2;
						for(i=0;i<25;i++)
							{
								printf("%i ",vetor[i]);
								if((i+1)%5==0 && i>0)
									{
										printf("\n");
									}
							}
				}
				else
				{
					vetor[20] = numeroini;
					vetor[16] = 8;
					vetor[8] = 18;
					vetor[4] =  23;
					vetor[23] = 24;
					vetor[22] = 7;
					vetor[21] = 20;
					vetor[19] = 4;
					vetor[17] = 25;
					vetor[15] = 16;
					vetor[5] = 22;
					vetor[13] = 5;
					vetor[11] = 21;
					vetor[10] = 9;
					vetor[9] = 10;
					vetor[7] = 1;
					vetor[14] = 17;
					vetor[3] = 6;
					vetor[2] = 19;
					vetor[1] =  2;
						for(i=0;i<25;i++)
							{
								printf("%i ",vetor[i]);
								if((i+1)%5==0 && i>0)
									{
										printf("\n");
									}
							}
        }
    }
}
}
return 0;
}
