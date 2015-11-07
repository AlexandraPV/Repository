int isVowel (char letter) {
    if (isalpha(letter) == 0) {
        return 0;
    }
    
    char *vowels = "aeiouy";
    for (int i = 0; (vowels[i] != '\0'); i++) {
        if (letter == vowels[i]) {
            return 1;
        }
    }
    return 0;
}

char *process (char *resultStr, const char *textLines [], int linesNum, const char *extraStr) {
    char result[100];
    result[0] = '\0';
    
    for (int i = 0; i < linesNum; i++) {
        char lineResult[100];
        char tempResult[100];
        
        sprintf(lineResult, "%d ", i);
        
        int sum = 0;
        int localSum = 0;
        int firstCharacterValue = 0;
        
        for (int j = 0; (textLines[i][j] != '\0'); j++) {
            if (textLines[i][j] == ' ') {
                firstCharacterValue = 0;
                sprintf(tempResult, "%d, ", localSum);
                strcat(lineResult, tempResult);
                localSum = 0;
            } else {
                if (firstCharacterValue == 0) {
                    firstCharacterValue = (isVowel(textLines[i][j])) ? -1 : 1;
                }
                localSum += firstCharacterValue;
                sum += firstCharacterValue;
            }
        }
        sprintf(tempResult, "%d", localSum);
        strcat(lineResult, tempResult);
        
        if (sum == 0) {
            strcpy(result, lineResult);
        }
    }
    
    resultStr = result;
    return (resultStr[0] == '\0') ? "-1" : resultStr;
}
