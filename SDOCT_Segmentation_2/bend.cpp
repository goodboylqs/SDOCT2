//------------------------������ƽ��ͼƬ�ظ���ԭ���������̶ȡ�----------------------------
//���ܣ����Ѿ��ֲ�õ�ͼƬ�ظ���ԭ���ĳ̶�
//ʱ�䣺2017.4.28  07��28
//˵����
//�޸ļ�¼��
//����޸�ʱ�䣺
#include"Bmp.h"

void Bend(IMAGEDATA **IMG_DATA,Point BrightestPixel[BMP_WIDTH])
{
	double *xishu, xishus[3];
	xishu = Fit(BrightestPixel);
	xishus[0] = *(xishu + 1);
	xishus[1] = *(xishu + 2);
	xishus[2] = *(xishu + 3);

	//ÿһ�ж������ߵ���͵�Ϊ��׼����ƽ�Ƶ�ǰ������͵�ĸ߶Ȳ�
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

		for (int j = BMP_HEIGHT - 1 - height_distance; j >= 0; --j)   //ÿһ������ƽ��height_distance����λ
		{
			IMG_DATA[j + height_distance][i] = IMG_DATA[j][i];
		}
	}
}