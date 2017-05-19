//------------------------【根据权重矩阵求最小权重和路径】----------------------------
//功能：求最小权重和路径并在图片上标示
//时间：2017.4.28  07：28
//说明：1）有方向搜索，以当前点(i,j)为起点，搜索右侧5 * 2区域内权重最小的点
//		2）循环搜索，找到一条之后，就不再搜索该路线所在区域，寻找其他区域内的路线
//			2.1搜索完毕之后，要重新计算权重
//		3)使用经过matlab进行对比度增强后的图片，使用之前先读取该图片
//		4)计算权重的时候，只计算纵坐标范围[500,700]的权重，因此权重数组为200 * BMP_HEIGHT
//状态：完成
//修改记录：
//最后修改时间：
#include"Bmp.h"
void PathBeColor(IMAGEDATA **IMG_DATA,int **flag,int color);

void Find_Path(IMAGEDATA **IMG_DATA)
{
	//步骤：初始化起点，计算权重，寻找路径，上色
	int **Weight = (int**)malloc(sizeof(int*) * 300);    //记录权重
	int **flag = (int **)malloc(sizeof(int *) * 512);    //标记最小权重和路径坐标
	int **flag1 = (int **)malloc(sizeof(int *) * 512);
	for (int i = 0; i < 512; ++i)
	{
		flag[i] = (int*)malloc(sizeof(int) * 2);
		flag1[i] = (int*)malloc(sizeof(int) * 2);
	}

	for (int i = 0; i < 300; ++i) 
	{
		Weight[i] = (int*)malloc(sizeof(int) * BMP_WIDTH);
	}
	//根据得到的权重矩阵寻找路径，循环4次搜索4条路径，每次选择不同的搜索起点
	
	int min,cur_x,cur_y,next_x,next_y,count,count1;

	//计算权重
	
	
	Assign_Weight(IMG_DATA, Weight,0);
	//初始化flag数组
	for (int i = 0; i < 512; ++i)
	{
		flag[i][0] = 0;
		flag[i][1] = 0;
	}
	cur_x = 0;
	cur_y = (TOP_BORDER - 300) + 105;
	count = 0;
	while (cur_x < BMP_WIDTH)
	{
		min = -1000;
		next_x = cur_x;
		next_y = cur_y;
		for (int i = cur_x + 1; i <= cur_x + 2; ++i)
		{
			for (int j = cur_y - 3; j <= cur_y + 7; ++j)
			{
				if (i >= 0 && i < BMP_WIDTH && j >= (TOP_BORDER - 300) && j < TOP_BORDER)
				{
					if (Weight[j - (TOP_BORDER - 300)][i] > min)
					{
						next_x = i;
						next_y = j;
						min = Weight[j - (TOP_BORDER - 300)][i];
					}
				}
			}
		}
		if (next_y >= TOP_BORDER)
			next_y = TOP_BORDER;
		if (next_y < TOP_BORDER - 300)
			next_y = TOP_BORDER - 300;
		cur_x = next_x;
		cur_y = next_y;
		flag[count][0] = cur_x;
		flag[count++][1] = cur_y;
		if (count >= 512)
			break;
	}

	PathBeColor(IMG_DATA, flag, 0);
	
	Assign_Weight(IMG_DATA, Weight,1);
	//初始化flag数组
	for (int i = 0; i < 512; ++i)
	{
		flag[i][0] = 0;
		flag[i][1] = 0;
		flag1[i][0] = 0;
		flag1[i][1] = 0;
	}
	cur_y = 200 + (TOP_BORDER - 300);
	cur_x = 0;
	count = 0;
	count1 = 0;
	//从左向右搜索
	while (cur_x < BMP_WIDTH)
	{
		min = -1000;
		next_x = cur_x;
		next_y = cur_y;
		for (int i = cur_x + 1; i <= cur_x + 2; ++i)
		{
			for (int j = cur_y - 3; j <= cur_y + 3; ++j)
			{
				if (i >= 0 && i < BMP_WIDTH && j >= (TOP_BORDER - 300) && j < TOP_BORDER )
				{
					if (Weight[j - (TOP_BORDER - 300)][i] > min)
					{
						next_x = i;
						next_y = j;
						min = Weight[j - (TOP_BORDER - 300)][i];
					}
				}
			}
		}
		
		if (next_y >= TOP_BORDER)
			next_y = TOP_BORDER;
		if (next_y < TOP_BORDER - 300)
			next_y = TOP_BORDER - 300;
		cur_x = next_x;
		cur_y = next_y;

		flag[count][0] = cur_x;
		flag[count++][1] = cur_y;
		
		if (count >= 512)
			break;
	}

	cur_y = 235 + (TOP_BORDER - 300);
	cur_x = BMP_WIDTH - 1;
	count1 = 0;
	//从右向左搜索
	while (cur_x < BMP_WIDTH)
	{
		min = -1000;
		next_x = cur_x;
		next_y = cur_y;
		for (int i = cur_x - 1; i >= cur_x - 2; --i)
		{
			for (int j = cur_y - 3; j <= cur_y + 13; ++j)
			{
				if (i >= 0 && i < BMP_WIDTH && j >= (TOP_BORDER - 300) && j < TOP_BORDER)
				{
					if (Weight[j - (TOP_BORDER - 300)][i] > min)
					{
						next_x = i;
						next_y = j;
						min = Weight[j - (TOP_BORDER - 300)][i];
					}
				}
			}
		}

		if (next_y >= TOP_BORDER)
			next_y = TOP_BORDER;
		if (next_y < (TOP_BORDER - 300))
			next_y = (TOP_BORDER - 300);
		cur_x = next_x;
		cur_y = next_y;

		flag1[count1][0] = cur_x;
		flag1[count1++][1] = cur_y;
		std::cout << flag1[count1 - 1][0] << "," << flag[count1 - 1][1] << " ";
		if (count1 >= 512)
			break;
	}
	//比较两个搜索结果，选择两个结果中合适的值
//	for (int i = 0; i < count && i < count1; ++i)
//	{
//		if (flag1[i][1] - flag[i][1] > 8)
//			flag[i][1] = flag1[i][1];
//	}
	PathBeColor(IMG_DATA, flag1, 1);
	
	Assign_Weight(IMG_DATA, Weight, 0);
	//初始化flag数组
	for (int i = 0; i < 512; ++i)
	{
		flag[i][0] = 0;
		flag[i][1] = 0;
	}
	cur_y = (TOP_BORDER - 300) + 165;
	cur_x = 0;
	count = 0;
	while (cur_x < BMP_WIDTH)
	{
		min = -1000;
		next_x = cur_x;
		next_y = cur_y;
		for (int i = cur_x + 1; i <= cur_x + 4; ++i)
		{
			for (int j = cur_y - 5; j <= cur_y + 5; ++j)
			{
				if (i >= 0 && i < BMP_WIDTH && j >= (TOP_BORDER - 300) && j < TOP_BORDER)
				{
					if (Weight[j - (TOP_BORDER - 300)][i] > min)
					{
						next_x = i;
						next_y = j;
						min = Weight[j - (TOP_BORDER - 300)][i];
					}
				}
			}
		}
		if (next_y >= TOP_BORDER)
			next_y = TOP_BORDER;
		if (next_y < (TOP_BORDER - 300))
			next_y = (TOP_BORDER - 300);
		cur_x = next_x;
		cur_y = next_y;
		flag[count][0] = cur_x;
		flag[count++][1] = cur_y;
		if (count >= 512)
			break;
	}

	PathBeColor(IMG_DATA, flag, 2);

	
	//释放图片矩阵内存
	for (int i = 0; i < 512; ++i)
	{
		free(flag[i]);
		free(flag1[i]);
	}
	for(int i = 0; i < 300; ++i) 
	{
		free(Weight[i]);
	}
	free(Weight);
	free(flag);
	free(flag1);
}
void PathBeColor(IMAGEDATA **IMG_DATA,int** flag,int color)
{  
	/*        测试是否能上色
	for (int i = 0; i < BMP_WIDTH; ++i)
	{
		for (int j = 0; j < BMP_HEIGHT; ++j)
		{
			if (j == 500)
			{
				IMG_DATA[j][i].blue = 255;
				IMG_DATA[j][i].green = 0;
				IMG_DATA[j][i].red = 0;
			}
		}
	}
	*/
	
	for (int i = 0; i < 512; ++i)
	{
		if (color == 0) 
		{
			IMG_DATA[flag[i][1]][flag[i][0]].blue = 255;
			IMG_DATA[flag[i][1]][flag[i][0]].green = 0;
			IMG_DATA[flag[i][1]][flag[i][0]].red = 0;
		}
		else if (color == 1)
		{
			IMG_DATA[flag[i][1]][flag[i][0]].blue = 0;
			IMG_DATA[flag[i][1]][flag[i][0]].green = 255;
			IMG_DATA[flag[i][1]][flag[i][0]].red = 0;
		}
		else if (color == 2)
		{
			IMG_DATA[flag[i][1]][flag[i][0]].blue = 0;
			IMG_DATA[flag[i][1]][flag[i][0]].green = 0;
			IMG_DATA[flag[i][1]][flag[i][0]].red = 255;
		}
	}
	
}

