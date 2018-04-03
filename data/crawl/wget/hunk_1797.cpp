     }
   else
     fprintf (stderr,
-             _("Invalid dot style specification `%s'; leaving unchanged.\n"),
-             params);
+             _("Invalid dot style specification %s; leaving unchanged.\n"),
+             quote (params));
 }
 
 /* "Thermometer" (bar) progress. */
 src/ChangeLog | 1 +
 src/recur.c   | 2 +-
 2 files changed, 2 insertions(+), 1 deletion(-)
