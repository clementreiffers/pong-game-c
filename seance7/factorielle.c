int factiter(int n) {
    int fact=1;
    if(n>1) for(int i=2; i<=n; i++) fact *= i;
    return fact;
}
int factrecu(int n) {
    return n==0 ? 1 : n*factrecu(n-1);
}