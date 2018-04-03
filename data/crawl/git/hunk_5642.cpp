 test_expect_success 'test notes in 2/2/36-fanout' 'test_sha1_based "s|^\(..\)\(..\)|\1/\2/|"'
 test_expect_success 'verify notes in 2/2/36-fanout' 'verify_notes'
 
+test_same_notes () {
+	(
+		start_note_commit &&
+		nr=$number_of_commits &&
+		git rev-list refs/heads/master |
+		while read sha1; do
+			first_note_path=$(echo "$sha1" | sed "$1")
+			second_note_path=$(echo "$sha1" | sed "$2")
+			cat <<INPUT_END &&
+M 100644 inline $second_note_path
+data <<EOF
+note for commit #$nr
+EOF
+
+M 100644 inline $first_note_path
+data <<EOF
+note for commit #$nr
+EOF
+
+INPUT_END
+
+			nr=$(($nr-1))
+		done
+	) |
+	git fast-import --quiet
+}
+
+test_expect_success 'test same notes in 4/36-fanout and 2/38-fanout' 'test_same_notes "s|^..|&/|" "s|^....|&/|"'
+test_expect_success 'verify same notes in 4/36-fanout and 2/38-fanout' 'verify_notes'
+
+test_expect_success 'test same notes in 2/38-fanout and 2/2/36-fanout' 'test_same_notes "s|^\(..\)\(..\)|\1/\2/|" "s|^..|&/|"'
+test_expect_success 'verify same notes in 2/38-fanout and 2/2/36-fanout' 'verify_notes'
+
+test_expect_success 'test same notes in 4/36-fanout and 2/2/36-fanout' 'test_same_notes "s|^\(..\)\(..\)|\1/\2/|" "s|^....|&/|"'
+test_expect_success 'verify same notes in 4/36-fanout and 2/2/36-fanout' 'verify_notes'
+
+test_concatenated_notes () {
+	(
+		start_note_commit &&
+		nr=$number_of_commits &&
+		git rev-list refs/heads/master |
+		while read sha1; do
+			first_note_path=$(echo "$sha1" | sed "$1")
+			second_note_path=$(echo "$sha1" | sed "$2")
+			cat <<INPUT_END &&
+M 100644 inline $second_note_path
+data <<EOF
+second note for commit #$nr
+EOF
+
+M 100644 inline $first_note_path
+data <<EOF
+first note for commit #$nr
+EOF
+
+INPUT_END
+
+			nr=$(($nr-1))
+		done
+	) |
+	git fast-import --quiet
+}
+
+verify_concatenated_notes () {
+    git log | grep "^    " > output &&
+    i=$number_of_commits &&
+    while [ $i -gt 0 ]; do
+        echo "    commit #$i" &&
+        echo "    first note for commit #$i" &&
+        echo "    second note for commit #$i" &&
+        i=$(($i-1));
+    done > expect &&
+    test_cmp expect output
+}
+
+test_expect_success 'test notes in 4/36-fanout concatenated with 2/38-fanout' 'test_concatenated_notes "s|^..|&/|" "s|^....|&/|"'
+test_expect_success 'verify notes in 4/36-fanout concatenated with 2/38-fanout' 'verify_concatenated_notes'
+
+test_expect_success 'test notes in 2/38-fanout concatenated with 2/2/36-fanout' 'test_concatenated_notes "s|^\(..\)\(..\)|\1/\2/|" "s|^..|&/|"'
+test_expect_success 'verify notes in 2/38-fanout concatenated with 2/2/36-fanout' 'verify_concatenated_notes'
+
+test_expect_success 'test notes in 4/36-fanout concatenated with 2/2/36-fanout' 'test_concatenated_notes "s|^\(..\)\(..\)|\1/\2/|" "s|^....|&/|"'
+test_expect_success 'verify notes in 4/36-fanout concatenated with 2/2/36-fanout' 'verify_concatenated_notes'
+
 test_done