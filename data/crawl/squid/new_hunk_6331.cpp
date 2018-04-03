    fclose(debug_log);
    exit(0);
}

static void
force_shutdown(void *unused)
{
    fdDumpOpen();
    fatal_dump("Shutdown procedure failed");
}