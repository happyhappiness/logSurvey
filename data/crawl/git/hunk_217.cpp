     # first lets get the commit list
     $ENV{GIT_DIR} = $self->{git_path};
 
-    my $commitsha1 = `git rev-parse $self->{module}`;
+    my $commitsha1 = ::safe_pipe_capture('git', 'rev-parse', $self->{module});
     chomp $commitsha1;
 
-    my $commitinfo = `git cat-file commit $self->{module} 2>&1`;
+    my $commitinfo = ::safe_pipe_capture('git', 'cat-file', 'commit', $self->{module});
     unless ( $commitinfo =~ /tree\s+[a-zA-Z0-9]{40}/ )
     {
         die("Invalid module '$self->{module}'");
