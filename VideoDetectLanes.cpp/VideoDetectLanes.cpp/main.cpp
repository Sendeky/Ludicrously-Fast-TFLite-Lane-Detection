//
//  main.cpp
//  VideoDetectLanes.cpp
//
//  Created by Ruslan Spirkin on 6/29/23.
//

#include <iostream>
#include </opt/homebrew/Cellar/opencv/4.8.0/include/opencv2/opencv.hpp>         // path is a bit different because M1 Mac Homebrew install (I think?)


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    // get path to video
    std::string videoPath;
    std::cout << "Enter Video Path:";
    std::cin >> videoPath;
    
    std::cout << "videoPath: " << videoPath;
    
    cv::VideoCapture cap;
    
    if (videoPath != "") {
        std::cout << "Yay!";
        cap.open(videoPath);
    }
    
    // if no success, exit program
    if (cap.isOpened() == false) {
        std::cout << "Cannot open video file";
        std::cin.get(); //wait for any key press
        return -1;
    }
    
    return 0;
}
