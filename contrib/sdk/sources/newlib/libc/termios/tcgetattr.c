#include <errno.h>
#include <termios.h>

extern int __conio_attributes;

int tcgetattr (int fd, struct termios *termios_p)
{
	if (fd < 0)
	{
		errno = EBADF;
		return -1;
	}
	if (termios_p == NULL)
	{
		errno = EINVAL;
		return -1;
	}

	errno = ENOSYS;
	return -1;
}
