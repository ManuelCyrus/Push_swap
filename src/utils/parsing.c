#include "../../include/push_swap.h"

/* contar palavras */
static int word_count(const char *s, char c)
{
    int i=0,count=0;
    while(s[i])
    {
        while(s[i]==c) i++;
        if(s[i]) count++;
        while(s[i] && s[i]!=c) i++;
    }
    return count;
}

/* tamanho palavra */
static int word_len(const char *s, char c)
{
    int i=0;
    while(s[i] && s[i]!=c) i++;
    return i;
}

/* ft_split */
char **ft_split(const char *s, char c)
{
    char **res = malloc(sizeof(char*)*(word_count(s,c)+1));
    int i=0,j=0,start,len;
    if(!res) return NULL;
    while(s[i])
    {
        while(s[i]==c) i++;
        if(!s[i]) break;
        start=i;
        len=word_len(&s[i],c);
        res[j]=malloc(len+1);
        for(int k=0;k<len;k++) res[j][k]=s[start+k];
        res[j][len]='\0';
        i+=len;
        j++;
    }
    res[j]=NULL;
    return res;
}

/* free split */
static void free_split(char **tab)
{
    int i=0;
    while(tab[i]) free(tab[i++]);
    free(tab);
}



void check_duplicates(t_stack *a)
{
    t_node *i = a->top;
    for(int c1=0; c1 < a->size; c1++)
    {
        t_node *j = i->next;
        for(int c2 = c1+1; c2 < a->size; c2++)
        {
            if(i->data == j->data)
                error_free(a,NULL);
            j = j->next;
        }
        i = i->next;
    }
}

void parse_args(t_stack *a,int ac,char **av)
{
    long n;
    for(int i=1;i<ac;i++)
    {
        n = ft_atol(av[i],a);
        if(n>2147483647||n<-2147483648) error_free(a,NULL);
        push_bottom(a,new_node((int)n));
    }
}

void parse_string(t_stack *a,char *str)
{
    char **nums = ft_split(str,' ');
    int i=0;
    long n;
    if(!nums || !nums[0]) error();
    while(nums[i])
    {
        n = ft_atol(nums[i], a);
        if(n>2147483647||n<-2147483648) error_free(a,NULL);
        push_bottom(a,new_node((int)n));
        i++;
    }
    free_split(nums);
}