 	}
 
 	nr = all - reaches - 1;
-	printf("Bisecting: %d revisions left to test after this "
-	       "(roughly %d steps)\n", nr, estimate_bisect_steps(all));
+	steps = estimate_bisect_steps(all);
+	printf("Bisecting: %d revision%s left to test after this "
+	       "(roughly %d step%s)\n", nr, (nr == 1 ? "" : "s"),
+	       steps, (steps == 1 ? "" : "s"));
 
 	return bisect_checkout(bisect_rev_hex);
 }