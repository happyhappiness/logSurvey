   learned to turn "git describe" output (e.g. v2.9.3-599-g2376d31787)
   into clickable links in its output.

 * When new paths were added by "git add -N" to the index, it was
   enough to circumvent the check by "git commit" to refrain from
   making an empty commit without "--allow-empty".  The same logic
   prevented "git status" to show such a path as "new file" in the
   "Changes not staged for commit" section.

 * The smudge/clean filter API expect an external process is spawned
   to filter the contents for each path that has a filter defined.  A
   new type of "process" filter API has been added to allow the first
   request to run the filter for a path to spawn a single process, and
   all filtering need is served by this single process for multiple
   paths, reducing the process creation overhead.

 * The user always has to say "stash@{$N}" when naming a single
