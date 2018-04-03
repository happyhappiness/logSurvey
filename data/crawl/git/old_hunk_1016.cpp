#define CAP_CLEAN    (1u<<0)
#define CAP_SMUDGE   (1u<<1)

static struct convert_driver {
	const char *name;
	struct convert_driver *next;
	const char *smudge;
	const char *clean;
	int required;
} *user_convert, **user_convert_tail;

