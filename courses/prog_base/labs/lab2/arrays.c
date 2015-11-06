void fillRand2(int arr[], int size){
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand()%511-225;
        
    }
    
}

int checkRand2(int arr[], int size){
    int i;
    for (i=0; i < size; i++){
        if ((arr[i]>=(-255)) || (arr[i]<=255))
            return 1;}
    return 0;
    
}


float meanValue(int arr[], int size){
    float sum=0;
    int i;
    for (i=0; i < size; i++)
        sum += arr[i];
    float sred = (sum / size);
    return sred;
}




int maxValue(int arr[], int size){
    int max=arr[0];
    int i;
    for (i=0; i < size; i++)
        max = max>arr[i] ? max : arr[i];
    return max;
}



int meanIndex(int arr[], int size){
    int indx = 0;
    int RizZnach;
    int i;
    float sred = meanValue(arr, size);
    int minRiz=fabs(arr[0] - sred);
    for (i = 0; i < size; i++){
        RizZnach = fabs(sred - arr[i]);
        if (RizZnach < minRiz){
            minRiz = RizZnach;
            indx = i;
        }
    }
    return indx;
    
}


int maxIndex(int arr[], int size){
    
    int maxV = maxValue(arr, size);
    int i;
    for (i = 0; i < size; i++){
        if (arr[i]==maxV)
            return i;
    
    }
    return i;
}

int maxOccurance(int arr[], int size){
    int occ;
    int maxNum=0;
    int res, i;
    for (i = 0; i < size; i++){
        occ = 0;
        for (int j = 0; j < size; j++){
            if (arr[i] == arr[j])
                occ++;
        }
        if (occ > maxNum){
            res= arr[i];
            maxNum = occ;
        }
        else  if ((occ == maxNum)&&(arr[i]>res))
            res = arr[i];
        
    }
    return res;
}

int diff(int arr1[], int arr2[], int res[], int size){
    int i, result;
    for (i = 0; i < size; i++){
        res[i] = arr1[i] - arr2[i];
        if (res[i]!=0) {
            result = 0;
        }
    }
    return result;

}

void add(int arr1[], int arr2[], int res[], int size){
    int i;
    for(i=0; i<size; i++)
        res[i]=arr1[i]+arr2[i];
    
}

int gteq(int arr1[], int arr2[], int size){
    int i;
    for (i = 0; i < size; i++){
        if (arr1[i] >= arr2[i]){
            return 1;
        }
    }
    return 0;
}

void lor(int arr1[], int arr2[], int res[], int size){
    int i;
    for (i = 0; i < size; i++)
        res[i] = arr1[i] || arr2[i];
}
