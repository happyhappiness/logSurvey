
// ----------------------------------------------------------------------

class REList
{
public:
    REList( const char* what, bool doCase ) :
        next(nullptr),
        data(xstrdup(what)),
        rexp(data, std::regex::extended | std::regex::nosubs |
             (doCase ? std::regex_constants::syntax_option_type() : std::regex::icase) )
    {}

    ~REList() {
        if (next) delete next;
        xfree(data);
    }

    bool match(const char *check) const {return std::regex_match(check, rexp);}

    REList*     next;
    const char* data;
private:
    std::regex  rexp;
};

// ----------------------------------------------------------------------

char*
