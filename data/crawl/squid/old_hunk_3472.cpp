    fatal("Not implemented");
}

CBDATA_TYPE(statefulhelper);

statefulhelper *
helperStatefulCreate(const char *name)
{
    statefulhelper *hlp;
    CBDATA_INIT_TYPE(statefulhelper);
    hlp = cbdataAlloc(statefulhelper);
    hlp->id_name = name;
    return hlp;
}

/*
 * DO NOT MODIFY:
