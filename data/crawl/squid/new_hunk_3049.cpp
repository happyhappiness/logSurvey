// warning: this function is once-recursive, no deeper.
{
    struct dirent* entry;
    if ( debugFlag & 0x01 )
        fprintf( stderr, "# [%d] %s\n", (level ? 1 : 0), dirname );

    DIR* dir = opendir( dirname );
