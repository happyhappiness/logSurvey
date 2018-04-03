//          fn (IN): file name of squid.conf to use
// returns: number of entries, or negative to warn of errors
{
    // try to open file
    if ( debug ) fprintf( debug, "# trying to open %s\n", fn ? fn : "(null)" );
    std::ifstream cfgin(fn);
