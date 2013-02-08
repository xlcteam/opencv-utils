opencv-cam-player
==================

`opencv-cam-player` is a totally lightweight app based on OpenCV which lets you
do just one thing: see what your camera sees.


Installation
------------

Just run

    $ make opencv-cam-player

Note: *you'll need OpenCV 2.3 to compile this*

Usage
-----

Just run

    $ ./opencv-cam-player

If it doesn't show anything it might be because you do not have rights to read
from the camera. Thus, you'll need to run it as the superuser:


    $ sudo ./opencv-cam-player

