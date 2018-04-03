    }
}

SBufList
ACLMaxUserIP::dump() const
{
    SBufList sl;
    if (!maximum)
        return sl;
    SBuf s;
    s.Printf("%lu", (unsigned long int) maximum);
    sl.push_back(s);
    return sl;
}
