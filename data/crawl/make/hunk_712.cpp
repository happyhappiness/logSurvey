         }
     }
 
+  *fd = -1;
   if (error == NULL)
     error = _("Cannot create a temporary file\n");
   fatal (NILF, error);
