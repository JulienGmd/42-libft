/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:48:19 by jgrimaud          #+#    #+#             */
/*   Updated: 2024/02/15 01:04:29 by jgrimaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// char

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

// str

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strdup(const char *s, t_list **ptr_list);
char	*ft_strjoin(char const *s1, char const *s2, t_list **ptr_list);
char	*ft_substr(char const *s, unsigned int start, size_t len, t_list **ptr_list);
char	*ft_strtrim(char const *s1, char const *set, t_list **ptr_list);
char	**ft_split(char const *s, char c, t_list **ptr_list);

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char), t_list **ptr_list);

// mem

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// conv

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n, t_list **ptr_list);

// fd

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// lst

t_list	*ft_lstnew(void *content, t_list **ptr_list);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *), t_list **ptr_list);
bool	ft_lstdelshift(t_list **lst, void *content, void (*del)(void *), t_list **ptr_list);
void	ft_lstclear(t_list **lst, void (*del)(void *), t_list **ptr_list);

int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *), t_list **ptr_list);

// alloc

void	add_to_ptr_list(void *ptr, t_list **ptr_list);
void	ft_free(void **ptr, t_list **ptr_list);
void	cleanup(t_list **ptr_list);

void	*check_ptr(void *ptr, t_list **ptr_list);
void	*ft_malloc(size_t size, t_list **ptr_list);
void	*ft_calloc(size_t nmemb, size_t size, t_list **ptr_list);
void	*ft_realloc(void *ptr, size_t size, size_t old_size, t_list **ptr_list);

void	**ft_malloc_2d(size_t size_y, size_t size_x, size_t element_size, t_list **ptr_list);
void	ft_free_2d(void ***ptr, t_list **ptr_list);



// error

ssize_t write_error(char *msg);
void	expect(int condition, char *msg, t_list **ptr_list);

// exit

void	clean_exit(int status, t_list **ptr_list);
void	clean_exit_with_error(char *msg, t_list **ptr_list);

// math

size_t	ft_min(size_t a, size_t b);
size_t	ft_max(size_t a, size_t b);

#endif
