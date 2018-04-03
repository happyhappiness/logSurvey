 	)
 '
 
+test_expect_success SYMLINKS 'empty symlink target' '
+	(
+		# first create the file as a file
+		cd "$cli" &&
+		>empty-symlink &&
+		p4 add empty-symlink &&
+		p4 submit -d "add empty-symlink as a file"
+	) &&
+	(
+		# now change it to be a symlink to "target1"
+		cd "$cli" &&
+		p4 edit empty-symlink &&
+		p4 reopen -t symlink empty-symlink &&
+		rm empty-symlink &&
+		ln -s target1 empty-symlink &&
+		p4 add empty-symlink &&
+		p4 submit -d "make empty-symlink point to target1"
+	) &&
+	(
+		# Hack the p4 depot to make the symlink point to nothing;
+		# this should not happen in reality, but shows up
+		# in p4 repos in the wild.
+		#
+		# The sed expression changes this:
+		#     @@
+		#     text
+		#     @target1
+		#     @
+		# to this:
+		#     @@
+		#     text
+		#     @@
+		#
+		cd "$db/depot" &&
+		sed "/@target1/{; s/target1/@/; n; d; }" \
+		    empty-symlink,v >empty-symlink,v.tmp &&
+		mv empty-symlink,v.tmp empty-symlink,v
+	) &&
+	(
+		# Make sure symlink really is empty.  Asking
+		# p4 to sync here will make it generate errors.
+		cd "$cli" &&
+		p4 print -q //depot/empty-symlink#2 >out &&
+		test ! -s out
+	) &&
+	test_when_finished cleanup_git &&
+
+	# make sure git p4 handles it without error
+	git p4 clone --dest="$git" //depot@all &&
+
+	# fix the symlink, make it point to "target2"
+	(
+		cd "$cli" &&
+		p4 open empty-symlink &&
+		rm empty-symlink &&
+		ln -s target2 empty-symlink &&
+		p4 submit -d "make empty-symlink point to target2"
+	) &&
+	cleanup_git &&
+	git p4 clone --dest="$git" //depot@all &&
+	(
+		cd "$git" &&
+		test $(readlink empty-symlink) = target2
+	)
+'
+
 test_expect_success 'kill p4d' '
 	kill_p4d
 '