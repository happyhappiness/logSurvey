    }
 out:
  if (ferror (fp))
    logprintf (LOG_NOTQUIET, _("Error writing to %s: %s\n"),
               quote (file), strerror (errno));
  if (fclose (fp) < 0)
    logprintf (LOG_NOTQUIET, _("Error closing %s: %s\n"),
               quote (file), strerror (errno));

  DEBUGP (("Done saving cookies.\n"));
}
src/ChangeLog  | 1 +
src/ftp-opie.c | 2 +-
2 files changed, 2 insertions(+), 1 deletion(-)
