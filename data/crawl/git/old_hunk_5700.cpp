
        if ( defined ( $lastpicked ) )
        {
            my $filepipe = open(FILELIST, '-|', 'git-diff-tree', '-z', '-r', $lastpicked, $commit->{hash}) or die("Cannot call git-diff-tree : $!");
	    local ($/) = "\0";
            while ( <FILELIST> )
            {
