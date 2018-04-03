       else if (dlsym( self,"_fnord")) status = $lt_dlneed_uscore;
       /* dlclose (self); */
     }
+  else
+    puts (dlerror ());
 
     exit (status);
 }]
