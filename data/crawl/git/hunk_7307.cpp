 		    !memcmp(mf1.ptr, mf2.ptr, mf1.size))
 			goto free_ab_and_return;
 		if (DIFF_OPT_TST(o, BINARY))
-			emit_binary_diff(&mf1, &mf2);
+			emit_binary_diff(o->file, &mf1, &mf2);
 		else
-			printf("Binary files %s and %s differ\n",
-			       lbl[0], lbl[1]);
+			fprintf(o->file, "Binary files %s and %s differ\n",
+				lbl[0], lbl[1]);
 		o->found_changes = 1;
 	}
 	else {
