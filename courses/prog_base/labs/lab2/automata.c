enum op { POP, CONTINUE, REPEAT, BREAK, EMPTY };

struct Move
{
    enum op left;
    int right;
};
int run(int moves[], int movesLen, int res[], int resLen, enum op c)
{
    movesLen = 4;
    resLen = movesLen;
    
    int currentState = 0;
    int currentMove;
    int i = 0;
    int j = 0;
    int ressssssss;
    int resNumbers = 0;
    
    struct Move automata[4][4];
    automata[0][0].left = 9;
    automata[0][0].right = 1;
    automata[0][1].left = BREAK;
    automata[0][1].right = EMPTY;
    automata[0][2].left = 7;
    automata[0][2].right = 2;
    automata[0][3].left = 5;
    automata[0][3].right = 3;
    automata[1][0].left = 3;
    automata[1][0].right = 2;
    automata[1][1].left = EMPTY;
    automata[1][1].right = EMPTY;
    automata[1][2].left = 1;
    automata[1][2].right = 2;
    automata[1][3].left = POP;
    automata[1][3].right = 0;
    automata[2][0].left = REPEAT;
    automata[2][0].right = 0;
    automata[2][1].left = BREAK;
    automata[2][1].right = EMPTY;
    automata[2][2].left = CONTINUE;
    automata[2][2].right = 0;
    automata[2][3].left = EMPTY;
    automata[2][3].right = EMPTY;
    automata[3][0].left = 19;
    automata[3][0].right = 0;
    automata[3][1].left = POP;
    automata[3][1].right = 0;
    automata[3][2].left = EMPTY;
    automata[3][2].right = EMPTY;
    automata[3][3].left = 14;
    automata[3][3].right = 1;
    
    
    while (1)
    {
        switch (moves[i])
        {
            case 6:
                currentMove = 0;
                break;
            case 14:
                currentMove = 1;
                break;
            case 24:
                currentMove = 2;
                break;
            case 204:
                currentMove = 3;
                break;
            default:
                ressssssss = 1;
                break;
        }
        if (ressssssss == 1)
        {
            break;
        }
        
        switch (automata[currentState][currentMove].left)
        {
            case BREAK:
                ressssssss = 1;
                break;
            case POP:
                if (j>0)
                {
                    res[j - 1] = 0;
                    j--;
                    i++;
                    currentState = automata[currentState][currentMove].right; 
                    break; 
                } 
                else 
                { 
                    ressssssss = 1;
                    break; 
                } 
            case REPEAT:
                currentState = automata[currentState][currentMove].right; 
                break; 
            case CONTINUE:
                i++;
                currentState = automata[currentState][currentMove].right; 
                break; 
            default: 
                res[j] = automata[currentState][currentMove].right;
                j++;
                i++; 
                currentState = automata[currentState][currentMove].right; 
                break; 
        } 
        
        if (ressssssss == 1) 
            break; 
    } 
    for (j = 0; j<resLen; j++)
    { 
        if (res[j] != 0)
            resNumbers++; 
    } 
    
    return resNumbers; 
} 
