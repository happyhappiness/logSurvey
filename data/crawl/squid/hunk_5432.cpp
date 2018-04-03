  *  along with this program; if not, write to the Free Software
  *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
  *
+ *
+ * Copyright (c) 2003, Robert Collins <robertc@squid-cache.org>
  */
 
 #include "config.h"
 
 #if DELAY_POOLS
 #include "squid.h"
+#include "DelaySpec.h"
+#include "DelayPools.h"
 #include "StoreClient.h"
 #include "Store.h"
 #include "MemObject.h"
 #include "client_side_request.h"
-#include "ACLChecklist.h"
+#include "Config.h"
+#include "DelayId.h"
+#include "Array.h"
+#include "SquidString.h"
+#include "CommonPool.h"
+#include "CompositePoolNode.h"
+#include "DelayPool.h"
+#include "DelayVector.h"
+#include "NullDelayId.h"
+#include "DelayBucket.h"
+#include "DelayUser.h"
+
+/*
+ * class 1		Everything is limited by a single aggregate
+ * 			bucket.
+ * 			
+ * class 2		Everything is limited by a single aggregate
+ * 			bucket as well as an "individual" bucket chosen
+ * 			from bits 25 through 32 of the IP address.
+ * 			
+ * class 3		Everything is limited by a single aggregate
+ * 			bucket as well as a "network" bucket chosen
+ * 			from bits 17 through 24 of the IP address and a
+ * 			"individual" bucket chosen from bits 17 through
+ * 			32 of the IP address.
+ */
 
