#if 1
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
using namespace std;
using namespace cv;
/////////////////   Warp Image    ////////////////////

float w = 250, h = 350;
Mat matrix, imgWarp;

void main() {
	string path = "card.png";
	Mat img = imread(path);

	Point2f src[4] = { {925,475},{1125,613},{647,742},{853,934} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	circle(img, Point((925 + 1125 + 647 + 853) / 4, (475 + 613 + 742 + 934) / 4), 250, Scalar(50, 50, 255), 3);

	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 25, Scalar(0, 0, 200), 3);
	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	waitKey(0);
}

#endif
