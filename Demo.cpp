/*
This file is part of BGSLibrary.

BGSLibrary is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

BGSLibrary is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with BGSLibrary.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv/cv.h>
#include <opencv/cvaux.h>
#include  <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\video\background_segm.hpp>
#include <opencv2\video\video.hpp>
#include <opencv\cxcore.h> 
#include <direct.h>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <io.h>
#include <string>
#include <stdio.h>

#include "package_bgs/FrameDifferenceBGS.h"
#include "package_bgs/AdaptiveBackgroundLearning.h"
#include "package_bgs/db/IndependentMultimodalBGS.h"
#include "package_bgs/bgfg_gaussmix.h"
#include "package_bgs/bgfg_gaussmix2.h"
#include "package_bgs/bgfg_gmg.h"

bool enableFiltering = true;

bool dirExists(const std::string& dirName_in)
{
	int ftyp = _access(dirName_in.c_str(), 0);

	if (0 == ftyp)
		return true;   // this is a directory!
	else
		return false;    // this is not a directory!
}

int process_one_video(string &videoname, string& savename)
{
	VideoCapture video(videoname);
	if (!video.isOpened())
		return -1;

	/* Background Subtraction Methods */

	BackgroundSubtractor* bgs;
	bgs = new m_BackgroundSubtractorMOG();
	Mat img_input;
	cv::Mat img_mask;
	int key = 0;
	int k = 0;
	std::ostringstream buffer;

	while (true)
	{	
		
		video >> img_input;
		if (img_input.empty())
		{
			break;
		}
		//cv::imshow("input", img_input);
		if (k == 0)
		{
			img_mask.create(img_input.size(), CV_8U);
		}
		
		(*bgs)(img_input, img_mask, -1);

		if (enableFiltering)
		{
			/*******************************形态学处理**********************************/
			Mat mDilate;
			Mat element = getStructuringElement(MORPH_CROSS,
				Size(3, 3),
				Point(1, 1));
			Mat elementD = getStructuringElement(MORPH_RECT,
				Size(4, 12),
				//								Size( 5, 15 ),
				Point(1, 3));
			erode(img_mask, mDilate, element);
			dilate(mDilate, mDilate, elementD);
			mDilate.copyTo(img_mask);
		}
		Mat element = getStructuringElement(MORPH_RECT, Size(8, 8));
		cv::Mat dst;
		if (!img_mask.empty())
		{
			erode(img_mask, dst, element);
			dilate(dst, dst, element);
			//imshow("dst", dst);
			//img_input.copyTo(fg, dst);
			//imshow("fg", fg);
			k++;
			buffer << savename <<"\\"<< std::setfill('0') << setw(6) << k << ".jpg";
			string save_image_name = buffer.str();
			buffer.str("");
			imwrite(save_image_name, dst);
		}
		key = cvWaitKey(3);
	}
	delete bgs;
	return 0;
}



int main(int argc, char **argv)
{
  std::cout << "Using OpenCV " << CV_MAJOR_VERSION << "." << CV_MINOR_VERSION << "." << CV_SUBMINOR_VERSION << std::endl;
 

  //std::string inPath = "Z:\\dataset\\HMDB51\\hmdb51_org\\";
  //std::string save_path = "Z:\\dataset\\HMDB51\\foreground_images\\";

  std::string inPath = "Z:\\dataset\\UCF101\\UCF101_org\\";
  std::string save_path = "Z:\\dataset\\UCF101\\foreground_images\\";

  _mkdir(save_path.c_str());
  //find handle
  long int handle;
  struct _finddata_t fileinfo;
  //first find
  handle = _findfirst((inPath+"*").c_str(), &fileinfo);
  if (handle == -1)
	  return -1;
  int videocount = 0;
  do
  {
	  printf("%s\n", fileinfo.name);
	  if (strcmp(fileinfo.name,".")==0 || strcmp(fileinfo.name ,"..")==0)
		  continue;
	  string class_save_path = save_path+ string(fileinfo.name);
	  _mkdir(class_save_path.c_str());

	  std::string class_path = inPath + fileinfo.name + "\\";
	  struct _finddata_t videosinfo;
	  long int v_handle;
	  v_handle = _findfirst((class_path + "*.avi").c_str(), &videosinfo);

	  do
	  {
		  if (strcmp(videosinfo.name, ".") == 0 || strcmp(videosinfo.name, "..") == 0)
			  continue;
		  // delete ".avi" or ".mp4"
		  videocount++;
		  printf("%d  %s  %s\n", videocount, fileinfo.name, videosinfo.name);
		  int N = strlen(videosinfo.name);
		  string images_save_path = class_save_path + "\\" + string(videosinfo.name).erase(N-4);
		  //string videoname = class_path + videosinfo.name;
		  //process_one_video(videoname, images_save_path);
		  if (!dirExists(images_save_path))
		  {
			  _mkdir(images_save_path.c_str());
			  string videoname = class_path + videosinfo.name;
			  process_one_video(videoname, images_save_path);
		  }
	  } while (!_findnext(v_handle, &videosinfo));
	
	  _findclose(v_handle);

  } while (!_findnext(handle, &fileinfo));

  _findclose(handle);
  return 0;

}

