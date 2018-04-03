            die ( "Invalid type '$type' (expected 'blob')" )
        }

        my $size = safe_pipe_capture('git', 'cat-file', '-s', $name);
        chomp $size;

        $log->debug("open_blob_or_die($name) size=$size, type=$type");
