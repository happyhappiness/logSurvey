    const Vector<ServiceConfig*> &configs = serviceConfigs;
    debugs(93,3, "Found " << configs.size() << " service configs.");
    for (VISCI i = configs.begin(); i != configs.end(); ++i) {
        ServicePointer s = createService(**i);
        if (s != NULL)
            AllServices().push_back(s);
