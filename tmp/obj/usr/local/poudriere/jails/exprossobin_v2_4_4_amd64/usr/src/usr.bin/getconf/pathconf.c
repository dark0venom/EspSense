/*
 * Copyright is disclaimed as to the contents of this file.
 *
 * $FreeBSD$
 */

#include <sys/types.h>

#include <string.h>
#include <unistd.h>

#include "getconf.h"

/*
 * Override gperf's built-in external scope.
 */
static const struct map *in_word_set(const char *str);

struct map { const char *name; int key; int valid; };
static const struct map wordlist[] = {
#ifdef _PC_ACL_EXTENDED
	{ "ACL_EXTENDED", _PC_ACL_EXTENDED, 1 },
#else
	{ "ACL_EXTENDED", 0, 0 },
#endif
#ifdef _PC_ACL_NFS4
	{ "ACL_NFS4", _PC_ACL_NFS4, 1 },
#else
	{ "ACL_NFS4", 0, 0 },
#endif
#ifdef _PC_ACL_PATH_MAX
	{ "ACL_PATH_MAX", _PC_ACL_PATH_MAX, 1 },
#else
	{ "ACL_PATH_MAX", 0, 0 },
#endif
#ifdef _PC_CAP_PRESENT
	{ "CAP_PRESENT", _PC_CAP_PRESENT, 1 },
#else
	{ "CAP_PRESENT", 0, 0 },
#endif
#ifdef _PC_FILESIZEBITS
	{ "FILESIZEBITS", _PC_FILESIZEBITS, 1 },
#else
	{ "FILESIZEBITS", 0, 0 },
#endif
#ifdef _PC_INF_PRESENT
	{ "INF_PRESENT", _PC_INF_PRESENT, 1 },
#else
	{ "INF_PRESENT", 0, 0 },
#endif
#ifdef _PC_LINK_MAX
	{ "LINK_MAX", _PC_LINK_MAX, 1 },
#else
	{ "LINK_MAX", 0, 0 },
#endif
#ifdef _PC_MAC_PRESENT
	{ "MAC_PRESENT", _PC_MAC_PRESENT, 1 },
#else
	{ "MAC_PRESENT", 0, 0 },
#endif
#ifdef _PC_MAX_CANON
	{ "MAX_CANON", _PC_MAX_CANON, 1 },
#else
	{ "MAX_CANON", 0, 0 },
#endif
#ifdef _PC_MAX_INPUT
	{ "MAX_INPUT", _PC_MAX_INPUT, 1 },
#else
	{ "MAX_INPUT", 0, 0 },
#endif
#ifdef _PC_MIN_HOLE_SIZE
	{ "MIN_HOLE_SIZE", _PC_MIN_HOLE_SIZE, 1 },
#else
	{ "MIN_HOLE_SIZE", 0, 0 },
#endif
#ifdef _PC_NAME_MAX
	{ "NAME_MAX", _PC_NAME_MAX, 1 },
#else
	{ "NAME_MAX", 0, 0 },
#endif
#ifdef _PC_PATH_MAX
	{ "PATH_MAX", _PC_PATH_MAX, 1 },
#else
	{ "PATH_MAX", 0, 0 },
#endif
#ifdef _PC_PIPE_BUF
	{ "PIPE_BUF", _PC_PIPE_BUF, 1 },
#else
	{ "PIPE_BUF", 0, 0 },
#endif
#ifdef _PC_ALLOC_SIZE_MIN
	{ "POSIX_ALLOC_SIZE_MIN", _PC_ALLOC_SIZE_MIN, 1 },
#else
	{ "POSIX_ALLOC_SIZE_MIN", 0, 0 },
#endif
#ifdef _PC_REC_INCR_XFER_SIZE
	{ "POSIX_REC_INCR_XFER_SIZE", _PC_REC_INCR_XFER_SIZE, 1 },
#else
	{ "POSIX_REC_INCR_XFER_SIZE", 0, 0 },
#endif
#ifdef _PC_REC_MAX_XFER_SIZE
	{ "POSIX_REC_MAX_XFER_SIZE", _PC_REC_MAX_XFER_SIZE, 1 },
#else
	{ "POSIX_REC_MAX_XFER_SIZE", 0, 0 },
#endif
#ifdef _PC_REC_MIN_XFER_SIZE
	{ "POSIX_REC_MIN_XFER_SIZE", _PC_REC_MIN_XFER_SIZE, 1 },
#else
	{ "POSIX_REC_MIN_XFER_SIZE", 0, 0 },
#endif
#ifdef _PC_REC_XFER_ALIGN
	{ "POSIX_REC_XFER_ALIGN", _PC_REC_XFER_ALIGN, 1 },
#else
	{ "POSIX_REC_XFER_ALIGN", 0, 0 },
#endif
#ifdef _PC_SYMLINK_MAX
	{ "SYMLINK_MAX", _PC_SYMLINK_MAX, 1 },
#else
	{ "SYMLINK_MAX", 0, 0 },
#endif
#ifdef _PC_ACL_EXTENDED
	{ "TRUSTEDBSD_ACL_EXTENDED", _PC_ACL_EXTENDED, 1 },
#else
	{ "TRUSTEDBSD_ACL_EXTENDED", 0, 0 },
#endif
#ifdef _PC_ACL_NFS4
	{ "TRUSTEDBSD_ACL_NFS4", _PC_ACL_NFS4, 1 },
#else
	{ "TRUSTEDBSD_ACL_NFS4", 0, 0 },
#endif
#ifdef _PC_ACL_PATH_MAX
	{ "TRUSTEDBSD_ACL_PATH_MAX", _PC_ACL_PATH_MAX, 1 },
#else
	{ "TRUSTEDBSD_ACL_PATH_MAX", 0, 0 },
#endif
#ifdef _PC_CAP_PRESENT
	{ "TRUSTEDBSD_CAP_PRESENT", _PC_CAP_PRESENT, 1 },
#else
	{ "TRUSTEDBSD_CAP_PRESENT", 0, 0 },
#endif
#ifdef _PC_INF_PRESENT
	{ "TRUSTEDBSD_INF_PRESENT", _PC_INF_PRESENT, 1 },
#else
	{ "TRUSTEDBSD_INF_PRESENT", 0, 0 },
#endif
#ifdef _PC_MAC_PRESENT
	{ "TRUSTEDBSD_MAC_PRESENT", _PC_MAC_PRESENT, 1 },
#else
	{ "TRUSTEDBSD_MAC_PRESENT", 0, 0 },
#endif
#ifdef _PC_CHOWN_RESTRICTED
	{ "_POSIX_CHOWN_RESTRICTED", _PC_CHOWN_RESTRICTED, 1 },
#else
	{ "_POSIX_CHOWN_RESTRICTED", 0, 0 },
#endif
#ifdef _PC_NO_TRUNC
	{ "_POSIX_NO_TRUNC", _PC_NO_TRUNC, 1 },
#else
	{ "_POSIX_NO_TRUNC", 0, 0 },
#endif
#ifdef _PC_VDISABLE
	{ "_POSIX_VDISABLE", _PC_VDISABLE, 1 },
#else
	{ "_POSIX_VDISABLE", 0, 0 },
#endif
#ifdef _PC_ASYNC_IO
	{ "_POSIX_ASYNC_IO", _PC_ASYNC_IO, 1 },
#else
	{ "_POSIX_ASYNC_IO", 0, 0 },
#endif
#ifdef _PC_PRIO_IO
	{ "_POSIX_PRIO_IO", _PC_PRIO_IO, 1 },
#else
	{ "_POSIX_PRIO_IO", 0, 0 },
#endif
#ifdef _PC_SYNC_IO
	{ "_POSIX_SYNC_IO", _PC_SYNC_IO, 1 },
#else
	{ "_POSIX_SYNC_IO", 0, 0 },
#endif
	{ NULL, 0, 0 }
};
#include <sys/param.h>
#define	NWORDS	(nitems(wordlist) - 1)
static const struct map *
in_word_set(const char *word)
{
	const struct map *mp;

	for (mp = wordlist; mp < &wordlist[NWORDS]; mp++) {
		if (strcmp(word, mp->name) == 0)
			return (mp);
	}
	return (NULL);
}

int
find_pathconf(const char *name, int *key)
{
	const struct map *rv;

	rv = in_word_set(name);
	if (rv != NULL) {
		if (rv->valid) {
			*key = rv->key;
			return 1;
		}
		return -1;
	}
	return 0;
}

void
foreach_pathconf(void (*func)(const char *, int, const char *),
    const char *path)
{
	const struct map *mp;

	for (mp = wordlist; mp->name != NULL; mp++) {
		if (mp->valid)
			func(mp->name, mp->key, path);
	}
}