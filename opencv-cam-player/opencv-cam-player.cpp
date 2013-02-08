#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
using namespace cv;



int main(int argc, const char** argv)
{
    CvCapture* capture = 0;
    Mat frame, frameCopy, image;
    int cam = (argc > 1 ? atoi(argv[1]) : 0);

    capture = cvCaptureFromCAM(cam);
    if(!capture) cout << "No camera detected" << endl;
    cvNamedWindow( "result", 1 );


    if(capture) {
        cout << "We've got a camera!" << endl;
        while (1) {
            IplImage* iplImg = cvQueryFrame( capture );
            frame = iplImg;
            if(frame.empty())
                break;

            if(iplImg->origin == IPL_ORIGIN_TL)
                frame.copyTo(frameCopy);
            else
                flip(frame, frameCopy, 0);

            imshow("result", frame);
            waitKey(20);
        }
    }
    cvDestroyWindow("result");

    return 0;
}
