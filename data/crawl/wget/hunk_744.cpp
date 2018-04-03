       f = f->next;
     }
   fprintf (fp, "</pre>\n</body>\n</html>\n");
+  xfree (htcldir);
   xfree (upwd);
   if (!output_stream)
     fclose (fp);
 src/ChangeLog | 5 +++++
 src/http.c    | 8 ++++++--
 2 files changed, 11 insertions(+), 2 deletions(-)
