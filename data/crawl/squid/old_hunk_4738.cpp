    debugs(93, 4, typeName << "::" << inCall << " caught an exception: " <<
           e.message << ' ' << status());

    if (!done())
        mustStop("exception");
}

void ICAPXaction::callEnd()
