       sprintf (buf2, llong_fmt[x], llong_nums[y]);
       if (strcmp (buf1, buf2))
       {
-        printf("snprintf doesn't match Format: %s\n\tsnprintf = %s\n\tsprintf  = %s\n", 
+        printf("snprintf doesn't match Format: %s\n\tsnprintf = %s\n\tsprintf  = %s\n",
             llong_fmt[x], buf1, buf2);
         fail++;
       }
