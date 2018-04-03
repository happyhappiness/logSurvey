         fatal("Ipc::Mem::Segment::create failed to ftruncate");
     }
 
+    assert(statSize("Ipc::Mem::Segment::create") == aSize); // paranoid
+
     theSize = aSize;
     theReserved = 0;
 
