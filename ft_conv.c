#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	while (ft_isspace(nptr[0]))
		nptr++;
	if (nptr[0] == '+' || nptr[0] == '-')
	{
		if (nptr[0] == '-')
			sign = -sign;
		nptr++;
	}
	while (ft_isdigit(nptr[0]))
	{
		if (nbr > (LONG_MAX - (nptr[0] - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nbr = nbr * 10 + nptr[0] - '0';
		nptr++;
	}
	return (sign * nbr);
}

static int	ft_itoa_get_str_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_itoa_get_str_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		str[len - 1] = (n % 10) * ((n > 0) * 2 - 1) + '0';
		n /= 10;
		len--;
	}
	return (str);
}