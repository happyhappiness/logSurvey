All of the fixes in v1.6.5.X maintenance series are included in this
release, unless otherwise noted.

---
exec >/var/tmp/1
echo O=$(git describe master)
O=v1.6.6-rc0-62-g7fc9d15
git shortlog --no-merges $O..master --not maint