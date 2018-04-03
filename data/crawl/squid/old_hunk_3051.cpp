        printf( "#\n# Currently active values for %s:\n# %s\n",
                ::programname, ::RCS_ID );
        printf( "# Debug level       : " );
        if ( ::debug ) printf( "%#6.4hx", ::debug );
        else printf( "production level" ); // printf omits 0x prefix for 0!
        printf( " + %s mode", ::no_fork ? "linear" : "parallel" );
        puts( ::verbose ? " + extra verbosity" : "" );
