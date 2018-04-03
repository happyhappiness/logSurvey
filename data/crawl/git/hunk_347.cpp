    pointer that used to point at it has been replaced with a new
    FREE_AND_NULL() macro.
 
+ * Traditionally, the default die() routine had a code to prevent it
+   from getting called multiple times, which interacted badly when a
+   threaded program used it (one downside is that the real error may
+   be hidden and instead the only error message given to the user may
+   end up being "die recursion detected", which is not very useful).
+
 
 Also contains various documentation updates and code clean-ups.
 
