#include <stdlib.h>
#include <stdio.h>

int get_list_len(int s, int e)
{
	int len = 0;

	if (s <= e)
	{
		while (s <= e)
		{
			len++;
			s++;
		}
	}
	else{
		while (e <= s)
		{
			len++;
			e++;
		}
	}
	return (len);
}

int *ft_rrange(int start, int end)
{
	int *tab;
	int len;
	int i = 0;

	len = get_list_len(start, end);
	tab = (int *)malloc(sizeof(int) * len);
	if (!tab)
		return (NULL);
	if (start <= end)
	{
		while (start <= end)
		{
			tab[i] = end;
			end--;
			i++;
		}
	}
	else
	{
		while (start >= end)
		{
			tab[i] = end;
			end++;
			i++;
		}
	}
	return (tab);
}

// int main(void)
// {
// 	// printf("%d\n", get_list_len(1, 3));
// 	// printf("%d\n", get_list_len(-1, 2));
// 	// printf("%d\n", get_list_len(0, 0));
// 	// printf("%d\n", get_list_len(0, -3));

// 	int *tab;
// 	int i;

// 	tab = ft_rrange(1, 3);
// 	i = 0;
// 	while (i < get_list_len(1, 3))
// 	{
// 		printf("%d ", tab[i]);
// 		i++;
// 	}
// 	printf("\n");

// 	tab = ft_rrange(-1, 2);
// 	i = 0;
// 	while (i < get_list_len(-1, 2))
// 	{
// 		printf("%d ", tab[i]);
// 		i++;
// 	}
// 	printf("\n");

// 	tab = ft_rrange(0, 0);
// 	i = 0;
// 	while (i < get_list_len(0, 0))
// 	{
// 		printf("%d ", tab[i]);
// 		i++;
// 	}
// 	printf("\n");

// 	tab = ft_rrange(0, -3);
// 	i = 0;
// 	while (i < get_list_len(0, -3))
// 	{
// 		printf("%d ", tab[i]);
// 		i++;
// 	}
// 	printf("\n");
// }