 			   &bufdesc.dsc$w_length, 0);
   if (! status)
     {
-      error ("lbr$set_module failed to extract module info, status = %d",
+      error (NILF, "lbr$set_module failed to extract module info, status = %d",
 	     status);
 
       lbr$close (&VMS_lib_idx);
