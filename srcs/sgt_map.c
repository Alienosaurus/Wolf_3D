#include <unistd.h>

char	**sgt_map(char **map)
{
	static char		**s = NULL;

	if (map)
		s = map;
	return (s);
}
