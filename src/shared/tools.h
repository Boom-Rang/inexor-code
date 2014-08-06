// generic useful stuff for any C++ program


/* include guard block
	include guards guarantee that header files will be included only once	
*/
#ifndef _TOOLS_H
#define _TOOLS_H

/*------------------------------------------------------------------------------------------------------------------*/
// TYPE DEFINITIONS AND "NULL"
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/

/*	If NULL is defined somewhere else, undefine it
	Make sure NULL is defined as 0 
	and not as.. "NULL"
*/
#ifdef NULL
	#undef NULL
#endif
// define it again here!
#define NULL 0

/* Very common type definitions
*/
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef signed long long int llong;
typedef unsigned long long int ullong;



/*------------------------------------------------------------------------------------------------------------------*/
// MACROS FOR "DEBUGGING TRICKS"
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/

/* This macro defines ASSERT as assert. If debugmode is disabled, you can use 
*/
#ifdef _DEBUG
	#define ASSERT(c) assert(c)
#else
	// do not do anything. Just run the code
	#define ASSERT(c) if(c) {}
#endif

/* __restrict is a keyword that can be used in pointer declarations
	http://stackoverflow.com/questions/745870/realistic-usage-of-the-c99-restrict-keyword
	http://en.wikipedia.org/wiki/Restrict
*/
#if defined(__GNUC__) || (defined(_MSC_VER) && _MSC_VER >= 1400)
	#define RESTRICT __restrict
#else
	#define RESTRICT
#endif




/*------------------------------------------------------------------------------------------------------------------*/
// MEMORY ALLOCATION / MEMORY RELEASE OPERATORS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/

/* Memory allocation operators
*/
inline void *operator new(size_t, void *p) { return p; }
inline void *operator new[](size_t, void *p) { return p; }

/* Memory delete operators
*/
inline void operator delete(void *, void *) {}
inline void operator delete[](void *, void *) {}




/*------------------------------------------------------------------------------------------------------------------*/
// SWAP / MIN / MAX / CLAMP  MACROS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/

/* This code passage checks for evidence of macros with the same names
	like the templates below. The macros will be undefined because they
	have HIGHEST PRIORITY and would override anything
*/
#ifdef swap
	#undef swap
#endif
#ifdef max
	#undef max
#endif
#ifdef min
	#undef min
#endif

/*	Swap is a template to swap the values of A and B
*/
template<class T>
static inline void swap(T &a, T &b) {
    T t = a; // temporary template to "save" a
    a = b;
    b = t; // restore a
}
/* Return the maximum of two types
*/
template<class T>
static inline T max(T a, T b) {
    return a > b ? a : b;
}
/* Return the minimum of two types
*/
template<class T>
static inline T min(T a, T b) {
    return a < b ? a : b;
}
/* Return the maximum of the [ minimum of (A,C) ], B
*/
template<class T, class U>
static inline T clamp(T a, U b, U c) {
    return max(T(b), min(a, T(c)));
}





/*------------------------------------------------------------------------------------------------------------------*/
// RANDOM NUMBER (SCALE) MACROS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/

/* Some crazy weird random number macros
	that could be replaced easily... (?)
	some set the signed/unsigned bit - why not use abs() ?
*/
#define rnd(x) ((int)(randomMT()&0x7FFFFFFF)%(x))
#define rndscale(x) (float((randomMT()&0x7FFFFFFF)*double(x)/double(0x7FFFFFFF)))
#define detrnd(s, x) ((int)(((((uint)(s))*1103515245+12345)>>16)%(x)))




/*------------------------------------------------------------------------------------------------------------------*/
// LOOP MACROS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/

/* Loop macros
	These macros must die!
	It is important to replace them with their equivalent code
	to make them visible for debuggers properly!
*/
#define loop(v,m) for(int v = 0; v<int(m); v++)
#define loopi(m) loop(i,m)
#define loopj(m) loop(j,m)
#define loopk(m) loop(k,m)
#define loopl(m) loop(l,m)
#define loopirev(v) for(int i = v-1; i>=0; i--)





/*------------------------------------------------------------------------------------------------------------------*/
// SAFE RELEASE MACROS WHICH SET POINTERS TO ZERO AFTER DELETE
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/

/* These macros represent a common way to delete dynamic memory:
	you delete the memory and set the pointer to NULL
*/
#define DELETEP(p) if(p) { delete   p; p = 0; }
#define DELETEA(p) if(p) { delete[] p; p = 0; }





/*------------------------------------------------------------------------------------------------------------------*/
// MATH CONSTANTS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/

/* Some important number constants
	such as PI, 2*pi and common square roots
*/
#define PI  (3.1415927f)
#define PI2 (2*PI)
#define SQRT2 (1.4142136f)
#define SQRT3 (1.7320508f)
#define RAD (PI / 180.0f)





/*------------------------------------------------------------------------------------------------------------------*/
// OPERATING SYSTEM SPECIFIC CODE PARTS THAT ENSURE EVIDENCE OF MACROS OR DEFINE OS SPECIFIC SETTINGS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/
#ifdef WIN32
	/* Windows-specific code part that makes sure M_PI and M_LN2 are defined
	*/
	#ifndef M_PI
		#define M_PI 3.14159265358979323846
	#endif
	#ifndef M_LN2
		#define M_LN2 0.693147180559945309417
	#endif

	/* These compiler pragma macros aim at Microsoft compilers
		some warnings are stupid indeed. Programmers know the risks so they can be disabled.
	*/
	#ifndef __GNUC__
		#pragma warning (3: 4189)       // local variable is initialized but not referenced
		#pragma warning (disable: 4244) // conversion from 'int' to 'float', possible loss of data
		#pragma warning (disable: 4267) // conversion from 'size_t' to 'int', possible loss of data
		#pragma warning (disable: 4355) // 'this' : used in base member initializer list
		#pragma warning (disable: 4996) // 'strncpy' was declared deprecated
	#endif

	#define strcasecmp _stricmp
	#define strncasecmp _strnicmp
	#define PATHDIV '\\'
/* #ifndef WIN32 (if not on Windows) 
*/
#else
	#define __cdecl // ignore Windows' __cdecl (?)
	#define _vsnprintf vsnprintf
	#define PATHDIV '/'
