#include <libft.h>

#include "open_map.h"
#include "sgt_bin_name.h"
#include "wolf.h"

int		main(int ac, char **av)
{
	sgt_bin_name(av[0]);
	if (ac != 2)
		return (ft_putendl(USAGE), 0);
	if (open_map(av[1]) == -1)
		return (ft_error(sgt_bin_name(0), ": open map.", 0), 1);
	ft_wolf();
	return (0);
}
