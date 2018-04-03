                new_line + shell_len + sizeof (minus_c) - 1, line_len);
       new_argv[0][line_len] = '\0';
       }
+#else
+    else
+      fatal("%s (line %d) Invalid shell context (!unixy && !batch_mode_shell)\n",
+            __FILE__, __LINE__);
 #endif
   }
 #endif	/* ! AMIGA */
