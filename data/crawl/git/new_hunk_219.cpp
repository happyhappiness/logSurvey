
    die "Need filehash" unless ( defined ( $filehash ) and $filehash =~ /^[a-zA-Z0-9]{40}$/ );

    my $type = safe_pipe_capture('git', 'cat-file', '-t', $filehash);
    chomp $type;

    die ( "Invalid type '$type' (expected 'blob')" ) unless ( defined ( $type ) and $type eq "blob" );

    my $size = safe_pipe_capture('git', 'cat-file', '-s', $filehash);
    chomp $size;

    $log->debug("transmitfile($filehash) size=$size, type=$type");
