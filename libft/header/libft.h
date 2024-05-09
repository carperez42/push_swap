/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:25:37 by carperez          #+#    #+#             */
/*   Updated: 2023/09/25 13:25:37 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

//<ctype.h>
int				ft_isalpha(int nChar);
int				ft_isdigit(int nChar);
int				ft_isalnum(int nChar);
int				ft_isascii(int nChar);
int				ft_isprint(int nChar);
int				ft_toupper(int nChar);
int				ft_tolower(int nChar);

//<string.h>
void			*ft_memset(void *sOri, int nChar, size_t nChg);
void			ft_bzero(void *sOri, size_t nChg);
void			*ft_memcpy(void *sDest, const void *sOri, size_t nChg);
void			*ft_memmove(void *sDest, const void *sOri, size_t nChg);
void			*ft_memchr(const void *sOri, int nChar, size_t nCmp);
int				ft_memcmp(const void *s1, const void *s2, size_t nCmp);
int				ft_strncmp(const char *s1, const char *s2, size_t nCpy);
size_t			ft_strlen(const char *sOri);
size_t			ft_strlcpy(char *sDest, const char *sOri, size_t nCpy);
size_t			ft_strlcat(char *sDest, const char *sOri, size_t nCpy);
char			*ft_strchr(const char *sOri, int nChar);
char			*ft_strrchr(const char *sOri, int nChar);
char			*ft_strnstr(const char *sMain, const char *sSub, size_t nCmp);
char			*ft_strdup(const char *sCpy);

//<stdlib.h>
int				ft_atoi(const char *sNum);
void			*ft_calloc(size_t nDimension, size_t tData);

//ADITIONAL FUNCTIONS
char			*ft_substr(char const *sOri, unsigned int start, size_t len);
char			*ft_strjoin(char const *sFront, char const *sBack);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *sMain, char cCmp);
void			ft_array_free(char **aPointers, size_t nDim);
char			*ft_itoa(int nStr);
long			ft_atol(const char *s);
char			*ft_strmapi(char const *sOri, char (*f)(unsigned int, char));
void			ft_striteri(char *sChg, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char cPrint, int fDscp);
void			ft_putstr_fd(char *sPrint, int fDscp);
void			ft_putendl_fd(char *sPrint, int fDscp);
void			ft_putnbr_fd(int nPrint, int fDscp);

//LIST simple link
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *pStart);
int				ft_lstsize(t_list *pStart);
void			ft_lstadd_front(t_list **pStart, t_list *pNew);
void			ft_lstadd_back(t_list **pStart, t_list *pNew);
void			ft_lstdelone(t_list *pNodo, void (*del)(void*));
void			ft_lstclear(t_list **pNodo, void (*del)(void*));
void			ft_lstiter(t_list *pStart, void (*f)(void *));
t_list			*ft_lstmap(t_list *pNodo, void *(*f)(void *),
					void (*del)(void *));

//LIST double link
typedef struct s_node
{
	void			*content;
	struct s_node	*p_prev;
	struct s_node	*p_next;
}					t_node;

typedef struct s_catalog
{
	int		n_nodes;
	t_node	*p_first;
	t_node	*p_last;
	t_node	*p_current;
}					t_catalog;

t_node			*ft_newnode(void *content);
void			ft_init_catalog(t_catalog **pHeader);
void			ft_addnode_front(t_catalog **pHeader, t_node *pNode);
void			ft_add_aftercurrent(t_catalog **pHeader, t_node *pNode);
void			ft_addnode_back(t_catalog **pHeader, t_node *pNode);
void			ft_add_beforecurrent(t_catalog **pHeader, t_node *pNode);
void			ft_delnode_front(t_catalog **pHeader, void (*del)(void*));
void			ft_del_aftercurrent(t_catalog **pHeader, void (*del)(void*));
void			ft_del_current(t_catalog **pHeader, void (*del)(void*));
void			ft_clear_catalog(t_catalog **pHeader, void (*del)(void*));

//FT_PRINTF
typedef struct s_set
{
	va_list	lst_items;
	int		f_zero[2];
	int		f_sign[2];
	int		f_left[2];
	int		f_prefix[2];
	int		f_space[2];
	int		f_dot[2];
	int		l_gap_1[2];
	int		l_gap_2[2];
	int		f_error;
	int		l_arg;
	char	c_type;
}			t_set;

int				ft_printf(char const *sPrint, ...);
void			ft_set_starter(t_set *pSet);
int				ft_set_type(char const cCmp, t_set *pSet);
void			ft_set_capturer_1(char const *sToken, t_set *pSet);
void			ft_set_capturer_2(char const *sToken, t_set *pSet);
void			ft_set_gapfiller(char const *sToken, t_set *pSet);
void			ft_set_validator(char const *sToken, t_set *pSet);
char			ft_toupper_char(char chng, char cFlag);
char			*ft_hexa_prefix(char *sDest, t_set sSet);
char			*ft_itoa_hex(t_set *pSet, int nOri);
char			*ft_itoa_ptr(t_set *pSet, unsigned long long nOri);
char			*ft_itoa_uns(unsigned int nStr);
char			*ft_buffer_creator(size_t nDimension, char cFiller);
void			ft_print_chr(t_set *pSet, int *nPrinted);
char			*ft_print_str(t_set *pSet, int *nPrinted);
char			*ft_print_int(t_set *pSet, int *nPrinted);
char			*ft_print_hex(t_set *pSet, int *nPrinted);
char			*ft_print_ptr(t_set *pSet, int *nPrinted);
char			*ft_print_uns(t_set *pSet, int *nPrinted);
void			ft_array_free(char **aPointers, size_t nDim);
#endif