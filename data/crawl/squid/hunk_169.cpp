 {
 
 public:
+    /// meta-information for debugs() or a similar debugging call
+    class Context
+    {
+    public:
+        Context(const int aSectionLevel, const int aLevel);
+
+        int level; ///< minimum debugging level required by the debugs() call
+        int sectionLevel; ///< maximum debugging level allowed during the call
+
+    private:
+        friend class Debug;
+        void rewind(const int aSection, const int aLevel);
+        void formatStream();
+        Context *upper; ///< previous or parent record in nested debugging calls
+        std::ostringstream buf; ///< debugs() output sink
+    };
+
+    /// whether debugging the given section and the given level produces output
+    static bool Enabled(const int section, const int level)
+    {
+        return level <= Debug::Levels[section];
+    }
+
     static char *debugOptions;
     static char *cache_log;
     static int rotateNumber;
     static int Levels[MAX_DEBUG_SECTIONS];
-    static int level; ///< minimum debugging level required by debugs() call
-    static int sectionLevel; ///< maximum debugging level allowed now
     static int override_X;
     static int log_stderr;
     static bool log_syslog;
 
-    static std::ostream &getDebugOut();
-    static void finishDebug();
     static void parseOptions(char const *);
 
-private:
-    // Hack: replaces global ::xassert() to debug debugging assertions
-    static void xassert(const char *msg, const char *file, int line);
+    /// minimum level required by the current debugs() call
+    static int Level() { return Current ? Current->level : 1; }
+    /// maximum level currently allowed
+    static int SectionLevel() { return Current ? Current->sectionLevel : 1; }
 
-    /// Wrapper class to prevent SquidNew.h overrides getting confused
-    /// with the libc++6 std::ostringstream definitions
-    class OutStream : public std::ostringstream
-    {
-        MEMPROXY_CLASS(OutStream);
-    public:
-        void *operator new[] (size_t size) throw(std::bad_alloc) = delete; //{return xmalloc(size);}
-        void operator delete[] (void *address) throw() = delete; // {xfree(address);}
-    };
+    /// opens debugging context and returns output buffer
+    static std::ostringstream &Start(const int section, const int level);
+    /// logs output buffer created in Start() and closes debugging context
+    static void Finish();
 
-    static OutStream *CurrentDebug;
-    static int TheDepth; // level of nested debugging calls
+private:
+    static Context *Current; ///< deepest active context; nil outside debugs()
 };
 
 extern FILE *debug_log;
