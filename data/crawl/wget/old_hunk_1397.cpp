
  printf (_("Continuing in background, pid %lu.\n"), pi.dwProcessId);
  if (info->logfile_changed)
    printf (_("Output will be written to `%s'.\n"), info->lfilename);

  UnmapViewOfFile (info);

src/ChangeLog | 1 +
src/openssl.c | 8 ++++----
2 files changed, 5 insertions(+), 4 deletions(-)
