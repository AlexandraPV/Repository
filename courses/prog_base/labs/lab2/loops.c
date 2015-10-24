double calc(int n, int m){
int i, j;
double sum1;
 for (i=1; i<=n; i++) {
    for (j=1; j<=m; j++)
        sum1 += 2*sin((j*(M_PI))/4)+ cos((i*(M_PI))/2);
        }
    return 0;
}
