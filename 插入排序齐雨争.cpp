// ConsoleApplication42.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>                                       //直接插入排序 
using namespace std;
void InsertSort(int* array, int n) {               //array待排序数组,n:数组元素数量
	int i, j;                                    //循环变量
	int temp;                                      //存储待排序元素
	for (i = 1; i < n; i++) {
		j = i;
		temp = array[i];                         //待排序元素赋值给临时变量
		while (j > 0 && temp < array[j - 1]) {   //当未达到数组的第一个元素并且待插入元素小于当前元素
			array[j] = array[j - 1];             //就将该元素后移
			j--;                                 //下标减一，继续比较
		}
		array[j] = temp;                         //插入位置已经找到，立即插入
	}
}
int main()
{
	int a[10] = { 1,3,43,457,8,6,45,5,9,659 };       //建立数组 
	InsertSort(a, 10);    
	for (int i = 0; i < 10; i++)
		cout << a[i]<<endl; //调用函数 
	return 0;


}