#endif

#ifdef __GNUC__
	#define PRINTFARGS(fmt, args) __attribute__((format(printf, fmt, args)))
#else
	#define PRINTFARGS(fmt, args)
#endif





/*------------------------------------------------------------------------------------------------------------------*/
// STRINGS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/

// easy safe strings

#define MAXSTRLEN 260
typedef char string[MAXSTRLEN];

inline void vformatstring(char *d, const char *fmt, va_list v, int len = MAXSTRLEN) { _vsnprintf(d, len, fmt, v); d[len-1] = 0; }
inline char *copystring(char *d, const char *s, size_t len = MAXSTRLEN) { strncpy(d, s, len); d[len-1] = 0; return d; }
inline char *concatstring(char *d, const char *s, size_t len = MAXSTRLEN) { size_t used = strlen(d); return used < len ? copystring(d+used, s, len-used) : d; }

struct stringformatter
{
    char *buf;
    stringformatter(char *buf): buf((char *)buf) {}
    void operator()(const char *fmt, ...) PRINTFARGS(2, 3)
    {
        va_list v;
        va_start(v, fmt);
        vformatstring(buf, fmt, v);
        va_end(v);
    }
};



/*------------------------------------------------------------------------------------------------------------------*/
// STRING FORMAT MACROS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/
#define formatstring(d) stringformatter((char *)d)
#define defformatstring(d) string d; formatstring(d)
#define defvformatstring(d,last,fmt) string d; { va_list ap; va_start(ap, last); vformatstring(d, fmt, ap); va_end(ap); }



/*------------------------------------------------------------------------------------------------------------------*/
// LOOP MACROS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/

/* These macros must die!
*/
#define loopv(v)    for(int i = 0; i<(v).length(); i++)
#define loopvj(v)   for(int j = 0; j<(v).length(); j++)
#define loopvk(v)   for(int k = 0; k<(v).length(); k++)
#define loopvrev(v) for(int i = (v).length()-1; i>=0; i--)



template <class T>
struct databuf
{
    enum
    {
        OVERREAD  = 1<<0,
        OVERWROTE = 1<<1
    };

    T *buf;
    int len, maxlen;
    uchar flags;

    databuf() : buf(NULL), len(0), maxlen(0), flags(0) {}

    template<class U>
    databuf(T *buf, U maxlen) : buf(buf), len(0), maxlen((int)maxlen), flags(0) {}

    const T &get()
    {
        static T overreadval = 0;
        if(len<maxlen) return buf[len++];
        flags |= OVERREAD;
        return overreadval;
    }

    databuf subbuf(int sz)
    {
        sz = clamp(sz, 0, maxlen-len);
        len += sz;
        return databuf(&buf[len-sz], sz);
    }

    void put(const T &val)
    {
        if(len<maxlen) buf[len++] = val;
        else flags |= OVERWROTE;
    }

    void put(const T *vals, int numvals)
    {
        if(maxlen-len<numvals) flags |= OVERWROTE;
        memcpy(&buf[len], (const void *)vals, min(maxlen-len, numvals)*sizeof(T));
        len += min(maxlen-len, numvals);
    }

    int get(T *vals, int numvals)
    {
        int read = min(maxlen-len, numvals);
        if(read<numvals) flags |= OVERREAD;
        memcpy(vals, (void *)&buf[len], read*sizeof(T));
        len += read;
        return read;
    }

    void offset(int n)
    {
        n = min(n, maxlen);
        buf += n;
        maxlen -= n;
        len = max(len-n, 0);
    }

    bool empty() const { return len==0; }
    int length() const { return len; }
    int remaining() const { return maxlen-len; }
    bool overread() const { return (flags&OVERREAD)!=0; }
    bool overwrote() const { return (flags&OVERWROTE)!=0; }

    void forceoverread()
    {
        len = maxlen;
        flags |= OVERREAD;
    }
};

typedef databuf<char> charbuf;
typedef databuf<uchar> ucharbuf;

struct packetbuf : ucharbuf
{
    ENetPacket *packet;
    int growth;

    packetbuf(ENetPacket *packet) : ucharbuf(packet->data, packet->dataLength), packet(packet), growth(0) {}
    packetbuf(int growth, int pflags = 0) : growth(growth)
    {
        packet = enet_packet_create(NULL, growth, pflags);
        buf = (uchar *)packet->data;
        maxlen = packet->dataLength;
    }
    ~packetbuf() { cleanup(); }

    void reliable() { packet->flags |= ENET_PACKET_FLAG_RELIABLE; }

    void resize(int n)
    {
        enet_packet_resize(packet, n);
        buf = (uchar *)packet->data;
        maxlen = packet->dataLength;
    }

    void checkspace(int n)
    {
        if(len + n > maxlen && packet && growth > 0) resize(max(len + n, maxlen + growth));
    }

    ucharbuf subbuf(int sz)
    {
        checkspace(sz);
        return ucharbuf::subbuf(sz);
    }

    void put(const uchar &val)
    {
        checkspace(1);
        ucharbuf::put(val);
    }

    void put(const uchar *vals, int numvals)
    {
        checkspace(numvals);
        ucharbuf::put(vals, numvals);
    }

    ENetPacket *finalize()
    {
        resize(len);
        return packet;
    }

    void cleanup()
    {
        if(growth > 0 && packet && !packet->referenceCount) { enet_packet_destroy(packet); packet = NULL; buf = NULL; len = maxlen = 0; }
    }
};

template<class T>
static inline float heapscore(const T &n) { return n; }


/* Return if value A is SMALLER THAN value B
	( <=> this means value B is BIGGER than value A)
*/
template<class T>
static inline bool compareless(const T &x, const T &y) { return x < y; }



/*------------------------------------------------------------------------------------------------------------------*/
// SEVERAL SORTING ALGORITHM TEMPLATES WITH VARIOUS PARAMETER CONSTELLATIONS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/

