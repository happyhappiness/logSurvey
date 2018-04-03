         """Write the string msg on a log file or on stderr.
 
         Sends the text to stderr by default, override to change the behavior."""
-        write_str(sys.stderr, msg)
+        self.get_logger().info(msg)
 
     def log_warning(self, msg):
         """Write the string msg on a log file or on stderr.
 
         Sends the text to stderr by default, override to change the behavior."""
-        write_str(sys.stderr, msg)
+        self.get_logger().warning(msg)
 
     def log_error(self, msg):
         """Write the string msg on a log file or on stderr.
 
         Sends the text to stderr by default, override to change the behavior."""
-        write_str(sys.stderr, msg)
+        self.get_logger().error(msg)
+
+    def check(self):
+        pass
 
 
 class ConfigEnvironmentMixin(Environment):
