#if 1
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
using namespace std;
using namespace cv;
/////////////////   Resize and Crop    ////////////////////
void main() {
	string path = "car.png";
	Mat img = imread(path);
	Mat imgResize, imgCrop;
	
	cout << img.size() << endl;
	
	resize(img, imgResize, Size(450,450));
	resize(img, imgResize, Size(), 0.5,0.5);
	
	Rect roi(50, 50, 150, 100);
	imgCrop = img(roi);
	
	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);
	waitKey(0);
}


#endif