 
 # Returns true if the mode reflects a symlink
 is_symlink () {
-    test "$1" = 120000
+	test "$1" = 120000
 }
 
 is_submodule () {
-    test "$1" = 160000
+	test "$1" = 160000
 }
 
 local_present () {
-    test -n "$local_mode"
+	test -n "$local_mode"
 }
 
 remote_present () {
-    test -n "$remote_mode"
+	test -n "$remote_mode"
 }
 
 base_present () {
-    test -n "$base_mode"
+	test -n "$base_mode"
 }
 
 cleanup_temp_files () {
-    if test "$1" = --save-backup ; then
-	rm -rf -- "$MERGED.orig"
-	test -e "$BACKUP" && mv -- "$BACKUP" "$MERGED.orig"
-	rm -f -- "$LOCAL" "$REMOTE" "$BASE"
-    else
-	rm -f -- "$LOCAL" "$REMOTE" "$BASE" "$BACKUP"
-    fi
+	if test "$1" = --save-backup
+	then
+		rm -rf -- "$MERGED.orig"
+		test -e "$BACKUP" && mv -- "$BACKUP" "$MERGED.orig"
+		rm -f -- "$LOCAL" "$REMOTE" "$BASE"
+	else
+		rm -f -- "$LOCAL" "$REMOTE" "$BASE" "$BACKUP"
+	fi
 }
 
 describe_file () {
-    mode="$1"
-    branch="$2"
-    file="$3"
-
-    printf "  {%s}: " "$branch"
-    if test -z "$mode"; then
-	echo "deleted"
-    elif is_symlink "$mode" ; then
-	echo "a symbolic link -> '$(cat "$file")'"
-    elif is_submodule "$mode" ; then
-	echo "submodule commit $file"
-    else
-	if base_present; then
-	    echo "modified file"
+	mode="$1"
+	branch="$2"
+	file="$3"
+
+	printf "  {%s}: " "$branch"
+	if test -z "$mode"
+	then
+		echo "deleted"
+	elif is_symlink "$mode"
+	then
+		echo "a symbolic link -> '$(cat "$file")'"
+	elif is_submodule "$mode"
+	then
+		echo "submodule commit $file"
+	elif base_present
+	then
+		echo "modified file"
 	else
-	    echo "created file"
+		echo "created file"
 	fi
-    fi
 }
 
