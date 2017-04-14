int		ft_strcmp(const char *s1, const char *s2)
{
	if ((*s2 != '\0') && (*s1 != '\0') && (*s1 == *s2))
		return (ft_strcmp(++s1, ++s2));
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
