 	unlink $gs->{index};
 }
 
+sub cmd_branch {
+	my ($branch_name, $head) = @_;
+
+	unless (defined $branch_name && length $branch_name) {
+		die(($_tag ? "tag" : "branch") . " name required\n");
+	}
+	$head ||= 'HEAD';
+
+	my ($src, $rev, undef, $gs) = working_head_info($head);
+
+	my $remote = Git::SVN::read_all_remotes()->{svn};
+	my $glob = $remote->{ $_tag ? 'tags' : 'branches' };
+	my ($lft, $rgt) = @{ $glob->{path} }{qw/left right/};
+	my $dst = join '/', $remote->{url}, $lft, $branch_name, ($rgt || ());
+
+	my $ctx = SVN::Client->new(
+		auth    => Git::SVN::Ra::_auth_providers(),
+		log_msg => sub {
+			${ $_[0] } = defined $_message
+				? $_message
+				: 'Create ' . ($_tag ? 'tag ' : 'branch ' )
+				. $branch_name;
+		},
+	);
+
+	eval {
+		$ctx->ls($dst, 'HEAD', 0);
+	} and die "branch ${branch_name} already exists\n";
+
+	print "Copying ${src} at r${rev} to ${dst}...\n";
+	$ctx->copy($src, $rev, $dst)
+		unless $_dry_run;
+
+	$gs->fetch_all;
+}
+
 sub cmd_find_rev {
 	my $revision_or_hash = shift or die "SVN or git revision required ",
 	                                    "as a command-line argument\n";
