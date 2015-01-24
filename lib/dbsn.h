#ifndef dllDbsnH
#define dllDbsnH
//#include <iostream.h>
//#include <fstream.h>
#include <io.h>
using namespace std;

#define     REC_DELETED      1
#define     OUT_OF_RANGE     2
#define     DBN_IS_EMPTY     4
#define     REC_EMPTY        8
#define     BAD_SUBSTNUMBER  16

#define     FATAL_ERROR      256
#define     BAD_PTR          256
#define     BAD_NUMBER       512
#define     DBS_NOT_EXIST    1024
#define     DBN_NOT_EXIST    2048
#define     BUFFER_SMALL     4096
#define     BAD_TABLE_NAME   8192
#define     BAD_TABLE_HANDLE 16384
#define     DBR_NOT_EXIST    32768

#define     ALL_FRAGM 0
#define     ACTIVE_FRAGM 1
#define     ALL_BACK 2
#define     ACTIVE_BACK 3


/*
typedef  unsigned int  uint;
typedef  unsigned long  ulong;

#define hndlEmpty	 0x80000000     //- ������������ ������ ������
#define notEdit		 0x40000000     //- �� �������� ������
#define notInsCut	 0x20000000     //- �� ��������� � �� �������� ����
#define notAppend	 0x10000000     //- �� ���������
#define notModify	 0x70000000     //- �� �������� ������
#define notView 	 0x08000000     //- �� ���������� �� ������

#define SpStrHead    0x74532553     //  S%St
#define SpBinHead    0x6E422553     //  S%Bn
#define SpSpHead     0x70532553     //  S%Sp
#define SpFnHead     0x6E462553     //  S%Fn


const   LOCAL_LINK     = 1;   //-- ������� ������ �� ���������� ���������
const   FILE_LINK      = 2;   //-- ������� ������ �� ����
const   DIR_LINK = 3;   //-- ������� ������ �� �������
const   FILEDBS_LINK   = 4;   //-- ������� ������ �� ���� ���� ����������
const   FRAGMENT_LINK  = 5;   //-- ������� ������ �� ��������

extern "C" int    __declspec(impexp) __stdcall
	SpadSbsLen(  spad* pSpad, int  NomSubst);

extern "C" int    __declspec(impexp)  __stdcall 
	SubstCount(char* pc = 0);


*/

#ifdef DBSNEXPORT
	#define		impexp	dllexport
#else
	#define		impexp	dllimport
#endif


#include <string>
#include <stdio.h>

//---------------------------------------------------------------------------

//-- ������� ������ ������ ����� �����
extern "C" int    __declspec(impexp) __stdcall   getLongArray( int count );

//-- �������� 2 ������ � ������ �������� � ������������� ��������
extern "C" long    __declspec(impexp) __stdcall    compSpec( char* pc, char* pc1);

//-- ��������� ����� ������
extern "C" int    __declspec(impexp) __stdcall    getLen( char* pc);

//-- ��������� ����� �������� � ������
extern "C" int    __declspec(impexp) __stdcall    substCount( char* pc);

//-- �������� ��������� � �������� ������� �� ������
extern "C" int    __declspec(impexp) __stdcall  getSubst(char* pc, char* pcbuf, int buf_sze, int nom_sub);

//== �������� ��������� � ������ �����
extern "C" int    __declspec(impexp) __stdcall
    addSubst(char* pc, char* pcres, int res_size, char* pcsubst);

//== �������� ��������� � ������ ����� ������
extern "C" int    __declspec(impexp) __stdcall
    insSubst(char* pc, char* pcres, int res_size, int nom_sub, char* pcsubst);

//== �������� ����� ���������
extern "C" int    __declspec(impexp) __stdcall
    substLen(char* pc, int nom_sub );

//-- �������� ��������� �� ����� �������� � ������ ����� ������
extern "C" int    __declspec(impexp) __stdcall
	setSubst(char* pc, char* pcres, int res_size, int nom_sub, char* pcsubst);

//-- �������� ��������� (�������� �� ������ �������� )
extern "C" int    __declspec(impexp) __stdcall
    clearSubst(char* pc, int nom_sub );

//-- ��������� ������� ���������
extern "C" int    __declspec(impexp) __stdcall
    cutSubst(char* pc, int nom_sub );

//-- ������� ��� ��������� ����� �������
extern "C" int    __declspec(impexp) __stdcall
    cutLeft(char* pc, int nom_sub );

//-- ������� ��� ��������� ������� � �������
extern "C" int    __declspec(impexp) __stdcall
    cutRight(char* pc, int nom_sub );

