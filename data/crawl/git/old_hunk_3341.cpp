	return strbuf_detach(&buf, NULL);
}

static int match_explicit(struct ref *src, struct ref *dst,
			  struct ref ***dst_tail,
			  struct refspec *rs)
{
	struct ref *matched_src, *matched_dst;
	int copy_src;

	const char *dst_value = rs->dst;
	char *dst_guess;
