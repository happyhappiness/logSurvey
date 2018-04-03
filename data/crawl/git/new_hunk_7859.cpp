	}

	progress->last_value = n;
	tp = (progress->throughput) ? progress->throughput->display : "";
	eol = done ? ", done.   \n" : "   \r";
	if (progress->total) {
		unsigned percent = n * 100 / progress->total;
		if (percent != progress->last_percent || progress_update) {
			progress->last_percent = percent;
			fprintf(stderr, "%s: %3u%% (%u/%u)%s%s",
				progress->title, percent, n,
				progress->total, tp, eol);
			progress_update = 0;
			return 1;
		}
	} else if (progress_update) {
		fprintf(stderr, "%s: %u%s%s", progress->title, n, tp, eol);
		progress_update = 0;
		return 1;
	}

	return 0;
}

void display_throughput(struct progress *progress, unsigned long n)
{
	struct throughput *tp;
	struct timeval tv;
	unsigned int misecs;

	if (!progress)
		return;
	tp = progress->throughput;

	gettimeofday(&tv, NULL);

	if (!tp) {
		progress->throughput = tp = calloc(1, sizeof(*tp));
		if (tp)
			tp->prev_tv = tv;
		return;
	}

	tp->count += n;

	/*
	 * We have x = bytes and y = microsecs.  We want z = KiB/s:
	 *
	 *	z = (x / 1024) / (y / 1000000)
	 *	z = x / y * 1000000 / 1024
	 *	z = x / (y * 1024 / 1000000)
	 *	z = x / y'
	 *
	 * To simplify things we'll keep track of misecs, or 1024th of a sec
	 * obtained with:
	 *
	 *	y' = y * 1024 / 1000000
	 *	y' = y / (1000000 / 1024)
	 *	y' = y / 977
	 */
	misecs = (tv.tv_sec - tp->prev_tv.tv_sec) * 1024;
	misecs += (int)(tv.tv_usec - tp->prev_tv.tv_usec) / 977;

	if (misecs > 512) {
		tp->prev_tv = tv;
		tp->avg_bytes += tp->count;
		tp->avg_misecs += misecs;
		snprintf(tp->display, sizeof(tp->display),
			 ", %lu KiB/s", tp->avg_bytes / tp->avg_misecs);
		tp->avg_bytes -= tp->last_bytes[tp->idx];
		tp->avg_misecs -= tp->last_misecs[tp->idx];
		tp->last_bytes[tp->idx] = tp->count;
		tp->last_misecs[tp->idx] = misecs;
		tp->idx = (tp->idx + 1) % TP_IDX_MAX;
		tp->count = 0;
	}
}

int display_progress(struct progress *progress, unsigned n)
{
	return progress ? display(progress, n, 0) : 0;
