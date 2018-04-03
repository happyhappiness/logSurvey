    return 0;
}

SBufList
ACLTimeData::dump()
{
    SBufList sl;
    ACLTimeData *t = this;

    while (t != NULL) {
        SBuf s;
        s.Printf("%c%c%c%c%c%c%c %02d:%02d-%02d:%02d",
                 t->weekbits & ACL_SUNDAY ? 'S' : '-',
                 t->weekbits & ACL_MONDAY ? 'M' : '-',
                 t->weekbits & ACL_TUESDAY ? 'T' : '-',