/* Insertionsort algorithm template
*/
template<class T, class F>
static inline void insertionsort(T *start, T *end, F fun)
{
    for(T *i = start+1; i < end; i++)
    {
        if(fun(*i, i[-1]))
        {
            T tmp = *i;
            *i = i[-1];
            T *j = i-1;
            for(; j > start && fun(tmp, j[-1]); --j)
                *j = j[-1];
            *j = tmp;
        }
    }

}
// this is just a dummy which will lead to the function above
template<class T, class F>
static inline void insertionsort(T *buf, int n, F fun) {
    insertionsort(buf, buf+n, fun);
}
// this is just a dummy which will lead to the function above
template<class T>
static inline void insertionsort(T *buf, int n) {
    insertionsort(buf, buf+n, compareless<T>);
}


/* Quicksort algorithm template
*/
template<class T, class F>
static inline void quicksort(T *start, T *end, F fun)
{
    while(end-start > 10)
    {
        T *mid = &start[(end-start)/2], *i = start+1, *j = end-2, pivot;
        if(fun(*start, *mid)) /* start < mid */
        {
            if(fun(end[-1], *start)) { pivot = *start; *start = end[-1]; end[-1] = *mid; } /* end < start < mid */
            else if(fun(end[-1], *mid)) { pivot = end[-1]; end[-1] = *mid; } /* start <= end < mid */
            else { pivot = *mid; } /* start < mid <= end */
        }
        else if(fun(*start, end[-1])) { pivot = *start; *start = *mid; } /*mid <= start < end */
        else if(fun(*mid, end[-1])) { pivot = end[-1]; end[-1] = *start; *start = *mid; } /* mid < end <= start */
        else { pivot = *mid; swap(*start, end[-1]); }  /* end <= mid <= start */
        *mid = end[-2];
        do
        {
            while(fun(*i, pivot)) if(++i >= j) goto partitioned;
            while(fun(pivot, *--j)) if(i >= j) goto partitioned;
            swap(*i, *j);
        }
        while(++i < j);
    partitioned:
        end[-2] = *i;
        *i = pivot;

        if(i-start < end-(i+1))
        {
            quicksort(start, i, fun);
            start = i+1;
        }
        else
        {
            quicksort(i+1, end, fun);
            end = i;
        }
    }

    insertionsort(start, end, fun);
}
// this is just a dummy which will lead to the function above
template<class T, class F>
static inline void quicksort(T *buf, int n, F fun) {
    quicksort(buf, buf+n, fun);
}
// this is just a dummy which will lead to the function above
template<class T>
static inline void quicksort(T *buf, int n) {
    quicksort(buf, buf+n, compareless<T>);
}



/*------------------------------------------------------------------------------------------------------------------*/
// HELPER CODE TO FIND OUT WHETHER A VECTOR TEMPLATE IS A CLASS OR NOT
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/
/* This code is used in vector (e.g.) to find out whether the data type that is maintained is a CLASS OR NOT!
	That code is weird!
*/
template<class T> struct isclass
{
    template<class C> static char test(void (C::*)(void));
    template<class C> static int test(...);
    enum { 
		yes = sizeof(test<T>(0)) == 1 ? 1 : 0, 
		no = yes^1
	};
};



/*------------------------------------------------------------------------------------------------------------------*/
// STATIC INLINE HASTABLE HELPER FUNCTIONS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/
/* Bernstein hash function to make hashtable data unique (?)
	http://www.cse.yorku.ca/~oz/hash.html
*/
static inline uint hthash(const char *key) {
    uint h = 5381;
    for(int i = 0, k; (k = key[i]); i++) h = ((h<<5)+h)^k;    // bernstein k=33 xor
    return h;
}

/* compare two strings
*/
static inline bool htcmp(const char *x, const char *y) {
    return !strcmp(x, y);
}

/* Get access to a key (return the value)
*/
static inline uint hthash(int key) {
    return key;
}

/* Compare two integer values
*/
static inline bool htcmp(int x, int y) {
    return x==y;
}

/* Special code part for STANDALONEs ?
*/
#ifndef STANDALONE
	static inline uint hthash(GLuint key) {
		return key;
	}
	static inline bool htcmp(GLuint x, GLuint y) {
		return x==y;
	}
#endif



