#define	ENUM_BITFIELD(bits)
#endif

#ifdef __MSDOS__
#define PATH_SEPARATOR_CHAR ';'
#else
#define PATH_SEPARATOR_CHAR ':'
#endif

extern void die ();
extern void message ();
