#if 1
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
#include <opencv2/objdetect.hpp>
using namespace std;
using namespace cv;
/////////////////   project3    ////////////////////



void main() {
	//pic
	/*string path = "carc3.jpg";
	Mat img = imread(path);*/
	//video
	string path = "street1.mp4";
	VideoCapture cap(path);
	Mat img;
	//camera
	//VideoCapture cap(0);
	//Mat img;

	//resize(img, img, Size(), 0.6, 0.6);

	CascadeClassifier plateCascade;
	plateCascade.load("haarcascade_russian_plate_number.xml");

	if (plateCascade.empty()) {
		cout << "XML file not loaded" << endl;
	}

	vector<Rect> plate;

	while (true) {
		cap.read(img);


		plateCascade.detectMultiScale(img, plate, 1.1, 3);

		for (int i = 0; i < plate.size(); i++) {
			Mat imgCrop = img(plate[i]);
			imshow(to_string(i), imgCrop);
			imwrite("Users\ian\C\oop\Plates\image.bmp", imgCrop);
			rectangle(img, plate[i].tl(), plate[i].br(), Scalar(255, 0, 255), 3);
		}

		imshow("Image", img);
		waitKey(1);
	}
}

#endif

