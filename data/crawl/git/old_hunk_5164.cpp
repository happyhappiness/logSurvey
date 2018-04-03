   minimize the output, but this often was spending too many extra cycles
   for very little gain (582aa00).

 * "git pull" accepted "--dry-run", gave it to underlying "git fetch" but
   ignored the option itself, resulting in a bogus attempt to merge
   unrelated commit (29609e68).

 * "git reset --hard" started from a wrong directory and a working tree in
   a nonstandard location is in use got confused (560fb6a1).

--
exec >/var/tmp/1
O=v1.7.1-336-g0925c02
echo O=$(git describe master)
git shortlog --no-merges master ^maint ^$O
