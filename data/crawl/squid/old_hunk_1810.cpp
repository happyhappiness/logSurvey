}

int
main (int argc, char **argv)
{
    Mem::Init();
    /* enable for debugging to console */
    //    _db_init (NULL, NULL);
    //    Debug::Levels[64] = 9;
    testRangeParser ("bytes=0-3");
    testRangeParser ("bytes=-3");
    testRangeParser ("bytes=1-");
    testRangeParser ("bytes=0-3, 1-, -2");
    testRangeIter ();
    testRangeCanonization();
    return 0;
}