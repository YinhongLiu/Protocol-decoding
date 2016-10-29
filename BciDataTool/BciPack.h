#ifndef _BCI_PACK_H_
#define _BCI_PACK_H_

#ifdef __cplusplus
extern "C" {
#endif
_declspec(dllexport) void   InitBcipack(void);
_declspec(dllexport) int    UnpackBciData(unsigned char d);
#ifdef __cplusplus
}
#endif

#endif
