 }
 
 void
+exec_error (char const *name)
+{
+  call_arg_error ("exec", name);
+}
+
+void
+fork_error (char const *name)
+{
+  call_arg_error ("fork", name);
+}
+
+void
+dup2_error (char const *name)
+{
+  call_arg_error ("dup2", name);
+}
+
+void
+pipe_error (char const *name)
+{
+  call_arg_error ("pipe", name);
+}
+
+void
 open_error (char const *name)
 {
   call_arg_error ("open", name);
