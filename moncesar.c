
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int ft_islower(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int ft_isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

char *ft_tocesar(char *str,int j)
{
    int l;
    char *cesar;
    int i;
    char temp;

    i = 0;
    l = ft_strlen(str);
    cesar = (char *)malloc(sizeof(char)*(l + 1));
    while (str[i] != '\0')
    {
        temp = str[i];
        if (ft_isupper(temp))
        {
            cesar[i] = ((temp + j - 65) % 26) + 65; 
        }
        else if (ft_islower(temp))
        {
            cesar[i] = ((temp + j - 97) % 26) + 97;
        }
        else if (!ft_isupper(temp) && !ft_isupper(temp))
        {
            cesar[i] = temp;
        }
        i++;
    }
    
    cesar[i] = '\0';
    return cesar;
}

int main()
{
    char message[512];
    char *m;
    int cle;
  
    printf("Chiffrement césar\n\n");
    printf("Saisir un message à chiffrer : ");
    scanf("%s",message);

    printf("enter le clé pour chiffré : ");

    scanf("%d",&cle);
    printf("Chiffrement césar donne %s\n",ft_tocesar(message,cle));
}
