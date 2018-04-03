         io = m->createStrategy();
         io->init();
     } else {
-        debugs(47,1, "Rock store is missing DiskIO module: " << ioModule);
+        debugs(47, DBG_CRITICAL, "FATAL: Rock store is missing DiskIO module: " <<
+               ioModule);
         fatal("Rock Store missing a required DiskIO module");
     }
 
