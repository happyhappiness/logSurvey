       }
 #else
     else
-      fatal (NILF, "%s (line %d) Bad shell context (!unixy && !batch_mode_shell)\n",
+      fatal (NILF, _("%s (line %d) Bad shell context (!unixy && !batch_mode_shell)\n"),
             __FILE__, __LINE__);
 #endif
   }
