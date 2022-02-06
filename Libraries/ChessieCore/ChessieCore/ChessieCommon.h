#ifndef INCLUDED_CHESSIECOMMON_H
#define INCLUDED_CHESSIECOMMON_H

#include <cstdint>

typedef uint8_t UInt8;
typedef uint16_t UInt16;
typedef uint32_t UInt32;
typedef uint64_t UInt64;
typedef int8_t Int8;
typedef int16_t CInt16;
typedef int32_t Int32;
typedef int64_t Int64;
typedef float Real32;
typedef double Real64;
typedef UInt8 Bool;
typedef UInt32 Size;

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
    typedef UInt8 Byte;
    typedef Byte* BytePointer;
    typedef char Char;
    typedef Char* CharPointer;
}

#endif // INCLUDED_CHESSIECOMMON_H