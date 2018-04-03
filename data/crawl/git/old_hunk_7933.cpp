				return 0;
			}
		}
		if (snprintf(buf, sizeof(buf),
			     progress->delayed_title, progress->total))
			fprintf(stderr, "%s\n", buf);
	}
	if (progress->total) {
		unsigned percent = n * 100 / progress->total;
		if (percent != progress->last_percent || progress_update) {
			progress->last_percent = percent;
			fprintf(stderr, "%s%4u%% (%u/%u) done\r",
				progress->prefix, percent, n, progress->total);
			progress_update = 0;
			progress->need_lf = 1;
			return 1;
		}
	} else if (progress_update) {
		fprintf(stderr, "%s%u\r", progress->prefix, n);
		progress_update = 0;
		progress->need_lf = 1;
		return 1;
	}
	return 0;
}

void start_progress(struct progress *progress, const char *title,
		    const char *prefix, unsigned total)
{
	char buf[80];
	progress->prefix = prefix;
	progress->total = total;
	progress->last_percent = -1;
	progress->delay = 0;
	progress->need_lf = 0;
	if (snprintf(buf, sizeof(buf), title, total))
		fprintf(stderr, "%s\n", buf);
	set_progress_signal();
}

void start_progress_delay(struct progress *progress, const char *title,
			  const char *prefix, unsigned total,
			  unsigned percent_treshold, unsigned delay)
{
	progress->prefix = prefix;
	progress->total = total;
	progress->last_percent = -1;
	progress->delayed_percent_treshold = percent_treshold;
	progress->delayed_title = title;
	progress->delay = delay;
	progress->need_lf = 0;
	set_progress_signal();
}

void stop_progress(struct progress *progress)
{
	clear_progress_signal();
	if (progress->need_lf)
		fputc('\n', stderr);
}
