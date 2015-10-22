void fillRand(int mat[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat[i][j] = rand()%1997-999;
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void flipV(int mat[4][4])
{
    
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            printf("%d ", mat [4-1-i][4-1-j]);
        printf("\n");
    }
    printf("\n");
}

void flipV(int mat[4][4])
{
    
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            printf("%d ", mat [4-1-i][j]);
        printf("\n");
    }
    printf("\n");
}

 void transposSide(int mat[4][4])
 {
  for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            printf("%d ", mat [4-1-j][4-1-i]);
        printf("\n");
    }
    printf("\n");
  }
