#include"morse.h"

void morseCipher(const char* plainString, char* cipherString, const unsigned mode)
{
    letterPosition position;
    size_t plainStringletterPosition = 0;
    size_t cipherStringLetterPosition = 0;

    while (plainString[plainStringletterPosition] != '\0' && plainStringletterPosition < strlen(plainString))
    {
        switch (mode)
        {
        case DECODE:
        {
            position.lettterInMorseAlphabet = findLetterPositionInMorseAlphabet(plainString, &plainStringletterPosition);
            decode(cipherString, position.letterInEnglishAlphabet, &cipherStringLetterPosition);
            break;
        }
        case ENCODE:
        {
            position.letterInEnglishAlphabet = findLetterPositionInEnglishAlphabet(plainString[plainStringletterPosition]);
            encode(cipherString, position.letterInEnglishAlphabet, &cipherStringLetterPosition);
            plainStringletterPosition++;
            break;
        }
        default:
            break;
        }
    }
    cipherString[cipherStringLetterPosition] = '\0';
}

void morsePlaySound(const char* cipherString)
{
    char* threadCipherString = strdup(cipherString);

    size_t position = 0;
    while (threadCipherString[position] != '\0')
    {
        if (threadCipherString[position] == '.')
        {
            PlaySound(L"./resources/dot.wav", 0, SND_SYNC);
        }
        else if (threadCipherString[position] == '-')
        {
            PlaySound(L"./resources/dash.wav", 0, SND_SYNC);
        }
        else if (threadCipherString[position] == ' ' && threadCipherString[position + 1] == ' ')
            SILENCE_BETWEEN_WORDS;
        else
            SILENCE_BETWEEN_LETTERS;

        position++;
    }

    free(threadCipherString);
}

void decode(char* decodedString, const int letterPositionInMorseAlphabet, int* decodedStringPosition)
{
    decodedString[*decodedStringPosition] = alphabet[letterPositionInMorseAlphabet].english;
    (*decodedStringPosition)++;
}

void encode(char* cipherString, const int letterPositionInEnglishAlphabet, int* cipherStringLetterPosition)
{
    size_t position = 0;
    while (alphabet[letterPositionInEnglishAlphabet].morse[position] != '\0')
    {
        cipherString[*cipherStringLetterPosition] = alphabet[letterPositionInEnglishAlphabet].morse[position];
        (*cipherStringLetterPosition)++;
        position++;
    }
    cipherString[*cipherStringLetterPosition] = ' ';
    (*cipherStringLetterPosition)++;
}