//-- ���������� ��������� � ����������
extern "C" int    __declspec(impexp) __stdcall
    uniteSubst(char* pc, int nom_sub );




//==  �������� ��������� ������ ������( ���������)
extern "C" int    __declspec(impexp) __stdcall  getTextHead(char* pc, char* pcbuf, int bufsize);

//==  �������� ������� ������ ��� ��������� ������( ��������� )
extern "C" int    __declspec(impexp) __stdcall  getTextBody(char* pc, char* pcbuf, int bufsize);

//-- ������ ������ ����� � �������� ����
extern "C" int    __declspec(impexp) __stdcall    fwriteInt( int fh, int val);

//-- ������ ������ ����� �� ��������� �����
extern "C" int    __declspec(impexp) __stdcall    freadInt( int fh );

//== ��������� ����� ����� � ������ =
extern "C" int    __declspec(impexp) __stdcall    countTextSt(char* pc);

//== �������� ������ � �������� ������� �� ������
extern "C" int  __declspec(impexp) __stdcall    getTextSt(char* pc, char* pcbuf, int bufsize,  int st_nom);

//== ������� �������� �������� ��������� ���� DBSN 
extern "C" int    __declspec(impexp) __stdcall    getFragmOffset( int  dbhadr,  int &rec_offset );

//== ������� �����  �������� ��������� ���� DBSN
extern "C" int    __declspec(impexp) __stdcall    getFragmSize( int  dbhadr, int &rec_size );

//== ��������� ������� �� ������
extern "C" int    __declspec(impexp) __stdcall    isActive( int dbhadr );

//==  ��������  ������� ������ DBSN
extern "C" int    __declspec(impexp) __stdcall    getErrCod( int dbhadr );

//== �������� ������� ������
extern "C" int    __declspec(impexp) __stdcall    clearError( int dbhadr );

//-- ����� ������� ----
extern "C" char*    __declspec(impexp) __stdcall  trim( char* pc, char* pcres);

//== ������� ������ ���� ���������� �� ����� �����
extern "C" int    __declspec(impexp) __stdcall     createDBSN( char*  fil_name );

//== ��������� ������������� ������ DBSN
extern "C" int    __declspec(impexp) __stdcall     existDBSN( char*  fil_name );

//== �������� ��� ���������� DBS �����
extern "C" int    __declspec(impexp) __stdcall  getAllDBS( char* fil_name, char* &text );

//== ������� ���� ���������� DBSN
extern "C" int   __declspec(impexp) __stdcall   openDBSN( char* fil_name );

//== ������� ���� ���������� DBSN
extern "C" int    __declspec(impexp) __stdcall  closeDBSN( int &dbhadr );

//==  ��������� ����� ������� � ���� DBSN
extern "C" int    __declspec(impexp) __stdcall  countFragm( int dbhadr );

//== ������� ��� ��������� ���� DBSN
extern "C" int    __declspec(impexp) __stdcall  delAllFragm(  int dbhadr );

//== ��������� ����������  ���� DBSN
extern "C" int    __declspec(impexp) __stdcall  eraseDBSN( char*  fil_name);

//==  ������������� ���� DBSN � ����� ���
extern "C" int    __declspec(impexp) __stdcall   renameDBSN( char*  old_fil, char*  new_fil );

//== ��������� ���� DBSN
extern "C" int    __declspec(impexp) __stdcall   packDBSN( char*  fil_name );

//== ��������� �� ����� ����� ���� DBSN
extern "C" int    __declspec(impexp) __stdcall   isEndDBSN( int dbhadr );

//==  �������� ����� �������� ���������
extern "C" int    __declspec(impexp) __stdcall   getNom(int dbhadr );

//==  ���������� ����� �������� ���������
extern "C" int    __declspec(impexp) __stdcall 	 setNom(int dbhadr, int new_nom );

//==  ��������� ����� �������� ���������  
extern "C" int    __declspec(impexp) __stdcall   incNom(int dbhadr, int  count );

//==  ��������� ����� �������� ���������
extern "C" int    __declspec(impexp) __stdcall   decNom(int dbhadr, int  count );

//==  ���������� ������ ����� ���������
extern "C" int    __declspec(impexp) __stdcall   setFirst(int dbhadr );

//==  ���������� ��������� ����� ���������
extern "C" int    __declspec(impexp) __stdcall   setLast(int dbhadr );

//== ������� ������� �������� ���� DBSN  
extern "C" int    __declspec(impexp) __stdcall   getFragm(  int dbhadr, char* fragm,  int bufsize );

//==  �������� ������ � ���� ���������� DBSN
extern "C" int    __declspec(impexp) __stdcall
        addFragm( int dbhadr, char* fragm );

