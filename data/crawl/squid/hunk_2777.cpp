         map = new DirMap(path, eAllowed);
     }
 
-    DiskIOModule *m = DiskIOModule::Find("IpcIo"); // TODO: configurable?
-    assert(m);
-    io = m->createStrategy();
-    io->init();
+    const char *ioModule = UsingSmp() ? "IpcIo" : "Blocking";
+    if (DiskIOModule *m = DiskIOModule::Find(ioModule)) {
+        debugs(47,2, HERE << "Using DiskIO module: " << ioModule);
+        io = m->createStrategy();
+        io->init();
+    } else {
+        debugs(47,1, "Rock store is missing DiskIO module: " << ioModule);
+        fatal("Rock Store missing a required DiskIO module");
+    }
 
     theFile = io->newFile(filePath);
     theFile->open(O_RDWR, 0644, this);