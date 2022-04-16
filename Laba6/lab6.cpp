#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

struct processes
{
	char name[10];
	int duration;
	int prior;
	int time;
	char symb[5];
	int left;
};

int main()
{
	int minPriority,minDuration,currentInd;
	setlocale(LC_ALL,"RUS");
	struct processes process[3];
	
	for (int i=0;i<3;i++)
	{
		printf("������� %d: \n-----------------------\n",i);
		fflush(stdin);
		puts("������� ��� ��������: ");
		gets(process[i].name);
		
		puts("������� ������������ ��������: ");
		scanf("%d",&process[i].duration);
		
		puts("������� ��������� ��������: ");
		scanf("%d",&process[i].prior);
		
		puts("������� ����� ��������� ��������: ");
		scanf("%d",&process[i].time);
		
		process[i].left=process[i].duration;
	}
	
	int timeAll=process[0].duration+process[1].duration+process[2].duration;
	
//	printf("%d\n",timeAll);
	
	printf(" ����� |%4s|%4s|%4s| �������� P1 | �������� P2 | �������� P3 |\n",process[0].name,process[1].name,process[2].name);
	
	for (int i=1;i<=timeAll;i++)
	{		
		minPriority=100;
		minDuration=timeAll;
		
		for(int k=0;k<3;k++)
		{
			if (process[k].time<=i && process[k].left>0)
			{
				if (process[k].prior<=minPriority)
				{
					minPriority=process[k].prior;
					if (process[k].duration<minDuration)
					{
						minDuration=process[k].duration;
						currentInd=k;
					}
				}
			}
		}
		
		for (int k=0;k<3;k++)
		{
			if(currentInd==k && process[k].left>0)
				strcpy(process[k].symb,"�");
			else if(process[k].time<=i && process[k].left>0)
				strcpy(process[k].symb,"�");
			else
				strcpy(process[k].symb," ");
		}
		//printf("%7d|%4s|%4s|%4s|\n",i,process[0].symb,process[1].symb,process[2].symb);
		fflush(stdin);		
		process[currentInd].left--;
		printf("%7d|%4s|%4s|%4s|%-13d|%-13d|%-13d|",i,process[0].symb,process[1].symb,process[2].symb,process[0].left,process[1].left,process[2].left);
	//	printf("\n");
		getchar();
	}
	
	
	fflush(stdin);
	getchar();
	return 0;
	
}
