     {
       struct log_ln *ln = log_lines + num;
       if (ln->content)
-        FPUTS (ln->content, fp);
+        {
+          FPUTS (ln->content, fp);
+          if (warcfp != NULL)
+            FPUTS (ln->content, warcfp);
+        }
       ROT_ADVANCE (num);
     }
   while (num != log_line_current);
   if (trailing_line)
     if (log_lines[log_line_current].content)
-      FPUTS (log_lines[log_line_current].content, fp);
+      {
+        FPUTS (log_lines[log_line_current].content, fp);
+        if (warcfp != NULL)
+          FPUTS (log_lines[log_line_current].content, warcfp);
+      }
   fflush (fp);
+  fflush (warcfp);
 }
 
 /* String escape functions. */
