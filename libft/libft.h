/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:52:25 by tching            #+#    #+#             */
/*   Updated: 2025/09/27 12:48:46 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

/* ************************************************************************** */
/*                                 STRUCT                                     */
/* ************************************************************************** */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ************************************************************************** */
/*                                  CHECK                                     */
/* ************************************************************************** */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
/* ************************************************************************** */
/*                                 STRING                                     */
/* ************************************************************************** */
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(char const *str);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(char const *s1);
char	*ft_strchr(char const *s, int c);
char	*ft_strrchr(char const *s, int c);
char	*ft_strnstr(char const *haystack, char const *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlen(char const *s);
size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char const *src, size_t dstsize);
/* ************************************************************************** */
/*                                  PRINT                                     */
/* ************************************************************************** */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/* ************************************************************************** */
/*                                 MEMORY                                     */
/* ************************************************************************** */
int		ft_memcmp(void const *s1, void const *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t n);
void	*ft_memcpy(void *dst, void const *src, size_t n);
void	*ft_memmove(void *dst, void const *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
/* ************************************************************************** */
/*                                 LIST                                       */
/* ************************************************************************** */
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
/* ************************************************************************** */
/*                              ADDITIONALS                                   */
/* ************************************************************************** */
int		ft_strcmp(char *s1, char *s2);
int		ft_isspace(int c);

#endif