-
 resolve_symlink_merge () {
-    while true; do
-	printf "Use (l)ocal or (r)emote, or (a)bort? "
-	read ans || return 1
-	case "$ans" in
-	    [lL]*)
-		git checkout-index -f --stage=2 -- "$MERGED"
-		git add -- "$MERGED"
-		cleanup_temp_files --save-backup
-		return 0
-		;;
-	    [rR]*)
-		git checkout-index -f --stage=3 -- "$MERGED"
-		git add -- "$MERGED"
-		cleanup_temp_files --save-backup
-		return 0
-		;;
-	    [aA]*)
-		return 1
-		;;
-	    esac
+	while true
+	do
+		printf "Use (l)ocal or (r)emote, or (a)bort? "
+		read ans || return 1
+		case "$ans" in
+		[lL]*)
+			git checkout-index -f --stage=2 -- "$MERGED"
+			git add -- "$MERGED"
+			cleanup_temp_files --save-backup
+			return 0
+			;;
+		[rR]*)
+			git checkout-index -f --stage=3 -- "$MERGED"
+			git add -- "$MERGED"
+			cleanup_temp_files --save-backup
+			return 0
+			;;
+		[aA]*)
+			return 1
+			;;
+		esac
 	done
 }
 
 resolve_deleted_merge () {
-    while true; do
-	if base_present; then
-	    printf "Use (m)odified or (d)eleted file, or (a)bort? "
-	else
-	    printf "Use (c)reated or (d)eleted file, or (a)bort? "
-	fi
-	read ans || return 1
-	case "$ans" in
-	    [mMcC]*)
-		git add -- "$MERGED"
-		cleanup_temp_files --save-backup
-		return 0
-		;;
-	    [dD]*)
-		git rm -- "$MERGED" > /dev/null
-		cleanup_temp_files
-		return 0
-		;;
-	    [aA]*)
-		return 1
-		;;
-	    esac
+	while true
+	do
+		if base_present
+		then
+			printf "Use (m)odified or (d)eleted file, or (a)bort? "
+		else
+			printf "Use (c)reated or (d)eleted file, or (a)bort? "
+		fi
+		read ans || return 1
+		case "$ans" in
+		[mMcC]*)
+			git add -- "$MERGED"
+			cleanup_temp_files --save-backup
+			return 0
+			;;
+		[dD]*)
+			git rm -- "$MERGED" > /dev/null
+			cleanup_temp_files
+			return 0
+			;;
+		[aA]*)
+			return 1
+			;;
+		esac
 	done
 }
 
 resolve_submodule_merge () {
-    while true; do
-	printf "Use (l)ocal or (r)emote, or (a)bort? "
-	read ans || return 1
-	case "$ans" in
-	    [lL]*)
-		if ! local_present; then
-		    if test -n "$(git ls-tree HEAD -- "$MERGED")"; then
-			# Local isn't present, but it's a subdirectory
-			git ls-tree --full-name -r HEAD -- "$MERGED" | git update-index --index-info || exit $?
-		    else
-			test -e "$MERGED" && mv -- "$MERGED" "$BACKUP"
-			git update-index --force-remove "$MERGED"
+	while true
+	do
+		printf "Use (l)ocal or (r)emote, or (a)bort? "
+		read ans || return 1
+		case "$ans" in
+		[lL]*)
+			if ! local_present
+			then
+				if test -n "$(git ls-tree HEAD -- "$MERGED")"
+				then
+					# Local isn't present, but it's a subdirectory
+					git ls-tree --full-name -r HEAD -- "$MERGED" |
+					git update-index --index-info || exit $?
+				else
+					test -e "$MERGED" && mv -- "$MERGED" "$BACKUP"
+					git update-index --force-remove "$MERGED"
+					cleanup_temp_files --save-backup
+				fi
+			elif is_submodule "$local_mode"
+			then
+				stage_submodule "$MERGED" "$local_sha1"
+			else
+				git checkout-index -f --stage=2 -- "$MERGED"
+				git add -- "$MERGED"
+			fi
+			return 0
+			;;
+		[rR]*)
+			if ! remote_present
+			then
+				if test -n "$(git ls-tree MERGE_HEAD -- "$MERGED")"
+				then
+					# Remote isn't present, but it's a subdirectory
+					git ls-tree --full-name -r MERGE_HEAD -- "$MERGED" |
+					git update-index --index-info || exit $?
+				else
+					test -e "$MERGED" && mv -- "$MERGED" "$BACKUP"
+					git update-index --force-remove "$MERGED"
+				fi
+			elif is_submodule "$remote_mode"
+			then
+				! is_submodule "$local_mode" &&
+				test -e "$MERGED" &&
+				mv -- "$MERGED" "$BACKUP"
+				stage_submodule "$MERGED" "$remote_sha1"
+			else
+				test -e "$MERGED" && mv -- "$MERGED" "$BACKUP"
+				git checkout-index -f --stage=3 -- "$MERGED"
+				git add -- "$MERGED"
+			fi
 			cleanup_temp_files --save-backup
