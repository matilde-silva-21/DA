#include <iostream>
/*
int curCap = curMaxCap % tamanho[cur_item], curValue = valor[cur_item];
currentBestValues[curMaxCap] = currentBestValues[curMaxCap-1];
currentBestIteration[curMaxCap] = currentBestIteration[curMaxCap-1];
if(curCap == 0 && ((curMaxCap/tamanho[cur_item])*curValue) > currentBestValues[cur_item]){
    currentBestValues[curMaxCap] = (valor[cur_item] * (curMaxCap/tamanho[cur_item]));
    currentBestIteration[curMaxCap] = cur_item;
}
*/
void knapsack(int max_cap, int tamanho[], int valor[], int n_items){
    int currentBestValues[max_cap+1], currentBestIteration[max_cap+1];

    for(int i = 0; i < max_cap+1; i++){
        currentBestValues[i]=0;
        currentBestIteration[i]=0;
    }

    for(int cur_item = 1; cur_item < n_items; cur_item++){
        for(int curMaxSize=tamanho[cur_item]; curMaxSize < max_cap + 1; curMaxSize++){
            int sizeCopy = curMaxSize, itemCopy = cur_item, val=0;
            while(sizeCopy!=0 && itemCopy>0){
                int div = (sizeCopy-sizeCopy%tamanho[itemCopy])/tamanho[itemCopy]; //numero de itens de tamanho=tamanho[curItem]
                if (sizeCopy >= tamanho[itemCopy]){
                    sizeCopy = sizeCopy%tamanho[itemCopy];
                    val+=div*valor[itemCopy];
                }
                else{
                    itemCopy--;
                }
            }
            if(val>currentBestValues[curMaxSize]){
                currentBestValues[curMaxSize]=val;
                currentBestIteration[curMaxSize]=cur_item;
            }
        }
    }

    std::cout << "max capacity: " <<currentBestValues[max_cap]<<"\n\n";
    for(int k=max_cap; k>0 && currentBestIteration[k] > 0; k -= tamanho[currentBestIteration[k]]){
        std::cout << "item number: " <<currentBestIteration[k]<<"\n";
        std::cout << "item value: " << valor[currentBestIteration[k]] << "\n";
        std::cout << "item size: " << tamanho[currentBestIteration[k]] << "\n";
        std::cout << "\n";
    }
}

/*só funciona para seuqncias contínuas*/
int LongestIncreasingSubsequence(const int numbers[], int array_size, int index, int LIS[]){
    int c = numbers[index], b = LIS[index];
    if(index == array_size-1){
        LIS[index]=1;
    }

    else if(numbers[index] < numbers[index+1]){
        LIS[index]= 1 + LIS[index+1];
    }

    else{
        LIS[index] = 1;
    }

    if(index==0){
        return LIS[index];
    }


    return LongestIncreasingSubsequence(numbers, array_size, index-1, LIS);


}
int main() {

    int numbers[] = {0,3,1,6,2,2,7};
    static int LIS[] = {0,0,0,0,0,0,0};
    int max_cap=17;
    int capacidade[]={0,3,4,7,8,9};
    int valor[]={0,4,5,10,11,13};
    int n_items=6;
    //LongestIncreasingSubsequence(numbers, 7, 6, LIS);
    knapsack(max_cap,capacidade, valor,n_items);
    return 0;
}
