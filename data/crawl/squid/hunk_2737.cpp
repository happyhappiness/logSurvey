                    "\tThe parent directory must be writeable by the\n"
                    "\tuser '%s', which is the cache_effective_user\n"
                    "\tset in squid.conf.", path, Config.effectiveUser);
+        } else if (EISDIR == errno && fatal_flag) {
+            fatalf("Cannot open '%s' because it is a directory, not a file.\n", path);
         } else {
             debugs(50, DBG_IMPORTANT, "logfileOpen (stdio): " <<  path << ": " << xstrerror());
             return 0;
