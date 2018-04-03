void ICAPModXact::handle204NoContent()
{
    stopParsing();

    // We want to clone the HTTP message, but we do not want
    // to copy some non-HTTP state parts that HttpMsg kids carry in them.
