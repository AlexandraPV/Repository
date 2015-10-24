void fillRand(int mat[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat[i][j] = rand()%1997-999;
        }
    }
}

void rotateCCW180(int mat[4][4])
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            mat [4-1-i][4-1-j] = mat[i][j];
    }
}

void flipV(int mat[4][4])
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            mat [4-1-i][4-1-j]=mat[i][j];
    }
}

 void transposMain(int mat[4][4])
 {
  for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
           mat [j][i]= mat[i][j];
    }
  }
