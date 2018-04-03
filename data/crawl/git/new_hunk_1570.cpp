	return offset;
}

/*
 * Find file diff header
 *
 * Returns:
 *  -1 if no header was found
 *  -128 in case of error
 *   the size of the header in bytes (called "offset") otherwise
 */
static int find_header(struct apply_state *state,
		       const char *line,
		       unsigned long size,