/*------------------------------------------------------------------------------------------------------------------*/
// EIHRULS SELFMADE STANDARD TEMPLATE LIBRARIES
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/
/* Equivalent to std::vector
*/
template <class T> struct vector
{
	// minimum vector size is 2^3 = 8
    static const int MINSIZE = 8;

    /* A pointer to the data type that will be maintained
	*/
	T *buf;
	
	/* You should not access these variables directly!
		Use the methods capacity() and length()
		...
		If we had a good class design these two would
		stand under protected or private!
	*/
    int alen; // CAPACITY, use .capacity()
	int ulen; // LENGTH, use .length()



	// CONSTRUCTOR with constructor list
    vector() : buf(NULL), alen(0), ulen(0) {
		// constructor itself does nothing...
    }
	// COPY-CONSTRUCTOR with constructor list
    vector(const vector &v) : buf(NULL), alen(0), ulen(0) {
		// "I AM THIS VECTOR NOW"
        *this = v;
    }
	// vector DESTRUCTOR
    ~vector() { 
		shrink(0); // set size to 0
		if(buf) {
			// free vector memory
			delete[] (uchar *)buf; 
		}
	}


	/* vector<int> a, b;
		a = b;
	*/
    vector<T> &operator=(const vector<T> &v)
    {
        shrink(0);
        if(v.length() > alen) growbuf(v.length());
        loopv(v) add(v[i]);
        return *this;
    }

	/* Add a new slot and object to the vector
		vector<int> phonenumbers;
		int add_this = 911;
		phonenumbers.add(911);
	*/
    T &add(const T &x)
    {
        if(ulen==alen) growbuf(ulen+1);
        new (&buf[ulen]) T(x);
        return buf[ulen++];
    }

	/*Add a new slot (but no object) to the vector
		vector<int> phonenumbers;
		phonenumbers.add(); // add an EMPTY item slot
	*/
    T &add()
    {
        if(ulen==alen) growbuf(ulen+1);
        new (&buf[ulen]) T;
        return buf[ulen++];
    }

	/* Duplicate the last item in the vector
		vector<int> phonenumbers;
		phonenumbers.add(911);	// [0] -> 911
		phonenumbers.dup();		// [0] -> 911, [1] -> 911
	*/
    T &dup()
    {
        if(ulen==alen) growbuf(ulen+1);
        new (&buf[ulen]) T(buf[ulen-1]);
        return buf[ulen++];
    }

	/* Add a fill-vector at the end of the existing vector
		The fill-vector should not be empty. Both vectors must have the same type!

		vector<int> a;			1,2,3,4,5
		vector<int> b;			2,45,2,87,-1
		a.move(b);		
		result:					1,2,3,4,5,2,45,2,87,-1

	*/
    void move(vector<T> &v)
    {
        if(!ulen)
        {	
			/* The current vector is empty but we are filling it with
				a vector hat is not empty. Just take the fill-vector's
				parameters and memory.
			*/			
            swap(buf, v.buf);
            swap(ulen, v.ulen);
            swap(alen, v.alen);
        }
        else
        {
			// Resize the current vector's memory
            growbuf(ulen+v.ulen);
			// copy fill-vector's memory
            if(v.ulen) memcpy(&buf[ulen], (void  *)v.buf, v.ulen*sizeof(T));
			// apply size
            ulen += v.ulen;
			// set the fill-vector's size to 0
            v.ulen = 0;
        }
    }

    /* Methods to check if index is in range or not
		this function is overloaded to support 
		both signed and unsigned integers as indices
	*/
	bool inrange(size_t i) const { 
		return i<size_t(ulen); 
	}
    bool inrange(int i) const { 
		return i>=0 && i<ulen; 
	}


	/* Return the last index of a vector
		Remove the last index of a vector by changing ulen (size)
		the memory will be deleted properly
	*/
    T &pop() { 
		/* please note that ulen is decremented LEFT SIDED which means
			that it will already return the decremented number in this function call
		*/
		return buf[--ulen];
	}
	/* Return the last index of a vector
		WITHOUT dropping the last index
	*/
    T &last() { 
		return buf[ulen-1];
	}
	/* Drop means that the last index will be abandonned.
		It is interesting that the DESTRUCTOR of the last index will be called!
	*/
    void drop() { 
		ulen--; // decrease length
		buf[ulen].~T(); // CALL DESTRUCTOR!
	}


	/*	Is this vector empty or not?
	*/
    bool empty() const { 
		return ulen==0; // are we empty or not?
	}


    /* Return the vector's CAPACITY (the amount of items that COULD BE STORED in it currently) 
	*/
	int capacity() const { 
		return alen; 
	}
	/* Return the vecvtor's LENGTH (the amount of items stored in it)
	*/
    int length() const { 
		return ulen; 
	}

	/* Address operator for auto and const types can be applied to any index
	*/
    T &operator[](int i) { 
		ASSERT(i>=0 && i<ulen); 
		return buf[i]; 
	}
    const T &operator[](int i) const { 
		ASSERT(i >= 0 && i<ulen); 
		return buf[i]; 
	}

	/* Give the memory away to some other code parts that care about it

		IMPORTANT NOTE: VECTOR MEMORY ALLOCATIONS ARE STORED IN THE HEAP AND
		WILL NOT BE RELEASED AUTOMATICLY!
		DO NOT USE THIS FUNCTION UNLESS YOU HAVE TO!
	*/
    void disown() { 
		buf = NULL; // DESTRUCTOR WILL NOT TAKE CARE OF IT
		alen = ulen = 0; 
	}


	/* Shrink ( = decrease size) vector to a certain size
	*/
    void shrink(int i) { 
		ASSERT(i<=ulen); // only if the new size less,equel than the current size it can be called "shrink"
		/* If the data type that is maintained is NOT a class, just change the size
			otherwise call the data type's DESTRUCTOR using the drop() method.
		*/
		if(isclass<T>::no) ulen = i; 
		else while(ulen>i) drop();
	}
    /* Change the vector's size WITHOUT CALLING ANY DESTRUCTORS!
		Please not that this may affects the data type's behaviour!
	*/
	void setsize(int i) { 
		ASSERT(i<=ulen); // make sure the new size is less,equel than the current size
		ulen = i; // change the vector's length
	}

    
	/* As long as the vector is not empty,
		get a pointer to the last index using the pop method()
		and delete the memory
	*/
	void deletecontents() { 
		while(!empty()) {
			delete pop();
		}
	}
	/* As long as the vector is not empty,
		get a pointer to the last index using the pop() method
		and delete the arrays
	*/
    void deletearrays() { 
		while(!empty()) {
			delete[] pop();
		}
	}

	
	/* Method to get access to the main data type pointer T* buf;
		In a valid C++ class concept, this buf would be protected/private!
		You should use these methods instead of accessing it directly!
	*/
    T *getbuf() { 
		return buf; 
	}
	/* Get access to the buffer as constant data type */
    const T *getbuf() const { 
		return buf; 
	}


	/* Check if buffer E is greater,equal than buffer BUF
		and if E is smaller than BUF
		[THIS METHOD IS NOT USED IN THE WHOLE CODE]
	*/
    bool inbuf(const T *e) const { 
		return e >= buf && e < &buf[ulen]; 
	}


	/* Sorting implementations
	*/
    template<class F>
    void sort(F fun, int i = 0, int n = -1) {
		// call quicksort template
		/* Standard data types cam be compared very easily
			More advanced types have OPERATORS to compare two values
		*/
        quicksort(&buf[i], n < 0 ? ulen-i : n, fun);
    }
	// this is a dummy method that will lead to the function above
    void sort() { 
		sort(compareless<T>); 
	}


	/* Shuffle the vector 
		EXAMPLE:
		before shuffle:	1 2 3 4 5 6 7 8 9
		after shuffle:	9 2 1 3 8 4 6 5 7
	*/
    void shuffle() {
    	extern uint randomMT();
    	for(int i = 0; i < ulen; i++){
    		int indx = rnd(ulen);
    		T temp = buf[i];
    		buf[i] = buf[indx];
    		buf[indx] = temp;
    	}
    }


	/* Change the data buffer's size
		and re-allocate memory
	*/
    void growbuf(int sz)
    {
        int olen = alen;
        if(!alen) alen = max(MINSIZE, sz);
        else while(alen < sz) alen *= 2;
        if(alen <= olen) return;
        uchar *newbuf = new uchar[alen*sizeof(T)];
        if(olen > 0)
        {
            memcpy(newbuf, (void *)buf, olen*sizeof(T));
            delete[] (uchar *)buf;
        }
        buf = (T *)newbuf;
    }

	/* Add some memory slots to the vector and return the
		additional slots as databuf 
	*/
    databuf<T> reserve(int sz)
    {
        if(ulen+sz > alen) {
			/* Re-allocate some memory if the amount of memory 
				to reserve exceedes the vector's capacity 
			*/
			growbuf(ulen+sz);
        }
		return databuf<T>(&buf[ulen], sz);
    }

	/* Change the vector's length without allocating new memory
	*/
    void advance(int sz) {
        ulen += sz;
    }

	/* Change the vector's size by the size of a data buffer
	*/
    void addbuf(const databuf<T> &p) {
		// call advance method to resize vector length
        advance(p.length());
    }
	
	/* Change the vector's length and allocate new memory
		return the new memory area as buffer
	*/
    T *pad(int n)
    {
        T *buf = reserve(n).buf;
        advance(n);
        return buf;
    }

	/* The methods put and add to the same!
	*/
    void put(const T &v) { 
		add(v); // calls "add" method
	}

	/* 
	*/
    void put(const T *v, int n)
    {
        databuf<T> buf = reserve(n);
        buf.put(v, n);
        addbuf(buf);
    }
	

	/* Remove a range of indices
		All the indices after the index which is removed will come a step closer
		All the indices in the range will be deleted
	*/
    void remove(int i, int n)
	{
		/*  123456789abcdefghijklmnopqrstuvwxyz
			remove(5, 4)
			1289abcdefghijklmnopqrstuvwxyz
			removed: 34567
		*/
		// push memory
        for(int p = i+n; p<ulen; p++) buf[p-n] = buf[p];
        ulen -= n; // shrink vector's length by range size
    }
	/* Remove one single index and return the removed index as a 
		data type
	*/
    T remove(int i)
    {
        T e = buf[i];
		// push memory 
        for(int p = i+1; p<ulen; p++) buf[p-1] = buf[p];
        ulen--; // decrement vector's size because we only remove 1 index
        return e;
    }
	/* Removes one single index and uses the last index to replace
		the removed index

		123456789abcdefghijklmnopqrstuvwxyz
		remove(15)
		123456789abcdefzhijklmnopqrstuvwxy
		removed: 'g'  (please note that 'z' takes its place)
	*/
    T removeunordered(int i)
    {
        T e = buf[i];
        ulen--;
		// if buffer is not empty, take last index as removed index
        if(ulen>0) buf[i] = buf[ulen];
        return e;
    }

	/* Find an index (the first occurance) in a vector
		Comparing operations in classes are based on operator implementations!
	*/
    template<class U>
    int find(const U &o)
    {
        //loopi(ulen) if(buf[i]==o) return i;
		/* Death to loop macros
		*/
		for(int index = 0; index < ulen; index++) {
			// if we find it, return it
			if(buf[index]==o) return index;
		}
		// no index found: return invalid index
        return -1;
    }
	/* Loop through all indices of a vector
		and remove all appearances of this value
	*/
    void removeobj(const T &o)
    {
        //loopi(ulen) if(buf[i]==o) remove(i--);
		for(int index = 0; index < ulen; index++) {
			if(buf[index]==o) remove(index--);
		}
    }
	/* Loop through a vector and replace all appearances
		with the last index (which wont be abanconned/changed until the end)
	*/
    void replacewithlast(const T &o)
    {
        if(!ulen) return;
		for(int index = 0; index < ulen-1; index++) {
			if(buf[i]==o) {
				buf[i] = buf[ulen-1];
			}
		}
        ulen--;
    }


	/* Insert a data type into a vector in a certain position
	*/
    T &insert(int i, const T &e)
    {
		// add additional memory slot
        add(T());
		// push memory
        for(int p = ulen-1; p>i; p--) buf[p] = buf[p-1];
		// copy value
        buf[i] = e;
		// return input value
        return buf[i];
    }
	/* Insert a data type into a vector SEVERAL TIMES
	*/
    T *insert(int i, const T *e, int n)
    {
		// reallocate vector memory
        if(ulen+n>alen) growbuf(ulen+n);
		// add memory slots
        for(int added_times = 0; added_times < n; added_times++) add(T());
        // push existing objects forward
		for(int p = ulen-1; p>=i+n; p--) buf[p] = buf[p-n];
		// insert new object [n] times
        for(int copied = 0; copied < n; copied++) buf[i+copied] = e[copied];
		// return added items as array
        return &buf[i];
    }


	/* Reverse buffer
		1 2 3 4 5 6 7 8 9
		reverse();
		9 8 7 6 5 4 3 2 1 
	*/
    void reverse() {
        loopi(ulen/2) swap(buf[i], buf[ulen-1-i]);
    }

    static int heapparent(int i) { return (i - 1) >> 1; }
    static int heapchild(int i) { return (i << 1) + 1; }

    void buildheap() {
        for(int i = ulen/2; i >= 0; i--) downheap(i);
    }

    int upheap(int i)
    {
        float score = heapscore(buf[i]);
        while(i > 0)
        {
            int pi = heapparent(i);
            if(score >= heapscore(buf[pi])) break;
            swap(buf[i], buf[pi]);
            i = pi;
        }
        return i;
    }

    T &addheap(const T &x)
    {
        add(x);
        return buf[upheap(ulen-1)];
    }

    int downheap(int i)
    {
        float score = heapscore(buf[i]);
        for(;;)
        {
            int ci = heapchild(i);
            if(ci >= ulen) break;
            float cscore = heapscore(buf[ci]);
            if(score > cscore)
            {
               if(ci+1 < ulen && heapscore(buf[ci+1]) < cscore) { swap(buf[ci+1], buf[i]); i = ci+1; }
               else { swap(buf[ci], buf[i]); i = ci; }
            }
            else if(ci+1 < ulen && heapscore(buf[ci+1]) < score) { swap(buf[ci+1], buf[i]); i = ci+1; }
            else break;
        }
        return i;
    }

    T removeheap()
    {
        T e = removeunordered(0);
        if(ulen) downheap(0);
        return e;
    }

    template<class K> 
    int htfind(const K &key)
    {
        loopi(ulen) if(htcmp(key, buf[i])) return i;
        return -1;
    }
};

