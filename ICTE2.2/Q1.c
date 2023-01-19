#include <stdio.h>

int main(){
    char inp_str[20];
    char *p;
    int vowels = 0;
    int cons = 0;

    printf("Input a String: ");
    scanf("%s", inp_str);

    p = inp_str;

    while (*p != '\0') {
        //Counting vowels
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' || 
            *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U') {
            vowels++;
        } 
        //Counting consonants
        else if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
            cons++;
        }

        p++;
    }

    //Printing number of vowels and consonants
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", cons);

    return 0;
}
