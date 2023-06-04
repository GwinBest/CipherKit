#include "railfence.h"

void railfenceCipher(const char* plainString, char* cipherString, const unsigned railsCount, const unsigned mode)
{
	const unsigned plainStringLength = strlen(plainString);

	unsigned railLetter = 0;
	unsigned currentRail = 0;
	
		switch (mode)
		{
			case DECODE:
			{
                railfenceDecode(plainString, railsCount, cipherString);
				break;
			}
			case ENCODE:
			{
                railfenceEncode(plainString, railsCount, cipherString, plainStringLength);
                break;
			}
			default:
				break;
		}
}

void railfenceDecode(const char* cipherString, const unsigned railsCount, char* plainString)
{
    int stringLength = strlen(cipherString);

    char** fence = (char**)malloc(railsCount * sizeof(char*));
    for (size_t i = 0; i < railsCount; i++)
        fence[i] = (char*)malloc(stringLength * sizeof(char));

    for (int i = 0; i < railsCount; i++)
    {
        for (int j = 0; j < stringLength; j++)
            fence[i][j] = '\n';
    }

    unsigned currentRow = 0;
    Bool isIncreaseRow = TRUE;

    for (int i = 0; i < stringLength; i++) {
        fence[currentRow][i] = '*';

        if (currentRow == 0)
            isIncreaseRow = TRUE;
        else if (currentRow == railsCount - 1) 
            isIncreaseRow = FALSE;

        if (isIncreaseRow) 
            currentRow++;
        else 
            currentRow--;
    }

    int index = 0;
    for (int i = 0; i < railsCount; i++) {
        for (int j = 0; j < stringLength; j++) {
            if (fence[i][j] == '*') {
                fence[i][j] = cipherString[index++];
            }
        }
    }

    currentRow = 0;
    isIncreaseRow = TRUE;

    for (int i = 0; i < stringLength; i++) {
        plainString[i] = fence[currentRow][i];

        if (currentRow == 0)
            isIncreaseRow = TRUE;
        else if (currentRow == railsCount - 1)
            isIncreaseRow = FALSE;
   
        if (isIncreaseRow)
            currentRow++;
        else
            currentRow--;
    }
    plainString[stringLength] = '\0';

    for (size_t i = 0; i < railsCount; i++)
        free(fence[i]);
    free(fence);
}

void railfenceEncode(const char* plainString, const unsigned railsCount, char* cipherString, const unsigned plainStringLength)
{
    char** fence = (char**)malloc(railsCount * sizeof(char*));
    for (size_t i = 0; i < railsCount; i++)
        fence[i] = (char*)malloc(plainStringLength * sizeof(char));


    for (size_t i = 0; i < railsCount; i++)
    {
        for (size_t j = 0; j < plainStringLength; j++) 
            fence[i][j] = '\n';
    }


    unsigned currentRow = 0;
    Bool isIncreaseRow = TRUE;

    for (size_t i = 0; i < plainStringLength; i++) {
        fence[currentRow][i] = plainString[i];

        if (currentRow == 0)
            isIncreaseRow = TRUE;
        else if (currentRow == railsCount - 1) 
            isIncreaseRow = FALSE;
        

        if (isIncreaseRow) 
            currentRow++;
        else 
            currentRow--;
    }

    int index = 0;
    for (size_t i = 0; i < railsCount; i++) 
    {
        for (size_t j = 0; j < plainStringLength; j++) 
        {
            if (fence[i][j] != '\n')
                cipherString[index++] = fence[i][j];
        }
    }
    cipherString[index] = '\0';

    for (size_t i = 0; i < railsCount; i++)
        free(fence[i]);
    free(fence);
}

