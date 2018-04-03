{
    Must(currentContentType == ContentType::ctAlert);
    const Alert alert(tkMessages);
    debugs(83, 3, "level " << alert.level << " description " << alert.description);
    // we are currently ignoring Alert Protocol messages
}

