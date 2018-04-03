         /* The entire name is the basename.  */
         o = variable_buffer_output (o, p2, len);
 
+#ifdef VMS
+      o = variable_buffer_output (o, ",", 1);
+#else
       o = variable_buffer_output (o, " ", 1);
+#endif
       doneany = 1;
     }
 
