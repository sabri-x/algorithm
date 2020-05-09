#ifndef MBOYERMOORE_H
#define MBOYERMOORE_H

#include <QObject>

class MBoyerMoore : public QObject
{
    Q_OBJECT
public:
    explicit MBoyerMoore(QObject *parent = nullptr);
    
    /*!匹配搜索测试，调用C文件
     */
    void startForText_c();
    
    /*!开始从文本中搜索
     * key: 搜索关键词
     * text: 文本内容
     * index: 累积搜索到当前文本的下标，若是搜索一个大文本，分成很多部分来搜索，此参数可用到
     */
    void startSearchForText(const QString &key,const QString &text,int index=0);
    
    /*!匹配一段与关键词同样长度的文本,返回匹配结果
     * key: 关键词
     * section: 文本段
     * return: 成功匹配： 0, 未成功匹配：需要右移动的位数
     */
    int matchSectionText(const QString &key,const QString &section);
     
       
signals:
    
public slots:
    
    
    
};

#endif // MBOYERMOORE_H