//==  �������� ����� � ������� ������ ���� DBSN
extern "C" int    __declspec(impexp) __stdcall   
	setFragm(  int dbhadr, char*  fragm );

//== ������� �������� ���� DBSN � �������� �������
extern "C" int    __declspec(impexp) __stdcall   
	delFragm(  int dbhadr );

//== ����� ������� �������� � ��������� ���� DBSN
extern "C" int    __declspec(impexp) __stdcall   
	undelFragm(  int dbhadr );

//== ��������� ����� ������ ���������� ���� DBSN
extern "C" int    __declspec(impexp) __stdcall   
	countBlocks( int dbhadr, int block_size, int flag_sel );

//== ������� �������� ���� ������� ���������� ���� DBSN
extern "C" int    __declspec(impexp) __stdcall   
	getBlock( int dbhadr, int* pblock, int block_nom,  int block_size, int flag_sel  );


//== 20 ��� 2014 ====
//-- ��������� ����� �������� � �������� ������
extern "C" int    __declspec(impexp) __stdcall 
	binsubstCount( char* pcFragm, int fragmLen);

//-- �������� �������� �������� ���������
extern "C" int    __declspec(impexp) __stdcall
	binsubstOffset(char* pcFragm, int fragmLen, long nom_sub);

//-- ��������� ����� ��������� � ������ �� �� ������
extern "C" int   __declspec(impexp)  __stdcall
	binsubstLen( char* pcFragm, int fragmLen, long nom_sub );

//-- ��������� ������ ��������� � ������ �� �� ������
extern "C" int   __declspec(impexp)  __stdcall
	binsubstSize( char* pcFragm, int fragmLen, long nom_sub );

//-- �������� �������� ��������� � �������� ������� �� ������ � �����
extern "C" int   __declspec(impexp)  __stdcall
	getBinsubst(char* pcFragm, int fragmLen, char* pcBuf, int bufLen, long nom_sub);

//== �������� � ��������� �������� ���������
extern "C" int    __declspec(impexp) __stdcall
	addBinsubst( char* pcFragm, int fragmLen, char* pcBuf, int bufLen,  char* pcBinsubst );

//== �������� �������� ��������� �� ���������
extern "C" int    __declspec(impexp) __stdcall
	cutBinsubst( char* pcFragm, int fragmLen, long nom_sub );

//== �������� �������� ���������  � ���������
extern "C" int    __declspec(impexp) __stdcall
    clearBinsubstIn( char* pcFragm, int fragmLen, long nom_sub );

//== �������� �������� ��������� ����� �������� �� ��������
extern "C" int    __declspec(impexp) __stdcall
	insBinsubst( char* pcFragm, int fragmLen, char* pcBuf, int bufLen, long nom_sub, char* pcBinsubst );

extern "C" int    __declspec(impexp) __stdcall
	setBinsubst( char* pcFragm, int fragmLen, char* pcBuf, int bufLen, long nom_sub, char* pcBinSubst);


//==  �������� ��� ������ � ���� ���������� DBSN
extern "C" int    __declspec(impexp) __stdcall     
	addBinFragm( int dbhadr, char* fragm, int len_fragm );

//==  �������� ��� �������� � ������� ������ ���� DBSN
extern "C" int    __declspec(impexp) __stdcall   
	setBinFragm(  int dbhadr, char*  fragm, int len_fragm );

////////////////////////////////////////

//==  ������� � ������� ��������� ���������
extern "C" int    __declspec(impexp) __stdcall
    gotoFirst( int dbhadr );

//==  ������� � ���������� ��������� ���������
extern "C" int    __declspec(impexp) __stdcall
    gotoNext( int dbhadr, int count );

//==  ������� � ����������� ��������� ���������
extern "C" int    __declspec(impexp) __stdcall
    gotoPrev( int dbhadr, int count );

//==  ������� � ���������� ��������� ���������
extern "C" int    __declspec(impexp) __stdcall
    gotoLast( int dbhadr );

//----------------------------------------------------------


extern "C" int*    __declspec(impexp) __stdcall
	writeBinRec( int dbhadr, int* plbuf);

extern "C" int*    __declspec(impexp) __stdcall 
	readBinRec( int dbhadr, int* plbuf);

extern "C" int    __declspec(impexp) __stdcall 
	xchgFragm( int  dbhadr, int  dest_nom );

extern "C" int    __declspec(impexp) __stdcall 
	flushDBSN( int  dbhadr );

//== ��������� �������� ������ ���������  �� dbn
extern "C" int    __declspec(impexp) __stdcall
	cutFragm(  int dbhadr );

