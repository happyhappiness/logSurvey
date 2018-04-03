	*var = 0;
}

#define free_onoff free_int
#define dump_pathname_stat dump_string
#define free_pathname_stat free_string

static void
parse_pathname_stat(char **path)
{
    struct stat sb;
    parse_string(path);
    if (stat(*path, &sb) < 0) {
	debug(50, 1) ("parse_pathname_stat: %s: %s\n", *path, xstrerror());
	self_destruct();
    }
}

static void
dump_refreshpattern(void)
{
