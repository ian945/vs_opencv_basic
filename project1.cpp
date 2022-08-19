#if 1
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
using namespace std;
using namespace cv;



/////////////////   Project 1    ////////////////////

vector<vector<int>> myColors{ {124,48,117,143,170,255}, {60,96,0,76,158,255} };
vector<Scalar> myColorValues{ {255,0,255}, {0,255,0} };
Mat img;
vector<vector<int>> newPoints;

Point getContours(Mat imgDil) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE); // §ä½ü¹ø
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	Point myPoint(0, 0);

	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		cout << area << endl;

		
		string objectType;

		if (area > 2500) {

			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
			myPoint.x = boundRect[i].x ;
			myPoint.y = boundRect[i].y + boundRect[i].height / 2;


			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
		}
	}
	return myPoint;
}

vector<vector<int>> findColor(Mat img) {
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	for (int i = 0; i < myColors.size(); i++) {
		Scalar lower(myColors[i][0], myColors[i][2], myColors[i][4]);
		Scalar upper(myColors[i][1], myColors[i][3], myColors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		//imshow(to_string(i), mask);
		Point myPoint = getContours(mask);

		if(myPoint.x != 0 && myPoint.y != 0)
		newPoints.push_back({ myPoint.x, myPoint.y , i});
	}
	return newPoints;
}

void drawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues) {
	for (int i = 0; i < newPoints.size(); i++) {
		circle(img, Point(newPoints[i][0],newPoints[i][1]),10, myColorValues[newPoints[i][2]], FILLED);
	}
}

void main() {
	VideoCapture cap("http://192.168.168.11:8081/");

	//string path = "USB.mp4";
	//VideoCapture cap(path);
	
	while (true) {
		cap.read(img);
		newPoints = findColor(img);
		drawOnCanvas(newPoints, myColorValues);

		imshow("Image", img);
		waitKey(1);
	}
}
#endif

