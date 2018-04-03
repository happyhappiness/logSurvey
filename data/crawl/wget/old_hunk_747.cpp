      logprintf (LOG_NOTQUIET,
                 _("FINISHED --%s--\nDownloaded: %d files, %s in %s (%s)\n"),
                 datetime_str (time (NULL)),
                 opt.numurls,
                 human_readable (total_downloaded_bytes),
                 secs_to_human_time (total_download_time),
                 retr_rate (total_downloaded_bytes, total_download_time));
