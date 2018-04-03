         try:
             p = subprocess.Popen(self.command, stdin=subprocess.PIPE)
         except OSError:
-            sys.stderr.write(
+            self.environment.get_logger().error(
                 '*** Cannot execute command: %s\n' % ' '.join(self.command) +
                 '*** %s\n' % sys.exc_info()[1] +
                 '*** Try setting multimailhook.mailer to "smtp"\n' +
