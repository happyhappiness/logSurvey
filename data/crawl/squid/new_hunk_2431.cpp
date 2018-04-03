    name.append(id);
    return name;
}

#else // HAVE_SHM

#include <map>

typedef std::map<String, Ipc::Mem::Segment *> SegmentMap;
static SegmentMap Segments;

Ipc::Mem::Segment::Segment(const char *const id):
    theName(id), theMem(NULL), theSize(0), theReserved(0), doUnlink(false)
{
}

Ipc::Mem::Segment::~Segment()
{
    if (doUnlink) {
        delete [] static_cast<char *>(theMem);
        debugs(54, 3, HERE << "deleted " << theName << " segment");
    }
}

bool
Ipc::Mem::Segment::Enabled()
{
    return !InDaemonMode() || (!UsingSmp() && IamWorkerProcess());
}

void
Ipc::Mem::Segment::create(const off_t aSize)
{
    assert(aSize > 0);
    assert(!theMem);
    checkSupport("Fake segment creation");

    const bool inserted = Segments.insert(std::make_pair(theName, this)).second;
    if (!inserted)
        fatalf("Duplicate fake segment creation: %s", theName.termedBuf());

    theMem = new char[aSize];
    theSize = aSize;
    doUnlink = true;

    debugs(54, 3, HERE << "created " << theName << " fake segment: " << theSize);
}

void
Ipc::Mem::Segment::open()
{
    assert(!theMem);
    checkSupport("Fake segment open");

    const SegmentMap::const_iterator i = Segments.find(theName);
    if (i == Segments.end())
        fatalf("Fake segment not found: %s", theName.termedBuf());

    const Segment &segment = *i->second;
    theMem = segment.theMem;
    theSize = segment.theSize;

    debugs(54, 3, HERE << "opened " << theName << " fake segment: " << theSize);
}

void
Ipc::Mem::Segment::checkSupport(const char *const context)
{
    if (!Enabled()) {
        debugs(54, 5, HERE << "True shared memory segments are not supported. "
               "Cannot fake shared segments in SMP config.");
        fatalf("%s failed", context);
    }
}

#endif // HAVE_SHM
