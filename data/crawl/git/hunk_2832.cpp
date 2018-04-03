    in C.
    (merge 22d6857 mm/pull-upload-pack later to maint).
 
+ * When trying to see that an object does not exist, a state errno
+   leaked from our "first try to open a packfile with O_NOATIME and
+   then if it fails retry without it" logic on a system that refuses
+   O_NOATIME.  This confused us and caused us to die, saying that the
+   packfile is unreadable, when we should have just reported that the
+   object does not exist in that packfile to the caller.
+   (merge dff6f28 cb/open-noatime-clear-errno later to maint).
+
+ * The codepath to produce error messages had a hard-coded limit to
+   the size of the message, primarily to avoid memory allocation while
+   calling die().
+   (merge f4c3edc jk/long-error-messages later to maint).
+
+ * strbuf_read() used to have one extra iteration (and an unnecessary
+   strbuf_grow() of 8kB), which was eliminated.
+   (merge 3ebbd00 jh/strbuf-read-use-read-in-full later to maint).
+
  * Code cleanups and documentation updates.
    (merge 1c601af es/doc-clean-outdated-tools later to maint).
    (merge 3581304 kn/tag-doc-fix later to maint).
