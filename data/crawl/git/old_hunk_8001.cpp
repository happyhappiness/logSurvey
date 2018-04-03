	one = quote_crlf(p->one->path, onebuf, sizeof(onebuf));
	two = quote_crlf(p->two->path, twobuf, sizeof(twobuf));

	color_printf(color(WT_STATUS_HEADER), "#\t");
	switch (p->status) {
	case DIFF_STATUS_ADDED:
		color_printf(c, "new file:   %s", one);
		break;
	case DIFF_STATUS_COPIED:
		color_printf(c, "copied:     %s -> %s", one, two);
		break;
	case DIFF_STATUS_DELETED:
		color_printf(c, "deleted:    %s", one);
		break;
	case DIFF_STATUS_MODIFIED:
		color_printf(c, "modified:   %s", one);
		break;
	case DIFF_STATUS_RENAMED:
		color_printf(c, "renamed:    %s -> %s", one, two);
		break;
	case DIFF_STATUS_TYPE_CHANGED:
		color_printf(c, "typechange: %s", one);
		break;
	case DIFF_STATUS_UNKNOWN:
		color_printf(c, "unknown:    %s", one);
		break;
	case DIFF_STATUS_UNMERGED:
		color_printf(c, "unmerged:   %s", one);
		break;
	default:
		die("bug: unhandled diff status %c", p->status);
	}
	printf("\n");
}

static void wt_status_print_updated_cb(struct diff_queue_struct *q,
