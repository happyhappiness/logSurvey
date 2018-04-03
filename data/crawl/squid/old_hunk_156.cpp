    Security::SessionPointer tmp;
    if (prepareSocket() && initializeTls(tmp))
        negotiateSsl();
}

void