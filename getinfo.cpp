#include <afxwin.h>
#include <stdio.h>
#include <windows.h>
#include <string>
#include "Wininet.h"
#pragma comment(lib,"Wininet.lib")

//模拟浏览器发送HTTP请求函数
std::string HttpRequest(char * lpHostName,short sPort,char * lpUrl,char * lpMethod,char * lpPostData,int nPostDataLen)
{
    HINTERNET hInternet,hConnect,hRequest;

    BOOL bRet;

    std::string strResponse;

    hInternet = (HINSTANCE)InternetOpen("User-Agent",INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0);
    if(!hInternet)
        goto Ret0;

    hConnect = (HINSTANCE)InternetConnect(hInternet,lpHostName,sPort,NULL,"HTTP/1.1",INTERNET_SERVICE_HTTP,0,0);
    if(!hConnect)
        goto Ret0;

    hRequest = (HINSTANCE)HttpOpenRequest(hConnect,lpMethod,lpUrl,"HTTP/1.1",NULL,NULL,INTERNET_FLAG_RELOAD,0);
    if(!hRequest)
        goto Ret0;

    //bRet = HttpAddRequestHeaders(hRequest,"Content-Type: application/x-www-form-urlencoded",Len(FORMHEADERS),HTTP_ADDREQ_FLAG_REPLACE | HTTP_ADDREQ_FLAG_ADD);
    //if(!bRet)
        //goto Ret0;

    bRet = HttpSendRequest(hRequest,NULL,0,lpPostData,nPostDataLen);
    while(TRUE)
    {
        char cReadBuffer[4096];
        unsigned long lNumberOfBytesRead;
        bRet = InternetReadFile(hRequest,cReadBuffer,sizeof(cReadBuffer) - 1,&lNumberOfBytesRead);
        if(!bRet || !lNumberOfBytesRead)
            break;
        cReadBuffer[lNumberOfBytesRead] = 0;
        strResponse = strResponse + cReadBuffer;
    }

 Ret0:
    if(hRequest)
        InternetCloseHandle(hRequest);
    if(hConnect)
        InternetCloseHandle(hConnect);
    if(hInternet)
        InternetCloseHandle(hInternet);

    return strResponse;
}

void main() 
{ 
    //CString strResponse = HttpRequest("translate.google.com",80,"/translate_t?langpair=en|zh-CN","POST","hl=zh-CN&ie=UTF-8&text=this is me&langpair=en|zh-CN",strlen("hl=zh-CN&ie=UTF-8&text=this is me&langpair=en|zh-CN"));
    std::string strResponse = HttpRequest("www.hao123.com",80,NULL,"GET",NULL,0);
    FILE * fp = fopen("C:\\123.htm","wb");
    fwrite(strResponse.c_str(),strResponse.length(),1,fp);
    fclose(fp);
}