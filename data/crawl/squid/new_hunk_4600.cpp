    Vector<ICAPClass*>::iterator i = classes.begin();

    while (i != classes.end()) {
        storeAppendPrintf(entry, "%s %s\n", name, (*i)->key.c_str());
        ++i;
    }
};

void
ICAPConfig::parseICAPAccess(ConfigParser &parser)
{
    string aKey;
    ConfigParser::ParseString(aKey);
    ICAPClass *theClass = TheICAPConfig.findClass(aKey);

    if (theClass == NULL)
        fatalf("Did not find ICAP class '%s' referenced on line %d\n",
               aKey.c_str(), config_lineno);

    aclParseAccessLine(parser, &theClass->accessList);
};
