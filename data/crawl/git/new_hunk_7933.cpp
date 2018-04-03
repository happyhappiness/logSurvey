				return 0;
			}
		}
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
	return display(progress, n, 0);
}

void start_progress_delay(struct progress *progress, const char *title,
			  unsigned total, unsigned percent_treshold, unsigned delay)
{
	progress->title = title;
	progress->total = total;
	progress->last_value = -1;
	progress->last_percent = -1;
	progress->delayed_percent_treshold = percent_treshold;
	progress->delay = delay;
	set_progress_signal();
}

void start_progress(struct progress *progress, const char *title, unsigned total)
{
	start_progress_delay(progress, title, total, 0, 0);
}

void stop_progress(struct progress *progress)
{
	if (progress->last_value != -1) {
		/* Force the last update */
		progress_update = 1;
		display(progress, progress->last_value, 1);
	}
	clear_progress_signal();
}