/* Equivalent to std::map
*/
template<class T> struct hashset
{
	/* Type definitions for template lements
	*/
    typedef T elem;
    typedef const T const_elem;

	// Set Chunk size to 64 (no other option available)
    enum { CHUNKSIZE = 64 };

	/* One-side chain structure
	    with pointer to the next element
	*/
    struct chain { 
		T elem; 
		// pointer to the next index
		chain *next; 
	};

	// chain chunk structure
    struct chainchunk { 
		// array of chains [64]
		chain chains[CHUNKSIZE];
		// pointer to the next chain chunk
		chainchunk *next; 
	};

    int size;
    int numelems;
    chain **chains;

    chainchunk *chunks;
    chain *unused;


	/* Constructor with constructor list
	*/
    hashset(int size = 1<<10) : size(size) {
        numelems = 0;
        chunks = NULL;
        unused = NULL;
        chains = new chain *[size];
        loopi(size) chains[i] = NULL;
    }
	/* Destructor
	*/
    ~hashset() {
		// relase chains safely
        DELETEA(chains);
        deletechunks();
    }

    chain *insert(uint h)
    {
        if(!unused)
        {
            chainchunk *chunk = new chainchunk;
            chunk->next = chunks;
            chunks = chunk;
            loopi(CHUNKSIZE-1) chunk->chains[i].next = &chunk->chains[i+1];
            chunk->chains[CHUNKSIZE-1].next = unused;
            unused = chunk->chains;
        }
        chain *c = unused;
        unused = unused->next;
        c->next = chains[h];
        chains[h] = c;
        numelems++;
        return c;
    }

    #define HTFIND(key, success, fail) \
        uint h = hthash(key)&(this->size-1); \
        for(chain *c = this->chains[h]; c; c = c->next) \
        { \
            if(htcmp(key, c->elem)) return (success); \
        } \
        return (fail);

    template<class K>
    T *access(const K &key)
    {
        HTFIND(key, &c->elem, NULL);
    }

    template<class K, class E>
    T &access(const K &key, const E &elem)
    {
        HTFIND(key, c->elem, insert(h)->elem = elem);
    }

    template<class K>
    T &operator[](const K &key)
    {
        HTFIND(key, c->elem, insert(h)->elem);
    }

    template<class K>
    T &find(const K &key, T &notfound)
    {
        HTFIND(key, c->elem, notfound);
    }

    template<class K>
    const T &find(const K &key, const T &notfound)
    {
        HTFIND(key, c->elem, notfound);
    }

    template<class K>
    bool remove(const K &key)
    {
        uint h = hthash(key)&(size-1);
        for(chain **p = &chains[h], *c = chains[h]; c; p = &c->next, c = c->next)
        {
            if(htcmp(key, c->elem))
            {
                *p = c->next;
                c->elem.~T();
                new (&c->elem) T;
                c->next = unused;
                unused = c;
                numelems--;
                return true;
            }
        }
        return false;
    }

    void deletechunks()
    {
        for(chainchunk *nextchunk; chunks; chunks = nextchunk)
        {
            nextchunk = chunks->next;
            delete chunks;
        }
    }

    void clear()
    {
        if(!numelems) return;
        loopi(size) chains[i] = NULL;
        numelems = 0;
        unused = NULL;
        deletechunks();
    }

    static inline chain *getnext(void *i) { return ((chain *)i)->next; }
    static inline T &getdata(void *i) { return ((chain *)i)->elem; }
};

