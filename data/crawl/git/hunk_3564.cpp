 	test_cmp expect actual
 }
 
+# $1 = success or failure
+# $2 = push.default value
+# $3 = branch to check for actual output (master or foo)
+# $4 = [optional] switch to triangular workflow
+test_pushdefault_workflow () {
+	workflow=central
+	pushdefault=parent1
+	if test -n "${4-}"; then
+		workflow=triangular
+		pushdefault=parent2
+	fi
+	test_expect_success "push.default = $2 $1 in $workflow workflows" "
+		test_config branch.master.remote parent1 &&
+		test_config branch.master.merge refs/heads/foo &&
+		test_config remote.pushdefault $pushdefault &&
+		test_commit commit-for-$2${4+-triangular} &&
+		test_push_$1 $2 $3 ${4+repo2}
+	"
+}
+
 test_expect_success '"upstream" pushes to configured upstream' '
 	git checkout master &&
 	test_config branch.master.remote parent1 &&
