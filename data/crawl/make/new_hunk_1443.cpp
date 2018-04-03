#define	ENUM_BITFIELD(bits)
#endif

#if defined(__MSDOS__) || defined(WIN32)
#define PATH_SEPARATOR_CHAR ';'
#else
#define PATH_SEPARATOR_CHAR ':'
#endif

#ifdef WIN32
#include <fcntl.h>
#include <malloc.h>
#define pipe(p) _pipe(p, 512, O_BINARY)
#define kill(pid,sig) w32_kill(pid,sig)

extern void sync_Path_environment(void);
extern int kill(int pid, int sig);
extern int safe_stat(char *file, struct stat *sb);
extern char *end_of_token_w32();
#endif

extern void die ();
extern void message ();
