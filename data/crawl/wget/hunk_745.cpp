         }
     }
 
-  if (statcode == HTTP_STATUS_RANGE_NOT_SATISFIABLE)
+  if (statcode == HTTP_STATUS_RANGE_NOT_SATISFIABLE
+      || (hs->restval > 0 && statcode == HTTP_STATUS_OK
+          && contrange == 0 && hs->restval >= contlen)
+     )
     {
       /* If `-c' is in use and the file has been fully downloaded (or
          the remote file has shrunk), Wget effectively requests bytes
-         after the end of file and the server response with 416.  */
+         after the end of file and the server response with 416
+         (or 200 with a <= Content-Length.  */
       logputs (LOG_VERBOSE, _("\
 \n    The file is already fully retrieved; nothing to do.\n\n"));
       /* In case the caller inspects. */
 tests/ChangeLog      |   5 +++
 tests/FTPServer.pm   | 106 +++++++++++++++++++++++++--------------------------
 tests/FTPTest.pm     |   4 +-
 tests/HTTPServer.pm  |   6 +--
 tests/HTTPTest.pm    |   6 +--
 tests/WgetTest.pm.in |  54 +++++++++++++-------------
 6 files changed, 93 insertions(+), 88 deletions(-)
