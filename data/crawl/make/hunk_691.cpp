       expanding_var = &this_var;
     }
 
+  /* If we have no other file-reading context, use the variable's context. */
+  if (!reading_file)
+    {
+      set_reading = 1;
+      reading_file = &v->fileinfo;
+    }
+
   if (v->expanding)
     {
       if (!v->exp_count)
         /* Expanding V causes infinite recursion.  Lose.  */
-        fatal (this_var,
+        fatal (*expanding_var,
                _("Recursive variable `%s' references itself (eventually)"),
                v->name);
       --v->exp_count;
