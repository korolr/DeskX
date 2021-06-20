<p align="center"><img height="120px" src="./info/logo.png"></p>
<h4 align="center">DeskX - Remote control program</h4>

## About project and reasons for creation

The project was created for its own use within the home local network (you can use DeskX over the internet using port forwarding via ssh, with such a connection you only need to use the TCP protocol). I have a server at home with a large number of Linux virtual machines to which I needed remote access. All similar remote control programs I tried lagged in the process (banal scrolling in the browser or dragging windows). For this reason, a project was created that focuses on the fastest possible data transfer over the local network. The project works on all operating systems with X11. [Leave your review :)](https://github.com/DeskX11/DeskX/discussions/4)

## Functionality (not fully implemented)

- Selection of the range of the difference between adjacent pixels to ensure compression (from 0 to 255).
- Multiple Commands: Server Side Shutdown, Remote Control, Take Screenshot.
- Ability to set an authorization password.
- There is a choice of data transfer protocol (TCP or UDP).
- Full screen or windowed mode.
- Two separate streams for transferring screen data and events.

## An example of working with compression

<p align="center"><img src="./info/example.png"></p>
Video example of how the program works (compression parameter is 16, protocol for events and screen is TCP, gigabit LAN is used): https://youtu.be/pDRSAVssPek

## Compression algorithm

The first step is to generate a hash table of colors that are most often found on the screen (up to 256 colors) on the server side. The color table is sent to the client side. Subsequently, 1 byte of the color identifier can be written to the place of writing 3 bytes of color. The next step is the lossy compression of the frame based on the allowable difference between the color bytes (the range of the difference can be changed by the user, this affects the packet size and picture quality). Also, in the process of sending the next frames, the program detects unchanged areas and makes an indication that nothing needs to be changed in this place on the screen, if it fails, it tries to refer to a similar color vertically or horizontally. Thus, it is possible to significantly reduce the size of the transmitted packet.

## Screen resolution

Controlling screen resolution and picture sizes is entirely dependent on the server-side resolution settings. To change it, use the standard utility xrandr.

## Window or Full screen mode

Full screen mode is enabled when your screen resolution matches the server side screen resolution. Press the `F7` key to exit full screen mode.

## Get started

```bash
sudo apt install libx11-dev libxtst-dev libssl-dev
git clone https://github.com/DeskX11/DeskX/
cd DeskX
make client # To compile the client side
make server # To compile the server side
```
After these steps 2 files will be compiled: `dxc` (the client part, which must be launched on the computer from which the control will be carried out) and `dxs` (server part for a managed computer). To get an example of how exactly you need to start the client and server parts - just run the programs without arguments `./dxc` or `./dxs`.

## How to get best performance?

Fast data transfer depends on two factors: the size of the transmitted packet and the transfer rate. To reduce the size of the batch, you can try changing the `--compression` parameter up. To reduce transmission latency, you can try changing the data transfer protocol for both screen and events (according to my observations, the best option is `--screen=TCP` and `--events=UDP`). Also, the speed of the transmission channel plays an important role; it is recommended to use a router with a gigabit LAN. As a last resort, you can also try to disable unnecessary effects such as window shadows.

## How to get the best picture quality?

You should take into account that the better the picture quality, the larger the packet size, and this will increase the delay. This moment will always be a compromise between quality and speed. To improve the quality of the picture, you can decrease the value of the parameter `--compression`. Also, to reduce distortion associated with shadow windows and other visual nuances, run the program with the `--disable-vert` parameter.

## Can't open X-Display.

This error usually occurs when you try to start `dxs` via ssh. To solve it, you need to specify the `--display` and `--xauth` arguments. `--xauth` - path to `.Xauthority` file, `--display` - display number, default value should be `:0` or `:0.0`. For more information you can read xauth, Xsecurity and xhost man pages.

## Upcoming updates

- Fixing a bug with reconnecting to the server (TCP).
- Fix disconnect bug with long palette generation.
- Stable bin files & .deb packs.
- Server side as a daemon.
- GUI part of the program.

## Requirements

- OS with x11
- `g++ make`
- `libx11-dev libxtst-dev libssl-dev libxext-dev`
