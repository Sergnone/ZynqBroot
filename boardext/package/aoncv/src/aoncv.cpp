//#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        //cout << "Usage: opencv_example <Input_image_path>" << endl;
        return -1;
    }

    // Load an image
    Mat img = imread(argv[1], IMREAD_COLOR);

    if (img.empty()) {
        //cout << "Could not open or find the image" << endl;
        return -1;
    }

    // Convert to grayscale
    Mat gray_img;
    cvtColor(img, gray_img, COLOR_BGR2GRAY);

    // Apply blur
    Mat blurred_img;
    blur(gray_img, blurred_img, Size(9, 9));

    // Save the processed image
    imwrite("output_image.jpg", blurred_img);
    //cout << "Processed image saved as output_image.jpg" << endl;

    return 0;
}
