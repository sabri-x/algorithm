/**************************************************************
** 作   者:  xcc
** 创建时间:  2020-05-08
** 描   述:  10大排序算法
** 
**                                |- 冒泡排序
**                     |- 交换排序 -
**                     |          |- 快速排序
**                     |
**                     |          |- 简单插入排序
**                     |- 插入排序 -
**                     |          |- 希尔排序
**         - 比较类排序 -
**         |           |          |- 简单选择排序
**         |           |- 选择排序 - 
**         |           |          |- 堆排序
**         |           |
**         |           |          |- 二路归并排序
**         |           |- 归并排序 -
**         |                      |- 多路归并排序
** 排序算法 -
**         |
**         |
**         |          |- 计数排序
**         - 非比较排序 |- 桶排序
**                    |- 基数排序
** 
** 参考之： https://www.cnblogs.com/onepixel/p/7674659.html
**************************************************************/
#include "msort.h"
#include <QDebug>
#include <QtMath>

MSort::MSort(QObject *parent) : QObject(parent)
{
    
}

void MSort::test()
{
    //step1: 构建随机数组
    QList<int> arr;
    int rNum = 0;
    for(int i=0;i<20;i++){
        do {
            rNum = qrand()%100;
        } while ( arr.indexOf(rNum) >=0 );
        arr.append(rNum);
    }
    qDebug()<<"--source arr="<<arr;
    //step2: 洗牌算法，打乱顺序
    
    //==========step3: 开始排序 ===============
    shuffle(arr);
    qDebug()<<"--shuffle arr="<<arr;
    //==冒泡排序测试
    bubbleSort(arr);
    qDebug()<<"--bubble arr="<<arr<<endl;
    
    //==插入排序
    shuffle(arr);
    qDebug()<<"--shuffle arr="<<arr;
    insertionSort(arr);
    qDebug()<<"--insertion arr="<<arr<<endl;
    
    //希尔排序
    shuffle(arr);
    qDebug()<<"--shuffle arr="<<arr;
    shellSort(arr);
    qDebug()<<"--shell arr="<<arr<<endl;
    
    
    shuffle(arr);
    qDebug()<<"--shuffle arr="<<arr;
    //==选择排序
    selectionSort(arr);
    qDebug()<<"--selectionS arr="<<arr<<endl;
}

void MSort::shuffle(QList<int> &arr)
{
    for(int i=arr.length()-1 ; i>0 ; i--){
        arr.swap(i,qrand()%i);
    }
}

/*!冒泡排序
 * 思路: 第一个元素a1与第二个元素a2比较，若a1>a2,则a1与a2交换位置，继续a2与a3比较，以此类推，一次循环后，
 *      最后一个就是最大的一个数，然后再来依次交换比较到上一次比较的位置时，就把剩下的最大的数，交换到上次最后比较的位置了
*/
void MSort::bubbleSort(QList<int> &arr)
{
    int len = arr.length();
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {// 相邻元素两两对比
                arr.swap(j+1,j); //元素交换
            }
        }
    }
}

/*!插入排序
 * 思路: 
 *     .从第一个元素开始，该元素可以认为已经被排序；
 *     .取出下一个元素，在已经排序的元素序列中从后向前扫描；
 *     .如果该元素（已排序）大于新元素，将该元素移到下一位置；
 *     .重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
 *     .将新元素插入到该位置后；
 *     .重复步骤2~5。
 */
void MSort::insertionSort(QList<int> &arr)
{
    int len = arr.length();
    int current = 0;
    int preIndex = -1;
    for(int i=1; i<len; i++){
        current = arr[i];
        preIndex = -1;
        for(int j=i-1;j>=0;j--){
            if( current < arr[j]  )
            {
                arr[j+1] = arr[j];
                preIndex = j;
            }
            else
                break;
        }
        if( preIndex >=0 )
            arr[preIndex] = current;
    }
}


/*!希尔排序
 * 思路： 
 */
void MSort::shellSort(QList<int> &arr)
{
    int len = arr.length();
    int j = 0;
    int current = 0;
    for (int gap = qFloor(len / 2); gap > 0; gap = qFloor(gap / 2)) {
        for (int i = gap; i < len; i++) {
            j = i;
            current = arr[i];
            while (j - gap >= 0 && current < arr[j - gap]) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            arr[j] = current;
        }
    }
}


/*!选择排序
 * 思路: 第一个元素向后依次比较，遇到比它小的就记录下位置，一次循环后，第一个元素与最小的元素交换位置，第一个位置就是最小的元素了
 *       然后第二个元素向后依次比较,直到倒数第二个，就全部排序完成
*/
void MSort::selectionSort(QList<int> &arr)
{
    int len = arr.length();
    int minIndex =  0;
    for(int i=0; i<len-1; i++){
        minIndex = i;
        for(int j=i+1;j<len;j++){
            if( arr[j] < arr[minIndex] ){
                minIndex = j;
            }
        }
        arr.swap(i,minIndex);
    }
}
 
