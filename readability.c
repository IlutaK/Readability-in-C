#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    // prompt user for some text
    string text = get_string("Text: ");
    // count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // calculate average per 100 words
    float L = ((float) letters / words * 100);
    float s = ((float) sentences / words * 100);
    // Comupte the Coleman-Liau index
    float index_0 = 0.0588 * L - 0.296 * s - 15.8;
    // Round to nearest whole number
    int index = round(index_0);
    // Print the grade level
    if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
        return 0;
    }
}
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i])) // check wheter a character is alphabetical
        {
            letters++;
        }
    }
    return letters;
    // return the number of letters in text
}

int count_words(string text)
{
    int words = 1; // start with 1 because text wont finish with space
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i])) //  check wheter a character is whitespace

        {
            words++;
        }
    }
    return words;
    // return the number of words in text
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // return the number of sentences in text
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
    // return the number of words in text
}
