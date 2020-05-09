/**************************************************************
** 作   者:  tyler
** 创建时间:  2020-05-06
** 描   述:  字符串匹配的Boyer-Moore算法
**************************************************************/
#include "mboyermoore.h"
#include <stdio.h>

extern "C"
{
#include "mboyermoore_c.h"
}
 
MBoyerMoore::MBoyerMoore(QObject *parent)
    : QObject(parent)
{
    
}

void MBoyerMoore::startForText_c()
{
    char text[256] ={ 'I','a','m','h','a','p','p','y','I','a','m','h','a','p','p','y'},pattern[256]={'a','p',};
    BM(pattern, strlen(pattern), text, strlen(text));
}

void MBoyerMoore::startSearchForText(const QString &key, const QString &text, int index)
{
    int keyLen = key.length();
    int len = text.length();
    int cIndex = 0;
    int resValue = 0;
    for(int i=0;i<len;i++){
        if( i+keyLen < len )
        {//剩余文本长度大于等于关键词长度时
            resValue = matchSectionText(key,text.mid(i,keyLen));
        }
        else{
            
        }
    }
}

int MBoyerMoore::matchSectionText(const QString &key, const QString &section)
{
    int len = section.length();
    int matchIndex = -1;
    int badChrOffset = 0;     //坏字符位移
    int goodSuffixOffset = 0; //好后缀位移
    for(int i=0;i<len;i++)
    {
        if( key.right(i+1) != section.right(i+1) )
        {//当开始遇到不匹配的文本时,即遇到坏字符时
            matchIndex = key.lastIndexOf(section.mid(len-i-1,1));
            
            badChrOffset = len-i-1-matchIndex;
            goodSuffixOffset = 0;//
            
            
            if( i==0 )//没有好后缀
                return len-i-1-matchIndex;
            else{//
                
            }
            
            if( i ==0 )
            {//匹配第一次时
                if( matchIndex >=0 )
                {//坏字符在关键词中出现
                    return key.length()-matchIndex;
                }
                else
                {//坏字符在关键词未出现
                    return key.length();
                }
            }
            else{
                if( matchIndex >=0 )
                {//坏字符在关键词中出现
                    return key.length()-matchIndex;
                }
                else
                {//坏字符在关键词未出现
                    return key.length();
                }
            }
        }
    }
    return 0;
}
 
