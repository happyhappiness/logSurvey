     puts (_("\n# No general (`VPATH' variable) search path."));
   else
     {
-      register char **path = general_vpath->searchpath;
-      register unsigned int i;
+      const char **path = general_vpath->searchpath;
+      unsigned int i;
 
       fputs (_("\n# General (`VPATH' variable) search path:\n# "), stdout);
 
