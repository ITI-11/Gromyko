#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

int cprocesses=0;
int fullMemory=0,freeMemory=0;
int cashMemory=0,freeCashMemory=0;

struct processes
{
	char name[30];
	int cash;
	int size;
	int request;
};

processes process[50];

void showData()
{
	puts("******************************");
	printf("����� ����������� ������: %d\n",fullMemory);
	printf("��������� ����� ����������� ������: %d\n",freeMemory);
	printf("����� ���-������: %d\n",cashMemory);
	printf("��������� ����� ���-������: %d\n",freeCashMemory);
	puts("******************************");
	puts("����������� ������: ");
	for (int i=0;i<cprocesses;i++)
	{
		if(process[i].cash==2)
		{
			printf("������� %s �������� %d � ����������� ��������� %d\n",process[i].name,process[i].size,process[i].request);
		}
	}
	puts("******************************");
	puts("���-������: ");
	for (int i=0;i<cprocesses;i++)
	{
		if(process[i].cash==1)
		{
			printf("������� %s �������� %d � ����������� ��������� %d\n",process[i].name,process[i].size,process[i].request);
		}
	}
}

void cash()
{
	int t=1,maxRequest=0,maxRequestIndex,count=0;
	
	for (int i=0;i<cprocesses;i++)
	{
		if (process[i].cash==2 && process[i].request>maxRequest && process[i].size<freeCashMemory)
		{
			maxRequest=process[i].request;
			maxRequestIndex=i;
			count++;
		}
	}
	
	if (count)
	{
		process[maxRequestIndex].cash=1;
		freeMemory+=process[maxRequestIndex].size;
		freeCashMemory-=process[maxRequestIndex].size;
	}
	else
	{
		count=0;
		int minCashRequest=0,minCashRequestIndex=0;
		for (int i=0;i<cprocesses;i++)
		{
			if (process[i].cash==1)
			{
				minCashRequest=process[i].request;
				minCashRequestIndex=i;
				break;
			}
		}
		
		for (int i=0;i<cprocesses;i++)
		{
			if (process[i].cash==1 && process[i].request<=minCashRequest && process[i].size<=freeMemory)
			{
				minCashRequest=process[i].request;
				minCashRequestIndex=i;
			}
		}
		
		for (int i=0;i<cprocesses;i++)
		{
			if (process[i].cash==2 && process[i].request>minCashRequest && process[i].size<=process[minCashRequestIndex].size && process[i].size<cashMemory)
			{
				maxRequest=process[i].request;
				maxRequestIndex=i;
				count++;
			}
		}
		if (count)
		{
			process[minCashRequestIndex].cash=2;
			process[maxRequestIndex].cash=1;
			
			freeCashMemory-=process[maxRequestIndex].size;
			freeCashMemory+=process[minCashRequestIndex].size;
			
			freeMemory+=process[maxRequestIndex].size;
			freeMemory-=process[minCashRequestIndex].size;
			
			t=1;
		}
		else
			t=0;
	}
	
	
	
	if(t)
		puts("����������� �����������");
	else
		puts("���������� ���������� �����������");
}

void addProcess()
{
	int size,t=1;
	//int min2Cash=cashMemory,tmp; // fullMemory=3072 freeMemory=2048 cashMemory=612 freeCashMemory=56
	char name[30];
	fflush(stdin);
	puts("������� ��� ��������: ");
	gets(name);
	
	
	while (t)
	{
		
		fflush(stdin);
		puts("������� ������ ��������: ");
		scanf("%d",&size);
		if(size>freeMemory)
		{
			puts("���������� �������� ������� ������.");
		}
		else
		{
			strcpy(process[cprocesses].name,name);
			process[cprocesses].size=size;
			freeMemory-=size;
			puts("������� ���������� ��������� � ��������: ");
			scanf("%d",&process[cprocesses].request);
			t=0;
			process[cprocesses].cash=2;
		}
			
		
	}
	
	
	
	cprocesses++;
	
}

int main()
{
	setlocale(LC_ALL,"RUS");
	
	puts("������� ������ ����������� ������: ");
	scanf("%d",&fullMemory);
	
	freeMemory=fullMemory;
	
	puts("������� ������ ���-������: ");
	scanf("%d",&cashMemory);
	
	freeCashMemory=cashMemory;
		
	int t=1,menu;
	
	while (t)
	{
	
		puts("\n******************************\n");
		puts(" 1. ��������� ������");
		puts(" 2. �������� �������");
		puts(" 3. �����������");
		puts(" 4. �����\n");
		puts("*******************************\n");
			
		scanf("%d",&menu);
			
		switch(menu)
		{
			case 1:
				showData();
				break;
			case 2:
				addProcess();
				break;
			case 3:
				cash();
				break;
			case 4:
				t=0;
				break;
			default:
				printf("������� �������� ������\n");
		}
	}
	
	fflush(stdin);
	getchar();
	return 0;
}
