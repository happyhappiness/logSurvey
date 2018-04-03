

static void
dump_ushortlist(ushortlist * u)
{
    while (u) {
	printf("%d ", (int) u->i);
