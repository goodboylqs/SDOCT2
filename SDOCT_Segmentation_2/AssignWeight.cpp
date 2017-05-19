//------------------------【求图像的梯度矩阵，并根据矩阵赋予权重】----------------------------
//功能：求图像的竖直方向和水平方向的梯度矩阵，梯度计算直接用像素值之差。
//时间：2017.4.28  07：28
//说明：1)权重的计算方法   Wab = 2 - Xab - Yab，像素差越大，Xab和Yab就越大，加上负号后就越小。
//		2）使用经过matlab进行对比度加强后的图片进行计算
//		3)参数type共有从亮到暗和从暗到亮两种情况，能被2整除是第一种
//		4)权重矩阵取图片的纵坐标范围[500,700]内的图片，高度为200，宽度为BMP_WIDTH
//状态：完成
//修改记录：
//最后修改时间：
#include"Bmp.h"
void Assign_Weight(IMAGEDATA **IMG_DATA,int **Weight,int type)
{
	for (int i = 0; i < 300; ++i)
	{
		for (int j = 0; j < BMP_WIDTH; ++j)
		{
			if (i - 1 >= 0)
			{
				if(type == 0)
					Weight[i][j] = IMG_DATA[i + (TOP_BORDER - 300)][j].blue - IMG_DATA[i + (TOP_BORDER - 300) - 1][j].blue;
				if(type == 1)
					Weight[i][j] = IMG_DATA[i + (TOP_BORDER - 300) - 1][j].blue - IMG_DATA[i + (TOP_BORDER - 300)][j].blue;
			}
		}
	}
}