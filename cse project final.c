#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define max 6000
#include <time.h>
int adj_mat[max][max];

int main()
{
    clock_t start = clock();
    int i, j, n,b,deg,degEX,edge=0,c,m;
    float sum=0;
    int total_time,ns = pow(10,9);

    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);

      srand(time(NULL));

    for(i=1; i<=n; i++)
    {

        for(j=1; j<=n; j++)
        {
            adj_mat[i][j]=rand()%2;
            if(adj_mat[i][j]==1 && i!=j)
            {

                adj_mat[j][i]=1;
            }
            else if(adj_mat[i][j]==0 && i!=j)
            {

               adj_mat[j][i]=0;
            }
        }
    }



    printf("\n Vertex \t Degree ");
    for ( i = 1 ; i <= n ; i++ )
    {
        deg = 0;
        degEX=0;
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( adj_mat[i][j] == 1)
            {
                deg++;
            }
            if(i==j && adj_mat[i][j]==1)
            {
                degEX++;
            }
            if(adj_mat[i][j]==1 && i>=j)
            {
               edge++;
            }
        }
        sum+=deg+degEX;

        printf("\n\n %5d \t\t %d\n\n", i, deg+degEX);
    }
    printf("The total edge is: %d",edge);

    if(sum/2==edge)

    printf("So,The Handshaking rules is proved");

    printf("\n");
    clock_t stop = clock();

    total_time = (stop - start) / CLOCKS_PER_SEC *ns;
    printf("Time elapsed in n.s: %f", total_time);

    return 0;

}
