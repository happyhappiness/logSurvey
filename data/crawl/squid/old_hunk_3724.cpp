
    acl_checklist = NULL;

    debugs(93, 5, HERE << "AccessCheck constructed for " << methodStr(method) << " " << vectPointStr(point));
}

Adaptation::AccessCheck::~AccessCheck()
{
    HTTPMSGUNLOCK(req);
    HTTPMSGUNLOCK(rep);
    if (callback_data)
