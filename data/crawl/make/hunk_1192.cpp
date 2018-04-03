   register unsigned int nvpaths;
   register struct vpath *v;
 
-  puts ("\n# VPATH Search Paths\n");
+  puts (_("\n# VPATH Search Paths\n"));
 
   nvpaths = 0;
   for (v = vpaths; v != 0; v = v->next)
