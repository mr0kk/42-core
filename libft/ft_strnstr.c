/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:45:28 by rmrok             #+#    #+#             */
/*   Updated: 2025/01/03 12:45:28 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	unsigned int i;
	unsigned int j;
	size_t big_len;

	big_len = ft_strlen(big);
	if (!small[0])
		return ((char *)big);
	i = 0;
	while (i < big_len && len != 0)
	{
		if (big[i] == small[0])
		{
			j = 0;
			while (j < len && i + j < big_len)
			{
				if (big[i + j] != small[j])
					break ;
				else
					j++;
			}
			if (j == len)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

// void test_ft_strnstr() {
//     const char *tests[][3] = {
//         {"Hello, World!", "World", "12"}, 
	// Test 1: Substring is found within len
//         {"Hello, World!", "World", "5"}, 
	// Test 2: Substring is not within len
//         {"Hello, World!", "Hello", "12"},
	// Test 3: Substring at the beginning
//         {"Hello, World!", "", "12"},      // Test 4: Empty substring
//         {"Hello, World!", "XYZ", "12"},   // Test 5: Substring not found
//         {"", "World", "12"},              // Test 6: Empty big string
//         {"Hello, World!", "World", "0"},  // Test 7: len is 0
//         {"abcabcabc", "abc", "9"},       
	// Test 8: Multiple occurrences of substring
//         {"Hello, World!", "o, W", "12"},  // Test 9: Substring in the middle
//         {"Hello, World!", "Hello, World!", "5"},
	// Test 10: len is smaller than the substring
//     };

//     printf("Testing ft_strnstr...\n");
//     for (int i = 0; i < 10; i++) {
//         const char *big = tests[i][0];
//         const char *small = tests[i][1];
//         size_t len = (size_t)atoi(tests[i][2]);

//         printf("\nTest %d:\n", i + 1);
//         printf("big: \"%s\"\nsmall: \"%s\"\nlen: %zu\n", big, small, len);

//         char *result = ft_strnstr(big, small, len);
//         if (result)
//             printf("ft_strnstr result: \"%s\"\n", result);
//         else
//             printf("ft_strnstr result: NULL\n");

//        
	// Porównanie z funkcją oryginalną strnstr (dla platform wspierających tę funkcję)
//         #ifdef __BSD_VISIBLE
//         char *expected = strnstr(big, small, len);
//         if (expected)
//             printf("strnstr (original) result: \"%s\"\n", expected);
//         else
//             printf("strnstr (original) result: NULL\n");
//         #endif
//     }
// }

// int main()
// {
//     // char str1[] = "alicja ma kopa";
//     // char str2[] = "kota";

//     // printf("%s\n", str1);
//     // printf("ft_strnstr: %s\n", ft_strnstr(str1, str2, 2));
//     // printf("test: %s\n", str1 + 10);

//     test_ft_strnstr();
// }