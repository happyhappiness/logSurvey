	}

	progress->last_value = n;
	eol = done ? ", done.   \n" : "   \r";
	if (progress->total) {
		unsigned percent = n * 100 / progress->total;
		if (percent != progress->last_percent || progress_update) {
			progress->last_percent = percent;
			fprintf(stderr, "%s: %3u%% (%u/%u)%s", progress->title,
				percent, n, progress->total, eol);
			progress_update = 0;
			return 1;
		}
	} else if (progress_update) {
		fprintf(stderr, "%s: %u%s", progress->title, n, eol);
		progress_update = 0;
		return 1;
	}

	return 0;
}

int display_progress(struct progress *progress, unsigned n)
{
	return progress ? display(progress, n, 0) : 0;