template<class K, class T> struct hashtableentry
{
    K key;
    T data;

    hashtableentry() {}
    hashtableentry(const K &key, const T &data) : key(key), data(data) {}
};

template<class U, class K, class T>
static inline bool htcmp(const U *x, const hashtableentry<K, T> &y)
{
    return htcmp(x, y.key);
}

template<class U, class K, class T>
static inline bool htcmp(const U &x, const hashtableentry<K, T> &y)
{
    return htcmp(x, y.key);
}

template<class K, class T> struct hashtable : hashset<hashtableentry<K, T> >
{
    typedef hashtableentry<K, T> entry;
    typedef struct hashset<entry>::chain chain;
    typedef K key;
    typedef T value;

    hashtable(int size = 1<<10) : hashset<entry>(size) {}

    entry &insert(const K &key, uint h)
    {
        chain *c = hashset<entry>::insert(h);
        c->elem.key = key;
        return c->elem;
    }

    T *access(const K &key)
    {
        HTFIND(key, &c->elem.data, NULL);
    }

    T &access(const K &key, const T &data)
    {
        HTFIND(key, c->elem.data, insert(key, h).data = data);
    }

    T &operator[](const K &key)
    {
        HTFIND(key, c->elem.data, insert(key, h).data);
    }

    T &find(const K &key, T &notfound)
    {
        HTFIND(key, c->elem.data, notfound);
    }

    const T &find(const K &key, const T &notfound)
    {
        HTFIND(key, c->elem.data, notfound);
    }   

    static inline chain *getnext(void *i) { return ((chain *)i)->next; }
    static inline K &getkey(void *i) { return ((chain *)i)->elem.key; }
    static inline T &getdata(void *i) { return ((chain *)i)->elem.data; }
};

#define enumerates(ht,t,e,b)      loopi((ht).size)  for(hashset<t>::chain *enumc = (ht).chains[i]; enumc;) { t &e = enumc->elem; enumc = enumc->next; b; }
#define enumeratekt(ht,k,e,t,f,b) loopi((ht).size)  for(hashtable<k,t>::chain *enumc = (ht).chains[i]; enumc;) { const hashtable<k,t>::key &e = enumc->elem.key; t &f = enumc->elem.data; enumc = enumc->next; b; }
#define enumerate(ht,t,e,b)       loopi((ht).size) for(void *enumc = (ht).chains[i]; enumc;) { t &e = (ht).getdata(enumc); enumc = (ht).getnext(enumc); b; }

struct unionfind
{
    struct ufval
    {
        int rank, next;

        ufval() : rank(0), next(-1) {}
    };

    vector<ufval> ufvals;

    int find(int k)
    {
        if(k>=ufvals.length()) return k;
        while(ufvals[k].next>=0) k = ufvals[k].next;
        return k;
    }

