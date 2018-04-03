
#include "squid.h"

#define stackSize(S) ((S)->top - (S)->base)

typedef struct {
    void **base;
    void **top;
    int max_size;
} Stack;

typedef struct {
    char *name;
    int n_allocated;
    size_t size;
    int n_used;
    Stack Stack;
} memData;

static memData MemData[MEM_MAX];

static void *stackPop(Stack * s);
static int stackFull(Stack * s);
static int stackEmpty(Stack * s);
static void stackPush(Stack * s, void *p);
static void memDataInit(mem_type, const char *, size_t, int);
static OBJH memStats;

static int
stackEmpty(Stack * s)
{
    return s->top == s->base;
}

static int
stackFull(Stack * s)
{
    return (stackSize(s) == s->max_size);
}

static void *
stackPop(Stack * s)
{
    void *p;
    assert(s->top != s->base);
    s->top--;
    p = *s->top;
    *s->top = NULL;
    return p;
}

static void
stackPush(Stack * s, void *p)
{
    if (stackSize(s) == s->max_size) {
	xfree(p);
    } else {
	*s->top = p;
	s->top++;
    }
}

static void
memDataInit(mem_type type, const char *name, size_t size, int max_pages)
{
    memData *m = &MemData[type];
    m->size = size;
    m->name = xstrdup(name);
#if !PURIFY
    if (Config.onoff.mem_pools) {
	m->Stack.max_size = max_pages;
	m->Stack.base = xcalloc(max_pages, sizeof(void **));
	m->Stack.top = m->Stack.base;
    }
#endif
}

/*
 * PUBLIC ROUTINES
 */

void *
memAllocate(mem_type type, int clear)
{
    void *p = NULL;
    memData *m = &MemData[type];
    if (!stackEmpty(&m->Stack)) {
	p = stackPop(&m->Stack);
	assert(p != NULL);
    } else {
	p = xmalloc(m->size);
	m->n_allocated++;
    }
    m->n_used++;
    if (clear)
	memset(p, '\0', m->size);
    return p;
}

void
memFree(mem_type type, void *p)
{
    memData *m = &MemData[type];
    assert(p != NULL);
    m->n_used--;
    if (stackFull(&m->Stack)) {
	xfree(p);
	m->n_allocated--;
    } else {
	stackPush(&m->Stack, p);
    }
}

void
memInit(void)
{
    mem_type t;
    memData *m;
    memset(MemData, '\0', MEM_MAX * sizeof(memData));
    memDataInit(MEM_4K_BUF, "4K Buffer", 4096, 10);
    memDataInit(MEM_8K_BUF, "8K Buffer", 8192, 10);
    memDataInit(MEM_ACCESSLOGENTRY, "AccessLogEntry",
