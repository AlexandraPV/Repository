void fillRand(int mat[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat[i][j] = rand()%1999-999;
        }
    }
}

void rotateCCW180(int mat[4][4])
{
    
    int mat1[4][4];
    for(int a=0; a<4; a++)
    {
        for(int b=0; b<4; b++)
            mat1[a][b] = mat[a][b];
    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        mat[i][j] = mat1[4-1-i][4-1-j];
    }
}





void flipV( int mat[4][4])
{
    int mat1[4][4];
    int mat2[4][4];
    
    
        for (int a=0;a<4;a++){
            for (int b=0;b<4;b++)
                mat1[a][b]=mat[a][b];
        }
       for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                mat2[i][j]=mat1[4-1-i][4-1-j];
                
            }
        }
    
    
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++)
            mat[i][j]=mat2[4-1-i][j];
    }
}


void transposMain(int mat[4][4]){
    int mat1[4][4];
    
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++)
            mat1[i][j]=mat[i][j];
        
    }
    for (int e=0;e<4;e++){
        for (int g=0;g<4;g++)
            mat[e][g]=mat1[g][e];
    }
}
