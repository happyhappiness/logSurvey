
 * "git log --abbrev=$num --format='%h' ignored --abbrev=$num.

 * "git ls-files ../out/side/cwd" refused to work.

 * "git merge --log" used to replace the custom message given by "-m" with
   the shortlog, instead of appending to it.

 * "git pull" accepted "--dry-run", gave it to underlying "git fetch" but
   ignored the option itself, resulting in a bogus attempt to merge
   unrelated commit.

 * "git reset --hard" started from a wrong directory and a working tree in
   a nonstandard location is in use got confused.

 * "git send-email" lacked a way to specify the domainname used in the
   EHLO/HELO exchange, causing rejected connection from picky servers.
   It learned --smtp-domain option to solve this issue.

 * "git show -C -C" and other corner cases lost diff metainfo output
   in 1.7.0.

 * "git stash" incorrectly lost paths in the working tree that were
   previously removed from the index.

