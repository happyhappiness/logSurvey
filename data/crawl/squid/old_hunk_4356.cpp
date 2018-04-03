    return Ctx_Descrs[ctx] ? Ctx_Descrs[ctx] : "<null>";
}

std::ostream &
Debug::getDebugOut() {
    assert (CurrentDebug == NULL);
    CurrentDebug = new std::ostringstream();
    // set default formatting flags
    CurrentDebug->setf(std::ios::fixed);
    CurrentDebug->precision(2);
    return *CurrentDebug;
}

void
Debug::finishDebug() {
    _db_print("%s\n", CurrentDebug->str().c_str());
    delete CurrentDebug;
    CurrentDebug = NULL;
}

std::ostringstream (*Debug::CurrentDebug)(NULL);