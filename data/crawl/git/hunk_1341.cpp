             lines = (str_to_bytes(line) for line in lines)
             p.stdin.writelines(lines)
         except Exception:
-            sys.stderr.write(
+            self.environment.get_logger().error(
                 '*** Error while generating commit email\n'
                 '***  - mail sending aborted.\n'
                 )
-            try:
+            if hasattr(p, 'terminate'):
                 # subprocess.terminate() is not available in Python 2.4
                 p.terminate()
-            except AttributeError:
-                pass
+            else:
+                import signal
+                os.kill(p.pid, signal.SIGTERM)
             raise
         else:
             p.stdin.close()