-		    fi
-		elif is_submodule "$local_mode"; then
-		    stage_submodule "$MERGED" "$local_sha1"
-		else
-		    git checkout-index -f --stage=2 -- "$MERGED"
-		    git add -- "$MERGED"
-		fi
-		return 0
-		;;
-	    [rR]*)
-		if ! remote_present; then
-		    if test -n "$(git ls-tree MERGE_HEAD -- "$MERGED")"; then
-			# Remote isn't present, but it's a subdirectory
-			git ls-tree --full-name -r MERGE_HEAD -- "$MERGED" | git update-index --index-info || exit $?
-		    else
-			test -e "$MERGED" && mv -- "$MERGED" "$BACKUP"
-			git update-index --force-remove "$MERGED"
-		    fi
-		elif is_submodule "$remote_mode"; then
-		    ! is_submodule "$local_mode" && test -e "$MERGED" && mv -- "$MERGED" "$BACKUP"
-		    stage_submodule "$MERGED" "$remote_sha1"
-		else
-		    test -e "$MERGED" && mv -- "$MERGED" "$BACKUP"
-		    git checkout-index -f --stage=3 -- "$MERGED"
-		    git add -- "$MERGED"
-		fi
-		cleanup_temp_files --save-backup
-		return 0
-		;;
-	    [aA]*)
-		return 1
-		;;
-	    esac
+			return 0
+			;;
+		[aA]*)
+			return 1
+			;;
+		esac
 	done
 }
 
 stage_submodule () {
-    path="$1"
-    submodule_sha1="$2"
-    mkdir -p "$path" || die "fatal: unable to create directory for module at $path"
-    # Find $path relative to work tree
-    work_tree_root=$(cd_to_toplevel && pwd)
-    work_rel_path=$(cd "$path" && GIT_WORK_TREE="${work_tree_root}" git rev-parse --show-prefix)
-    test -n "$work_rel_path" || die "fatal: unable to get path of module $path relative to work tree"
-    git update-index --add --replace --cacheinfo 160000 "$submodule_sha1" "${work_rel_path%/}" || die
+	path="$1"
+	submodule_sha1="$2"
+	mkdir -p "$path" ||
+	die "fatal: unable to create directory for module at $path"
+	# Find $path relative to work tree
+	work_tree_root=$(cd_to_toplevel && pwd)
+	work_rel_path=$(cd "$path" &&
+		GIT_WORK_TREE="${work_tree_root}" git rev-parse --show-prefix
+	)
+	test -n "$work_rel_path" ||
+	die "fatal: unable to get path of module $path relative to work tree"
+	git update-index --add --replace --cacheinfo 160000 "$submodule_sha1" "${work_rel_path%/}" || die
 }
 
 checkout_staged_file () {
-    tmpfile=$(expr \
-	    "$(git checkout-index --temp --stage="$1" "$2" 2>/dev/null)" \
-	    : '\([^	]*\)	')
-
-    if test $? -eq 0 -a -n "$tmpfile" ; then
-	mv -- "$(git rev-parse --show-cdup)$tmpfile" "$3"
-    else
-	>"$3"
-    fi
+	tmpfile=$(expr \
+		"$(git checkout-index --temp --stage="$1" "$2" 2>/dev/null)" \
+		: '\([^	]*\)	')
+
+	if test $? -eq 0 -a -n "$tmpfile"
+	then
+		mv -- "$(git rev-parse --show-cdup)$tmpfile" "$3"
+	else
+		>"$3"
+	fi
 }
 
 merge_file () {
-    MERGED="$1"
+	MERGED="$1"
 
-    f=$(git ls-files -u -- "$MERGED")
-    if test -z "$f" ; then
-	if test ! -f "$MERGED" ; then
-	    echo "$MERGED: file not found"
-	else
-	    echo "$MERGED: file does not need merging"
+	f=$(git ls-files -u -- "$MERGED")
+	if test -z "$f"
+	then
+		if test ! -f "$MERGED"
+		then
+			echo "$MERGED: file not found"
+		else
+			echo "$MERGED: file does not need merging"
+		fi
+		return 1
 	fi
-	return 1
-    fi
-
-    ext="$$$(expr "$MERGED" : '.*\(\.[^/]*\)$')"
-    BACKUP="./$MERGED.BACKUP.$ext"
-    LOCAL="./$MERGED.LOCAL.$ext"
-    REMOTE="./$MERGED.REMOTE.$ext"
-    BASE="./$MERGED.BASE.$ext"
-
-    base_mode=$(git ls-files -u -- "$MERGED" | awk '{if ($3==1) print $1;}')
-    local_mode=$(git ls-files -u -- "$MERGED" | awk '{if ($3==2) print $1;}')
-    remote_mode=$(git ls-files -u -- "$MERGED" | awk '{if ($3==3) print $1;}')
-
-    if is_submodule "$local_mode" || is_submodule "$remote_mode"; then
-	echo "Submodule merge conflict for '$MERGED':"
-	local_sha1=$(git ls-files -u -- "$MERGED" | awk '{if ($3==2) print $2;}')
-	remote_sha1=$(git ls-files -u -- "$MERGED" | awk '{if ($3==3) print $2;}')
-	describe_file "$local_mode" "local" "$local_sha1"
-	describe_file "$remote_mode" "remote" "$remote_sha1"
-	resolve_submodule_merge
-	return
-    fi
-
-    mv -- "$MERGED" "$BACKUP"
-    cp -- "$BACKUP" "$MERGED"
-
-    checkout_staged_file 1 "$MERGED" "$BASE"
-    checkout_staged_file 2 "$MERGED" "$LOCAL"
-    checkout_staged_file 3 "$MERGED" "$REMOTE"
-
-    if test -z "$local_mode" -o -z "$remote_mode"; then
-	echo "Deleted merge conflict for '$MERGED':"
-	describe_file "$local_mode" "local" "$LOCAL"
-	describe_file "$remote_mode" "remote" "$REMOTE"
-	resolve_deleted_merge
-	return
-    fi
 
-    if is_symlink "$local_mode" || is_symlink "$remote_mode"; then
-	echo "Symbolic link merge conflict for '$MERGED':"
+	ext="$$$(expr "$MERGED" : '.*\(\.[^/]*\)$')"
+	BACKUP="./$MERGED.BACKUP.$ext"
+	LOCAL="./$MERGED.LOCAL.$ext"
+	REMOTE="./$MERGED.REMOTE.$ext"
+	BASE="./$MERGED.BASE.$ext"
+
+	base_mode=$(git ls-files -u -- "$MERGED" | awk '{if ($3==1) print $1;}')
+	local_mode=$(git ls-files -u -- "$MERGED" | awk '{if ($3==2) print $1;}')
+	remote_mode=$(git ls-files -u -- "$MERGED" | awk '{if ($3==3) print $1;}')
+
+	if is_submodule "$local_mode" || is_submodule "$remote_mode"
+	then
+		echo "Submodule merge conflict for '$MERGED':"
+		local_sha1=$(git ls-files -u -- "$MERGED" | awk '{if ($3==2) print $2;}')
+		remote_sha1=$(git ls-files -u -- "$MERGED" | awk '{if ($3==3) print $2;}')
+		describe_file "$local_mode" "local" "$local_sha1"
+		describe_file "$remote_mode" "remote" "$remote_sha1"
+		resolve_submodule_merge
+		return
+	fi
+
+	mv -- "$MERGED" "$BACKUP"
+	cp -- "$BACKUP" "$MERGED"
+
+	checkout_staged_file 1 "$MERGED" "$BASE"
+	checkout_staged_file 2 "$MERGED" "$LOCAL"
+	checkout_staged_file 3 "$MERGED" "$REMOTE"
+
+	if test -z "$local_mode" -o -z "$remote_mode"
+	then
+		echo "Deleted merge conflict for '$MERGED':"
+		describe_file "$local_mode" "local" "$LOCAL"
+		describe_file "$remote_mode" "remote" "$REMOTE"
+		resolve_deleted_merge
+		return
+	fi
+
+	if is_symlink "$local_mode" || is_symlink "$remote_mode"
+	then
+		echo "Symbolic link merge conflict for '$MERGED':"
+		describe_file "$local_mode" "local" "$LOCAL"
+		describe_file "$remote_mode" "remote" "$REMOTE"
+		resolve_symlink_merge
+		return
+	fi
+
+	echo "Normal merge conflict for '$MERGED':"
 	describe_file "$local_mode" "local" "$LOCAL"
 	describe_file "$remote_mode" "remote" "$REMOTE"
-	resolve_symlink_merge
-	return
-    fi
-
-    echo "Normal merge conflict for '$MERGED':"
-    describe_file "$local_mode" "local" "$LOCAL"
-    describe_file "$remote_mode" "remote" "$REMOTE"
-    if "$prompt" = true; then
-	printf "Hit return to start merge resolution tool (%s): " "$merge_tool"
-	read ans || return 1
-    fi
-
-    if base_present; then
-	    present=true
-    else
-	    present=false
-    fi
-
-    if ! run_merge_tool "$merge_tool" "$present"; then
-	echo "merge of $MERGED failed" 1>&2
-	mv -- "$BACKUP" "$MERGED"
-
-	if test "$merge_keep_temporaries" = "false"; then
-	    cleanup_temp_files
+	if "$prompt" = true
+	then
+		printf "Hit return to start merge resolution tool (%s): " "$merge_tool"
+		read ans || return 1
 	fi
 
-	return 1
-    fi
+	if base_present
+	then
+		present=true
+	else
+		present=false
+	fi
+
+	if ! run_merge_tool "$merge_tool" "$present"
+	then
+		echo "merge of $MERGED failed" 1>&2
+		mv -- "$BACKUP" "$MERGED"
+
+		if test "$merge_keep_temporaries" = "false"
+		then
+			cleanup_temp_files
+		fi
 
-    if test "$merge_keep_backup" = "true"; then
-	mv -- "$BACKUP" "$MERGED.orig"
-    else
-	rm -- "$BACKUP"
-    fi
+		return 1
+	fi
 
-    git add -- "$MERGED"
-    cleanup_temp_files
-    return 0
+	if test "$merge_keep_backup" = "true"
+	then
+		mv -- "$BACKUP" "$MERGED.orig"
+	else
+		rm -- "$BACKUP"
+	fi
+
+	git add -- "$MERGED"
+	cleanup_temp_files
+	return 0
 }
 
 show_tool_help () {
