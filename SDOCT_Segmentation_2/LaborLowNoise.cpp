//------------------------【均值滤波去噪】----------------------------
//功能：对图片进行均值滤波去噪，增强对比度
//时间：2017.4.28  07：28
//说明：
//状态：完成
//修改记录：
//最后修改时间：
#include"Bmp.h"

void LaborLowNoise(IMAGEDATA **IMG_DATA)
{
	int result,x,y,count;        //x,y记录当前区域的中心点坐标，result记录滤波后的像素值,count记录当前区域内像素点个数
	
	for (int i = 0; i < BMP_WIDTH; i += 3)       //图片的规格是512 * 1024的，有用的部分大概在纵坐标[500,700]范围内
	{
		for (int j = 0; j < BMP_HEIGHT; j += 3)
		{
			//选3 * 19区域进行滤波，中心点坐标(x,y)为(1,10)
			x = i + 10;
			y = j + 1;
			result = 0;
			count = 0;
			for (int a = -9; a <= 9; ++a)
			{
				for (int b = -1; b <= 1; ++b)
				{
					if (a + x >= 0 && a + x < BMP_WIDTH && b + y >= 0 && b + y < BMP_HEIGHT)
					{
						count++;
						result += IMG_DATA[b + y][a + x].blue;
					}
				}
			}
			result /= count;
			//对目标区域的像素点进行赋值
			
			for (int a = -9; a <= 9; ++a)
			{
				for (int b = -1; b <= 1; ++b)
				{
					if (a + x >= 0 && a + x < BMP_WIDTH && b + y >= 0 && b + y < BMP_HEIGHT)
					{
						IMG_DATA[b + y][a + x].blue = result;
						IMG_DATA[b + y][a + x].green = result;
						IMG_DATA[b + y][a + x].red = result;
					}
				}
			}
			
		}
	}
}
