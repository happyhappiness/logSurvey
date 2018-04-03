#define get_gecos(struct_passwd) ((struct_passwd)->pw_gecos)
#endif

static void copy_gecos(const struct passwd *w, struct strbuf *name)
{
	char *src;
