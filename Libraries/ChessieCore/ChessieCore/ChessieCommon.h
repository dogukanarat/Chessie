#ifndef INCLUDED_CHESSIECOMMON_H
#define INCLUDED_CHESSIECOMMON_H

#include <cstdint>

typedef uint8_t CUINT8;
typedef uint16_t CUINT16;
typedef uint32_t CUINT32;
typedef uint64_t CUINT64;
typedef int8_t CINT8;
typedef int16_t CINT16;
typedef int32_t CINT32;
typedef int64_t CINT64;
typedef float CREAL32;
typedef double CREAL64;
typedef CUINT8 CBOOL;
typedef CUINT32 CSIZE;

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef CHESSIE_EXPECT
#include <assert.h>
#define CHESSIE_EXPECT(A) assert(A);
#endif

#ifndef CHESSIE_NO_IMPLEMENTATION
#define CHESSIE_NO_IMPLEMENTATION 
#endif

#ifndef CHESSIE_UNUSED_PARAMETER
#define CHESSIE_UNUSED_PARAMETER(A) (void)(A);
#endif

namespace Chessie
{
    typedef void Void;
    typedef Void* VoidPointer;
    typedef const Void* ConstVoidPointer;
    typedef CUINT8 Byte;
    typedef Byte* BytePointer;
    typedef CSIZE Size;
    typedef char Char;
    typedef Char* CharPointer;
    
}

#endif // INCLUDED_CHESSIECOMMON_H