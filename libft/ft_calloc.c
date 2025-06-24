/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:48:11 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/11 10:26:36 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = malloc(nmemb * size);
	if (!array)
		return (0);
	else
	{
		ft_bzero(array, nmemb * size);
		return (array);
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
  long * array;
  long * index;
  int    i;
  int  num;
 
  printf( "Enter the size of the array\n" );
  scanf( "%i", &num);
 
                                            
	if ( (index = array = (long *) ft_calloc( num, sizeof( long ))) != NULL )
	{
 
   //for ( i = 0; i < num; ++i )     
		// *index++ = i; 
    for ( i = 0; i < num; ++i )
      printf( "array[%i ] = %li\n", i, array[i] );
  }
  else
  {
    perror( "Out of storage" );
    abort();
  }
}*/
