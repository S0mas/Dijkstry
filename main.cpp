#include <iostream>

using namespace std;
void Fill_Matrix(int**adjacency_matrix)
{
adjacency_matrix[0] = new int [5];
adjacency_matrix[1] = new int [5];
adjacency_matrix[2] = new int [5];
adjacency_matrix[3] = new int [5];
adjacency_matrix[4] = new int [5];
adjacency_matrix[5] = new int [5];
/////////////////////////////////
adjacency_matrix[0][1]=3;
adjacency_matrix[0][2]=0;
adjacency_matrix[0][3]=7;
adjacency_matrix[0][4]=9;
adjacency_matrix[1][1]=0;
adjacency_matrix[1][2]=1;
adjacency_matrix[1][3]=0;
adjacency_matrix[1][4]=7;
adjacency_matrix[2][1]=0;
adjacency_matrix[2][2]=0;
adjacency_matrix[2][3]=1;
adjacency_matrix[2][4]=7;
adjacency_matrix[3][1]=0;
adjacency_matrix[3][2]=0;
adjacency_matrix[3][3]=0;
adjacency_matrix[3][4]=1;
adjacency_matrix[4][1]=0;
adjacency_matrix[4][2]=0;
adjacency_matrix[4][3]=0;
adjacency_matrix[4][4]=0;
}

void Dijkstra(int**adjacency_matrix,int road_matrix[],int i,int j,int vertices)
{
    if(i==vertices-1)
    {
        return;
    }
    if(j==vertices)
    {
        i++; j=1;
        return Dijkstra(adjacency_matrix, road_matrix, i, j, vertices);
    }
    if(adjacency_matrix[i][j]==0)
    {
        j++;
        return Dijkstra(adjacency_matrix, road_matrix, i, j, vertices);
    }
    if(adjacency_matrix[i][j]>0)
    {
        if((adjacency_matrix[i][j]+road_matrix[i])<(road_matrix[j])||(road_matrix[j]==0))
        {
            road_matrix[j]=adjacency_matrix[i][j]+road_matrix[i];
            j++;
            return Dijkstra(adjacency_matrix, road_matrix, i, j, vertices);
        }
        else
        {
        j++;
        return Dijkstra(adjacency_matrix, road_matrix, i, j, vertices);
        }
    }
}
int main()
{
int vertices = 5;
int road_matrix[vertices-1];
for (int i = 0; i<=vertices; i++)
{
    road_matrix[i]=0;
}
int i=0;//Column
int j=1;//Line
int** adjacency_matrix = new int *[4];
Fill_Matrix(adjacency_matrix);
Dijkstra(adjacency_matrix ,road_matrix ,i ,j ,vertices);
cout<<"The shortest distance possible "<<road_matrix[4]<<endl;
    return 0;
}
