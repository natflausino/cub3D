#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <sys/param.h>
# include <sys/resource.h>

//# define MAX_FILE_DESCRIPTOR	RLIMIT_NOFILE
//# define BUFFER_SIZE	32

# define READ_LINE		1
# define NEW_LINE		1
# define NO_NEW_LINE	0
# define POINTER		'p'

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	32
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_get_next_line
{
	char		read[BUFFER_SIZE + 1];
	char		*temp;
	char		*break_line_ptr;
	int			read_return;
}				t_gnl;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strclen(const char *str, const char c);
void	ft_strdel(char **str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin_free(char *dest, char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen_ptr(char **s);
int		c_split(char const *str, char c);
char	*ft_strndup(const char *str, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
void	ft_putendl(char *s);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		str_free(char *str, int i);
int		get_next_line(const int fd, char **line);
char	*ft_strsub(char *str, int start, int len);
void	*ft_calloc(size_t count, size_t size);
int		ft_tolower(int c);
char	*ft_itoa(int n);

#endif
