{
    ACLFilledChecklist *checklist = Filled(ch);
    HttpRequest *request = checklist->request;
    Http::HdrType headertype;

    if (NULL == request) {
        fatal ("requiresRequest SHOULD have been true for this ACL!!");
