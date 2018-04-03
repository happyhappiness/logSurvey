  if (!pattern_match (common_name, host))
    {
      logprintf (LOG_NOTQUIET, _("\
%s: certificate common name %s doesn't match requested host name %s.\n"),
                 severity, quote (escnonprint (common_name)), quote (escnonprint (host)));
      success = false;
    }

src/ChangeLog  | 1 +
src/progress.c | 4 ++--
2 files changed, 3 insertions(+), 2 deletions(-)
