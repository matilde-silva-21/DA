#include <iostream>
#include "string"

int type(std::string s, std::string t){
    if(s.length()==0) return t.length();
    if(t.length()==0) return s.length();

    int n = s.length()+1, m = t.length()+1;
    int matrix[n][m];
    for(int i=0; i<n; i++){
        matrix[i][0] = i;
    }
    for(int j=0; j<m; j++){
        matrix[0][j] = j;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1;j++){
            int addon = 1;
            if(s[i-1]==t[j-1]){addon=0;}
            int min = matrix[i-1][j]+addon, s2 = matrix[i][j-1]+addon, s3 = matrix[i-1][j-1]+addon;
            if(s2<min) min = s2;
            else if(s3<min) min = s3;

            matrix[i][j]=min;
        }
    }

    return matrix[n][m];
}
int main() {
    std::cout <<type("GOTAS", "") << std::endl;
    return 0;
}
