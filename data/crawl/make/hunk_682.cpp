             pattern_percent = find_percent (pattern);
             if (pattern_percent == 0)
               fatal (fstart, _("target pattern contains no `%%'"));
-            free ((char *)target);
+            free (target);
           }
         else
           pattern = 0;
