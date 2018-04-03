

static void
dump_ushortlist(ushortlist * u)
{
    while (u) {
	printf("%d ", (int) u->i);
	u = u->next;
    }
}

static void
parse_ushortlist(ushortlist ** P)
{
