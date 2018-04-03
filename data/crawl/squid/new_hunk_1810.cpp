}

int
main(int argc, char **argv)
{
    try{
        Mem::Init();
        /* enable for debugging to console */
        //    _db_init (NULL, NULL);
        //    Debug::Levels[64] = 9;
        testRangeParser("bytes=0-3");
        testRangeParser("bytes=-3");
        testRangeParser("bytes=1-");
        testRangeParser("bytes=0-3, 1-, -2");
        testRangeIter();
        testRangeCanonization();
    } catch (const std::exception &e) {
        printf("Error: dying from an unhandled exception: %s\n", e.what());
        return 1;
    } catch (...) {
        printf("Error: dying from an unhandled exception.\n");
        return 1;
    }
    return 0;
}