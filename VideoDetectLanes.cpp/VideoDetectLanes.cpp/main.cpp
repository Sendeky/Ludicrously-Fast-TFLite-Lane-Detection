//
//  main.cpp
//  VideoDetectLanes.cpp
//
//  Created by Ruslan Spirkin on 6/29/23.
//

#include <iostream>
#include </opt/homebrew/Cellar/opencv/4.8.0/include/opencv2/opencv.hpp>         // path is a bit different because M1 Mac Homebrew install (I think?)
#include "LudicrousLaneDetector.hpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    // get path to video
    std::string videoPath;
    std::cout << "Enter Video Path:";
    std::cin >> videoPath;
    
    std::cout << "videoPath: " << videoPath << std::endl;
    
    cv::VideoCapture cap;
    
    if (videoPath != "") {
        std::cout << "Yay!" << std::endl;
        cap.open(videoPath);
    }
    
    std::cout << "main2: ";
    main2();
    
    // if no success, exit program
    if (cap.isOpened() == false) {
        std::cout << "Cannot open video file";
        std::cin.get(); //wait for any key press
        return -1;
    }
    
    //Uncomment for skipping to video position
    //cap.set(CAP_PROP_POS_MSEC, 300);
    
    // gets fps of video
    double fps = cap.get(cv::CAP_PROP_FPS);
    std::cout << "Video fps: " << fps << std::endl;
    
    // OpenCV window name
    cv::String window_name = "OpenCV WIndow";
    
    // creates window
    cv::namedWindow(window_name, cv::WINDOW_NORMAL);
    
    while (true) {
        cv::Mat frame;
        bool bSuccess = cap.read(frame);    // read new frame from video
        
        // breaks the while loop at the end of the video or if reading frame is false
        if (bSuccess == false) {
            std::cout << "Found the end of the video" << std::endl;
            break;
        }
        
        // show frame in created window
        cv::imshow(window_name, frame);

        //wait for for 10 ms until any key is pressed.
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop
        //If any key is not pressed withing 10 ms, continue the loop
        if (cv::waitKey(5) == 27) {
            std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
            break;
        }
    }
    return 0;
}
