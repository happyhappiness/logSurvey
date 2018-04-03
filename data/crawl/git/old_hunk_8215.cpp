        {
            open NEWFILE, ">", $targetfile or die("Couldn't open '$targetfile' for writing : $!");
            print NEWFILE $_ while ( <$fh> );
            close NEWFILE;
        } else {
            print "$size\n";
            print while ( <$fh> );
        }
        close $fh or die ("Couldn't close filehandle for transmitfile()");
    } else {
        die("Couldn't execute git-cat-file");
    }
