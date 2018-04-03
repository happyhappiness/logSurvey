			match_beginning = match_end = 0;
			continue;
		}
		/*
		 * Reduce the number of context lines; reduce both
		 * leading and trailing if they are equal otherwise
		 * just reduce the larger context.
		 */
		if (leading >= trailing) {
			remove_first_line(&oldlines, &oldsize);
			remove_first_line(&newlines, &newsize);
			pos--;
			leading--;
		}
		if (trailing > leading) {
			remove_last_line(&oldlines, &oldsize);
			remove_last_line(&newlines, &newsize);
			trailing--;
		}
	}

	if (offset && apply_verbosely)
		error("while searching for:\n%.*s", oldsize, oldlines);

	free(old);
	free(new);
	return offset;
}

static int apply_binary_fragment(struct strbuf *buf, struct patch *patch)
{
	struct fragment *fragment = patch->fragments;
	unsigned long len;
