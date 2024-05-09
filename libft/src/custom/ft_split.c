/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:03:03 by carperez          #+#    #+#             */
/*   Updated: 2023/02/04 18:10:06 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_array_creator(char const *sOri, char cCmp, int *nSubs)
{
	char	**a_new;
	int		*p_numsubs;

	p_numsubs = nSubs;
	*p_numsubs = 0;
	a_new = NULL;
	while (*sOri != '\0')
	{
		while (*sOri == cCmp)
			sOri++;
		if (*sOri != '\0')
			*p_numsubs += 1;
		while (*sOri != '\0' && *sOri != cCmp)
			sOri++;
	}
	a_new = (char **) malloc((*p_numsubs + 1) * sizeof(char *));
	if (a_new != NULL)
		a_new[*p_numsubs] = NULL;
	return (a_new);
}

static int	ft_substring_sizer(const char *sOri, char cCmp)
{
	int	chars;

	chars = 0;
	while (*sOri != '\0' && *sOri != cCmp)
	{
		chars++;
		sOri++;
	}
	return (chars);
}

void	ft_array_free(char **aPointers, size_t nDim)
{
	size_t	ia;

	ia = 0;
	while (ia < nDim)
		free(aPointers[ia++]);
	free(aPointers);
	aPointers = NULL;
}

static char	**ft_array_initializer(char **aPointers, char const *sOri,
				char cCmp, int nSub)
{
	int		ia;

	ia = 0;
	if ((nSub > 0) && *sOri != '\0')
	{
		while (ia < nSub)
		{
			while (*sOri == cCmp)
				sOri ++;
			aPointers[ia] = ft_substr(sOri, 0, ft_substring_sizer(sOri, cCmp));
			if (aPointers[ia] == NULL)
			{
				ft_array_free(aPointers, ia);
				return (NULL);
			}
			sOri += ft_substring_sizer(sOri, cCmp);
			ia ++;
		}
	}
	return (aPointers);
}

char	**ft_split(char const *sMain, char cCmp)
{
	char	**a_pointers;
	int		n_subs;

	a_pointers = NULL;
	if (sMain != NULL)
	{
		a_pointers = ft_array_creator(sMain, cCmp, &n_subs);
		if (a_pointers != NULL)
			a_pointers = ft_array_initializer(a_pointers, sMain, cCmp, n_subs);
	}
	return (a_pointers);
}
// Firt --> COUNT the substrings and CREATE the array of pointers + 1, and
// INITIALIZE the last pointer to NULL.
// Second --> INITIALIZE the each pointer of the array with prior substring 

// The user has to free the array of substrings calculating the dimension
// until pointer NULL.

//ft_strlen.c ft_substr.c ft_strlcpy.c are embedded functions.

/*int main()
{
	char **arra = ft_split("hello!",  'e');
	int ib=0;
	while (arra[ib] != NULL)
	{
		//printf("%d----%p-------%s\n",ib,&arra[ib],arra[ib]);
		ib++;
	}
	//printf("%d----%p-------%s\n",ib,&arra[ib],arra[ib]);
	//printf("%d\n",ib);
	arra[0] = NULL;

	ft_array_free(arra,ib);
	return (0);
}*/