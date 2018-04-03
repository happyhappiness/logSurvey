	return 0;
}

static void append_lost(struct sline *sline, int n, const char *line, int len, long flags)
{
	struct lline *lline;
	unsigned long this_mask = (1UL<<n);
	if (line[len-1] == '\n')
		len--;

	/* Check to see if we can squash things */
	if (sline->lost_head) {
		lline = sline->next_lost;
		while (lline) {
			if (match_string_spaces(lline->line, lline->len,
						line, len, flags)) {
				lline->parent_map |= this_mask;
				sline->next_lost = lline->next;
				return;
			}
			lline = lline->next;
		}
	}

	lline = xmalloc(sizeof(*lline) + len + 1);
	lline->len = len;
	lline->next = NULL;
	lline->parent_map = this_mask;
	memcpy(lline->line, line, len);
	lline->line[len] = 0;
	*sline->lost_tail = lline;
	sline->lost_tail = &lline->next;
	sline->next_lost = NULL;
}

struct combine_diff_state {
