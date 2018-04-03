All of the fixes in v1.7.3.X maintenance series are included in this
release, unless otherwise noted.

 * "git log --author=me --author=her" did not find commits written by
   me or by her; instead it looked for commits written by me and by
   her, which is impossible.


---
exec >/var/tmp/1
O=v1.7.3
O=v1.7.3.1-42-g34289ec
echo O=$(git describe master)
git shortlog --no-merges ^maint ^$O master