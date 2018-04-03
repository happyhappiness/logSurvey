     required_gerrit_options = (options.oldrev, options.newrev, options.refname,
                                options.project)
     if required_gerrit_options != (None,) * 4:
-        return compute_gerrit_options(options, args, required_gerrit_options)
+        return compute_gerrit_options(options, args, required_gerrit_options,
+                                      raw_refname)
 
     # No special options in use, just return what we started with
     return options, args, {}
 
 
+class Logger(object):
+    def parse_verbose(self, verbose):
+        if verbose > 0:
+            return logging.DEBUG
+        else:
+            return logging.INFO
+
+    def create_log_file(self, environment, name, path, verbosity):
+        log_file = logging.getLogger(name)
+        file_handler = logging.FileHandler(path)
+        log_fmt = logging.Formatter("%(asctime)s [%(levelname)-5.5s]  %(message)s")
+        file_handler.setFormatter(log_fmt)
+        log_file.addHandler(file_handler)
+        log_file.setLevel(verbosity)
+        return log_file
+
+    def __init__(self, environment):
+        self.environment = environment
+        self.loggers = []
+        stderr_log = logging.getLogger('git_multimail.stderr')
+
+        class EncodedStderr(object):
+            def write(self, x):
+                write_str(sys.stderr, x)
+
+            def flush(self):
+                sys.stderr.flush()
+
+        stderr_handler = logging.StreamHandler(EncodedStderr())
+        stderr_log.addHandler(stderr_handler)
+        stderr_log.setLevel(self.parse_verbose(environment.verbose))
+        self.loggers.append(stderr_log)
+
+        if environment.debug_log_file is not None:
+            debug_log_file = self.create_log_file(
+                environment, 'git_multimail.debug', environment.debug_log_file, logging.DEBUG)
+            self.loggers.append(debug_log_file)
+
+        if environment.log_file is not None:
+            log_file = self.create_log_file(
+                environment, 'git_multimail.file', environment.log_file, logging.INFO)
+            self.loggers.append(log_file)
+
+        if environment.error_log_file is not None:
+            error_log_file = self.create_log_file(
+                environment, 'git_multimail.error', environment.error_log_file, logging.ERROR)
+            self.loggers.append(error_log_file)
+
+    def info(self, msg):
+        for l in self.loggers:
+            l.info(msg)
+
+    def debug(self, msg):
+        for l in self.loggers:
+            l.debug(msg)
+
+    def warning(self, msg):
+        for l in self.loggers:
+            l.warning(msg)
+
+    def error(self, msg):
+        for l in self.loggers:
+            l.error(msg)
+
+
 def main(args):
     parser = optparse.OptionParser(
         description=__doc__,
