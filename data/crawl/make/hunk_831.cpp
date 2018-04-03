   variables.  This may mean that if you added extra escaping to your
   $(call ...) function arguments you will need to undo it now.
 
+* The variable invoked by $(call ...) can now be recursive: unlike other
+  variables it can reference itself and this will not produce an error
+  when it is used as the first argument to $(call ...) (but only then).
+
 * New pseudo-target .LOW_RESOLUTION_TIME, superseding the configure
   option --disable-nsec-timestamps.  You might need this if your build
   process depends on tools like "cp -p" preserving time stamps, since
