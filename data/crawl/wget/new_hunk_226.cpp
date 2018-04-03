      char *wall_time = xstrdup (secs_to_human_time (end_time - start_time));
      char *download_time = xstrdup (secs_to_human_time (total_download_time));
      logprintf (LOG_NOTQUIET,
                 _("FINISHED --%s--\nTotal wall clock time: %s\n"
                   "Downloaded: %d files, %s in %s (%s)\n"),
                 datetime_str (time (NULL)),
                 wall_time,
                 numurls,
                 human_readable (total_downloaded_bytes, 10, 1),
                 download_time,
                 retr_rate (total_downloaded_bytes, total_download_time));
      xfree (wall_time);
      xfree (download_time);

