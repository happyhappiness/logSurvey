 {
   /*printf("[ remote = current = `%s'\n", current);*/
   if (remote)
-    xfree (remote);
+    {
+      /* Do nothing if already equal */
+      if (current && !strcasecmp (remote, current))
+        return;
+      xfree (remote);
+    }
 
   remote = current ? xstrdup (current) : NULL;
 }
 src/convert.c  |   2 +-
 src/html-url.c |  29 +++++++-------
 src/html-url.h |   2 +-
 src/http.c     |  20 ++++++----
 src/http.h     |   2 +-
 src/iri.c      | 120 +++++++++++++++++----------------------------------------
 src/iri.h      |  48 ++++++++++-------------
 src/main.c     |  11 +++---
 src/recur.c    |  75 ++++++++++++++++++------------------
 src/res.c      |  13 +++++--
 src/res.h      |   2 +-
 src/retr.c     |  53 ++++++++++++++-----------
 src/retr.h     |   3 +-
 src/url.c      |  37 +++++++++---------
 src/url.h      |   2 +-
 src/wget.h     |   3 ++
 16 files changed, 194 insertions(+), 228 deletions(-)
