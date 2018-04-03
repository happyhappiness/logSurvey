 
 sub validate_patch {
 	my $fn = shift;
+
+	my $validate_hook = catfile(catdir($repo->repo_path(), 'hooks'),
+				    'sendemail-validate');
+	my $hook_error;
+	if (-x $validate_hook) {
+		my $target = abs_path($fn);
+		# The hook needs a correct cwd and GIT_DIR.
+		my $cwd_save = cwd();
+		chdir($repo->wc_path() or $repo->repo_path())
+			or die("chdir: $!");
+		local $ENV{"GIT_DIR"} = $repo->repo_path();
+		$hook_error = "rejected by sendemail-validate hook"
+			if system($validate_hook, $target);
+		chdir($cwd_save) or die("chdir: $!");
+	}
+	return $hook_error if $hook_error;
+
 	open(my $fh, '<', $fn)
 		or die sprintf(__("unable to open %s: %s\n"), $fn, $!);
 	while (my $line = <$fh>) {
