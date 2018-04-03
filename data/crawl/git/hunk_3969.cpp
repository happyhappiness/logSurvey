    the GIT_DIR discovery logic to escape the ceiling.
    (merge 059b379 mh/ceiling later to maint).
 
- * t4014, t9502 and t0200 tests had various portability issues that
-   broke on OpenBSD.
-   (merge 27f6342 jc/maint-test-portability later to maint).
-
- * t9020 and t3600 tests had various portability issues.
-   (merge 5a02966 jc/test-portability later to maint).
-
- * t9200 runs "cvs init" on a directory that already exists, but a
-   platform can configure this fail for the current user (e.g. you
-   need to be in the cvsadmin group on NetBSD 6.0).
-   (merge 8666df0 jc/test-cvs-no-init-in-existing-dir later to maint).
+ * When attempting to read the XDG-style $HOME/.config/git/config and
+   finding that $HOME/.config/git is a file, we gave a wrong error
+   message, instead of treating the case as "a custom config file does
+   not exist there" and moving on.
+   (merge 8f2bbe4 jn/warn-on-inaccessible-loosen later to maint).
 
  * The behaviour visible to the end users was confusing, when they
    attempt to kill a process spawned in the editor that was in turn
