            variable we don't want to expand it.  So, walk from the
            beginning, expanding as we go, and looking for "interesting"
            chars.  The first word is always expandable.  */
-        wtype = get_next_mword(line, NULL, &lb_next, &wlen);
+        wtype = get_next_mword (line, NULL, &lb_next, &wlen);
         switch (wtype)
           {
           case w_eol:
             if (cmdleft != 0)
-              fatal(fstart, _("missing rule before recipe"));
+              fatal (fstart, _("missing rule before recipe"));
             /* This line contained something but turned out to be nothing
                but whitespace (a comment?).  */
             continue;
