      DEBUGP (("Unlinking %s (symlink).\n", file));
      err = unlink (file);
      if (err != 0)
        logprintf (LOG_VERBOSE, _("Failed to unlink symlink %s: %s\n"),
                   quote (file), strerror (errno));
    }
  return err;
}
header).
src/convert.c | 28 +++++++++++++++-------------
src/wget.h    |  6 +++++-
2 files changed, 20 insertions(+), 14 deletions(-)
