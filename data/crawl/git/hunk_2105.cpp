         except UnicodeEncodeError:
             f.buffer.write(msg.encode(ENCODING))
 else:
+    def is_string(s):
+        try:
+            return isinstance(s, basestring)
+        except NameError:  # Silence Pyflakes warning
+            raise
+
     def str_to_bytes(s):
         return s
 
