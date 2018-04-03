   anyway.
   (merge 12434efc1d nd/add-i-ignore-submodules later to maint).

 * Avoid showing a warning message in the middle of a line of "git
   diff" output.
   (merge 4e056c989f nd/diff-flush-before-warning later to maint).

 * The http tracing code, often used to debug connection issues,
   learned to redact potentially sensitive information from its output
   so that it can be more safely sharable.
   (merge 8ba18e6fa4 jt/http-redact-cookies later to maint).

 * Crash fix for a corner case where an error codepath tried to unlock
   what it did not acquire lock on.
   (merge 81fcb698e0 mr/packed-ref-store-fix later to maint).

 * The split-index mode had a few corner case bugs fixed.
   (merge ae59a4e44f tg/split-index-fixes later to maint).

 * Assorted fixes to "git daemon".
   (merge ed15e58efe jk/daemon-fixes later to maint).

 * Completion of "git merge -s<strategy>" (in contrib/) did not work
   well in non-C locale.
   (merge 7cc763aaa3 nd/list-merge-strategy later to maint).

 * Workaround for segfault with more recent versions of SVN.
   (merge 7f6f75e97a ew/svn-branch-segfault-fix later to maint).

 * Other minor doc, test and build updates and code cleanups.
   (merge e2a5a028c7 bw/oidmap-autoinit later to maint).
   (merge f0a6068a9f ys/bisect-object-id-missing-conversion-fix later to maint).
   (merge 30221a3389 as/read-tree-prefix-doc-fix later to maint).
   (merge 9bd2ce5432 ab/doc-cat-file-e-still-shows-errors later to maint).
   (merge ec3b4b06f8 cl/t9001-cleanup later to maint).
   (merge e1b3f3dd38 ks/submodule-doc-updates later to maint).
   (merge fbac558a9b rs/describe-unique-abbrev later to maint).
   (merge 8462ff43e4 tb/crlf-conv-flags later to maint).
   (merge 7d68bb0766 rb/hashmap-h-compilation-fix later to maint).
   (merge 3449847168 cc/sha1-file-name later to maint).
   (merge ad622a256f ds/use-get-be64 later to maint).
   (merge f919ffebed sg/cocci-move-array later to maint).
   (merge 4e801463c7 jc/mailinfo-cleanup-fix later to maint).
   (merge ef5b3a6c5e nd/shared-index-fix later to maint).
   (merge 9f5258cbb8 tz/doc-show-defaults-to-head later to maint).