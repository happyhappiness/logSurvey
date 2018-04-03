            // collect the garbase
            pid_t temp;
            int status;
            for ( size_t i=0; i < cdv.size(); ++i ) {
                while ( (temp=waitpid( (pid_t)-1, &status, 0 )) == -1 )
                    if ( errno == EINTR ) continue;
                if ( ::debug ) printf( "collected child %d\n", (int) temp );
