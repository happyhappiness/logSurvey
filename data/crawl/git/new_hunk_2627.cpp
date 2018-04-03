   but a test insisted that the function drops a trailing slash.
   (merge b2a7123 rd/test-path-utils later to maint).

 * A test for interaction between untracked cache and sparse checkout
   added in Git 2.5 days were flaky.
   (merge 9b680fb dt/t7063-fix-flaky-test later to maint).

 * A couple of commands still showed "[options]" in their usage string
   to note where options should come on their command line, but we
   spell that "[<options>]" in most places these days.
   (merge d96a031 rt/placeholder-in-usage later to maint).

 * The synopsis text and the usage string of subcommands that read
   list of things from the standard input are often shown as if they
   only take input from a file on a filesystem, which was misleading.
   (merge 33e8fc8 jc/usage-stdin later to maint).

 * "git am -3" had a small regression where it is aborted in its error
   handling codepath when underlying merge-recursive failed in certain
   ways, as it assumed that the internal call to merge-recursive will
   never die, which is not the case (yet).
   (merge c63d4b2 jc/am-3-fallback-regression-fix later to maint).

 * Code clean-up and minor fixes.
   (merge 15ed07d jc/rerere later to maint).
   (merge e7a7401 pt/pull-builtin later to maint).
