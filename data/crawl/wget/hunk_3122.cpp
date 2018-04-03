     }
   fprintf (fp, "</pre>\n</body>\n</html>\n");
   xfree (upwd);
-  if (!opt.dfp)
+  if (!output_stream)
     fclose (fp);
   else
     fflush (fp);
