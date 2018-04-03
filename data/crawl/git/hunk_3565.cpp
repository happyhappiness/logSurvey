 	test_cmp expect-other-name actual-other-name
 '
 
+# We are on 'master', which integrates with 'foo' from parent1
+# remote (set in test_pushdefault_workflow helper).  Push to
+# parent1 in centralized, and push to parent2 in triangular workflow.
+# The parent1 repository has 'master' and 'foo' branches, while
+# the parent2 repository has only 'master' branch.
+#
+# test_pushdefault_workflow() arguments:
+# $1 = success or failure
+# $2 = push.default value
+# $3 = branch to check for actual output (master or foo)
+# $4 = [optional] switch to triangular workflow
+
+# update parent1's master (which is not our upstream)
+test_pushdefault_workflow success current master
+
+# update parent1's foo (which is our upstream)
+test_pushdefault_workflow success upstream foo
+
+# upsream is foo which is not the name of the current branch
+test_pushdefault_workflow failure simple master
+
+# master and foo are updated
+test_pushdefault_workflow success matching master
+
+# master is updated
+test_pushdefault_workflow success current master triangular
+
+# upstream mode cannot be used in triangular
+test_pushdefault_workflow failure upstream foo triangular
+
+# in triangular, 'simple' works as 'current' and update the branch
+# with the same name.
+test_pushdefault_workflow success simple master triangular
+
+# master is updated (parent2 does not have foo)
+test_pushdefault_workflow success matching master triangular
+
 test_done