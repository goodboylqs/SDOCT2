//------------------------【将拉平的图片回复到原来的弯曲程度】----------------------------
//功能：将已经分层好的图片回复到原来的程度
//时间：2017.4.28  07：28
//说明：
//修改记录：
//最后修改时间：
#include"Bmp.h"

void Bend(IMAGEDATA **IMG_DATA,Point BrightestPixel[BMP_WIDTH])
{
	double *xishu, xishus[3];
	xishu = Fit(BrightestPixel);
	xishus[0] = *(xishu + 1);
	xishus[1] = *(xishu + 2);
	xishus[2] = *(xishu + 3);

	//每一列都以曲线的最低点为基准向上平移当前点与最低点的高度差
	double lowest_x = xishus[1] / (2 * xishus[2] * (-1));
	double lowest_y = Cal(int(lowest_x), xishus) / 2;
	//	std::cout << lowest_x << "," << lowest_y << std::endl;
	for (int i = 0; i < BMP_WIDTH; ++i)
	{
		int y = Cal(i, xishus) / 2;
		if (y > 1024 || y < 1)continue;
		//		IMG_DATA[y - 1][i].blue = 255;
		//		IMG_DATA[y - 1][i].green = 255;
		//		IMG_DATA[y - 1][i].red = 255;

		//		std::cout << y << "," << lowest_y << std::endl;
		int height_distance = abs(y - (int)lowest_y);
		//		std::cout << height_distance << std::endl;

		for (int j = BMP_HEIGHT - 1 - height_distance; j >= 0; --j)   //每一列上下平移height_distance个单位
		{
			IMG_DATA[j + height_distance][i] = IMG_DATA[j][i];
		}
	}
}