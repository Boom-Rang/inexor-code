// world.h
// contains general enumerations and structure 
// to describe world, map format and enviroment
// 
// 
// 

// bump if map format changes, see worldio.cpp last sauerbraten-one was 33
#define MAPVERSION 40

// constant macros to describe visual appearance of game world
#define WATER_AMPLITUDE 0.4f
#define WATER_OFFSET 1.1f
#define TEX_SCALE 8.0f

// hardcoded texture numbers
enum
{
    DEFAULT_SKY = 0,
    DEFAULT_GEOM
};

// octree header structure
struct octaheader
{
    char magic[4];              // "OCTA"
    int version;                // any >8bit quantity is little endian
    int headersize;             // sizeof(header)
    int worldsize;
    int numents;
    int numpvs;
    int lightmaps;
    int blendmap;
    int numvars;
    int numvslots;
};

// map file format header
// all cube engine based games use the OGZ file format
// OGZ files are zipped. see specification here:
// http://incoherency.co.uk/interest/sauer_map.html
struct compatheader             
{
    char magic[4];              // "OCTA"
    int version;                // any >8bit quantity is little endian
    int headersize;             // sizeof(header)
    int worldsize;
    int numents;
    int numpvs;
    int lightmaps;
    int lightprecision, lighterror, lightlod;
    uchar ambient;
    uchar watercolour[3];
    uchar blendmap;
    uchar lerpangle, lerpsubdiv, lerpsubdivsize;
    uchar bumperror;
    uchar skylight[3];
    uchar lavacolour[3];
    uchar waterfallcolour[3];
    uchar reserved[10];
    char maptitle[128];
};

// enumeration for material visibility
enum 
{ 
    MATSURF_NOT_VISIBLE = 0,
    MATSURF_VISIBLE,
    MATSURF_EDIT_ONLY
};

// reduced vertex structure (no tangent vector)
struct vertexff 
{
	vec pos;		// vertex position
	bvec4 norm;		// normal vector of this vertex
	float u, v;		// UV coordinates
	float lmu, lmv; // light map UV coordinates
};

// Inexor's vertex structure
struct vertex 
{
	vec pos;		// vertex position
	bvec4 norm;		// normal vector
	float u, v;		// UV coordinates
	short lmu, lmv;	// light map UV coordinates
	bvec4 tangent;	// tangents (for skinning/animation ?)
};
 
 // 
#define VTXSIZE (renderpath==R_FIXEDFUNCTION ? sizeof(vertexff) : sizeof(vertex))

