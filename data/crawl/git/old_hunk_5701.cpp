            # this is used to detect files removed from the repo
            my $seen_files = {};

            my $filepipe = open(FILELIST, '-|', 'git-ls-tree', '-z', '-r', $commit->{hash}) or die("Cannot call git-ls-tree : $!");
	    local $/ = "\0";
            while ( <FILELIST> )
            {
