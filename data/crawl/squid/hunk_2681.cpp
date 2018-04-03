 #include <sys/types.h>
 #include <unistd.h>
 
-SharedMemory::SharedMemory(const char *const id):
+Ipc::Mem::Segment::Segment(const char *const id):
     theName(GenerateName(id)), theFD(-1), theSize(-1), theMem(NULL)
 {
 }
 
-SharedMemory::~SharedMemory() {
+Ipc::Mem::Segment::~Segment() {
     if (theFD >= 0) {
         detach();
-        if (close(theFD))
-            debugs(54, 5, "SharedMemory::~SharedMemory: close: " << xstrerror());
+        if (close(theFD) != 0)
+            debugs(54, 5, HERE << "close: " << xstrerror());
     }
 }
 
 void
-SharedMemory::create(const int aSize)
+Ipc::Mem::Segment::create(const int aSize)
 {
     assert(aSize > 0);
     assert(theFD < 0);
 
     theFD = shm_open(theName.termedBuf(), O_CREAT | O_RDWR | O_TRUNC,
                      S_IRUSR | S_IWUSR);
     if (theFD < 0) {
-        debugs(54, 5, "SharedMemory::create: shm_open: " << xstrerror());
-        fatal("SharedMemory::create failed");
+        debugs(54, 5, HERE << "shm_open: " << xstrerror());
+        fatal("Ipc::Mem::Segment::create failed to shm_open");
     }
 
     if (ftruncate(theFD, aSize)) {
-        debugs(54, 5, "SharedMemory::create: ftruncate: " << xstrerror());
-        fatal("SharedMemory::create failed");
+        debugs(54, 5, HERE << "ftruncate: " << xstrerror());
+        fatal("Ipc::Mem::Segment::create failed to ftruncate");
     }
 
     theSize = aSize;
