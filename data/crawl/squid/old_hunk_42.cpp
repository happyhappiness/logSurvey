Note::Value::~Value()
{
    aclDestroyAclList(&aclList);
}

Note::Value::Value(const char *aVal, const bool quoted, const char *descr, const Method m)
    : aclList(nullptr), valueFormat(nullptr), theValue(aVal), theMethod(m)
{
    if (quoted) {
        valueFormat = new Format::Format(descr ? descr : "Notes");
        valueFormat->parse(theValue.c_str());
    }
}

