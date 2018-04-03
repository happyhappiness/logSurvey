
 * "git log --abbrev=$num --format='%h' ignored --abbrev=$num.

 * "git pull" accepted "--dry-run", gave it to underlying "git fetch" but
   ignored the option itself, resulting in a bogus attempt to merge
   unrelated commit.

 * "git send-email" lacked a way to specify the domainname used in the
   EHLO/HELO exchange, causing rejected connection from picky servers.
   It learned --smtp-domain option to solve this issue.

 * "git stash" incorrectly lost paths in the working tree that were
   previously removed from the index.

