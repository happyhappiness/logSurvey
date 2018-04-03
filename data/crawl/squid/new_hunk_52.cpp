Note::Value::~Value()
{
    aclDestroyAclList(&aclList);
    delete valueFormat;
}

Note::Value::Value(const char *aVal, const bool quoted, const char *descr, const Method m)
    : aclList(nullptr), valueFormat(nullptr), theValue(aVal), theMethod(m)
{
    if (quoted) {
        valueFormat = new Format::Format(descr ? descr : "Notes");
        if (!valueFormat->parse(theValue.c_str())) {
            delete valueFormat;
            SBuf exceptionMsg;
            exceptionMsg.Printf("failed to parse annotation value %s", theValue.c_str());
            throw TexcHere(exceptionMsg.c_str());
        }
    }
}
