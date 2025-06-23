#ifndef VAR_TYPE_H
#define VAR_TYPE_H

typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_CHAR, TYPE_BOOL, TYPE_VOID, TYPE_POINTER, TYPE_UNKNOWN } VarType;

char* typeToString(VarType type);

#endif // VAR_TYPE_H