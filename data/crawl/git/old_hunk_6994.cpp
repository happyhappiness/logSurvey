	die("pack has bad object at offset %lu: %s", offset, buf);
}

static void link_base_data(struct base_data *base, struct base_data *c)
{
	if (base)
