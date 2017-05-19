clear all;clc;close all;
ImgFile='D:\PROJECT\SDOCT_Segmentation_Code\SDOCT_Segmentation_2\AfterLabor.bmp';
ImgIn=imread(ImgFile);
ImgHistEq=histeq(ImgIn,256);
figure;subplot(121);imshow(uint8(ImgIn));title('原图');
subplot(122);imshow(ImgHistEq);title('全局灰度增强 - 直方图均衡');
figure;subplot(121);imhist(ImgIn,256);
axis([0 255 0 1e5]);title('原图的直方图');
subplot(122);imhist(ImgHistEq,256);axis([0 255 0 1e5]);title('直方图均衡化后的直方图');
% 自定义直方图均衡
[counts,x]=imhist(ImgIn,256);
cum_counts=cumsum(counts);
cum_counts=uint8(cum_counts/max(cum_counts)*255);% 转化函数
figure;plot(x,cum_counts);axis([0 255 0 255]);
xlabel('原图灰度');ylabel('转换后灰度');title('原图CDF转化的灰度映射函数');
ImgOut=nan(size(ImgIn));
for i=1:length(x)
    ImgOut(ImgIn==x(i))=cum_counts(i);
end
ImgOut=uint8(ImgOut);
figure;imshow(uint8(ImgOut));title('自定义直方图均衡')
figure;imhist(ImgOut,256);axis([0 255 0 1e5]);title('自定义直方图均衡的直方图')