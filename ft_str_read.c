#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/**
 * Compare each char of s1 and s2.
 * @return 0 if both strings are the same or the difference in the ascii table
 * between the first different character.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i < n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}

/**
 * @return a pointer to the first occurrence of the character c in the string s.
 * @note The terminating null byte is considered part of the string, so that if
 * c is specified as '\0', these functions return a pointer to the terminator.
*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if ((char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/**
 * @return a pointer to the last occurrence of the character c in the string s.
 * @note The terminating null byte is considered part of the string, so that if
 * c is specified as '\0', these functions return a pointer to the terminator.
*/
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if ((char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = ft_strlen(s);
	while (i-- > 0)
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	return (NULL);
}

/**
 * Locates the first occurrence of the null-terminated string little in the
 * string big, where not more than len characters are searched.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return (&((char *)big)[i]);
		}
		i++;
	}
	return (NULL);
}
