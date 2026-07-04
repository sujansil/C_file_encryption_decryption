#include <stdio.h>
#include <string.h>

char encode(char);

char encode(char letter)
{
    char letter_encoded;

    if (letter <= 123)
    {
        letter_encoded = letter + 3;
    }
    else
    {
        letter_encoded = (letter + 3) - 95;
    }
    return letter_encoded;
}

char decode(char);
char decode(char letter)
{
    char letter_decrypted;
    if (letter >= 35)
    {
        letter_decrypted = letter - 3;
    }
    else
    {
        int temp;
        temp = letter - 2;
        letter_decrypted = 126 - (32 - temp);
    }
    return letter_decrypted;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./cypher <mode> <filename>\n");
        return 1;
    }

    int is_encodnig;
    if (strcmp(argv[1], "-e") == 0)
    {
        is_encodnig = 1;
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
        is_encodnig = -1;
    }
    else
    {
        printf("Error: Invalid mode '%s'. Use -e or -d.\n", argv[1]);
        return 1;
    }

    FILE *ptr;
    FILE *ptr2;
    ptr = fopen(argv[2], "r");
    
    if (ptr == NULL)
    {
        printf("Error! File Not found");
        return 1;
    }
    
    ptr2 = fopen("dest.txt", "w");

    int ch;
    int i = 0;
    while ((ch = fgetc(ptr)) != EOF)
    {
        char e;
        if (is_encodnig == 1)
        {
            e = encode(ch);
        }
        else if (is_encodnig == -1)
        {
            e = decode(ch);
        }

        fputc(e, ptr2);
        i++;
    }

    fclose(ptr);
    fclose(ptr2);
    if (remove(argv[2]) == 0)
    {
        printf("Original file deleted successfully.\n");
    }
    else
    {
        printf("Error: Could not delete file.\n");
    }

    if (rename("dest.txt", argv[2]) == 0)
    {
        printf("Temporary file renamed successfully.\n");
    }
    else
    {
        printf("Error: Could not rename file.\n");
    }
    if (is_encodnig == 1)
    {
        printf("Encoding Complete");
    }
    else if (is_encodnig == -1)
    {
        printf("Decoding Complet");
    }

    return 0;
}