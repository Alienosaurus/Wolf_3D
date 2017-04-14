#include <unistd.h>

char	*sgt_bin_name(char *s)
{
	static char		*t = NULL;

	if (s)
		t = s;
	return (t);
}
