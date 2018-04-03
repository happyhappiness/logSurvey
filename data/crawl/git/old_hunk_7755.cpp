		die("bug: unhandled diff status %c", p->status);
	}
	fprintf(s->fp, "\n");
}

static void wt_status_print_updated_cb(struct diff_queue_struct *q,
