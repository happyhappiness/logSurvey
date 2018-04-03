
    die "Need filehash" unless ( defined ( $filehash ) and $filehash =~ /^[a-zA-Z0-9]{40}$/ );

    my $type = `git-cat-file -t $filehash`;
    chomp $type;

    die ( "Invalid type '$type' (expected 'blob')" ) unless ( defined ( $type ) and $type eq "blob" );

    my $size = `git-cat-file -s $filehash`;
    chomp $size;

    $log->debug("transmitfile($filehash) size=$size, type=$type");

    if ( open my $fh, '-|', "git-cat-file", "blob", $filehash )
    {
        if ( defined ( $options->{targetfile} ) )
        {