    int compressfind(int k)
    {
        if(ufvals[k].next<0) return k;
        return ufvals[k].next = compressfind(ufvals[k].next);
    }

    void unite (int x, int y)
    {
        while(ufvals.length() <= max(x, y)) ufvals.add();
        x = compressfind(x);
        y = compressfind(y);
        if(x==y) return;
        ufval &xval = ufvals[x], &yval = ufvals[y];
        if(xval.rank < yval.rank) xval.next = y;
        else
        {
            yval.next = x;
            if(xval.rank==yval.rank) yval.rank++;
        }
    }
};

template <class T, int SIZE> struct queue
{
    int head, tail, len;
    T data[SIZE];

    queue() { clear(); }

    void clear() { head = tail = len = 0; }

    int length() const { return len; }
    bool empty() const { return !len; }
    bool full() const { return len == SIZE; }

    bool inrange(size_t i) const { return i<size_t(len); }
    bool inrange(int i) const { return i>=0 && i<len; }

    T &added() { return data[tail > 0 ? tail-1 : SIZE-1]; }
    T &added(int offset) { return data[tail-offset > 0 ? tail-offset-1 : tail-offset-1 + SIZE]; }
    T &adding() { return data[tail]; }
    T &adding(int offset) { return data[tail+offset >= SIZE ? tail+offset - SIZE : tail+offset]; }
    T &add()
    {
        T &t = data[tail];
        tail++;
        if(tail >= SIZE) tail -= SIZE;
        if(len < SIZE) len++;
        return t;
    }
    T &add(const T &e) { return add() = e; }

    T &pop()
    {
        tail--;
        if(tail < 0) tail += SIZE;
        len--;
        return data[tail];
    }

    T &removing() { return data[head]; }
    T &removing(int offset) { return data[head+offset >= SIZE ? head+offset - SIZE : head+offset]; }
    T &remove()
    {
        T &t = data[head];
        head++;
        if(head >= SIZE) head -= SIZE;
        len--; 
        return t;
    }

    T &operator[](int offset) { return removing(offset); }
    const T &operator[](int offset) const { return removing(offset); }
};

template <class T, int SIZE> struct reversequeue : queue<T, SIZE>
{
    T &operator[](int offset) { return queue<T, SIZE>::added(offset); }
    const T &operator[](int offset) const { return queue<T, SIZE>::added(offset); }
};

inline char *newstring(size_t l)                { return new char[l+1]; }
inline char *newstring(const char *s, size_t l) { return copystring(newstring(l), s, l+1); }
inline char *newstring(const char *s)           { return newstring(s, strlen(s));          }
inline char *newstringbuf(const char *s)        { return newstring(s, MAXSTRLEN-1);       }

const int islittleendian = 1;



#ifdef SDL_BYTEORDER
	#define endianswap16 SDL_Swap16
	#define endianswap32 SDL_Swap32
	#define endianswap64 SDL_Swap64
#else
	inline ushort endianswap16(ushort n) { return (n<<8) | (n>>8); }
	inline uint endianswap32(uint n) { return (n<<24) | (n>>24) | ((n>>8)&0xFF00) | ((n<<8)&0xFF0000); }
	inline ullong endianswap64(ullong n) { return endianswap32(uint(n >> 32)) | ((ullong)endianswap32(uint(n)) << 32); }
#endif




template<class T> inline T endianswap(T n) { union { T t; uint i; } conv; conv.t = n; conv.i = endianswap32(conv.i); return conv.t; }
template<> inline ushort endianswap<ushort>(ushort n) { return endianswap16(n); }
template<> inline short endianswap<short>(short n) { return endianswap16(n); }
template<> inline uint endianswap<uint>(uint n) { return endianswap32(n); }
template<> inline int endianswap<int>(int n) { return endianswap32(n); }
template<> inline ullong endianswap<ullong>(ullong n) { return endianswap64(n); }
template<> inline llong endianswap<llong>(llong n) { return endianswap64(n); }
template<> inline double endianswap<double>(double n) { union { double t; uint i; } conv; conv.t = n; conv.i = endianswap64(conv.i); return conv.t; }
template<class T> inline void endianswap(T *buf, int len) { for(T *end = &buf[len]; buf < end; buf++) *buf = endianswap(*buf); }
template<class T> inline T endiansame(T n) { return n; }
template<class T> inline void endiansame(T *buf, int len) {}




#ifdef SDL_BYTEORDER
	#if SDL_BYTEORDER == SDL_LIL_ENDIAN
		#define lilswap endiansame
		#define bigswap endianswap
	#else
		#define lilswap endianswap
		#define bigswap endiansame
	#endif
#else
	template<class T> inline T lilswap(T n) { return *(const uchar *)&islittleendian ? n : endianswap(n); }
	template<class T> inline void lilswap(T *buf, int len) { if(!*(const uchar *)&islittleendian) endianswap(buf, len); }
	template<class T> inline T bigswap(T n) { return *(const uchar *)&islittleendian ? endianswap(n) : n; }
	template<class T> inline void bigswap(T *buf, int len) { if(*(const uchar *)&islittleendian) endianswap(buf, len); }
#endif



/* workaround for some C platforms that have these two functions as macros - not used anywhere */
#ifdef getchar
	#undef getchar
#endif
#ifdef putchar
	#undef putchar
#endif




struct stream
{
	/*
	*/
	#ifdef WIN32
		#ifdef __GNUC__
			typedef off64_t offset;
		#else
			typedef __int64 offset;
		#endif
	#else
		typedef off_t offset;
	#endif


    virtual ~stream() {}
    virtual void close() = 0;
    virtual bool end() = 0;
    virtual offset tell() { return -1; }
    virtual offset rawtell() { return tell(); }
    virtual bool seek(offset pos, int whence = SEEK_SET) { return false; }
    virtual offset size();
    virtual offset rawsize() { return size(); }
    virtual int read(void *buf, int len) { return 0; }
    virtual int write(const void *buf, int len) { return 0; }
    virtual int getchar() { uchar c; return read(&c, 1) == 1 ? c : -1; }
    virtual bool putchar(int n) { uchar c = n; return write(&c, 1) == 1; }
    virtual bool getline(char *str, int len);
    virtual bool putstring(const char *str) { int len = (int)strlen(str); return write(str, len) == len; }
    virtual bool putline(const char *str) { return putstring(str) && putchar('\n'); }
    virtual int printf(const char *fmt, ...) PRINTFARGS(2, 3);
    virtual uint getcrc() { return 0; }

