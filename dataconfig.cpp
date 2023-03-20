#include "dataconfig.h"
#include <QDebug>
dataConfig::dataConfig(QObject *parent) : QObject(parent)
{
    //   1->金币  0->银币
     int array1[4][4] = {{1, 1, 1, 1},
                        {1, 1, 0, 1},
                        {1, 0, -1, 0},
                        {1, 1, 0, 1} } ;

     QVector< QVector<int>> v;
     for(int i = 0 ; i < 4;i++)//将数组放进容器
     {
         QVector<int>v1;
         for(int j = 0 ; j < 4;j++)
         {

            v1.push_back(array1[i][j]);
         }
         v.push_back(v1);
     }

     mData.insert(1,v);//带上关卡号与矩阵加入map容器中

///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array2[4][4] = { {1, 0, 1, 1},
                          {0, 0, 1, 1},
                          {1, 1, 0, 0},
                          {1, 1, 0, 1}} ;

     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array2[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(2,v);


///////////////////////////////////////////关卡3///////////////////////////////////////////////////////
     int array3[4][4] = {  {0, 0, 0, 0},
                           {0, 1, 1, 0},
                           {0, 1, 1, 0},
                           {0, 0, 0, 0}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array3[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(3,v);

///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array4[4][4] = {   {0, 1, 1, 1},
                            {1, 0, 0, 1},
                            {1, 0, 1, 1},
                            {1, 1, 1, 1}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array4[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(4,v);

///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array5[4][4] = {  {1, 0, 0, 1},
                           {0, 0, 0, 0},
                           {0, 0, 0, 0},
                           {1, 0, 0, 1}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array5[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(5,v);

///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array6[4][4] = {   {1, 0, 0, 1},
                            {0, 1, 1, 0},
                            {0, 1, 1, 0},
                            {1, 0, 0, 1}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array6[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(6,v);

///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array7[4][4] = {   {0, 1, 1, 1},
                            {1, 0, 1, 1},
                            {1, 1, 0, 1},
                            {1, 1, 1, 0}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array7[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(7,v);
///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array8[4][4] = {  {0, 1, 0, 1},
                           {1, 0, 0, 0},
                           {0, 0, 0, 1},
                           {1, 0, 1, 0}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array8[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(8,v);
///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array9[4][4] = {   {1, 0, 1, 0},
                            {1, 0, 1, 0},
                            {0, 0, 1, 0},
                            {1, 0, 0, 1}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array9[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(9,v);


///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array10[4][4] = {  {1, 0, 1, 1},
                            {1, 1, 0, 0},
                            {0, 0, 1, 1},
                            {1, 1, 0, 1}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array10[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(10,v);

///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array11[4][4] = {  {0, 1, 1, 0},
                            {1, 0, 0, 1},
                            {1, 0, 0, 1},
                            {0, 1, 1, 0}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array11[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(11,v);
///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array12[4][4] = {  {0, 1, 1, 0},
                            {0, 0, 0, 0},
                            {1, 1, 1, 1},
                            {0, 0, 0, 0}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array12[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(12,v);

///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array13[4][4] = {    {0, 1, 1, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 1, 1, 0}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array13[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(13,v);
///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array14[4][4] = {    {1, 0, 1, 1},
                              {0, 1, 0, 1},
                              {1, 0, 1, 0},
                              {1, 1, 0, 1}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array14[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(14,v);

///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array15[4][4] = {   {0, 1, 0, 1},
                             {1, 0, 0, 0},
                             {1, 0, 0, 0},
                             {0, 1, 0, 1}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array15[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(15,v);

///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array16[4][4] = {   {0, 1, 1, 0},
                             {1, 1, 1, 1},
                             {1, 1, 1, 1},
                             {0, 1, 1, 0}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array16[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(16,v);
///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array17[4][4] = {  {0, 1, 1, 1},
                            {0, 1, 0, 0},
                            {0, 0, 1, 0},
                            {1, 1, 1, 0}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array17[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(17,v);

///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array18[4][4] = { {0, 0, 0, 1},
                           {0, 0, 1, 0},
                           {0, 1, 0, 0},
                           {1, 0, 0, 0}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array18[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(18,v);
///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array19[4][4] = {   {0, 1, 0, 0},
                             {0, 1, 1, 0},
                             {0, 0, 1, 1},
                             {0, 0, 0, 0}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array19[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(19,v);
///////////////////////////////////////////关卡2///////////////////////////////////////////////////////
     int array20[4][4] = {  {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}} ;
     v.clear();
     for(int i = 0 ; i < 4;i++)
     {
          QVector<int>v1;
          for(int j = 0 ; j < 4;j++)
          {
             v1.push_back(array20[i][j]);
          }
          v.push_back(v1);
     }

     mData.insert(20,v);


     //测试数据
//    for( QMap<int, QVector< QVector<int> > >::iterator it = mData.begin();it != mData.end();it++ )
//    {
//         for(QVector< QVector<int> >::iterator it2 = (*it).begin(); it2!= (*it).end();it2++)
//         {
//            for(QVector<int>::iterator it3 = (*it2).begin(); it3 != (*it2).end(); it3++ )
//            {
//                qDebug() << *it3 ;
//            }
//         }
//         qDebug() << endl;
//    }


}
