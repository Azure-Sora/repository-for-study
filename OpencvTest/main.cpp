#include<opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>
#include<Windows.h>
#include<atlimage.h>
#include<iostream>
#include"ADB.h"
#include<thread>
using namespace cv;
using std::string;
using std::cout;

bool connected = false;

bool desktopScreenShot(std::wstring name,HWND hWnd)
{
	HDC hDc = NULL;
	hWnd = (hWnd == NULL) ? GetDesktopWindow() : hWnd; //判断窗口句柄是否为NULL,如果为NULL则默认获取桌面DC
	hDc = GetDC(hWnd); //获取DC
	if (hDc == NULL) return false;
	int bitOfPix = GetDeviceCaps(hDc, BITSPIXEL); //获取DC像素的大小

	int width = 2560;
	int hight = 1440;

	CImage image;
	image.Create(width, hight, bitOfPix); //为图像类创建与窗口DC相同大小的DC
	BitBlt(image.GetDC(), 0, 0, width, hight, hDc, 0, 0, SRCCOPY); //将窗口DC图像复制到image
	image.Save(name.data(), Gdiplus::ImageFormatJPEG); //保存为png格式图片文件
	image.ReleaseDC(); //释放DC
	ReleaseDC(hWnd, hDc); //释放DC资源
}

bool findTemplPos(std::string srcPath, std::string templPath, Point& resultPt)
{
	Mat src = imread(srcPath);
	Mat templ = imread(templPath);
	
	if (!src.empty() && !templ.empty())
	{
		Mat result(src.rows - templ.rows + 1, src.cols - templ.cols + 1, CV_32FC1);

		matchTemplate(src, templ, result, TM_CCOEFF_NORMED);

		double dMaxVal; //分数最大值
		Point ptMaxLoc; //最大值坐标
		minMaxLoc(result, 0, &dMaxVal, 0, &ptMaxLoc); //寻找结果矩阵中的最大值

		if (dMaxVal > 0.9)
		{
			resultPt = ptMaxLoc;
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;

	//匹配结果的四个顶点
	//Point pt1(ptMaxLoc.x, ptMaxLoc.y);
	/*Point pt2(ptMaxLoc.x + templ.cols, ptMaxLoc.y);
	Point pt3(ptMaxLoc.x, ptMaxLoc.y + templ.rows);
	Point pt4(ptMaxLoc.x + templ.cols, ptMaxLoc.y + templ.rows);*/

	//std::cout << pt1.x << '\n' << pt1.y << '\n';
	

}

bool findUnreadMsg()
{
	ADB::getScreenShot();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	cout << "findUnreadMsg\n";

	string src = "screen.jpg";
	string unread1 = "unread1.jpg";
	string unread2 = "unread2.jpg";
	Point pt;

	if (findTemplPos(src, unread1, pt))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		ADB::tap(pt.x, pt.y);
		return true;
	}
	else if (findTemplPos(src, unread2, pt))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		ADB::tap(pt.x, pt.y);
		return true;
	}
	return false;
}

bool waitKizunaEvent()
{
	Point pt;
	bool clickEvent = false;
	int retryTimes = 10;
	cout << "waitKizunaEvent\n";
	while (retryTimes)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		ADB::getScreenShot();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		if (clickEvent && findTemplPos("screen.jpg", "startKizunaEvent.jpg", pt))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			ADB::tap(pt.x + 150, pt.y + 100);
			cout << "startKizunaEvent\n";
			break;
		}
		if (findTemplPos("screen.jpg", "reply.jpg", pt))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			retryTimes = 10;
			ADB::tap(pt.x + 150, pt.y + 100);
			cout << "reply\n";
		}
		if (findTemplPos("screen.jpg", "kizunaEvent.jpg", pt))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			retryTimes = 10;
			ADB::tap(pt.x + 150, pt.y + 100);
			cout << "kizunaEvent\n";
			clickEvent = true;
		}
		--retryTimes;
	}
	if (retryTimes <= 0) return false;
	return true;
}

bool skipKizunaEvent(bool retry = false)
{
	Point pt;
	bool clickMenu = false;
	bool clickSkip = false;
	bool clickOK = false;
	int retryTimes = 10;
	cout << "skipKizunaEvent\n";
	while (retryTimes)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		ADB::getScreenShot();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		if (findTemplPos("screen.jpg", "stone.jpg", pt))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			ADB::tap(1000, 800);
			cout << "stone\n";
			clickOK = true;
			break;
		}
		if (!clickOK && findTemplPos("screen.jpg", "OKButton.jpg", pt))
		{
			retryTimes = 10;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			ADB::tap(pt.x + 150, pt.y + 100);
			cout << "OKButton\n";
			clickSkip = true;
			continue;
		}
		if (!clickSkip && findTemplPos("screen.jpg", "skip.jpg", pt))
		{
			retryTimes = 10;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			ADB::tap(pt.x + 30, pt.y + 30);
			cout << "skip\n";
			clickMenu = true;
			continue;
		}
		if (!clickMenu && findTemplPos("screen.jpg", "menuButton.jpg", pt))
		{
			retryTimes = 10;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			ADB::tap(pt.x + 30, pt.y + 30);
			cout << "menuButton\n";
			
		}
		--retryTimes;
		if (retryTimes <= 0)
		{
			if (!retry)
			{
				return skipKizunaEvent(true);
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

void refreshMonoTalk()
{
	cout << "refreshMonoTalk\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	ADB::tap(100, 100);
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	ADB::tap(260, 220);
	std::this_thread::sleep_for(std::chrono::milliseconds(2500));;
	ADB::tap(260, 415);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void swipeMsgList()
{
	cout << "swipeMsgList\n";
	string rslt = "";
	ADB::executeADB("shell input swipe 700 850 700 400", rslt);
}

void schedule()
{
	if (findUnreadMsg())
	{
		if (!waitKizunaEvent())
		{
			refreshMonoTalk();
			return;
		}
		if (!skipKizunaEvent()) exit(0);
		refreshMonoTalk();
	}
	else
	{
		swipeMsgList();
	}
	
}

//void countDown(std::thread& instance)
//{
//	int restartCountDown = 60;
//	while (restartCountDown > 0)
//	{
//		--restartCountDown;
//		std::this_thread::sleep_for(std::chrono::seconds(1));
//	}
//	ExitThread()
//}

int main()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cv::utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);

	string result = "";

	connected = ADB::connectTo("localhost:16384");

	if (connected)
	{
		cout << "\tconnected\t";
		while (1)
		{
			schedule();
			/*std::thread instance = std::thread(schedule);
			instance.join();*/
		}
		
	}
	
	//ADB::connectTo("localhost:16384");

	/*while (1)
	{
		Sleep(1000);

	}*/

	//ADB::getScreenShot();

	//cout << result;

	//desktopScreenShot(L"test.jpg", NULL);
	/*string src = "screen.jpg";
	string tmpl = "unread1.jpg";
	Point pt1 = findTemplPos(src, tmpl);

	std::cout << pt1.x << '\n' << pt1.y << '\n';*/

	//ADB::tap(pt1.x, pt1.y);

	//replyButton(pt1);

	//SetCursorPos(pt1.x / 1.25, pt1.y / 1.25);
	//Sleep(10);
	//mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//模拟鼠标键按下
	//Sleep(10);//要留给某些应用的反应时间 
	//mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//模拟鼠标键抬起


	//imshow("templ", templ);
	//imshow("result", src);

	ADB::executeCmd(".\\ADB\\adb kill-server", result);

    waitKey(0);
    return 0;
}
//nemudisplay