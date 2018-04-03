    return 0;
}

static struct radix_mask *
rn_new_radix_mask(struct radix_node *tt, struct radix_mask *next)
{
    register struct radix_mask *m;

    MKGet(m);
    if (m == 0) {
	fprintf(stderr, "Mask for route not entered\n");
	return (0);
