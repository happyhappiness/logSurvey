 		$(git write-tree) $parentstr < ../message > ../map/$commit
 done <../revs
 
-src_head=$(tail -n 1 ../revs | sed -e 's/ .*//')
-target_head=$(head -n 1 ../map/$src_head)
-case "$target_head" in
-'')
-	echo Nothing rewritten
+# In case of a subdirectory filter, it is possible that a specified head
+# is not in the set of rewritten commits, because it was pruned by the
+# revision walker.  Fix it by mapping these heads to the next rewritten
+# ancestor(s), i.e. the boundaries in the set of rewritten commits.
+
+# NEEDSWORK: we should sort the unmapped refs topologically first
+while read ref
+do
+	sha1=$(git rev-parse "$ref"^0)
+	test -f "$workdir"/../map/$sha1 && continue
+	# Assign the boundarie(s) in the set of rewritten commits
+	# as the replacement commit(s).
+	# (This would look a bit nicer if --not --stdin worked.)
+	for p in $((cd "$workdir"/../map; ls | sed "s/^/^/") |
+		git rev-list $ref --boundary --stdin |
+		sed -n "s/^-//p")
+	do
+		map $p >> "$workdir"/../map/$sha1
+	done
+done < "$tempdir"/heads
+
+# Finally update the refs
+
+_x40='[0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f]'
+_x40="$_x40$_x40$_x40$_x40$_x40$_x40$_x40$_x40"
+count=0
+echo
+while read ref
+do
+	# avoid rewriting a ref twice
+	test -f "$orig_namespace$ref" && continue
+
+	sha1=$(git rev-parse "$ref"^0)
+	rewritten=$(map $sha1)
+
+	test $sha1 = "$rewritten" &&
+		warn "WARNING: Ref '$ref' is unchanged" &&
+		continue
+
+	case "$rewritten" in
+	'')
+		echo "Ref '$ref' was deleted"
+		git update-ref -m "filter-branch: delete" -d "$ref" $sha1 ||
+			die "Could not delete $ref"
 	;;
-*)
-	git update-ref refs/heads/"$dstbranch" $target_head ||
-		die "Could not update $dstbranch with $target_head"
-	if [ $(wc -l <../map/$src_head) -gt 1 ]; then
-		echo "WARNING: Your commit filter caused the head commit to expand to several rewritten commits. Only the first such commit was recorded as the current $dstbranch head but you will need to resolve the situation now (probably by manually merging the other commits). These are all the commits:" >&2
-		sed 's/^/	/' ../map/$src_head >&2
-		ret=1
-	fi
+	$_x40)
+		echo "Ref '$ref' was rewritten"
+		git update-ref -m "filter-branch: rewrite" \
+				"$ref" $rewritten $sha1 ||
+			die "Could not rewrite $ref"
 	;;
-esac
+	*)
+		# NEEDSWORK: possibly add -Werror, making this an error
+		warn "WARNING: '$ref' was rewritten into multiple commits:"
+		warn "$rewritten"
+		warn "WARNING: Ref '$ref' points to the first one now."
+		rewritten=$(echo "$rewritten" | head -n 1)
+		git update-ref -m "filter-branch: rewrite to first" \
+				"$ref" $rewritten $sha1 ||
+			die "Could not rewrite $ref"
+	;;
+	esac
+	git update-ref -m "filter-branch: backup" "$orig_namespace$ref" $sha1
+	count=$(($count+1))
+done < "$tempdir"/heads
+
+# TODO: This should possibly go, with the semantics that all positive given
+#       refs are updated, and their original heads stored in refs/original/
+# Filter tags
 
 if [ "$filter_tag_name" ]; then
 	git for-each-ref --format='%(objectname) %(objecttype) %(refname)' refs/tags |