//==  �������� ������ � ���� ���������� DBSN � ������� �������
extern "C" int    __declspec(impexp) __stdcall
	insFragm( int dbhadr, char* fragm);

//== ����������� ������� ��������� � �������� ����� dbn
extern "C" int    __declspec(impexp) __stdcall
	moveFragm(  int dbhadr, int  dest_nom );

//== ����������� ���� ���������� ��� ������ ������
extern "C" int    __declspec(impexp) __stdcall
	copyDBSN( char*  fil_name, char*  copy_filname, int flag_pack  );

//== ���������� � ����� �������� ������ � ������������
extern "C" int    __declspec(impexp) __stdcall
	getErrMes( int dbhadr, char* err_buf, int buf_len, char* comment);

//== ������ �� ��������

//== ������� ��������� ���� �� ������� ���������� �� ����� �����
extern "C" int  __declspec(impexp) __stdcall createDBRF( char*  fil_name);

//== ������� ��������� ���� �� ������� ���������� DBSN
extern "C" int  __declspec(impexp) __stdcall openDBRF( char* filref_name );

//== ������� ��������� ���� �� ������� ���������� DBSN
extern "C" int  __declspec(impexp) __stdcall closeDBRF( int fhr );

//== ���������� ���������� ������� � ����� ������
extern "C" int  __declspec(impexp) __stdcall countRef( int fhr );

//== �������� ����� ��������� �� ������ �� ����
extern "C" int   __declspec(impexp) __stdcall getFragmNomByRef(  int fhr, int ref_nom );

//== �������� �������� �� ������ �� ����
extern "C" int   __declspec(impexp) __stdcall getFragmByRef(  int dbhadr, int fhr, int ref_nom,  char* fragm, int bufsize );

//== �������� � ��������� ���� ����� ���������
extern "C" int   __declspec(impexp) __stdcall addFragmRef(  int fhr, int fragm_nom );

//== �������� � ��������� ����� ����� ��������� � ������ �������
extern "C" int   __declspec(impexp) __stdcall setFragmRef(  int fhr, int ref_nom, int fragm_nom );

//== ������� � ��������� ����� ����� ��������� � ������ �������
extern "C" int   __declspec(impexp) __stdcall delFragmRef(  int fhr, int ref_nom );

//== ����� �������� � ��������� �����
extern "C" int   __declspec(impexp) __stdcall undelFragmRef(  int fhr, int ref_nom );

//== �������� ������� ������ �� ���������
extern "C" int    __declspec(impexp) __stdcall  xchgFragmRef( int  fhr, int  ref_nom1,  int ref_nom2 );

//==  �������� ��������� � ��������� ����� ����� ��������� � ������ �������
extern "C" int   __declspec(impexp) __stdcall cutFragmRef(  int fhr, int ref_nom );

//== �������� � ��������� ����� ����� ��������� � ������ �������
extern "C" int   __declspec(impexp) __stdcall insFragmRef(  int fhr, int ref_nom, int fragm_nom );

//== ���������� ����� ����� � �������� ����� ������ �������� ���������
extern "C" int   __declspec(impexp) __stdcall
    setBinnum(char* pcFragm, int fragmLen, long nom_sub, long nom_num, long src );

//== �������� ����� � �������� ������� �� ������ �������� ���������
extern "C" int   __declspec(impexp) __stdcall
    getBinnum(char* pcFragm, int fragmLen, long nom_sub, long nom_num, long &dst );

//== ������� ����� � �������� ������� �� ������ �������� ���������
extern "C" int   __declspec(impexp) __stdcall
    cutBinnum(char* pcFragm, int fragmLen, long nom_sub, long nom_num );

//== �������� ����� ����� � ����� ������ �������� ���������
extern "C" int   __declspec(impexp) __stdcall
    addBinnum(char* pcFragm, int fragmLen, char* pcBuf, int lenBuf, long nom_sub, long src );

//== �������� ����� ����� � �������� ����� ������ �������� ���������
extern "C" int   __declspec(impexp) __stdcall
    insBinnum(char* pcFragm, int fragmLen, char* pcBuf, int lenBuf, long nom_sub, long nom_num, long src );

//== �������� ������� 2 ����� � ������ �������� ���������
extern "C" int   __declspec(impexp) __stdcall
    chgBinnum(char* pcFragm, int fragmLen, long nom_sub, long nom_num1, long nom_num2 );

//== ������� DBS ���� �� ��������� �� ��������� �����
extern "C" int   __declspec(impexp) __stdcall
	formDBSN( char* txtFile, char* keyWord);

#endif
