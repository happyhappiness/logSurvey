    logprintf (LOG_VERBOSE, " (%s)", human_readable (size));
  if (start > 0)
    {
      if (start >= 1024)
        logprintf (LOG_VERBOSE, _(", %s (%s) remaining"),
                   number_to_static_string (size - start),
                   human_readable (size - start));
ChangeLog     |  5 +++++
MAILING-LIST  |  9 ++++++++-
doc/ChangeLog |  2 ++
doc/wget.texi | 10 +++++++++-
4 files changed, 24 insertions(+), 2 deletions(-)
