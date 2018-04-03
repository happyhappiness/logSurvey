    # first lets get the commit list
    $ENV{GIT_DIR} = $self->{git_path};

    my $commitsha1 = `git rev-parse $self->{module}`;
    chomp $commitsha1;

    my $commitinfo = `git cat-file commit $self->{module} 2>&1`;
    unless ( $commitinfo =~ /tree\s+[a-zA-Z0-9]{40}/ )
    {
        die("Invalid module '$self->{module}'");
