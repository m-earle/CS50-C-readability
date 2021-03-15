// username mecme

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sent(string s);

int main(void)
{
    string text = get_string("Text:"); //ask user for string
    float letters = count_letters(text); //call function to count letters
    float words = count_words(text); //call function to count words
    float sentences = count_sent(text); //call function to count sentences
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8); //reading level formula
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index); //prints reading level
    }
}

int count_letters(string s) //function that takes in a string and gives out an integer
{
    int letters = 0; //initialize integer variable "letters"
    for (int i = 0, n = strlen(s); i < n; i ++) //for the length of the string
    {
        if (isalpha(s[i]) != 0) //isalpha returns non-zero value if character in array/string is a letter
        {
            letters = letters + 1; //if it is a letter, add one to "letters"
        }
    }
    return letters; //output is total number of letters
}

//assume sentence doesnt start or end with space
//assume no multiple spaces in a row
int count_words(string s) // does same as count letters but for words
{
    int words = 0;
    for (int i = 0, n = strlen(s); i < n + 1; i ++)
    {
        if (isblank(s[i]) != 0 || s[i] == '\0') //isblank checks for spaces or tabs or end of text/array
        {
            words = words + 1;
        }
    }
    return words;
}

// assume . ! or ? indicates end of sentence

int count_sent(string s)
{
    int sentences = 0;
    for (int i = 0, n = strlen(s); i < n + 1; i ++)
    {
        if ((s[i]) == '.' || s[i] == '?' || s[i] == '!')
        {
            sentences = sentences + 1;
        }
    }
    return sentences;
}