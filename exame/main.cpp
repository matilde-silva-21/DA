#include <iostream>

void knapsack(int max_cap, int capacidade[], int valor[], int n_items){
    int currentBestValues[max_cap+1], currentBestIteration[max_cap+1];

    for(int i = 0; i < max_cap+1; i++){
        currentBestValues[i]=0;
        currentBestIteration[i]=0;
    }

    for(int cur_item = 1; cur_item < n_items; cur_item++){
        for(int curMaxCap=1; curMaxCap<max_cap+1; curMaxCap++){
            int curCap = curMaxCap % capacidade[cur_item], curValue = valor[cur_item];
            currentBestValues[curMaxCap] = currentBestValues[curMaxCap-1];
            currentBestIteration[curMaxCap] = currentBestIteration[curMaxCap-1];
            if(curCap == 0 && ((curMaxCap/capacidade[cur_item])*curValue) > currentBestValues[cur_item]){
                currentBestValues[curMaxCap] = (valor[cur_item] * (curMaxCap/capacidade[cur_item]));
                currentBestIteration[curMaxCap] = cur_item;
            }
        }
    }

    std::cout << "max capacity: " <<currentBestValues[max_cap]<<"\n";
    for(int k=max_cap; k>0 && currentBestIteration[k] > 0; k -= capacidade[currentBestIteration[k]]){
        std::cout << "item number: " <<currentBestIteration[k]<<"\n";
        std::cout << "item capacity: " <<capacidade[k]<<"\n";
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

    LongestIncreasingSubsequence(numbers, 7, 6, LIS);

    return 0;
}
