#if 1
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
using namespace std;
using namespace cv;
/////////////////   Image    ////////////////////
//void main() {
//	string path = "car.png";
//	Mat img = imread(path);
//	imshow("Image", img);
//	waitKey(0);
//}

/////////////////   Video    ////////////////////
//void main() {
//	string path = "USB.mp4";
//	VideoCapture cap(path);
//	Mat img;
//	while (true) {
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(20);
//	}
//}

/////////////////   Webcam    ////////////////////
void main() {
	VideoCapture cap("http://192.168.168.11:8081/");
	Mat img;
	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	}
}
#endif




#if 0
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main() {

	string path = "pic.png";
	Mat img = imread(path);
	imshow("Image", img);
	waitKey(0);
	return 0;
}
#endif