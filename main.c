#include <stdio.h>
#include <stdbool.h>


#define n 4
#define N n*n


int main(){
	int i,j,k,l;
	bool hairetsu[3][N*2][n*2];
	int a,b;
	int za,za2;
	
	for(i=0;i<3;i++){
		for(j=0;j<N*2;j++){
			for(k=0;k<n*2;k++){
				hairetsu[i][j][k]=0;
			}
		}
	}
	
	za=0;
	do{
		/*int flag[n+1];
		for(i=0;i<=n;i++){
			flag[i]=0;
		}*/
		scanf("%d",&a);
		if(a!=0&&a!=1&&a!=2){
			break;
		}
/*
		if(a==2){
			flag[0]=1;
			flag[n]++;
		}else{
*/
		hairetsu[0][za][0]=a;
//		}
		for(i=1;i<n;i++){
			scanf("%d",&a);
/*
			if(a==2){
				flag[i]=1;
				flag[n]++;
			}else{
*/
			hairetsu[0][za][i]=a;
//			}
		}
		printf("\n");
		/*if(flag[n]){
			j=0;
			for(i=0;i<n;i++){
				if(flag[i]){
					hairetsu[0][za][i]=1-hairetsu[0][za-1][i];
				}else{
					hairetsu[0][za][i]=hairetsu[0][za-1][i];
				}
			}
			za++;
		}*/ //˜_—Ž®‚©‚çÅ¬€‚ð‹‚ß‚æ‚¤‚Æ‚µ‚æ‚¤‚Æ‚µ‚½B–¢Š®¬B
		za++;
	}while(za<N);
	
	for(i=0;i<za;i++){
		for(j=0;j<n*2;j++){
			printf("%d",hairetsu[0][i][j]);
		}
		printf("\n");
	}
	bool flag;
	int main_counter=1;
	do{
		l=0;
		flag=0;
		for(i=0;i<za;i++){
			for(j=i+1;j<za;j++){
				int sum=0;
				int num;
				for(k=n;k<2*n;k++){
					if(hairetsu[0][i][k]!=hairetsu[0][j][k]){
						sum++;
						num=k;
					}
				}
				if(sum==0){
					for(k=0;k<n;k++){
						if(hairetsu[0][i][k+n]==0){
							if(hairetsu[0][i][k]!=hairetsu[0][j][k]){
								sum++;
								num=k;
							}
						}
					}
					if(sum==1){
						for(k=0;k<2*n;k++){
								hairetsu[1][l][k]=hairetsu[0][i][k];
						}
						hairetsu[1][l][num]=0;
						hairetsu[1][l][num+n]=1;
						l++;
						flag=1;
					}
				}
			}
		}
		if(flag){
			printf("‘æ%dŽŸˆ³k\n",main_counter++);
		}
		for(i=0;i<l;i++){
			for(j=0;j<n;j++){
				if(hairetsu[1][i][j+n]==1){
					printf("_");
				}else{
					printf("%d",hairetsu[1][i][j]);
				}
				hairetsu[2][i][j]=hairetsu[1][i][j];
				hairetsu[2][i][j+n]=hairetsu[1][i][j+n];
			}
			printf("\n");
		}
		za2=za;
		printf("\n");
		for(j=0;j<N*2;j++){
			for(k=0;k<2*n;k++){
				hairetsu[0][j][k]=hairetsu[1][j][k];
				hairetsu[1][j][k]=0;
			}
		}
		za=l;
	}while(flag);
	
	
	for(i=0;i<za2;i++){
		for(j=i+1;j<za2;j++){
			int sum=0;
			for(k=0;k<n*2;k++){
				if(hairetsu[2][i][k]!=hairetsu[2][j][k]){
					sum++;
				}
			}
			
			if(sum==0){
				for(k=0;k<n;k++){
					hairetsu[2][j][k]=0;
					hairetsu[2][j][k+n]=1;
				}
			}
		}
	}
	
	for(i=0;i<za2;i++){
		int sum=0;
		for(k=0;k<2*n;k++){
			if(hairetsu[2][i][k]==k/n){
				sum++;
			}
		}
		if(sum!=2*n){
			for(j=0;j<n;j++){
				if(hairetsu[2][i][j+n]==1){
					printf("_");
				}else{
					printf("%d",hairetsu[2][i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}