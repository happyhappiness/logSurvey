
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