    template<class T> int put(const T *v, int n) { return write(v, n*sizeof(T))/sizeof(T); } 
    template<class T> bool put(T n) { return write(&n, sizeof(n)) == sizeof(n); }
    template<class T> bool putlil(T n) { return put<T>(lilswap(n)); }
    template<class T> bool putbig(T n) { return put<T>(bigswap(n)); }

    template<class T> int get(T *v, int n) { return read(v, n*sizeof(T))/sizeof(T); }
    template<class T> T get() { T n; return read(&n, sizeof(n)) == sizeof(n) ? n : 0; }
    template<class T> T getlil() { return lilswap(get<T>()); }
    template<class T> T getbig() { return bigswap(get<T>()); }

#ifndef STANDALONE
    SDL_RWops *rwops();
#endif
};

template<class T>
struct streambuf
{
    stream *s;

    streambuf(stream *s) : s(s) {}
    
    T get() { return s->get<T>(); }
    int get(T *vals, int numvals) { return s->get(vals, numvals); }
    void put(const T &val) { s->put(&val, 1); }
    void put(const T *vals, int numvals) { s->put(vals, numvals); } 
    int length() { return s->size(); }
};

enum
{
    CT_PRINT   = 1<<0,
    CT_SPACE   = 1<<1,
    CT_DIGIT   = 1<<2,
    CT_ALPHA   = 1<<3,
    CT_LOWER   = 1<<4,
    CT_UPPER   = 1<<5,
    CT_UNICODE = 1<<6
};
extern const uchar cubectype[256];
static inline int iscubeprint(uchar c) { return cubectype[c]&CT_PRINT; }
static inline int iscubespace(uchar c) { return cubectype[c]&CT_SPACE; }
static inline int iscubealpha(uchar c) { return cubectype[c]&CT_ALPHA; }
static inline int iscubealnum(uchar c) { return cubectype[c]&(CT_ALPHA|CT_DIGIT); }
static inline int iscubelower(uchar c) { return cubectype[c]&CT_LOWER; }
static inline int iscubeupper(uchar c) { return cubectype[c]&CT_UPPER; }






/*------------------------------------------------------------------------------------------------------------------*/
// CUBE INFORMATION CODE -> UNICODE CONVERSION TOOLS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/
/* Convert from Cube to Unichar
*/
static inline int cube2uni(uchar c) { 
    extern const int cube2unichars[256]; 
    return cube2unichars[c]; 
}
/* Convert from Unichar to Cube2
*/
static inline uchar uni2cube(int c) {
    extern const int uni2cubeoffsets[8];
    extern const uchar uni2cubechars[];
    return uint(c) <= 0x7FF ? uni2cubechars[uni2cubeoffsets[c>>8] + (c&0xFF)] : 0;
}






/*------------------------------------------------------------------------------------------------------------------*/
// EXTERN DEFINITIONS FOR FUNCTIONS
// 
// 
/*------------------------------------------------------------------------------------------------------------------*/
/* UTF-8 encoding/decoding function declaration
*/
extern int decodeutf8(uchar *dst, int dstlen, const uchar *src, int srclen, int *carry = NULL);
extern int encodeutf8(uchar *dstbuf, int dstlen, const uchar *srcbuf, int srclen, int *carry = NULL);

/* common useful functions
*/
extern char *makerelpath(const char *dir, const char *file, const char *prefix = NULL, const char *cmd = NULL);
extern char *path(char *s);
extern char *path(const char *s, bool copy);
extern const char *parentdir(const char *directory);
extern bool fileexists(const char *path, const char *mode);
extern bool createdir(const char *path);
extern size_t fixpackagedir(char *dir);
extern const char *sethomedir(const char *dir);
extern const char *addpackagedir(const char *dir);
extern const char *findfile(const char *filename, const char *mode);
extern stream *openrawfile(const char *filename, const char *mode);
extern stream *openzipfile(const char *filename, const char *mode);
extern stream *openfile(const char *filename, const char *mode);
extern stream *opentempfile(const char *filename, const char *mode);
extern stream *opengzfile(const char *filename, const char *mode, stream *file = NULL, int level = Z_BEST_COMPRESSION);
extern stream *openutf8file(const char *filename, const char *mode, stream *file = NULL);
extern char *loadfile(const char *fn, int *size, bool utf8 = true);
extern void sortfiles(vector<char *> &files);
extern bool listdir(const char *dir, bool rel, const char *ext, vector<char *> &files);
extern int listfiles(const char *dir, const char *ext, vector<char *> &files);
extern int listzipfiles(const char *dir, const char *ext, vector<char *> &files);
extern void seedMT(uint seed);
extern uint randomMT();
extern int guessnumcpus();

/* network code
*/
extern void putint(ucharbuf &p, int n);
extern void putint(packetbuf &p, int n);
extern void putint(vector<uchar> &p, int n);
extern int getint(ucharbuf &p);
extern void putuint(ucharbuf &p, int n);
extern void putuint(packetbuf &p, int n);
extern void putuint(vector<uchar> &p, int n);
extern int getuint(ucharbuf &p);
extern void putfloat(ucharbuf &p, float f);
extern void putfloat(packetbuf &p, float f);
extern void putfloat(vector<uchar> &p, float f);
extern float getfloat(ucharbuf &p);
extern void sendstring(const char *t, ucharbuf &p);
extern void sendstring(const char *t, packetbuf &p);
extern void sendstring(const char *t, vector<uchar> &p);
extern void getstring(char *t, ucharbuf &p, int len);
template<size_t N> static inline void getstring(char (&t)[N], ucharbuf &p) { getstring(t, p, int(N)); }
extern void filtertext(char *dst, const char *src, bool whitespace = true, int len = sizeof(string)-1);


// -----------------------------------------------------------------------------------------------------------------------------------------------------

/* end of include guard block:
	#ifndef _TOOLS_H
*/
#endif 