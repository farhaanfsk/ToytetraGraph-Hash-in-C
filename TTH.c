#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int beta[26]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
char data[4][4],msg[40];
int fh[4],th[4],round2[4][4];
int main(){
	int len,m,i=1,j=0,k=0,l;
	
	printf("\n Toy Tetra Graph Hash");
	printf("\n-----------------------");
	printf("\n enter data(ignoring spaces,puntuatins):");
	scanf("%s",&msg);
	len=strlen(msg);
	if(len<16){
		for(m=len;m<16;m++){
			for(i=0;i<4;i++){
				for(j=0;j<4;j++) {
					data[i][j]=msg[m++]='\0';
				}
			}
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			data[i][j]=msg[k];
			k++;
			if(k>strlen(msg)){
				break;
			}
		}
	}
	printf("\n data is: \n");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%c \t",data[i][j]);
		}
		printf("\n");
	}
	 i=0,j=0,k=0;
	char key;
	for(i=0;i<4;i++){
	for(j=0;j<4;j++){
	key=data[i][j];
	for(k=0;alpha[k]!='\0';k++){
	if(key==alpha[k]){
	data[i][j]=k;
	}
	}
	}
	th[0]=((data[0][0]+data[1][0]+data[2][0]+data[3][0])%26);
	th[1]=((data[0][1]+data[1][1]+data[2][1]+data[3][1])%26);
	th[2]=((data[0][2]+data[1][2]+data[2][2]+data[3][2])%26);
	th[3]=((data[0][3]+data[1][3]+data[2][3]+data[3][3])%26);
	printf("\n values of data hash are: \n");
	for(i=0;i<4;i++){
		printf("%d \t",th[i]);
	}
	//round 2 is matrix shifting of round 1
	round2[0][0]=data[0][1];
	round2[0][1]=data[0][2];
	round2[0][2]=data[0][3];
	round2[0][3]=data[0][0];
	round2[1][0]=data[1][2];
	round2[1][1]=data[1][3];
	round2[1][2]=data[1][0];
	round2[1][3]=data[1][1];
	round2[2][0]=data[2][3];
	round2[2][1]=data[2][0];
	round2[2][2]=data[2][1];
	round2[2][3]=data[2][2];
	round2[3][0]=data[3][3];
	round2[3][1]=data[3][2];
	round2[3][2]=data[3][1];
	round2[3][3]=data[3][0];
	//hash values of round2
	fh[0]=((round2[0][0]+round2[1][0]+round2[2][0]+round2[3][0])%26);
	fh[1]=((round2[0][1]+round2[1][1]+round2[2][1]+round2[3][1])%26);
	fh[2]=((round2[0][2]+round2[1][2]+round2[2][2]+round2[3][2])%26);
	fh[3]=((round2[0][3]+round2[1][3]+round2[2][3]+round2[3][3])%26);
	printf("\n values of round2 are: \n");
	for(i=0;i<4;i++){
	printf("%d \t",fh[i]);
	}
	
	i=0;
	printf("\n hash value is:");
	do{
	fh[i]=(fh[i]+th[i])%26;
	printf("\t %c",alpha[fh[i]]);
	i++;
	}while(i<4);
	}
	}
