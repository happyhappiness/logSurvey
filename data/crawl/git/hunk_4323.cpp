 	done
 }
 
+resolve_submodule_merge () {
+    while true; do
+	printf "Use (l)ocal or (r)emote, or (a)bort? "
+	read ans
+	case "$ans" in
+	    [lL]*)
+		if ! local_present; then
+		    if test -n "$(git ls-tree HEAD -- "$MERGED")"; then
+			# Local isn't present, but it's a subdirectory
+			git ls-tree --full-name -r HEAD -- "$MERGED" | git update-index --index-info || exit $?
+		    else
+			test -e "$MERGED" && mv -- "$MERGED" "$BACKUP"
+			git update-index --force-remove "$MERGED"
+			cleanup_temp_files --save-backup
+		    fi
+		elif is_submodule "$local_mode"; then
+		    stage_submodule "$MERGED" "$local_sha1"
+		else
+		    git checkout-index -f --stage=2 -- "$MERGED"
+		    git add -- "$MERGED"
+		fi
+		return 0
+		;;
+	    [rR]*)
+		if ! remote_present; then
+		    if test -n "$(git ls-tree MERGE_HEAD -- "$MERGED")"; then
+			# Remote isn't present, but it's a subdirectory
+			git ls-tree --full-name -r MERGE_HEAD -- "$MERGED" | git update-index --index-info || exit $?
+		    else
+			test -e "$MERGED" && mv -- "$MERGED" "$BACKUP"
+			git update-index --force-remove "$MERGED"
+		    fi
+		elif is_submodule "$remote_mode"; then
+		    ! is_submodule "$local_mode" && test -e "$MERGED" && mv -- "$MERGED" "$BACKUP"
+		    stage_submodule "$MERGED" "$remote_sha1"
+		else
+		    test -e "$MERGED" && mv -- "$MERGED" "$BACKUP"
+		    git checkout-index -f --stage=3 -- "$MERGED"
+		    git add -- "$MERGED"
+		fi
+		cleanup_temp_files --save-backup
+		return 0
+		;;
+	    [aA]*)
+		return 1
+		;;
+	    esac
+	done
+}
+
+stage_submodule () {
+    path="$1"
+    submodule_sha1="$2"
+    mkdir -p "$path" || die "fatal: unable to create directory for module at $path"
+    # Find $path relative to work tree
+    work_tree_root=$(cd_to_toplevel && pwd)
+    work_rel_path=$(cd "$path" && GIT_WORK_TREE="${work_tree_root}" git rev-parse --show-prefix)
+    test -n "$work_rel_path" || die "fatal: unable to get path of module $path relative to work tree"
+    git update-index --add --replace --cacheinfo 160000 "$submodule_sha1" "${work_rel_path%/}" || die
+}
+
 checkout_staged_file () {
     tmpfile=$(expr "$(git checkout-index --temp --stage="$1" "$2")" : '\([^	]*\)	')
 
