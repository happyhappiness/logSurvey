     {
       /* If opt.noclobber is turned on and file already exists, do not
          retrieve the file. But if the output_document was given, then this
-         test was already done and the file doesn't exist. Hence the !opt.output_document */
+         test was already done and the file didn't exist. Hence the !opt.output_document */
       logprintf (LOG_VERBOSE, _("\
 File `%s' already there; not retrieving.\n\n"), 
                  hstat.local_file);
 src/ChangeLog | 5 +++++
 src/ftp.c     | 8 ++++----
 2 files changed, 9 insertions(+), 4 deletions(-)
