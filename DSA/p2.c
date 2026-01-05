#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*void readstring(str,size_t maxlen,const char*label)
void stringlength(const char*str)
void ismatch(str,pat,pos)
void replacestring(str,pat,rep,result)
*/
void readString(char str[],size_t maxlen , const char* label)
{
    int c;
    printf("enter the %s: ", label);
    if (fgets(str,(int)maxlen,stdin)==NULL)
    {
        str[0]='\0';
        return;
    }
    size_t len = strlen(str);
    if (len>0 && str[len-1]=='\n')
    {
        str[len-1]='\0';
    }
    else
    {
        while ((c=getchar()) !='\n' && c!=EOF);
        {}
    }
}
//function to calculate string length
int stringLength(const char* str)
{
    int length=0;
    while (str[length]!='\0')
    {
        length++;
    }
    return length;
}
// function to check if PAT matches STR at a givnen position
int isMatchAtPosition(char str[],char pat[], int pos)
{
    int i=0;
    while (pat[i]!='\0')
    {
        // compare string with pattern , if equal all pattern charcters should be traversed , if not equal return 0
        if (str[pos+i]!=pat[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}
// function to replace all occurrences of PAT in STR with REP
void replacePattern(char str[], char pat[], char rep[],char result[])
    {
    int i =0 , j=0;
    int found =0;
    int lenSTR = stringLength(str);
    int lenPAT = stringLength(pat); 
    int lenREP = stringLength(rep);
    while (i<lenSTR)
    {
        if(isMatchAtPosition(str, pat, i)){
            found=1;
            for(int k=0;k<lenREP;k++)
            {
                result[j++]=rep[k];
            }
            i+=lenPAT;
        }
        else
        {
            result[j++]=str[i++];
        }
    }
    result[j]='\0';
    if (found){
        printf("\nUpdated String: %s\n", result);
    }
    else{
        printf("\nPattern not found in the string.\n");
    }
}

int main(void)
{
    /* small driver to test replacePattern */
    char str[512];
    char pat[128];
    char rep[128];
    char result[1024];

    readString(str, sizeof(str), "input string");
    readString(pat, sizeof(pat), "pattern to replace");
    readString(rep, sizeof(rep), "replacement string");

    replacePattern(str, pat, rep, result);

    return 0;
}