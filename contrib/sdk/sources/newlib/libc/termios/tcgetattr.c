#include <errno.h>
#include <termios.h>

extern int __conio_attributes;

int tcgetattr (int fd, struct termios *termios_p)
{
	if (fd < 0)
	{
		__set_errno (EBADF);
		return -1;
	}
	if (termios_p == NULL)
	{
		_set_errno (EINVAL);
		return -1;
	}

	__set_errno (ENOSYS);
	return -1;
}
