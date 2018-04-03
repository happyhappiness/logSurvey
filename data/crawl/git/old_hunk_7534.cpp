	memcpy(output, patch, plen);
	if (add_nl_to_tail)
		output[plen++] = '\n';
	if (fixed)
		applied_after_fixing_ws++;
	return output + plen - buf;
}

static int match_fragment(struct image *img,
			  struct image *preimage,
			  struct image *postimage,
