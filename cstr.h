/*
 * =====================================================================================
 *
 *       Filename:  cstr.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年09月30日 11时00分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

typedef struct cstr{
	char* val;
	int size;
}cstr;

cstr cstrn(char* str);
void cstrcpy(cstr* str,char* s);
cstr cstrsub(cstr* str,int len); 

