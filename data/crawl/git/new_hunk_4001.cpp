 * We failed to mention a file without any content change but whose
   permission bit was modified, or (worse yet) a new file without any
   content in the "git diff --stat" output.
   (merge de9095955 lt/diff-stat-show-0-lines later to maint).

 * When "--stat-count" hides a diffstat for binary contents, the total
   number of added and removed lines at the bottom was computed
   incorrectly.
   (merge de9095955 lt/diff-stat-show-0-lines later to maint).

 * When "--stat-count" hides a diffstat for unmerged paths, the total
   number of affected files at the bottom of the "diff --stat" output
   was computed incorrectly.
   (merge de9095955 lt/diff-stat-show-0-lines later to maint).

 * "diff --shortstat" miscounted the total number of affected files
   when there were unmerged paths.
   (merge de9095955 lt/diff-stat-show-0-lines later to maint).

 * "update-ref -d --deref SYM" to delete a ref through a symbolic ref
   that points to it did not remove it correctly.