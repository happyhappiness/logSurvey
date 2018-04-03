};
static struct discovery *last_discovery;

static void free_discovery(struct discovery *d)
{
	if (d) {
