#ifndef MSORT_H
#define MSORT_H

#include <QObject>

class MSort : public QObject
{
    Q_OBJECT
public:
    explicit MSort(QObject *parent = nullptr);
    
    void test();
    
    /*!洗牌算法，打乱数组顺序
     */
    void shuffle(QList<int> &arr);
    
    //=============交换排序
    /*!冒泡排序
     * sList: 需要排序的源数组
     */
    void bubbleSort(QList<int> &arr);
    
    //=============插入排序
    /*!插入排序
     */
    void insertionSort(QList<int> &arr);
    
    /*!希尔排序
     */
    void shellSort(QList<int> &arr);
    
    //=============选择排序
    /*!选择排序
     */
    void selectionSort(QList<int> &arr);
    
    
    //=============归并排序
    /*!归并排序
     */
signals:
    
public slots:
};

#endif // MSORT_H
