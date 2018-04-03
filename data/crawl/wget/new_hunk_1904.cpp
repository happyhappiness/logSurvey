      DEBUGP (("Unlinking %s (symlink).\n", file));
      err = unlink (file);
      if (err != 0)
        logprintf (LOG_VERBOSE, _("Failed to unlink symlink %s: %s\n"),
                   quote (file), strerror (errno));
    }
  return err;
}
