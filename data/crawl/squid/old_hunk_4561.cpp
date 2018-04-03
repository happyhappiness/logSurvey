    extern const HttpHeaderStat *dump_stat;     /* argh! */
    const int id = (int) val;
    const int valid_id = id >= 0 && id < SC_ENUM_END;
    const char *name = valid_id ? ScFieldsInfo[id].name.c_str() : "INVALID";

    if (count || valid_id)
        storeAppendPrintf(sentry, "%2d\t %-20s\t %5d\t %6.2f\n",
