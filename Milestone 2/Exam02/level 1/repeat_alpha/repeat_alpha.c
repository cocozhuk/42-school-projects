/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:59:17 by kzhu              #+#    #+#             */
/*   Updated: 2026/01/16 16:00:01 by kzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    int j;
    
    /* check the number of argument
     */
    if (ac == 2)
    {
        i = 0;
        /* loop over the whole string
         */
        while (av[1][i])
        {
            /* if the character is an upper-case letter
             */
            if (av[1][i] >= 65 && av[1][i] <= 90)
            {
                j = 0;
                /* loop while the j is smaller than the alphabetical
                 * index of the current character
                 * - 64 is to get the alphabetical index
                 * A in ASCII => 65, so 65 - 64 = 1
                 * Z in ASCII => 90, so 90 - 64 = 26
                 */
                while (j < av[1][i] - 64)
                {
                    write(1, &av[1][i], 1);
                    j++;
                }
            }
            else if (av[1][i] >= 97 && av[1][i] <= 122)
            {
                j = 0;
                /* loop while the j is smaller than the alphabetical
                 * index of the current character
                 * - 96 is to get the alphabetical index
                 * a in ASCII => 97, so 97 - 96 = 1
                 * z in ASCII => 122, so 122 - 96 = 26
                 */
                while (j < av[1][i] - 96)
                {
                    write(1, &av[1][i], 1);
                    j++;
                }
            }
            else
                /* if the current character is not a letter
                 * simply write the character
                 */
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
