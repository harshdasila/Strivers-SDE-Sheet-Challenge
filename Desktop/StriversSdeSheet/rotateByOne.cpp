#include <bits/stdc++.h>

void rotateMatrix(vector< vector <int> > &mat, int n, int m)
{
    if(n==1 | m==1) return;
    int left=0,right=m-1,top=0,bot=n-1;
    while(top<bot && left<right){
        int temp = mat[left][top];
        for(int i=top;i<bot;i++){ //top to bottom
            mat[i][left] = mat[i+1][left];
        }
        for(int i=left;i<right;i++){ //left to right
            mat[bot][i] = mat[bot][i+1];
        }
        for(int i=bot;i>top;i--){ //top to bottom
            mat[i][right] = mat[i-1][right];
        }
        for(int i=right;i>left+1;i--){
            mat[top][i] = mat[top][i-1];
        }
        mat[top][left+1] = temp;
        left++; right--; top++; bot--;
    }

}