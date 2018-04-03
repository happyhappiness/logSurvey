         if (p != 0)
           {
             struct nameseq *target;
-            target = parse_file_seq (&p2, sizeof (struct nameseq), ':',
-                                     NULL, PARSEFS_NOGLOB|PARSEFS_NOCACHE);
+            target = PARSE_FILE_SEQ (&p2, struct nameseq, ':', NULL,
+                                     PARSEFS_NOGLOB|PARSEFS_NOCACHE);
             ++p2;
             if (target == 0)
               fatal (fstart, _("missing target pattern"));
