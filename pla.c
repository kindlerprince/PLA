#include<stdio.h>
int main()
{
	int N = 50, i = 0, d = 2, error, j, ep;
	FILE *fp;
	fp = fopen("data_pla.csv", "r");
	float input[N][d + 1], w[d + 1], sum = 0;
	int y[N];
	for(j = 0; j < d + 1; j++)
	{
		w[j] = 0.25;
	}
	while(!feof(fp))
	{
		input[i][0] = 1;
		fscanf(fp, "%f, %f, %d\n", &input[i][1], &input[i][2], &y[i]);
		i++ ;
	}
	printf("|*********PERCEPTRON LEARNING ALGORITHM***********|\n\n");
	printf("|-------------------INPUT DATA--------------------|\n");
	printf("Feature 1\tFeature2\tFeature 3\tLabel\n");
	for(i = 0; i < N; i++)
	{
		printf("%f\t%f\t%f\t%d\n", input[i][0], input[i][1], input[i][2], y[i]);
	}
	fclose(fp);
	error = 1;
	for(ep = 0; ep < 10 && error == 1; ep++)
	{
		error = 0;
		for(i = 0; i < N; i++)
		{
			sum = 0;
			for(j = 0; j < d + 1; j++)
			{
				sum += w[j]*input[i][j];
			}
			if(sum*y[i] < 0 )
			{

				for(j = 0; j < d + 1; j++)
				{
					w[j] += y[i]*input[i][j];
					//printf("%d\n", y[i]);
				}
				error = 1;
			}
		}
	}
	
	printf("\n\nParameters after training\n");
	for(i = 0; i < d + 1; i++)
	{
		printf("w[%d]  =  %f\n", i, w[i]);
	}
	printf("\n");
	return 0;
}
