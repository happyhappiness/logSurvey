		$(git write-tree) $parentstr < ../message > ../map/$commit
done <../revs

src_head=$(tail -n 1 ../revs | sed -e 's/ .*//')
target_head=$(head -n 1 ../map/$src_head)
case "$target_head" in
'')
	echo Nothing rewritten
	;;
*)
	git update-ref refs/heads/"$dstbranch" $target_head ||
		die "Could not update $dstbranch with $target_head"
	if [ $(wc -l <../map/$src_head) -gt 1 ]; then
		echo "WARNING: Your commit filter caused the head commit to expand to several rewritten commits. Only the first such commit was recorded as the current $dstbranch head but you will need to resolve the situation now (probably by manually merging the other commits). These are all the commits:" >&2
		sed 's/^/	/' ../map/$src_head >&2
		ret=1
	fi
	;;
esac

if [ "$filter_tag_name" ]; then
	git for-each-ref --format='%(objectname) %(objecttype) %(refname)' refs/tags |