-struct _class1DelayPool {
-    int delay_class;
-    int aggregate;
+long DelayPools::MemoryUsed = 0;
+
+class Aggregate : public CompositePoolNode {
+  public:
+    typedef RefCount<Aggregate> Pointer;
+    void *operator new(size_t);
+    void operator delete (void *);
+    virtual void deleteSelf() const;
+    Aggregate();
+    ~Aggregate();
+    virtual DelaySpec *rate() {return &spec;}
+    virtual DelaySpec const *rate() const {return &spec;}
+    virtual void stats(StoreEntry * sentry);
+    virtual void dump(StoreEntry *entry) const;
+    virtual void update(int incr);
+    virtual void parse();
+    virtual DelayIdComposite::Pointer id(struct in_addr &src_addr, AuthUserRequest *);
+  private:
+    class AggregateId:public DelayIdComposite {
+      public:
+	void *operator new(size_t);
+	void operator delete (void *);
+	virtual void deleteSelf() const;
+	AggregateId (Aggregate::Pointer);
+	virtual int bytesWanted (int min, int max) const;
+	virtual void bytesIn(int qty);
+      private:
+	Aggregate::Pointer theAggregate;
+    };
+    DelayBucket theBucket;
+    DelaySpec spec;
 };
 
+template <class Key, class Value>
+class VectorMap {
+  public:
+    VectorMap();
+    unsigned int size() const;
+    unsigned char findKeyIndex (Key const key) const;
+    bool indexUsed (unsigned char const index) const;
+    unsigned int insert (Key const key);
+    
 #define IND_MAP_SZ 256
+    Key key_map[IND_MAP_SZ];
+    Value values[IND_MAP_SZ];
+  private:
+    unsigned int nextMapPosition;
+};
 
-struct _class2DelayPool {
-    int delay_class;
-    int aggregate;
-    /* OK: -1 is terminator.  individual[255] is always host 255. */
-    /* 255 entries + 1 terminator byte */
-    unsigned char individual_map[IND_MAP_SZ];
-    unsigned char individual_255_used;
-    /* 256 entries */
-    int individual[IND_MAP_SZ];
+class VectorPool : public CompositePoolNode {
+  public:
+    typedef RefCount<VectorPool> Pointer;
+    virtual void dump(StoreEntry *entry) const;
+    virtual void parse();
+    virtual void update(int incr);
+    virtual void stats(StoreEntry * sentry);
+    virtual DelayIdComposite::Pointer id(struct in_addr &src_addr, AuthUserRequest *);
+    VectorMap<unsigned char, DelayBucket> buckets;
+    VectorPool();
+    ~VectorPool();
+  protected:
+    bool keyAllocated (unsigned char const key) const;
+    virtual DelaySpec *rate() {return &spec;}
+    virtual DelaySpec const *rate() const {return &spec;}
+    virtual char const *label() const = 0;
+    virtual unsigned int const makeKey (struct in_addr &src_addr) const = 0;
+
+    DelaySpec spec;
+    class Id:public DelayIdComposite {
+      public:
+	void *operator new(size_t);
+	void operator delete (void *);
+	virtual void deleteSelf() const;
+	Id (VectorPool::Pointer, int);
+	virtual int bytesWanted (int min, int max) const;
+	virtual void bytesIn(int qty);
+      private:
+	VectorPool::Pointer theVector;
+	int theIndex;
+    };
 };
 
-#define NET_MAP_SZ 256
-#define C3_IND_SZ (NET_MAP_SZ*IND_MAP_SZ)
-
-struct _class3DelayPool {
-    int delay_class;
-    int aggregate;
-    /* OK: -1 is terminator.  network[255] is always host 255. */
-    /* 255 entries + 1 terminator byte */
-    unsigned char network_map[NET_MAP_SZ];
-    unsigned char network_255_used;
-    /* 256 entries */
-    int network[256];
-    /* 256 sets of (255 entries + 1 terminator byte) */
-    unsigned char individual_map[NET_MAP_SZ][IND_MAP_SZ];
-    /* Pack this into one bit per net */
-    unsigned char individual_255_used[32];
-    /* largest entry = (255<<8)+255 = 65535 */
-    int individual[C3_IND_SZ];
+class IndividualPool : public VectorPool {
+  public:
+    void *operator new(size_t);
+    void operator delete (void *);
+    virtual void deleteSelf() const;
+  protected:
+    virtual char const *label() const {return "Individual";}
+    virtual unsigned int const makeKey (struct in_addr &src_addr) const;
+
 };
 
-typedef struct _class1DelayPool class1DelayPool;
-typedef struct _class2DelayPool class2DelayPool;
-typedef struct _class3DelayPool class3DelayPool;
+class ClassCNetPool : public VectorPool {
+  public:
+    void *operator new(size_t);
+    void operator delete (void *);
+    virtual void deleteSelf() const;
+  protected:
+    virtual char const *label() const {return "Network";}
+    virtual unsigned int const makeKey (struct in_addr &src_addr) const;
+};
 
-union _delayPool {
-    class1DelayPool *class1;
-    class2DelayPool *class2;
-    class3DelayPool *class3;
+/* don't use remote storage for these */
+class ClassCBucket {
+  public:
+    bool individualUsed (unsigned int index)const;
+    unsigned char findHostMapPosition (unsigned char const host) const;
+    bool individualAllocated (unsigned char host) const;
+    unsigned char hostPosition (DelaySpec &rate, unsigned char const host);
+    void initHostIndex (DelaySpec &rate, unsigned char index, unsigned char host);
+    void update (DelaySpec const &, int incr);
+    void stats(StoreEntry *)const;
+    
+    DelayBucket net;
+    VectorMap<unsigned char, DelayBucket> individuals;
 };
 
-typedef union _delayPool delayPool;
-
-static delayPool *delay_data = NULL;
-static fd_set delay_no_delay;
-static time_t delay_pools_last_update = 0;
-static hash_table *delay_id_ptr_hash = NULL;
-static long memory_used = 0;
-
-static OBJH delayPoolStats;
-
-static unsigned int
-delayIdPtrHash(const void *key, unsigned int n)
-{
-    /* Hashes actual POINTER VALUE.
-     * Assumes <= 256 hash buckets & even hash size.
-     * Assumes the most variation in pointers to inside
-     * medium size objects occurs in the 2nd and 3rd
-     * least significant bytes.
-     */
-    const char *ptr = (char *) &key;
-#if SIZEOF_VOID_P == 4
-    return (ptr[1] ^ ptr[2]) & (n - 1);
-#elif SIZEOF_VOID_P == 8
-#if WORDS_BIGENDIAN
-    return (ptr[5] ^ ptr[6]) & (n - 1);
-#else
-    return (ptr[1] ^ ptr[2]) & (n - 1);
-#endif
-#else
-#error What kind of a sick architecture are you on anyway?
-#endif
+class ClassCHostPool : public CompositePoolNode {
+  public:
+    typedef RefCount<ClassCHostPool> Pointer;
+    virtual void dump(StoreEntry *entry) const;
+    virtual void parse();
+    virtual void update(int incr);
+    virtual void stats(StoreEntry * sentry);
+    virtual DelayIdComposite::Pointer id(struct in_addr &src_addr, AuthUserRequest *);
+    ClassCHostPool();
+    ~ClassCHostPool();
+  protected:
+    bool keyAllocated (unsigned char const key) const;
+    virtual DelaySpec *rate() {return &spec;}
+    virtual DelaySpec const *rate() const {return &spec;}
+    virtual char const *label() const {return "Individual";}
+    virtual unsigned int const makeKey (struct in_addr &src_addr) const;
+    unsigned char const makeHostKey (struct in_addr &src_addr) const;
+
+    DelaySpec spec;
+    VectorMap<unsigned char, ClassCBucket> buckets;
+    class Id:public DelayIdComposite {
+      public:
+	void *operator new(size_t);
+	void operator delete (void *);
+	virtual void deleteSelf() const;
+	Id (ClassCHostPool::Pointer, unsigned char, unsigned char);
+	virtual int bytesWanted (int min, int max) const;
+	virtual void bytesIn(int qty);
+      private:
+	ClassCHostPool::Pointer theClassCHost;
+	unsigned char theNet;
+	unsigned char theHost;
+    };
+};
+
+
+void *
+CommonPool::operator new(size_t size)
+{
+    DelayPools::MemoryUsed += sizeof (CommonPool);
+    return ::operator new (size);
 }
 
-static int
-delayIdPtrHashCmp(const void *a, const void *b)
+void
+CommonPool::operator delete (void *address)
 {
-    /*
-     * Compare POINTER VALUE.
-     * Note, we can't subtract void pointers, but we don't need
-     * to anyway.  All we need is a test for equality.
-     */
-    return a != b;
+    DelayPools::MemoryUsed -= sizeof (CommonPool);
+    ::operator delete (address);
 }
 
 void
-delayPoolsInit(void)
+CommonPool::deleteSelf() const
+{
+    delete this;
+}
+
+CommonPool *
+CommonPool::Factory(unsigned char _class, CompositePoolNode::Pointer& compositeCopy)
+{
+    CommonPool *result = new CommonPool;
+    switch (_class) {
+      case 0:
+      break;
+      case 1:
+	compositeCopy = new Aggregate;
+	result->typeLabel = "1";
+	break;
+      case 2:
+	result->typeLabel = "2";
+	  {
+	    DelayVector::Pointer temp = new DelayVector;
+	    compositeCopy = temp.getRaw();
+	    temp->push_back (new Aggregate);
+	    temp->push_back(new IndividualPool);
+	  }
+	break;
+      case 3:
+	result->typeLabel = "3";
+	  {
+	    DelayVector::Pointer temp = new DelayVector;
+	    compositeCopy = temp.getRaw();
+	    temp->push_back (new Aggregate);
+	    temp->push_back (new ClassCNetPool);
+	    temp->push_back (new ClassCHostPool);
+	  }
+	break;
+      case 4:
+	result->typeLabel = "4";
+	  {
+	    DelayVector::Pointer temp = new DelayVector;
+	    compositeCopy = temp.getRaw();
+	    temp->push_back (new Aggregate);
+	    temp->push_back (new ClassCNetPool);
+	    temp->push_back (new ClassCHostPool);
+	    temp->push_back (new DelayUser);
+	  }
+	break;
+      default:
+        fatal ("unknown delay pool class");
+	return NULL;
+    };
+
+    return result;
+}
+
+CommonPool::CommonPool() 
 {
-    delay_pools_last_update = getCurrentTime();
-    FD_ZERO(&delay_no_delay);
-    cachemgrRegister("delay", "Delay Pool Levels", delayPoolStats, 0, 1);
 }
 
 void
-delayInitDelayData(unsigned short pools)
+ClassCBucket::update (DelaySpec const &rate, int incr)
 {
-    if (!pools)
-	return;
-    delay_data = (delayPool *)xcalloc(pools, sizeof(*delay_data));
-    memory_used += pools * sizeof(*delay_data);
-    eventAdd("delayPoolsUpdate", delayPoolsUpdate, NULL, 1.0, 1);
-    delay_id_ptr_hash = hash_create(delayIdPtrHashCmp, 256, delayIdPtrHash);
+    /* If we aren't active, don't try to update us ! */
+    assert (rate.restore_bps != -1);
+
+    for (unsigned char j = 0; j < individuals.size(); ++j)
+	individuals.values[j].update (rate, incr);
+}
+
+void
+ClassCBucket::stats(StoreEntry *sentry)const
+{
+    for (unsigned int j = 0; j < individuals.size(); ++j) {
+	assert (individualUsed (j));
+	storeAppendPrintf(sentry, " %d:",individuals.key_map[j]);
+	individuals.values[j].stats (sentry);
+    }
+}
+
+unsigned char
+ClassCBucket::findHostMapPosition (unsigned char const host) const
+{
+    return individuals.findKeyIndex(host);
+}
+
+bool
+ClassCBucket::individualUsed (unsigned int index)const
+{
+    return individuals.indexUsed(index);
+}
+
+bool
+ClassCBucket::individualAllocated (unsigned char host) const
+{
+    return individualUsed(findHostMapPosition (host));
 }
 
-static void
-delayIdZero(void *hlink)
+unsigned char
+ClassCBucket::hostPosition (DelaySpec &rate, unsigned char const host)
 {
-    hash_link *h = (hash_link *)hlink;
-    delay_id *id = (delay_id *) h->key;
-    *id = 0;
-    xfree(h);
-    memory_used -= sizeof(*h);
+    if (individualAllocated (host))
+	return findHostMapPosition(host);
+
+    assert (!individualUsed (findHostMapPosition(host)));
+    unsigned char result = findHostMapPosition(host);
+    initHostIndex (rate, result, host);
+    return result;
 }
 
 void
-delayFreeDelayData(unsigned short pools)
+ClassCBucket::initHostIndex (DelaySpec &rate, unsigned char index, unsigned char host)
 {
-    safe_free(delay_data);
-    memory_used -= pools * sizeof(*delay_data);
-    if (!delay_id_ptr_hash)
-	return;
-    hashFreeItems(delay_id_ptr_hash, delayIdZero);
-    hashFreeMemory(delay_id_ptr_hash);
-    delay_id_ptr_hash = NULL;
+    assert (!individualUsed(index));
+    
+    unsigned char const newIndex = individuals.insert (host);
+
+    /* give the bucket a default value */
+    individuals.values[newIndex].init (rate);
+}
+
+void *
+CompositePoolNode::operator new(size_t size)
+{
+    DelayPools::MemoryUsed += sizeof (CompositePoolNode);
+    return ::operator new (size);
 }
 
 void
-delayRegisterDelayIdPtr(delay_id * loc)
+CompositePoolNode::operator delete (void *address)
 {
-    hash_link *lnk;
-    if (!delay_id_ptr_hash)
-	return;
-    if (*loc == 0)
-	return;
-    lnk = (hash_link *)xmalloc(sizeof(hash_link));
-    memory_used += sizeof(hash_link);
-    lnk->key = (char *) loc;
-    hash_join(delay_id_ptr_hash, lnk);
+    DelayPools::MemoryUsed -= sizeof (CompositePoolNode);
+    ::operator delete (address);
 }
 
 void
-delayUnregisterDelayIdPtr(delay_id * loc)
+CompositePoolNode::deleteSelf() const
 {
-    hash_link *lnk;
-    if (!delay_id_ptr_hash)
-	return;
-    /*
-     * If we went through a reconfigure, then all the delay_id's
-     * got set to zero, and they were removed from our hash
-     * table.
-     */
-    if (*loc == 0)
-	return;
-    lnk = (hash_link *)hash_lookup(delay_id_ptr_hash, loc);
-    assert(lnk);
-    hash_remove_link(delay_id_ptr_hash, lnk);
-    xxfree(lnk);
-    memory_used -= sizeof(*lnk);
+    delete this;
+}
+
+void *
+Aggregate::operator new(size_t size)
+{
+    DelayPools::MemoryUsed += sizeof (Aggregate);
+    return ::operator new (size);
 }
 
 void
-delayCreateDelayPool(unsigned short pool, u_char delay_class)
+Aggregate::operator delete (void *address)
 {
-    switch (delay_class) {
-    case 1:
-	delay_data[pool].class1 = (class1DelayPool *)xmalloc(sizeof(class1DelayPool));
-	delay_data[pool].class1->delay_class = 1;
-	memory_used += sizeof(class1DelayPool);
-	break;
-    case 2:
-	delay_data[pool].class2 = (class2DelayPool *)xmalloc(sizeof(class2DelayPool));
-	delay_data[pool].class1->delay_class = 2;
-	memory_used += sizeof(class2DelayPool);
-	break;
-    case 3:
-	delay_data[pool].class3 = (class3DelayPool *)xmalloc(sizeof(class3DelayPool));
-	delay_data[pool].class1->delay_class = 3;
-	memory_used += sizeof(class3DelayPool);
-	break;
-    default:
-	assert(0);
-    }
+    DelayPools::MemoryUsed -= sizeof (Aggregate);
+    ::operator delete (address);
 }
 
 void
-delayInitDelayPool(unsigned short pool, u_char delay_class, delaySpecSet * rates)
+Aggregate::deleteSelf() const
 {
-    /* delaySetSpec may be pointer to partial structure so MUST pass by
-     * reference.
-     */
-    switch (delay_class) {
-    case 1:
-	delay_data[pool].class1->aggregate = (int) (((double) rates->aggregate.max_bytes *
-		Config.Delay.initial) / 100);
-	break;
-    case 2:
-	delay_data[pool].class2->aggregate = (int) (((double) rates->aggregate.max_bytes *
-		Config.Delay.initial) / 100);
-	delay_data[pool].class2->individual_map[0] = 255;
-	delay_data[pool].class2->individual_255_used = 0;
-	break;
-    case 3:
-	delay_data[pool].class3->aggregate = (int) (((double) rates->aggregate.max_bytes *
-		Config.Delay.initial) / 100);
-	delay_data[pool].class3->network_map[0] = 255;
-	delay_data[pool].class3->network_255_used = 0;
-	memset(&delay_data[pool].class3->individual_255_used, '\0',
-	    sizeof(delay_data[pool].class3->individual_255_used));
-	break;
-    default:
-	assert(0);
-    }
+    delete this;
+}
+
+Aggregate::Aggregate()
+{
+    theBucket.init (*rate());
+    DelayPools::registerForUpdates (this);
+}
+
+Aggregate::~Aggregate()
+{
+    DelayPools::deregisterForUpdates (this);
 }
 
 void
-delayFreeDelayPool(unsigned short pool)
+Aggregate::stats(StoreEntry * sentry)
 {
-    /* this is a union - and all free() cares about is the pointer location */
-    switch (delay_data[pool].class1->delay_class) {
-    case 1:
-	memory_used -= sizeof(class1DelayPool);
-	break;
-    case 2:
-	memory_used -= sizeof(class2DelayPool);
-	break;
-    case 3:
-	memory_used -= sizeof(class3DelayPool);
-	break;
-    default:
-	debug(77, 1) ("delayFreeDelayPool: bad class %d\n",
-	    delay_data[pool].class1->delay_class);
-    }
-    safe_free(delay_data[pool].class1);
+    rate()->stats (sentry, "Aggregate");
+    if (rate()->restore_bps == -1)
+	return;
+    storeAppendPrintf(sentry, "\t\tCurrent: ");
+    theBucket.stats(sentry);
+    storeAppendPrintf(sentry, "\n\n");
 }
 
 void
-delaySetNoDelay(int fd)
+Aggregate::dump(StoreEntry *entry) const
 {
-    FD_SET(fd, &delay_no_delay);
+    rate()->dump (entry);
 }
 
 void
-delayClearNoDelay(int fd)
+Aggregate::update(int incr)
 {
-    FD_CLR(fd, &delay_no_delay);
+    theBucket.update(*rate(), incr);
 }
 
-int
-delayIsNoDelay(int fd)
+void
+Aggregate::parse()
 {
-    return FD_ISSET(fd, &delay_no_delay);
+    rate()->parse();
 }
 
-static delay_id
-delayId(unsigned short pool, unsigned short position)
+DelayIdComposite::Pointer
+Aggregate::id(struct in_addr &src_addr, AuthUserRequest *)
 {
-    return (delay_id)((pool << 16) | position);
+    if (rate()->restore_bps != -1)
+	return new AggregateId (this);
+    else
+	return new NullDelayId;
 }
 
-delay_id
-delayClient(clientHttpRequest * http)
+void *
+Aggregate::AggregateId::operator new(size_t size)
 {
-    request_t *r;
-    int i;
-    int j;
-    unsigned int host;
-    unsigned short pool, position;
-    unsigned char delay_class, net;
-    assert(http);
-    r = http->request;
-
-    ACLChecklist ch;
-    ch.src_addr = r->client_addr;
-    ch.my_addr = r->my_addr;
-    ch.my_port = r->my_port;
-    ch.conn = http->conn;
-    ch.request = r;
-    if (r->client_addr.s_addr == INADDR_BROADCAST) {
-	debug(77, 2) ("delayClient: WARNING: Called with 'allones' address, ignoring\n");
-	return delayId(0, 0);
-    }
-    for (pool = 0; pool < Config.Delay.pools; pool++) {
-	if (aclCheckFast(Config.Delay.access[pool], &ch))
-	    break;
-    }
-    if (pool == Config.Delay.pools)
-	return delayId(0, 0);
-    delay_class = Config.Delay.delay_class[pool];
-    if (delay_class == 0)
-	return delayId(0, 0);
-    if (delay_class == 1)
-	return delayId(pool + 1, 0);
-    if (delay_class == 2) {
-	host = ntohl(ch.src_addr.s_addr) & 0xff;
-	if (host == 255) {
-	    if (!delay_data[pool].class2->individual_255_used) {
-		delay_data[pool].class2->individual_255_used = 1;
-		delay_data[pool].class2->individual[IND_MAP_SZ - 1] =
-		    (int) (((double) Config.Delay.rates[pool]->individual.max_bytes *
-			Config.Delay.initial) / 100);
-	    }
-	    return delayId(pool + 1, 255);
-	}
-	for (i = 0; i < IND_MAP_SZ; i++) {
-	    if (delay_data[pool].class2->individual_map[i] == host)
-		break;
-	    if (delay_data[pool].class2->individual_map[i] == 255) {
-		delay_data[pool].class2->individual_map[i] = host;
-		assert(i < (IND_MAP_SZ - 1));
-		delay_data[pool].class2->individual_map[i + 1] = 255;
-		delay_data[pool].class2->individual[i] =
-		    (int) (((double) Config.Delay.rates[pool]->individual.max_bytes *
-			Config.Delay.initial) / 100);
-		break;
-	    }
-	}
-	return delayId(pool + 1, i);
-    }
-    /* class == 3 */
-    host = ntohl(ch.src_addr.s_addr) & 0xffff;
-    net = host >> 8;
-    host &= 0xff;
-    if (net == 255) {
-	i = 255;
-	if (!delay_data[pool].class3->network_255_used) {
-	    delay_data[pool].class3->network_255_used = 1;
-	    delay_data[pool].class3->network[255] =
-		(int) (((double) Config.Delay.rates[pool]->network.max_bytes *
-		    Config.Delay.initial) / 100);
-	}
-    } else {
-	for (i = 0; i < NET_MAP_SZ; i++) {
-	    if (delay_data[pool].class3->network_map[i] == net)
-		break;
-	    if (delay_data[pool].class3->network_map[i] == 255) {
-		delay_data[pool].class3->network_map[i] = net;
-		delay_data[pool].class3->individual_map[i][0] = 255;
-		assert(i < (NET_MAP_SZ - 1));
-		delay_data[pool].class3->network_map[i + 1] = 255;
-		delay_data[pool].class3->network[i] =
-		    (int) (((double) Config.Delay.rates[pool]->network.max_bytes *
-			Config.Delay.initial) / 100);
-		break;
-	    }
-	}
-    }
-    position = i << 8;
-    if (host == 255) {
-	position |= 255;
-	if (!(delay_data[pool].class3->individual_255_used[i / 8] & (1 << (i % 8)))) {
-	    delay_data[pool].class3->individual_255_used[i / 8] |= (1 << (i % 8));
-	    assert(position < C3_IND_SZ);
-	    delay_data[pool].class3->individual[position] =
-		(int) (((double) Config.Delay.rates[pool]->individual.max_bytes *
-		    Config.Delay.initial) / 100);
-	}
-	return delayId(pool + 1, position);
-    }
-    assert(i < NET_MAP_SZ);
-    for (j = 0; j < IND_MAP_SZ; j++) {
-	if (delay_data[pool].class3->individual_map[i][j] == host) {
-	    position |= j;
-	    break;
-	}
-	if (delay_data[pool].class3->individual_map[i][j] == 255) {
-	    delay_data[pool].class3->individual_map[i][j] = host;
-	    assert(j < (IND_MAP_SZ - 1));
-	    delay_data[pool].class3->individual_map[i][j + 1] = 255;
-	    position |= j;
-	    assert(position < C3_IND_SZ);
-	    delay_data[pool].class3->individual[position] =
-		(int) (((double) Config.Delay.rates[pool]->individual.max_bytes *
-		    Config.Delay.initial) / 100);
-	    break;
-	}
-    }
-    return delayId(pool + 1, position);
-}
-
-static void
-delayUpdateClass1(class1DelayPool * class1, delaySpecSet * rates, int incr)
-{
-    /* delaySetSpec may be pointer to partial structure so MUST pass by
-     * reference.
-     */
-    if (rates->aggregate.restore_bps != -1 &&
-	(class1->aggregate += rates->aggregate.restore_bps * incr) >
-	rates->aggregate.max_bytes)
-	class1->aggregate = rates->aggregate.max_bytes;
-}
-
-static void
-delayUpdateClass2(class2DelayPool * class2, delaySpecSet * rates, int incr)
-{
-    int restore_bytes;
-    unsigned char i;		/* depends on 255 + 1 = 0 */
-    /* delaySetSpec may be pointer to partial structure so MUST pass by
-     * reference.
-     */
-    if (rates->aggregate.restore_bps != -1 &&
-	(class2->aggregate += rates->aggregate.restore_bps * incr) >
-	rates->aggregate.max_bytes)
-	class2->aggregate = rates->aggregate.max_bytes;
-    if ((restore_bytes = rates->individual.restore_bps) == -1)
-	return;
-    restore_bytes *= incr;
-    /* i < IND_MAP_SZ is enforced by data type (unsigned chars are all < 256).
-     * this loop starts at 0 or 255 and ends at 254 unless terminated earlier
-     * by finding the end of the map.  note as above that 255 + 1 = 0.
-     */
-    for (i = (class2->individual_255_used ? 255 : 0);; i++) {
-	if (i != 255 && class2->individual_map[i] == 255)
-	    return;
-	if (class2->individual[i] != rates->individual.max_bytes &&
-	    (class2->individual[i] += restore_bytes) > rates->individual.max_bytes)
-	    class2->individual[i] = rates->individual.max_bytes;
-	if (i == 254)
-	    return;
-    }
+    DelayPools::MemoryUsed += sizeof (AggregateId);
+    return ::operator new (size);
 }
 
-static void
-delayUpdateClass3(class3DelayPool * class3, delaySpecSet * rates, int incr)
-{
-    int individual_restore_bytes, network_restore_bytes;
-    int mpos;
-    unsigned char i, j;		/* depends on 255 + 1 = 0 */
-    /* delaySetSpec may be pointer to partial structure so MUST pass by
-     * reference.
-     */
-    if (rates->aggregate.restore_bps != -1 &&
-	(class3->aggregate += rates->aggregate.restore_bps * incr) >
-	rates->aggregate.max_bytes)
-	class3->aggregate = rates->aggregate.max_bytes;
-    /* the following line deliberately uses &, not &&, in an if statement
-     * to avoid conditional execution
-     */
-    if (((network_restore_bytes = rates->network.restore_bps) == -1) &
-	((individual_restore_bytes = rates->individual.restore_bps) == -1))
-	return;
-    individual_restore_bytes *= incr;
-    network_restore_bytes *= incr;
-    /* i < NET_MAP_SZ is enforced by data type (unsigned chars are all < 256).
-     * this loop starts at 0 or 255 and ends at 254 unless terminated earlier
-     * by finding the end of the map.  note as above that 255 + 1 = 0.
-     */
-    for (i = (class3->network_255_used ? 0 : 255);; ++i) {
-	if (i != 255 && class3->network_map[i] == 255)
-	    return;
-	if (individual_restore_bytes != -incr) {
-	    mpos = i << 8;
-	    /* this is not as simple as the outer loop as mpos doesn't wrap like
-	     * i and j do.  so the net 255 increment is done as a separate special
-	     * case.  the alternative would be overlapping a union of two chars on
-	     * top of a 16-bit unsigned int, but that wouldn't really be worth the
-	     * effort.
-	     */
-	    for (j = 0;; ++j, ++mpos) {
-		if (class3->individual_map[i][j] == 255)
-		    break;
-		assert(mpos < C3_IND_SZ);
-		if (class3->individual[mpos] != rates->individual.max_bytes &&
-		    (class3->individual[mpos] += individual_restore_bytes) >
-		    rates->individual.max_bytes)
-		    class3->individual[mpos] = rates->individual.max_bytes;
-		if (j == 254)
-		    break;
-	    }
-	    if (class3->individual_255_used[i / 8] & (1 << (i % 8))) {
-		mpos |= 255;	/* this will set mpos to network 255 */
-		assert(mpos < C3_IND_SZ);
-		if (class3->individual[mpos] != rates->individual.max_bytes &&
-		    (class3->individual[mpos] += individual_restore_bytes) >
-		    rates->individual.max_bytes)
-		    class3->individual[mpos] = rates->individual.max_bytes;
-	    }
-	}
-	if (network_restore_bytes != -incr &&
-	    class3->network[i] != rates->network.max_bytes &&
-	    (class3->network[i] += network_restore_bytes) >
-	    rates->network.max_bytes)
-	    class3->network[i] = rates->network.max_bytes;
-	if (i == 254)
-	    return;
-    }
+void
+Aggregate::AggregateId::operator delete (void *address)
+{
+    DelayPools::MemoryUsed -= sizeof (AggregateId);
+    ::operator delete (address);
 }
 
 void
-delayPoolsUpdate(void *unused)
+Aggregate::AggregateId::deleteSelf() const
+{
+    delete this;
+}
+
+Aggregate::AggregateId::AggregateId(Aggregate::Pointer anAggregate) : theAggregate(anAggregate)
 {
-    int incr = squid_curtime - delay_pools_last_update;
-    unsigned short i;
-    unsigned char delay_class;
-    if (!Config.Delay.pools)
-	return;
-    eventAdd("delayPoolsUpdate", delayPoolsUpdate, NULL, 1.0, 1);
-    if (incr < 1)
-	return;
-    delay_pools_last_update = squid_curtime;
-    for (i = 0; i < Config.Delay.pools; i++) {
-	delay_class = Config.Delay.delay_class[i];
-	if (!delay_class)
-	    continue;
-	switch (delay_class) {
-	case 1:
-	    delayUpdateClass1(delay_data[i].class1, Config.Delay.rates[i], incr);
-	    break;
-	case 2:
-	    delayUpdateClass2(delay_data[i].class2, Config.Delay.rates[i], incr);
-	    break;
-	case 3:
-	    delayUpdateClass3(delay_data[i].class3, Config.Delay.rates[i], incr);
-	    break;
-	default:
-	    assert(0);
-	}
-    }
 }
 
-/*
- * this returns the number of bytes the client is permitted. it does not take
- * into account bytes already buffered - that is up to the caller.
- */
 int
-delayBytesWanted(delay_id d, int min, int max)
+Aggregate::AggregateId::bytesWanted (int min, int max) const
 {
-    unsigned short position = d & 0xFFFF;
-    unsigned short pool = (d >> 16) - 1;
-    unsigned char delay_class = (pool == 0xFFFF) ? 0 : Config.Delay.delay_class[pool];
-    int nbytes = max;
+    return theAggregate->theBucket.bytesWanted(min, max);
+}
 
-    switch (delay_class) {
-    case 0:
-	break;
+void
+Aggregate::AggregateId::bytesIn(int qty)
+{
+    theAggregate->theBucket.bytesIn(qty);
+}
 
-    case 1:
-	if (Config.Delay.rates[pool]->aggregate.restore_bps != -1)
-	    nbytes = XMIN(nbytes, delay_data[pool].class1->aggregate);
-	break;
+DelayPool *DelayPools::delay_data = NULL;
+fd_set DelayPools::delay_no_delay;
+time_t DelayPools::LastUpdate = 0;
+unsigned short DelayPools::pools_ (0);
 
-    case 2:
-	if (Config.Delay.rates[pool]->aggregate.restore_bps != -1)
-	    nbytes = XMIN(nbytes, delay_data[pool].class2->aggregate);
-	if (Config.Delay.rates[pool]->individual.restore_bps != -1)
-	    nbytes = XMIN(nbytes, delay_data[pool].class2->individual[position]);
-	break;
+void
+DelayPools::Init()
+{
+    LastUpdate = getCurrentTime();
+    FD_ZERO(&delay_no_delay);
+    cachemgrRegister("delay", "Delay Pool Levels", Stats, 0, 1);
+}
 
-    case 3:
-	if (Config.Delay.rates[pool]->aggregate.restore_bps != -1)
-	    nbytes = XMIN(nbytes, delay_data[pool].class3->aggregate);
-	if (Config.Delay.rates[pool]->individual.restore_bps != -1)
-	    nbytes = XMIN(nbytes, delay_data[pool].class3->individual[position]);
-	if (Config.Delay.rates[pool]->network.restore_bps != -1)
-	    nbytes = XMIN(nbytes, delay_data[pool].class3->network[position >> 8]);
-	break;
+void
+DelayPools::InitDelayData()
+{
+    if (!pools())
+	return;
+    DelayPools::delay_data = new DelayPool[pools()];
+    DelayPools::MemoryUsed += pools() * sizeof(DelayPool);
+    eventAdd("DelayPools::Update", DelayPools::Update, NULL, 1.0, 1);
+}
 
-    default:
-	fatalf("delayBytesWanted: Invalid class %d\n", delay_class);
-	break;
-    }
-    nbytes = XMAX(min, nbytes);
-    return nbytes;
+void
+DelayPools::FreeDelayData()
+{
+    delete[] DelayPools::delay_data;
+    DelayPools::MemoryUsed -= pools() * sizeof(*DelayPools::delay_data);
+    pools_ = 0;
 }
 
-/*
- * this records actual bytes recieved.  always recorded, even if the
- * class is disabled - it's more efficient to just do it than to do all
- * the checks.
- */
 void
-delayBytesIn(delay_id d, int qty)
+DelayPools::SetNoDelay(int fd)
 {
-    unsigned short position = d & 0xFFFF;
-    unsigned short pool = (d >> 16) - 1;
-    unsigned char delay_class;
+    FD_SET(fd, &delay_no_delay);
+}
 
-    if (pool == 0xFFFF)
-	return;
-    delay_class = Config.Delay.delay_class[pool];
-    switch (delay_class) {
-    case 1:
-	delay_data[pool].class1->aggregate -= qty;
-	return;
-    case 2:
-	delay_data[pool].class2->aggregate -= qty;
-	delay_data[pool].class2->individual[position] -= qty;
+void
+DelayPools::ClearNoDelay(int fd)
+{
+    FD_CLR(fd, &delay_no_delay);
+}
+
+bool
+DelayPools::IsNoDelay(int fd)
+{
+    return FD_ISSET(fd, &delay_no_delay);
+}
+
+void
+DelayPools::Update(void *unused)
+{
+    if (!pools())
 	return;
-    case 3:
-	delay_data[pool].class3->aggregate -= qty;
-	delay_data[pool].class3->network[position >> 8] -= qty;
-	delay_data[pool].class3->individual[position] -= qty;
+    eventAdd("DelayPools::Update", Update, NULL, 1.0, 1);
+    int incr = squid_curtime - LastUpdate;
+    if (incr < 1)
 	return;
+    LastUpdate = squid_curtime;
+    Vector<Updateable *>::iterator pos = toUpdate.begin();
+    while (pos != toUpdate.end()) {
+	(*pos)->update(incr);
+	++pos;
     }
-    fatalf("delayBytesWanted: Invalid class %d\n", delay_class);
-    assert(0);
 }
 
-int
-delayMostBytesWanted(const MemObject * mem, int max)
-{
-    int i = 0;
-    int found = 0;
-    int wanted;
-    store_client *sc;
-    dlink_node *node;
-    for (node = mem->clients.head; node; node = node->next) {
-	sc = (store_client *) node->data;
-	if (!sc->callbackPending())
-	    /* not waiting for more data */
-	    continue;
-	if (sc->getType() != STORE_MEM_CLIENT)
-	    continue;
-	wanted = sc->copyInto.length;
-	if (wanted > max)
-	    wanted = max;
-	i = delayBytesWanted(sc->delayId, i, wanted);
-	found = 1;
+void
+DelayPools::registerForUpdates(Updateable *anObject)
+{
+    /* Assume no doubles */
+    toUpdate.push_back(anObject);
+}
+
+void
+DelayPools::deregisterForUpdates (Updateable *anObject)
+{
+    Vector<Updateable *>::iterator pos = toUpdate.begin();
+    while (pos != toUpdate.end() && *pos != anObject) {
+	++pos;
     }
-    return found ? i : max;
-}
-
-delay_id
-delayMostBytesAllowed(const MemObject * mem)
-{
-    int j;
-    int jmax = -1;
-    store_client *sc;
-    dlink_node *node;
-    delay_id d = 0;
-    for (node = mem->clients.head; node; node = node->next) {
-	sc = (store_client *) node->data;
-	if (!sc->callbackPending())
-	    /* not waiting for more data */
-	    continue;
-	if (sc->getType() != STORE_MEM_CLIENT)
-	    continue;
-	j = delayBytesWanted(sc->delayId, 0, sc->copyInto.length);
-	if (j > jmax) {
-	    jmax = j;
-	    d = sc->delayId;
+    if (pos != toUpdate.end()) {
+	/* move all objects down one */
+	Vector<Updateable *>::iterator temp = pos;
+	++pos;
+	while (pos != toUpdate.end()) {
+	    *temp = *pos;
+	    ++temp;
+	    ++pos;
 	}
+	toUpdate.pop_back();
     }
-    return d;
 }
 
+Vector<Updateable *> DelayPools::toUpdate;
+
 void
-delaySetStoreClient(store_client * sc, delay_id delayId)
+DelayPools::Stats(StoreEntry * sentry)
 {
-    assert(sc != NULL);
-    sc->delayId = delayId;
-    delayRegisterDelayIdPtr(&sc->delayId);
+    unsigned short i;
+
+    storeAppendPrintf(sentry, "Delay pools configured: %d\n\n", DelayPools::pools());
+    for (i = 0; i < DelayPools::pools(); ++i) {
+	if (DelayPools::delay_data[i].theComposite().getRaw()) {
+	    storeAppendPrintf(sentry, "Pool: %d\n\tClass: %s\n\n", i + 1, DelayPools::delay_data[i].pool->theClassTypeLabel());
+	    DelayPools::delay_data[i].theComposite()->stats (sentry);
+	} else
+	    storeAppendPrintf(sentry, "\tMisconfigured pool.\n\n");
+    }
+    storeAppendPrintf(sentry, "Memory Used: %d bytes\n", (int) DelayPools::MemoryUsed);
 }
 
-static void
-delayPoolStatsAg(StoreEntry * sentry, delaySpecSet * rate, int ag)
+void
+DelayPools::FreePools()
 {
-    /* note - always pass delaySpecSet's by reference as may be incomplete */
-    if (rate->aggregate.restore_bps == -1) {
-	storeAppendPrintf(sentry, "\tAggregate:\n\t\tDisabled.\n\n");
+    if (!DelayPools::pools())
 	return;
+    FreeDelayData();
+}
+
+unsigned short
+DelayPools::pools() 
+{
+    return pools_;
+}
+
+void
+DelayPools::pools (u_short newPools)
+{
+    if (pools()) {
+	debug(3, 0) ("parse_delay_pool_count: multiple delay_pools lines, aborting all previous delay_pools config\n");
+	FreePools();
     }
-    storeAppendPrintf(sentry, "\tAggregate:\n");
-    storeAppendPrintf(sentry, "\t\tMax: %d\n", rate->aggregate.max_bytes);
-    storeAppendPrintf(sentry, "\t\tRestore: %d\n", rate->aggregate.restore_bps);
-    storeAppendPrintf(sentry, "\t\tCurrent: %d\n\n", ag);
+    pools_ = newPools;
+    if (pools())
+	InitDelayData();
+}
+
+template <class Key, class Value>
+VectorMap<Key,Value>::VectorMap() : nextMapPosition(0)
+{
+}
+
+template <class Key, class Value>
+unsigned int 
+VectorMap<Key,Value>::size() const
+{
+    return nextMapPosition;
+}
+ 
+template <class Key, class Value>
+unsigned int
+VectorMap<Key,Value>::insert (Key const key)
+{
+    unsigned char index = findKeyIndex (key);
+    assert (!indexUsed(index));
+
+    key_map[index] = key;
+
+    ++nextMapPosition;
+
+    return index;
+}
+
+void *
+IndividualPool::operator new(size_t size)
+{
+    DelayPools::MemoryUsed += sizeof (IndividualPool);
+    return ::operator new (size);
+}
+
+void
+IndividualPool::operator delete (void *address)
+{
+    DelayPools::MemoryUsed -= sizeof (IndividualPool);
+    ::operator delete (address);
 }
 
-static void
-delayPoolStats1(StoreEntry * sentry, unsigned short pool)
+void
+IndividualPool::deleteSelf() const
 {
-    /* must be a reference only - partially malloc()d struct */
-    delaySpecSet *rate = Config.Delay.rates[pool];
+    delete this;
+}
 
-    storeAppendPrintf(sentry, "Pool: %d\n\tClass: 1\n\n", pool + 1);
-    delayPoolStatsAg(sentry, rate, delay_data[pool].class1->aggregate);
+VectorPool::VectorPool()
+{
+    DelayPools::registerForUpdates (this);
 }
 
-static void
-delayPoolStats2(StoreEntry * sentry, unsigned short pool)
+VectorPool::~VectorPool()
 {
-    /* must be a reference only - partially malloc()d struct */
-    delaySpecSet *rate = Config.Delay.rates[pool];
-    class2DelayPool *class2 = delay_data[pool].class2;
-    unsigned char shown = 0;
-    unsigned int i;
+    DelayPools::deregisterForUpdates (this);
+}
 
-    storeAppendPrintf(sentry, "Pool: %d\n\tClass: 2\n\n", pool + 1);
-    delayPoolStatsAg(sentry, rate, class2->aggregate);
-    if (rate->individual.restore_bps == -1) {
-	storeAppendPrintf(sentry, "\tIndividual:\n\t\tDisabled.\n\n");
+void
+VectorPool::stats(StoreEntry * sentry)
+{
+    rate()->stats (sentry, label());
+    if (rate()->restore_bps == -1) {
+	storeAppendPrintf(sentry, "\n\n");
 	return;
     }
-    storeAppendPrintf(sentry, "\tIndividual:\n");
-    storeAppendPrintf(sentry, "\t\tMax: %d\n", rate->individual.max_bytes);
-    storeAppendPrintf(sentry, "\t\tRate: %d\n", rate->individual.restore_bps);
-    storeAppendPrintf(sentry, "\t\tCurrent: ");
-    for (i = 0; i < IND_MAP_SZ; i++) {
-	if (class2->individual_map[i] == 255)
-	    break;
-	storeAppendPrintf(sentry, "%d:%d ", class2->individual_map[i],
-	    class2->individual[i]);
-	shown = 1;
-    }
-    if (class2->individual_255_used) {
-	storeAppendPrintf(sentry, "%d:%d ", 255, class2->individual[255]);
-	shown = 1;
+    storeAppendPrintf(sentry, "\t\tCurrent:");
+    for (unsigned int i = 0; i < buckets.size(); i++) {
+	storeAppendPrintf(sentry, " %d:", buckets.key_map[i]);
+	buckets.values[i].stats(sentry);
     }
-    if (!shown)
-	storeAppendPrintf(sentry, "Not used yet.");
+    if (!buckets.size())
+	storeAppendPrintf(sentry, " Not used yet.");
     storeAppendPrintf(sentry, "\n\n");
 }
 
-static void
-delayPoolStats3(StoreEntry * sentry, unsigned short pool)
-{
-    /* fully malloc()d struct in this case only */
-    delaySpecSet *rate = Config.Delay.rates[pool];
-    class3DelayPool *class3 = delay_data[pool].class3;
-    unsigned char shown = 0;
-    unsigned int i;
-    unsigned int j;
-
-    storeAppendPrintf(sentry, "Pool: %d\n\tClass: 3\n\n", pool + 1);
-    delayPoolStatsAg(sentry, rate, class3->aggregate);
-    if (rate->network.restore_bps == -1) {
-	storeAppendPrintf(sentry, "\tNetwork:\n\t\tDisabled.");
-    } else {
-	storeAppendPrintf(sentry, "\tNetwork:\n");
-	storeAppendPrintf(sentry, "\t\tMax: %d\n", rate->network.max_bytes);
-	storeAppendPrintf(sentry, "\t\tRate: %d\n", rate->network.restore_bps);
-	storeAppendPrintf(sentry, "\t\tCurrent: ");
-	for (i = 0; i < NET_MAP_SZ; i++) {
-	    if (class3->network_map[i] == 255)
-		break;
-	    storeAppendPrintf(sentry, "%d:%d ", class3->network_map[i],
-		class3->network[i]);
-	    shown = 1;
-	}
-	if (class3->network_255_used) {
-	    storeAppendPrintf(sentry, "%d:%d ", 255, class3->network[255]);
-	    shown = 1;
-	}
-	if (!shown)
-	    storeAppendPrintf(sentry, "Not used yet.");
-    }
-    storeAppendPrintf(sentry, "\n\n");
-    shown = 0;
-    if (rate->individual.restore_bps == -1) {
-	storeAppendPrintf(sentry, "\tIndividual:\n\t\tDisabled.\n\n");
+void
+VectorPool::dump(StoreEntry *entry) const
+{
+    rate()->dump (entry);
+}
+
+void
+VectorPool::update(int incr)
+{
+    if (rate()->restore_bps == -1)
 	return;
+    for (unsigned int i = 0; i< buckets.size(); ++i)
+	buckets.values[i].update (*rate(), incr);
+}
+
+void
+VectorPool::parse()
+{
+    rate()->parse();
+}
+
+bool
+VectorPool::keyAllocated (unsigned char const key) const
+{
+    return buckets.indexUsed(buckets.findKeyIndex (key));
+}
+
+template <class Key, class Value>
+bool
+VectorMap<Key,Value>::indexUsed (unsigned char const index) const
+{
+    assert (index <= IND_MAP_SZ);
+    return index < size();
+}
+
+/* returns the used position, or the position to allocate */
+template <class Key, class Value>
+unsigned char
+VectorMap<Key,Value>::findKeyIndex (Key const key) const
+{
+    for (unsigned int index = 0; index < size(); ++index) {
+	assert (indexUsed (index));
+	if (key_map[index] == key)
+	    return index;
     }
-    storeAppendPrintf(sentry, "\tIndividual:\n");
-    storeAppendPrintf(sentry, "\t\tMax: %d\n", rate->individual.max_bytes);
-    storeAppendPrintf(sentry, "\t\tRate: %d\n", rate->individual.restore_bps);
-    for (i = 0; i < NET_MAP_SZ; i++) {
-	if (class3->network_map[i] == 255)
-	    break;
-	storeAppendPrintf(sentry, "\t\tCurrent [Network %d]: ", class3->network_map[i]);
-	shown = 1;
-	for (j = 0; j < IND_MAP_SZ; j++) {
-	    if (class3->individual_map[i][j] == 255)
-		break;
-	    storeAppendPrintf(sentry, "%d:%d ", class3->individual_map[i][j],
-		class3->individual[(i << 8) | j]);
-	}
-	if (class3->individual_255_used[i / 8] & (1 << (i % 8))) {
-	    storeAppendPrintf(sentry, "%d:%d ", 255, class3->individual[(i << 8) | 255]);
-	}
-	storeAppendPrintf(sentry, "\n");
+    /* not in map */
+    return size();
+}
+
+DelayIdComposite::Pointer
+VectorPool::id(struct in_addr &src_addr, AuthUserRequest *)
+{
+    if (rate()->restore_bps == -1)
+	return new NullDelayId;
+
+    unsigned int key = makeKey (src_addr);
+
+    if (keyAllocated (key))
+	return new Id (this, buckets.findKeyIndex(key));
+    
+    unsigned char const resultIndex = buckets.insert(key);
+    buckets.values[resultIndex].init (*rate());
+    return new Id(this, resultIndex);
+}
+
+void *
+VectorPool::Id::operator new(size_t size)
+{
+    DelayPools::MemoryUsed += sizeof (Id);
+    return ::operator new (size);
+}
+
+void
+VectorPool::Id::operator delete (void *address)
+{
+    DelayPools::MemoryUsed -= sizeof (Id);
+    ::operator delete (address);
+}
+
+void
+VectorPool::Id::deleteSelf() const
+{
+    delete this;
+}
+
+VectorPool::Id::Id (VectorPool::Pointer aPool, int anIndex) : theVector (aPool), theIndex (anIndex)
+{
+}
+
+int
+VectorPool::Id::bytesWanted (int min, int max) const
+{
+    return theVector->buckets.values[theIndex].bytesWanted (min, max);
+}
+
+void
+VectorPool::Id::bytesIn(int qty)
+{
+    theVector->buckets.values[theIndex].bytesIn (qty);
+}
+
+unsigned int const
+IndividualPool::makeKey (struct in_addr &src_addr) const
+{
+    unsigned int host;
+    host = ntohl(src_addr.s_addr) & 0xff;
+    return host;
+}
+
+void *
+ClassCNetPool::operator new(size_t size)
+{
+    DelayPools::MemoryUsed += sizeof (ClassCNetPool);
+    return ::operator new (size);
+}
+
+void
+ClassCNetPool::operator delete (void *address)
+{
+    DelayPools::MemoryUsed -= sizeof (ClassCNetPool);
+    ::operator delete (address);
+}
+
+void
+ClassCNetPool::deleteSelf() const
+{
+    delete this;
+}
+
+unsigned int const
+ClassCNetPool::makeKey (struct in_addr &src_addr) const
+{
+    unsigned int net;
+    net = (ntohl(src_addr.s_addr) >> 8) & 0xff;
+    return net;
+}
+
+
+ClassCHostPool::ClassCHostPool()
+{
+    DelayPools::registerForUpdates (this);
+}
+
+ClassCHostPool::~ClassCHostPool()
+{
+    DelayPools::deregisterForUpdates (this);
+}
+
+void
+ClassCHostPool::stats(StoreEntry * sentry)
+{
+    rate()->stats (sentry, label());
+    if (rate()->restore_bps == -1) {
+	storeAppendPrintf(sentry, "\n\n");
+	return;
     }
-    if (class3->network_255_used) {
-	storeAppendPrintf(sentry, "\t\tCurrent [Network 255]: ");
-	shown = 1;
-	for (j = 0; j < IND_MAP_SZ; j++) {
-	    if (class3->individual_map[255][j] == 255)
-		break;
-	    storeAppendPrintf(sentry, "%d:%d ", class3->individual_map[255][j],
-		class3->individual[(255 << 8) | j]);
-	}
-	if (class3->individual_255_used[255 / 8] & (1 << (255 % 8))) {
-	    storeAppendPrintf(sentry, "%d:%d ", 255, class3->individual[(255 << 8) | 255]);
-	}
+
+    for (unsigned int index = 0; index < buckets.size(); ++index) {
+	storeAppendPrintf(sentry, "\t\tCurrent [Network %d]:", buckets.key_map[index]);
+	buckets.values[index].stats (sentry);
 	storeAppendPrintf(sentry, "\n");
     }
-    if (!shown)
+
+    if (!buckets.size())
 	storeAppendPrintf(sentry, "\t\tCurrent [All networks]: Not used yet.\n");
-    storeAppendPrintf(sentry, "\n");
+
+    storeAppendPrintf(sentry, "\n\n");
 }
 
-static void
-delayPoolStats(StoreEntry * sentry)
+void
+ClassCHostPool::dump(StoreEntry *entry) const
 {
-    unsigned short i;
+    rate()->dump (entry);
+}
 
-    storeAppendPrintf(sentry, "Delay pools configured: %d\n\n", Config.Delay.pools);
-    for (i = 0; i < Config.Delay.pools; i++) {
-	switch (Config.Delay.delay_class[i]) {
-	case 0:
-	    storeAppendPrintf(sentry, "Pool: %d\n\tClass: 0\n\n", i + 1);
-	    storeAppendPrintf(sentry, "\tMisconfigured pool.\n\n");
-	    break;
-	case 1:
-	    delayPoolStats1(sentry, i);
-	    break;
-	case 2:
-	    delayPoolStats2(sentry, i);
-	    break;
-	case 3:
-	    delayPoolStats3(sentry, i);
-	    break;
-	default:
-	    assert(0);
-	}
-    }
-    storeAppendPrintf(sentry, "Memory Used: %d bytes\n", (int) memory_used);
+void
+ClassCHostPool::update(int incr)
+{
+    if (rate()->restore_bps == -1)
+	return;
+    for (unsigned int i = 0; i< buckets.size(); ++i)
+	buckets.values[i].update (*rate(), incr);
+}
+
+void
+ClassCHostPool::parse()
+{
+    rate()->parse();
+}
+
+bool
+ClassCHostPool::keyAllocated (unsigned char const key) const
+{
+    return buckets.indexUsed(buckets.findKeyIndex (key));
+}
+
+unsigned char const
+ClassCHostPool::makeHostKey (struct in_addr &src_addr) const
+{
+    unsigned int host;
+    host = ntohl(src_addr.s_addr) & 0xff;
+    return host;
+}
+
+unsigned int const
+ClassCHostPool::makeKey (struct in_addr &src_addr) const
+{
+    unsigned int net;
+    net = (ntohl(src_addr.s_addr) >> 8) & 0xff;
+    return net;
+}
+DelayIdComposite::Pointer
+ClassCHostPool::id(struct in_addr &src_addr, AuthUserRequest *)
+{
+    if (rate()->restore_bps == -1)
+	return new NullDelayId;
+
+    unsigned int key = makeKey (src_addr);
+    unsigned char host = makeHostKey (src_addr);
+
+    unsigned char hostIndex;
+    unsigned char netIndex;
+    if (keyAllocated (key))
+	netIndex = buckets.findKeyIndex(key);
+    else
+	netIndex = buckets.insert (key);
+
+    hostIndex = buckets.values[netIndex].hostPosition (*rate(), host);
+    
+    return new Id (this, netIndex, hostIndex);
+}
+
+void *
+ClassCHostPool::Id::operator new(size_t size)
+{
+    DelayPools::MemoryUsed += sizeof (Id);
+    return ::operator new (size);
+}
+
+void
+ClassCHostPool::Id::operator delete (void *address)
+{
+    DelayPools::MemoryUsed -= sizeof (Id);
+    ::operator delete (address);
+}
+
+void
+ClassCHostPool::Id::deleteSelf() const
+{
+    delete this;
+}
+
+ClassCHostPool::Id::Id (ClassCHostPool::Pointer aPool, unsigned char aNet, unsigned char aHost) : theClassCHost (aPool), theNet (aNet), theHost (aHost)
+{
+}
+
+int
+ClassCHostPool::Id::bytesWanted (int min, int max) const
+{
+    return theClassCHost->buckets.values[theNet].individuals.values[theHost].bytesWanted (min, max);
+}
+
+void
+ClassCHostPool::Id::bytesIn(int qty)
+{
+    theClassCHost->buckets.values[theNet].individuals.values[theHost].bytesIn (qty);
 }
 
 #endif
+
