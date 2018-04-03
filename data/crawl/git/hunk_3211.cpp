    but hopefully will give us one extra level of abstraction in the
    end, when completed.
 
+ * Catch a programmer mistake to feed a pointer not an array to
+   ARRAY_SIZE() macro, by using a couple of GCC extensions.
+   (merge 89c855e ep/do-not-feed-a-pointer-to-array-size later to maint).
+
+ * Some error messages in "git config" were emitted without calling
+   the usual error() facility.
+
+ * When "add--interactive" splits a hunk into two overlapping hunks
+   and then let the user choose only one, it sometimes feeds an
+   incorrect patch text to "git apply".  Add tests to demonstrate
+   this.
+
+   I have a slight suspicion that this may be $gmane/87202 coming back
+   and biting us (I seem to have said "let's run with this and see
+   what happens" back then).
+
+ * More line-ending tests.
+
+ * An earlier rewrite to use strbuf_getwholeline() instead of fgets(3)
+   to read packed-refs file revealed that the former is unacceptably
+   inefficient.
+
+ * Many long-running operations show progress eye-candy, even when
+   they are later backgrounded.  Hide the eye-candy when the process
+   is sent to the background instead.
+   (merge 9a9a41d lm/squelch-bg-progress later to maint).
+
 
 Also contains various documentation updates and code clean-ups.
 
