#include "get_next_line.h"

static	char			*ft_joinchr(char const *line, char c, size_t len)
{
	char		*s;
	size_t		i;

	if (!(s = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
		s[i++] = (*line) ? *line++ : c;
	s[i] = '\0';
	return (s);
}

int						get_next_line(char **line)
{
	char		buffer;
	int			res;
	char		*tmp;
	size_t		len;

	if (!line || !(*line = (char *)malloc(1)))
		return (-1);
	**line = '\0';
	len = 0;
	while ((res = read(0, &buffer, 1)) > 0 && buffer != '\n')
	{
		if (!(tmp = ft_joinchr(*line, buffer, ++len)))
			return (-1);
		free(*line);
		*line = tmp;
	}
	return (res);
}
