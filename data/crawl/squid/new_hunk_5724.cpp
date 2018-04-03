    return 0;
}

static struct squid_radix_mask *
rn_new_radix_mask(struct squid_radix_node *tt, struct squid_radix_mask *next)
{
    register struct squid_radix_mask *m;

    squid_MKGet(m);
    if (m == 0) {
	fprintf(stderr, "Mask for route not entered\n");
	return (0);
