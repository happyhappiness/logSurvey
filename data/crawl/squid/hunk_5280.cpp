 
 protected:
     CommCommonCallback result;
-    friend void _comm_close(int fd, char *file, int line);
+    friend void _comm_close(int fd, char const *file, int line);
     friend void comm_calliocallback(void);
 
 private:
