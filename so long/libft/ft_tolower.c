/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:26:52 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/02/14 14:27:49 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int g)
{
	if (g >= 'A' && g <= 'Z')
		return (g + 32);
	else
		return (g);
}
