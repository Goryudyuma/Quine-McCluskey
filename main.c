#include <stdio.h>
#include <stdbool.h>

#define N 16

int main(){
	int i,j,k,l;
	bool hairetsu[2][N*2][8];
	int a,b;
	int za;
	
	for(i=0;i<2;i++){
		for(j=0;j<N*2;j++){
			for(k=0;k<8;k++){
				hairetsu[i][j][k]=0;
			}
		}
	}
	
	za=0;
	do{
		scanf("%d",&a);
		if(a!=0&&a!=1){
			break;
		}
		hairetsu[0][za][0]=a;
		scanf("%d",&a);
		hairetsu[0][za][1]=a;
		scanf("%d",&a);
		hairetsu[0][za][2]=a;
		scanf("%d",&a);
		hairetsu[0][za][3]=a;
		printf("\n");
		za++;
	}while(za<N);
	bool flag;
	do{
		l=0;
		flag=0;
		for(i=0;i<za;i++){
			for(j=i+1;j<za;j++){
				int sum=0;
				int num;
				for(k=4;k<8;k++){
					if(hairetsu[0][i][k]!=hairetsu[0][j][k]){
						sum++;
						num=k;
					}
				}
				if(sum==0){
					for(k=0;k<4;k++){
						if(hairetsu[0][i][k+4]==0){
							if(hairetsu[0][i][k]!=hairetsu[0][j][k]){
								sum++;
								num=k;
							}
						}
					}
					if(sum==1){
						for(k=0;k<8;k++){
								hairetsu[1][l][k]=hairetsu[0][i][k];
						}
						hairetsu[1][l][num]=0;
						hairetsu[1][l][num+4]=1;
						l++;
						flag=1;
					}
				}
			}
		}
		for(i=0;i<l;i++){
			for(j=0;j<4;j++){
				if(hairetsu[1][i][j+4]==1){
					printf("_");
				}else{
					printf("%d",hairetsu[1][i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");
		for(j=0;j<N*2;j++){
			for(k=0;k<8;k++){
				hairetsu[0][j][k]=hairetsu[1][j][k];
				hairetsu[1][j][k]=0;
			}
		}
		za=l;
	}while(flag);
	
	return 0;
}