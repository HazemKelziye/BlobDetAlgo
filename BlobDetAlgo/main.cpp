#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, const char * argv[]) {

    Mat Blob = imread("/Users/hazemkilzieh/Desktop/BlobDetAlgo/PartialBlob2.jpg",IMREAD_GRAYSCALE);
    
    
    
    for (int r = 0; r < Blob.rows; r++) {
        for (int c = 0; c < Blob.cols; c++) {
            <#statements#>
        }
    }
    
    return 0;
}
