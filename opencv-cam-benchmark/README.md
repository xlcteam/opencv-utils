opencv-cam-benchmark
====================

`opencv-cam-benchmark` tries to find the FPS rate of your camera.

Installation
------------

Just run

    $ make opencv-cam-benchmark

Note: *you'll need OpenCV 2.3 to compile this*.

If you have trouble installing it, have a look at this [guide for
Ubuntu](https://help.ubuntu.com/community/OpenCV)

Usage
-----

Just run

    $ ./opencv-cam-benchmark

If it doesn't show anything it might be because you do not have rights to read
from the camera. Thus, you'll need to run it as the superuser:


    $ sudo ./opencv-cam-benchmark




