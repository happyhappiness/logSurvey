{
	diff_debug_filespec(p->one, i, "one");
	diff_debug_filespec(p->two, i, "two");
	fprintf(stderr, "score %d, status %c rename_used %d broken %d\n",
		p->score, p->status ? p->status : '?',
		p->one->rename_used, p->broken_pair);
}

void diff_debug_queue(const char *msg, struct diff_queue_struct *q)
