#ifndef INCLUDED_CHESSIECOMMON_H
#define INCLUDED_CHESSIECOMMON_H

typedef unsigned char CUINT8;
typedef unsigned short CUINT16;
typedef unsigned int CUINT32;
typedef unsigned long CUINT64;
typedef signed char CINT8;
typedef signed short CINT16;
typedef signed int CINT32;
typedef signed long CINT64;
typedef float CREAL32;
typedef double CREAL64;
typedef CUINT8 CBOOL;
typedef CUINT32 CSIZE;

#ifndef NULL
#define NULL 0
#endif

#ifndef C_NO_IMPLEMENTATION
#define C_NO_IMPLEMENTATION 
#endif

#ifndef C_UNUSED_PARAMETER˚
#define C_UNUSED_PARAMETER(A) (void)(A);
#endif

namespace Chessie
{
    typedef void Void;
    typedef void* VoidPointer;
    
}

#endif // INCLUDED_CHESSIECOMMON_H