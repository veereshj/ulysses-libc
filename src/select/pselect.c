#include <sys/select.h>
#include "syscall.h"
#include "libc.h"

int pselect(int n, fd_set *restrict rfds, fd_set *restrict wfds, fd_set *restrict efds, const struct timespec *restrict ts, const sigset_t *restrict mask)
{
	long data[2] = { (long)mask, __SYSCALL_SSLEN };
	struct timespec ts_tmp;
	if (ts) ts_tmp = *ts;
	return syscall_cp(SYS_pselect6, n, rfds, wfds, efds, ts ? &ts_tmp : 0, data);
}
