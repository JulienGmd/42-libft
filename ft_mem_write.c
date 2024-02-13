#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

/**
 * Erases the data in the n bytes of the memory starting at the location pointed
 * to by s, by writing zeros (bytes containing '\0') to that area.
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/**
 * @note The memory area may overlap, so if dest is AFTER src, it will reverse
 * copy.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	return (dest);
}
