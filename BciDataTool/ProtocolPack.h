#ifndef _PROTOCOL_PACK_H_
#define _PROTOCOL_PACK_H_

//Protocol rules: (HEAD/Status)+Red(0-7)+Red(8-16)+Red(17-23)+InfraRed(0-7)+InfraRed(8-16)+InfraRed(17-23)
//Sync_bit 0
typedef enum
{
	Var_RedWave,
	Var_InfraRedWave,
	Var_Debug_Status,
	Var_Total_Num
}VarType;

#ifdef __cplusplus
extern "C" {
#endif
	__declspec(dllexport) void InitWavePack(void);
	__declspec(dllexport) void PackWaveData(int RedWave,int InfraRed, unsigned char Status, unsigned char* pPack);
	__declspec(dllexport) int UnpackWaveData(unsigned char d);//return !0 if right pack
	__declspec(dllexport) int GetPackData(unsigned char type);
#ifdef __cplusplus
}
#endif


#endif