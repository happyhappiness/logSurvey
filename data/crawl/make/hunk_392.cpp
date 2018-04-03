     puts (_("#  Command line target."));
   if (f->dontcare)
     puts (_("#  A default, MAKEFILES, or -include/sinclude makefile."));
+  if (f->builtin)
+    puts (_("#  Builtin rule"));
   puts (f->tried_implicit
         ? _("#  Implicit rule search has been done.")
         : _("#  Implicit rule search has not been done."));
