    
/*
useful snippet of c++ opencv

author : liuweiwei
date   : 2018-11-04

*/	
	
	
	
//导入图像
Mat img1 = imread("MEI.jpg", 1);
Mat img2(img1.rows,img1.cols,CV_8UC3);

//设置感兴趣区域,拷贝
img1(Rect(10, 15, 150, 250)).copyTo(img2);

///////////////////////////////////////////// 形态学处理 ///////////////////////////////////////////////////
morphologyEx(MEI_image, MEI_image, MORPH_ERODE, element);
morphologyEx(MEI_image, MEI_image, MORPH_DILATE, element);

morphologyEx(MEI_image, MEI_image, MORPH_OPEN, element); //先MORPH_ERODE, 后MORPH_DILATE
morphologyEx(MEI_image, MEI_image, MORPH_CLOSE, element); //先MORPH_DILATE, 后MORPH_ERODE

morphologyEx(MEI_image, MEI_image, MORPH_BLACKHAT, element); //先MORPH_CLOSE 后减去 src;  黑帽操作常用于检测图像中的波谷结构。
morphologyEx(MEI_image, MEI_image, MORPH_TOPHAT, element); //src 减去 开运算过后的图像； 顶帽操作常用与检测图像中的峰结构。


/////////////////////////////////////// 前景提取方案/ 图像遍历 ///////////////////////////////////////////
/*
description：比较蠢的一种提取前景方案，不是前景置0；
function：
input: img_mask: 原始图像
output: img_mask:图片前景
*/
Mat getPedestrianMask( Mat& img_mask, vector<cv::Rect>* detected )
{
	int width= img_mask.rows;
	int height = img_mask.cols;
//	Mat dst_mask(width,height, CV_8UC1);
//	dst_mask.convertTo(dst_mask,CV_64FC1,1);  自己创建图像会倒立显示，还不知道有什么好方法。
	for(int k=detected->size();k>0;--k)
	{
		Rect r= (*detected)[k-1];
	    for (int i=0;i<width;i++)
	    	   for(int j=0;j<height;j++)
					  if((i< r.x)||(i>(r.x+r.width))||(j< r.y)||(j>(r.y+r.height)))
						   img_mask.at<uchar>(i,j)=0;
//					  else 
//						  dst_mask.at<uchar>(i,j)=img_mask.at<uchar>(i,j);
	}
	return img_mask;
}