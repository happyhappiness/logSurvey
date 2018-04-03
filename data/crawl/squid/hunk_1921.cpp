 public:
     static inline void NotifyIOCompleted();
     static void ResetNotifications();
-    static void Initialise();
+    static void Initialize();
     static void NotifyIOClose();
 
 private:
     static void NULLFDHandler(int, void *);
     static void FlushPipe();
-    static bool Initialised;
+    static bool Initialized;
     static bool DoneSignalled;
     static int DoneFD;
     static int DoneReadFD;
 };
 
-/* Inline code. TODO: make structued approach to inlining */
+/* Inline code. TODO: make structured approach to inlining */
 void
 CommIO::NotifyIOCompleted()
 {
-    if (!Initialised)
-        Initialise();
+    if (!Initialized) {
+        fatalf("Disk Threads I/O pipes not initialized before first use.");
+    }
 
     if (!DoneSignalled) {
         DoneSignalled = true;