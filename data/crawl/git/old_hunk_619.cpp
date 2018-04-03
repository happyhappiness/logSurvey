		color_fprintf_ln(s->fp, color(WT_STATUS_HEADER, s), "%c",
				 comment_line_char);
	else
		fputs("", s->fp);
}

static int has_unmerged(struct wt_status *s)