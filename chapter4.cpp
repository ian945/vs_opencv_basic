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
	int x=512, y=512;
	Mat img(x,y, CV_8UC3, Scalar(255,0,0));
	
	circle(img, Point(x / 2, y / 2),512/3, Scalar(0,155,180),10);
	//            x,y adress             R         color    line pixel
	circle(img, Point(x / 2, y / 2), 512 / 8, Scalar(50, 255, 50), FILLED);
	//            x,y adress             R               color          All clean
	
	rectangle(img, Point(x/2-120, y/2-25), Point(x/2+120, y/2+25),Scalar(255,255,255), FILLED);
	line(img, Point(x/2-80, y/2+80), Point(x/2+80, y/2-80), Scalar(0, 0, 0), 3);
	
	putText(img, "Murtaza' Workshop", Point(137, 262), FONT_HERSHEY_PLAIN, 1.5, Scalar(20, 20, 20),3);

	imshow("Image", img);

	waitKey(0);
}


#endif
