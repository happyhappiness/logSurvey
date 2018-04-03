   learned to turn "git describe" output (e.g. v2.9.3-599-g2376d31787)
   into clickable links in its output.

 * "git commit" created an empty commit when invoked with an index
   consisting solely of intend-to-add paths (added with "git add -N").
   It now requires the "--allow-empty" option to create such a commit.
   The same logic prevented "git status" from showing such paths as "new files" in the
   "Changes not staged for commit" section.

 * The smudge/clean filter API spawns an external process
   to filter the contents of each path that has a filter defined.  A
   new type of "process" filter API has been added to allow the first
   request to run the filter for a path to spawn a single process, and
   all filtering is served by this single process for multiple
   paths, reducing the process creation overhead.

 * The user always has to say "stash@{$N}" when naming a single
