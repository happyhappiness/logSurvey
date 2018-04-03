
static struct {
	int nr, alloc;
	const char **name;
} list;

static int check_local_mod(unsigned char *head, int index_only)
{
	/*
