#include"Bmp.h"
//------------------------����ÿһ�������㲢ȥ�뺯����----------------------------
//���ܣ���ÿһ�������㣬�����õ�����ȵ������,������������Բ��������㣬���ǳ�����
//		��ͼƬ����ʾʱ��������������ȵ������
//ʱ�䣺2017.1.8  00:16
//˵��������ͼƬ����Ѱ��ÿһ�е������㣬Ȼ��������ĻҶ�ֵ���Ϊ255�����浽ͼƬ�У�
//		��ͼƬ�еİ׵㼴ÿһ�е������㣬�۲��������λ���Ƿ���Ԥ����������ֲ��������㸽��
//״̬�����
//�޸ļ�¼��
//����޸�ʱ�䣺2017.2.28
void BrightestPixel_And_LowerNoise(IMAGEDATA **IMG_DATA,Point *BrightPixel)
{
	int index_x = 0, index_y = 0,max_pixel;
	for (int i = 0; i < BMP_WIDTH; ++i)
	{
		max_pixel = IMG_DATA[0][i].blue;
		for (int j = 0; j < BMP_HEIGHT; ++j)
		{
			if (max_pixel < IMG_DATA[j][i].blue)
			{
				max_pixel = IMG_DATA[j][i].blue;
				index_x = i;
				index_y = j;
			}
		}
		std::cout << index_x << "," << index_y << std::endl;
		BrightPixel[i].x = index_y;               //��¼����������
		BrightPixel[i].y = index_x;
	}

	//ȥ������
	for (int i = 1; i < BMP_WIDTH; ++i)
	{
		if (BrightPixel[i].y - BrightPixel[i - 1].y > 20)
		{
			std::cout << "��������" << std::endl;
			int tmp_x = i;
			for (int j = tmp_x; BrightPixel[j].y - BrightPixel[tmp_x - 1].y > 20; ++j)
			{
//				std::cout << "ȥ������" << std::endl;
				BrightPixel[j].x = -1;
			}
		}
	}

	//��ͼƬ�б��������
	/*
	for (int i = 0; i < BMP_WIDTH; ++i)
	{
		if (BrightPixel[i].y != -1)
	{
			IMG_DATA[BrightPixel[i].x][BrightPixel[i].y].blue = 255;
			IMG_DATA[BrightPixel[i].x][BrightPixel[i].y].green = 255;
			IMG_DATA[BrightPixel[i].x][BrightPixel[i].y].red = 255;
		}
	}
	*/
	//std::cout << count;
	Fit(BrightPixel);
}
