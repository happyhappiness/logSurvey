    }
}

# This should have the same heuristics as convert.c:is_binary() and related.
# Note that the bare CR test is done by callers in convert.c.
sub is_binary
{
    my ($srcType,$name) = @_;
    $log->debug("is_binary($srcType,$name)");

    # Minimize amount of interpreted code run in the inner per-character
    # loop for large files, by totalling each character value and
    # then analyzing the totals.
    my @counts;
    my $i;
    for($i=0;$i<256;$i++)
    {
        $counts[$i]=0;
    }

    my $fh = open_blob_or_die($srcType,$name);
    my $line;
    while( defined($line=<$fh>) )
    {
        # Any '\0' and bare CR are considered binary.
        if( $line =~ /\0|(\r[^\n])/ )
        {
            close($fh);
            return 1;
        }

        # Count up each character in the line:
        my $len=length($line);
        for($i=0;$i<$len;$i++)
        {
            $counts[ord(substr($line,$i,1))]++;
        }
    }
    close $fh;

    # Don't count CR and LF as either printable/nonprintable
    $counts[ord("\n")]=0;
    $counts[ord("\r")]=0;

    # Categorize individual character count into printable and nonprintable:
    my $printable=0;
    my $nonprintable=0;
    for($i=0;$i<256;$i++)
    {
        if( $i < 32 &&
            $i != ord("\b") &&
            $i != ord("\t") &&
            $i != 033 &&       # ESC
            $i != 014 )        # FF
        {
            $nonprintable+=$counts[$i];
        }
        elsif( $i==127 )  # DEL
        {
            $nonprintable+=$counts[$i];
        }
        else
        {
            $printable+=$counts[$i];
        }
    }

    return ($printable >> 7) < $nonprintable;
}

# Returns open file handle.  Possible invocations:
#  - open_blob_or_die("file",$filename);
#  - open_blob_or_die("sha1",$filehash);
sub open_blob_or_die
{
    my ($srcType,$name) = @_;
    my ($fh);
    if( $srcType eq "file" )
    {
        if( !open $fh,"<",$name )
        {
            $log->warn("Unable to open file $name: $!");
            die "Unable to open file $name: $!\n";
        }
    }
    elsif( $srcType eq "sha1" || $srcType eq "sha1Or-k" )
    {
        unless ( defined ( $name ) and $name =~ /^[a-zA-Z0-9]{40}$/ )
        {
            $log->warn("Need filehash");
            die "Need filehash\n";
        }

        my $type = `git cat-file -t $name`;
        chomp $type;

        unless ( defined ( $type ) and $type eq "blob" )
        {
            $log->warn("Invalid type '$type' for '$name'");
            die ( "Invalid type '$type' (expected 'blob')" )
        }

        my $size = `git cat-file -s $name`;
        chomp $size;

        $log->debug("open_blob_or_die($name) size=$size, type=$type");

        unless( open $fh, '-|', "git", "cat-file", "blob", $name )
        {
            $log->warn("Unable to open sha1 $name");
            die "Unable to open sha1 $name\n";
        }
    }
    else
    {
        $log->warn("Unknown type of blob source: $srcType");
        die "Unknown type of blob source: $srcType\n";
    }
    return $fh;
}

# Generate a CVS author name from Git author information, by taking
# the first eight characters of the user part of the email address.
sub cvs_author
